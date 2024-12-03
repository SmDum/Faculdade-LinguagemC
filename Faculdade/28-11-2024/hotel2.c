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

void aloca_quarto(quarto **pq, int qq);
void aloca_hospede(hospede **ph, int qh);

int verifica_quarto();
int verifica_hospede();

void cadastra_quarto(quarto *pq, int qq);
void cadastra_hospede(hospede *ph, quarto *pq, int qh);

void grava_quarto(quarto *pq);
void grava_hospede(hospede *ph, char *aux, int pos);

int busca_quarto(quarto *pq, int qq, char cat);
int busca_hospede(hospede *ph, int n_quarto);
int busca_vago(hospede *ph, int qh);

void check_out(quarto *pq, hospede *ph);

void mostra_quarto(quarto *pq);
void mostra_hospede(hospede *ph);

int main()
{
    setlocale(LC_ALL, "portuguese");

    quarto *pq = NULL;
    hospede *ph = NULL;
    int op, pos, qquarto;

    aloca_quarto(&pq, 1);
    qquarto = verifica_quarto();

    if (qquarto == 0)
    {
        cadastra_quarto(pq, 15);
    }
    aloca_hospede(&ph, 1);

    do
    {
        switch (op)
        {
            printf("\n[1] - Check-In\n[2] - Check-Out\n[3] - Mostrar Quartos\n[4] - Mostrar Hóspedes\n[5] - Fim");

        case 1:
            cadastra_hospede(ph, pq, 15);
            break;

        case 2:
            check_out(pq, ph);
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
    } while (op != 5);
}

void aloca_quarto(quarto **pq, int qq)
{
    if ((*pq = (quarto *)realloc(*pq, qq * sizeof(quarto))) == NULL)
    {
        exit(1);
    }
}

void aloca_hospede(hospede **ph, int qh)
{
    if ((*ph = (quarto *)realloc(*ph, qh * sizeof(hospede))) == NULL)
    {
        exit(1);
    }
}

int verifica_quarto()
{
    FILE *fq = NULL;
    int qtd = 0;

    if (fq = fopen("quartos.bin", "rb") == NULL)
    {
        printf("\nArquivo Inexistente");
    }
    else
    {
        fseek(fq, 0, 2);
        qtd = ftell(fq) / sizeof(quarto);
        fclose(qtd);
        return (qtd);
    }
}

int verifica_hospede()
{
    FILE *fh = NULL;
    int qtd = 0;

    if (fh = fopen("hospedes.bin", "rb") == NULL)
    {
        printf("\nArquivo Inexistente");
    }
    else
    {
        fseek(fh, 0, 2);
        qtd = ftell(fh) / sizeof(hospede);
        fclose(qtd);
        return (qtd);
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
    FILE *fh = NULL;

    qhosp = verifica_hospede();
    pos = busca_vago(ph, qhosp);

    printf("\nNome: ");
    gets(ph->nome);
    fflush(stdin);

    do
    {
        printf("\nAcompanhantes: ");
        scanf("%i", &(ph->acompanhante));
        fflush(stdin);
    } while (ph->acompanhante < 0 && ph->acompanhante > 3);

    if (ph->acompanhante == 0)
    {
        ph->acompanhante = 'S';
    }

    else
    {
        ph->acompanhante = 'F';
    }

    printf("\nDias: ");
    scanf("%i", &(ph->dias));
    fflush(stdin);

    ph->quarto = busca_quarto(pq, qq, ph->categoria);

    if (ph->quarto == -1)
    {
        printf("\nNão há quartos disponíveis nessa categoria...");
    }
    else
    {
        printf("\nCadastro realizado com sucesso!\nSeu quarto é %i", ph->quarto);

        if(pos == -1)
        {
            grava_hospede(ph, "ab", 1);
        }
        else
        {
            grava_hospede(ph, "rb+", pos);
        }
    }
    system("pause");
}

void grava_quarto(quarto *pq)
{
    FILE *fq; 

    if((fq = fopen("quartos.bin", "ab")) == NULL)
    {
        printf("\nErro\n\n");
    }
    else
    {
        fwrite(pq, sizeof(quarto), 1, fq);
    }
    fclose(fq);
}

void grava_hospede(hospede *ph, char *aux, int pos)
{
    FILE *fh; 

    if((fh = fopen("hospedes.bin", "ab")) == NULL)
    {
        printf("\nErro\n\n");
    }
    else
    {
        fwrite(ph, sizeof(quarto), 1, fh);
    }
    fclose(fh);
}

int busca_quarto(quarto *pq, int qq, char cat)
{
    int i, pos = -1;
    FILE *fq = NULL;

    if ((fq = fopen("hospedes.bin", "rb+")) == NULL)
    {
        printf("\nErro\n\n");
    }
    else
    {
        for (i = 0; i < qq; i++)
        {
            fseek(fq, i * sizeof(hospede), 0);
            fread(pq, sizeof(hospede), 1, fq);

            if (pq->categoria == cat && pq->status == 'L')
            {
                pq->status = 'O';
                fseek(fq, i * sizeof(hospede), 0);
                fwrite(pq, sizeof(quarto), 1, fq);
                pos = pq->num;
                i = qq;
            }
        }
    }
    fclose(fq);
    return pos;
}

int busca_hospede(hospede *ph, int n_quarto)
{
}

int busca_vago(hospede *ph, int qh)
{
    int i;
    FILE *fh = NULL;

    if ((fh = fopen("hospedes.bin", "rb")) == NULL)
    {
        exit(1);
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
    return (-1);
}

void check_out(quarto *pq, hospede *ph)
{
}

void mostra_quarto(quarto *pq)
{
}

void mostra_hospede(hospede *ph)
{
}