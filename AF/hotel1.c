#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct quarto
{
    int num;
    char categoria;
    char status; // L-ivre ou O-cupado
} quarto;

typedef struct hospede
{
    int quarto;
    char nome[80];
    int acompanhante;
    char categoria;
    int dias;
} hospede;

void aloca_hospede(hospede **ph, int qh);
void aloca_quarto(quarto **pq, int qq);

int verifica_hospede();
int verifica_quarto();

void cadastra_hospede(hospede *ph, quarto *pq, int qq);
void cadastra_quarto(quarto *pq, int qq);

void check_out(hospede *ph, quarto *pq);

int busca_hospede(hospede *ph, int n_quarto);
int busca_quarto(quarto *pq, int qq, char cat);
int busca_vago(hospede *ph, int qh);

void atualiza_quarto(quarto *pq, int n_quarto);

void grava_hospede(hospede *ph, char *aux, int pos);
void grava_quarto(quarto *pq);

void mostra_hospede(hospede *ph);
void mostra_quarto(quarto *pq);

int main()
{
    setlocale(LC_ALL, "portuguese");

    quarto *pq = NULL;
    hospede *ph = NULL;
    int opc, qq;

    aloca_quarto(&pq, 1);

    qq = verifica_quarto();

    if (qq == 0)
    {
        cadastra_quarto(pq, 15);
    }

    aloca_hospede(&ph, 1);

    do
    {
        system("cls");
        printf("\n[1]Check-in\n[2]Check-out\n[3]Mostra Quarto\n[4]Mostra Hospede\n[5]Fim\nOpcao: ");
        scanf("%i", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            cadastra_hospede(ph, pq, qq);
            break;

        case 2:
            check_out(ph, pq);
            break;

        case 3:
            mostra_quarto(pq);
            break;

        case 4:
            mostra_hospede(ph);
            break;

        default:
            break;
        }

    } while (opc != 5);

    return 0;
}

void aloca_hospede(hospede **ph, int qh)
{
    if ((*ph = (hospede *)realloc(*ph, qh * sizeof(hospede))) == NULL)
    {
        exit(1);
    }
}

void aloca_quarto(quarto **pq, int qq)
{
    if ((*pq = (quarto *)realloc(*pq, qq * sizeof(quarto))) == NULL)
    {
        exit(1);
    }
}

int verifica_hospede()
{
    FILE *fh = NULL;
    int qh = 0;

    if ((fh = fopen("hospedes.bin", "rb")) == NULL)
    {
        return qh;
    }
    else
    {
        fseek(fh, 0, 2);
        qh = ftell(fh) / sizeof(hospede);
        fclose(fh);
        return qh;
    }
}

int verifica_quarto()
{
    FILE *fq = NULL;
    int qq = 0;

    if ((fq = fopen("quartos.bin", "rb")) == NULL)
    {
        return qq;
    }
    else
    {
        fseek(fq, 0, 2);
        qq = ftell(fq) / sizeof(quarto);
        fclose(fq);
        return qq;
    }
}

void cadastra_hospede(hospede *ph, quarto *pq, int qq)
{
    int qh = verifica_hospede();
    int pos = busca_vago(ph, qh);

    printf("\nNome: ");
    gets(ph->nome);
    fflush(stdin);

    do
    {
        printf("\nAcompanhantes (máx 3): ");
        scanf("%i", &(ph->acompanhante));
        fflush(stdin);
    } while (ph->acompanhante < 0 || ph->acompanhante > 3);

    if (ph->acompanhante == 0)
        ph->categoria = 'S';

    else
        ph->categoria = 'F';

    printf("\nDias: ");
    scanf("%i", &(ph->dias));
    fflush(stdin);

    ph->quarto = busca_quarto(pq, qq, ph->categoria);

    if (ph->quarto == -1)
    {
        printf("\nNão há quartos nessa categoria...");
    }
    else
    {
        printf("\nSua reserva foi feita com sucesso! Seu quarto é %i.", pq->num);

        if (pos == -1)
            grava_hospede(ph, "ab", 1);

        else
            grava_hospede(ph, "rb+", pos);
    }

    system("pause");
}

void cadastra_quarto(quarto *pq, int qq)
{
    int i;

    for (i = 0; i < qq; i++)
    {
        pq->num = i + 1;
        pq->status = 'L';

        if (i < 5)
            pq->categoria = 'S';

        else
            pq->categoria = 'F';

        grava_quarto(pq);
    }
}

void check_out(hospede *ph, quarto *pq)
{
    int n_quarto, achou;
    float valor;

    printf("\nQuarto a ser finalizado: ");
    scanf("%i", &n_quarto);
    fflush(stdin);

    achou = busca_hospede(ph, n_quarto);

    if (achou == -1)
    {
        printf("\nQuarto não encontrado\n\n");
    }

    else
    {
        if (ph->categoria == 'S')
            valor = ph->dias * 85;

        else
            valor = ph->dias * ((ph->acompanhante) + 1) * 65;

        printf("\nNome: %s\nAcompanhantes: %i\nCategoria: %c\nDias: %i\nValor a ser pago: %.2f\n\n", ph->nome, ph->acompanhante, ph->categoria, ph->dias, valor);

        atualiza_quarto(pq, n_quarto);
    }

    system("pause");
}

