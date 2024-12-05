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

void cadastra_quarto(quarto *pq, int qq);
void cadastra_hospede(hospede *ph, quarto *pq, int qq);

void atualiza_quarto(quarto *pq, int n_quarto);

void grava_quarto(quarto *pq);
void grava_hospede(hospede *ph, char *aux, int pos);

int busca_hospede(hospede *ph, int n_quarto);
int busca_quarto(quarto *pq, int qq, char cat);
int busca_vago(hospede *ph, int qh);

void check_out(hospede *ph, quarto *pq);

void mostra_quarto(quarto *pq);
void mostra_hospede(hospede *ph);

int main()
{
    setlocale(LC_ALL, "portuguese");

    quarto *pq = NULL;
    hospede *ph = NULL;
    int op, qq;

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
        printf("[1] - Check-In\n[2] - Check-Out\n[3] - Mostrar Hóspedes\n[4] - Mostrar Quartos\n[5] - Fim\nOpção: ");
        scanf("%i", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            cadastra_hospede(ph, pq, qq);
            break;

        case 2:
            check_out(ph, pq);
            break;

        case 3:
            mostra_hospede(ph);
            break;

        case 4:
            mostra_quarto(pq);
            break;

        default:
            break;
        }

    } while (op != 5);

    return 0;
}

void aloca_hospede(hospede **ph, int qh)
{
    if ((*ph = (hospede *)realloc(*ph, qh * sizeof(hospede))) == NULL)
    {
        printf("\nErro 1\n\n");
        exit(1);
    }
}

void aloca_quarto(quarto **pq, int qq)
{
    if ((*pq = (quarto *)realloc(*pq, qq * sizeof(quarto))) == NULL)
    {
        printf("\nErro 2\n\n");
        exit(1);
    }
}

int verifica_hospede()
{
    FILE *fh = NULL;
    int qtd = 0;

    if ((fh = fopen("hospedes.bin", "rb")) == NULL)
    {
        printf("\nErro 0\n\n");
        return qtd;
    }
    else
    {
        fseek(fh, 0, 2);
        qtd = ftell(fh) / sizeof(hospede);
        fclose(fh);
        return qtd;
    }
}

int verifica_quarto()
{
    FILE *fq = NULL;
    int qtd = 0;

    if ((fq = fopen("quartos.bin", "rb")) == NULL)
    {
        printf("\nErro 3\n\n");
        return qtd;
    }
    else
    {
        fseek(fq, 0, 2);
        qtd = ftell(fq) / sizeof(quarto);
        fclose(fq);
        return qtd;
    }
}

void cadastra_quarto(quarto *pq, int qq)
{
    int i;

    for (i = 0; i < qq; i++)
    {
        pq->num = i + 1;
        pq->status = 'L';

        if (i < 5)
        {
            pq->categoria = 'S';
        }
        else
        {
            pq->categoria = 'F';
        }

        grava_quarto(pq);
    }
}

void cadastra_hospede(hospede *ph, quarto *pq, int qq)
{
    int qhosp, pos;

    qhosp = verifica_hospede();
    pos = busca_vago(ph, qq);

    printf("\nNome: ");
    gets(ph->nome);
    fflush(stdin);

    do
    {
        printf("\nNúmero de Acompanhantes (máx 3): ");
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
        printf("\nNão há quartos nessa categoria...\n\n");
    }
    else
    {
        printf("\nCadastro com sucesso - quarto = %i\n\n", ph->quarto);
        if (pos == -1)
        {
            grava_hospede(ph, "ab", 1);
        }

        else
        {
            grava_hospede(ph, "rb+", pos);
        }
    }

    printf("\n\n\n");
    system("pause");
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

void grava_hospede(hospede *ph, char *aux, int pos)
{
    FILE *fh = NULL;

    if ((fh = fopen("hospedes.bin", aux)) == NULL)
        printf("\nErro 4\n\n");

    else
    {
        if (strcmp(aux, "rb+") == 0)
            fseek(fh, pos * sizeof(hospede), 0);

        fwrite(ph, sizeof(hospede), 1, fh);
    }

    fclose(fh);
}

void atualiza_quarto(quarto *pq, int n_quarto)
{
    FILE *fq = NULL;
    int i, qq;

    qq = verifica_quarto();

    if ((fq = fopen("quartos.bin", "rb+")) == NULL)
    {
        printf("\nErro 5\n\n");
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

int busca_hospede(hospede *ph, int n_quarto)
{
    FILE *fh = NULL;
    int i, pos = -1;
    int qh = verifica_hospede();

    if ((fh = fopen("hospedes.bin", "rb+")) == NULL)
        printf("\nErro 6\n\n");

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
    int i, pos = -1;

    if ((fq = fopen("quartos.bin", "rb+")) == NULL)
        printf("\nErro 7\n\n");

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
        printf("\nQuarto não encontrado...\n\n");
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
}

void mostra_quarto(quarto *pq)
{
    FILE *fq = NULL;
    int i, qq;

    qq = verifica_quarto();

    if ((fq = fopen("quartos.bin", "rb")) == NULL)
    {
        printf("\nErro 9\n\n");
    }

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

void mostra_hospede(hospede *ph)
{
    FILE *fh = NULL;
    int i, qh;

    qh = verifica_hospede();

    if ((fh = fopen("hospedes.bin", "rb")) == NULL)
    {
        printf("\nErro 10\n\n");
    }

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