int busca_hospede(hospede *ph, int n_quarto)
{
    FILE *fh = NULL;
    int i, qh, pos = -1;
    qh = verifica_hospede();

    if ((fh = fopen("hospedes.bin", "rb+")) == NULL)
    {
        printf("\nErro\n\n");
    }
    else
    {
        for (i = 0; i < qh; i++)
        {
            fseek(fh, i * sizeof(hospede), 0);
            fread(ph, sizeof(hospede), 1, fh);

            if (ph->quarto == n_quarto)
            {
                ph->quarto = -1;
                fseek(fh, i * sizeof(hospede), 0);
                fwrite(ph, sizeof(hospede), 1, fh);
                pos = i;
                i = qh;
            }
        }
    }
    fclose(fh);
    return pos;
}

int busca_quarto(quarto *pq, int qq, char cat)
{
    FILE *fq = NULL;
    int pos = -1, i;

    if ((fq = fopen("quartos.bin", "rb+")) == NULL)
    {
        printf("\nErro\n\n");
    }
    else
    {
        for (i = 0; i < qq; i++)
        {
            fseek(fq, i * sizeof(quarto), 0);
            fread(pq, sizeof(quarto), 1, fq);

            if (pq->categoria == cat && pq->status == 'L')
            {
                pq->status = 'O';
                fseek(fq, i * sizeof(quarto), 0);
                fwrite(pq, sizeof(quarto), 1, fq);
                pos = pq->num;
                i = qq;
            }
        }
    }
    fclose(fq);
    return pos;
}

int busca_vago(hospede *ph, int qh)
{
    FILE *fh = NULL;
    int i;

    if ((fh = fopen("hospedes.bin", "rb")) == NULL)
    {
        return -1;
    }

    else
    {
        for (i = 0; i < qh; i++)
        {
            fseek(fh, i * sizeof(hospede), 0);
            fread(ph, sizeof(hospede), 1, fh);

            if (ph->quarto == -1)
            {
                fclose(fh);
                return i;
            }
        }

        fclose(fh);
    }
    return -1;
}

void atualiza_quarto(quarto *pq, int n_quarto)
{
    FILE *fq = NULL;
    int i, qq, pos = -1;
    qq = verifica_quarto();

    if ((fq = fopen("quartos.bin", "rb+")) == NULL)
    {
        printf("\nErro\n\n");
    }
    else
    {
        for (i = 0; i < qq; i++)
        {
            fseek(fq, i * sizeof(quarto), 0);
            fread(pq, sizeof(quarto), 1, fq);

            if (pq->num == n_quarto)
            {
                pq->status = 'L';
                fseek(fq, i * sizeof(quarto), 0);
                fwrite(pq, sizeof(quarto), 1, fq);
                i = qq;
            }
        }
    }
    fclose(fq);
}

void grava_hospede(hospede *ph, char *aux, int pos)
{
    FILE *fh = NULL;

    if ((fh = fopen("hospedes.bin", aux)) == NULL)
        printf("\nErro\n\n");

    else
    {
        if (strcmp(aux, "rb+") == 0)
            fseek(fh, pos * sizeof(hospede), 0);

        fwrite(ph, sizeof(hospede), 1, fh);
    }

    fclose(fh);
}

void grava_quarto(quarto *pq)
{
    FILE *fq = NULL;

    if ((fq = fopen("quartos.bin", "ab")) == NULL)
        printf("\nErro\n\n");

    else
        fwrite(pq, sizeof(quarto), 1, fq);

    fclose(fq);
}

void mostra_hospede(hospede *ph)
{
    FILE *fh = NULL;
    int i, qh;

    qh = verifica_hospede();

    if ((fh = fopen("hospedes.bin", "rb")) == NULL)
        printf("\nErro\n\n");

    else
    {
        for (i = 0; i < qh; i++)
        {
            fseek(fh, i * sizeof(hospede), 0);
            fread(ph, sizeof(hospede), 1, fh);
            printf("\nQuarto: %i\nNome: %s\nAcompanhantes: %i\nCategoria: %c\nDias: %i\n\n", ph->quarto, ph->nome, ph->acompanhante, ph->categoria, ph->dias);
        }
        fclose(fh);
    }
    system("pause");
}
void mostra_quarto(quarto *pq)
{
    FILE *fq = NULL;
    int i, qq;

    qq = verifica_quarto();

    if ((fq = fopen("quartos.bin", "rb")) == NULL)
        printf("\nErro\n\n");

    else
    {
        for (i = 0; i < qq; i++)
        {
            fseek(fq, i * sizeof(quarto), 0);
            fread(pq, sizeof(quarto), 1, fq);
            printf("\nQuarto: %i\nCategoria: %c\nStatus: %c\n\n", pq->num, pq->categoria, pq->status);
        }
        fclose(fq);
    }
    system("pause");
}