#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hospede
{
    int quarto;
    char nome[30];
    int acompanhante;
    int dias;
} hospede;

typedef struct quarto
{
    int num;
    char categoria;
    char status;
} quarto;

void aloca_quarto(quarto **pq, int qq);
void aloca_hospede(hospede **ph, int qh);

int verifica_hospede();

void cadastro_quarto(quarto *pq, int qq);
void cadastro_hospede(hospede *ph, quarto *pq, int qq);

void grava_quarto(quarto *pq);
void grava_hospede(hospede *ph, char *aux, int pos);

int busca_vago(hospede *ph, int qh);
int busca_quarto(quarto *pq, int qq, char letra);

void encerra_quarto(hospede *ph, quarto *pq, int qq);

void mostra_hospede(hospede *ph, int num);
void mostra_quarto(quarto *pq, int qq);

int main()
{
    quarto *q = NULL;
    hospede *hosp = NULL;
    int op;

    aloca_quarto(&q, 1);
    cadastro_quarto(q, 15);
    aloca_hospede(&hosp, 1);

    do
    {
        system("cls");

        printf("[1]Check-in\n[2]Check-out\n[3]Mostra Hospedes\n[4]Mostra Quarto\n[5]Fim\nOpcao:");
        scanf("%i", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            cadastro_hospede(hosp, q, 15);
            break;
        case 2:
            encerra_quarto(hosp, q, 15);
            break;
        case 3:
            mostra_hospede(hosp, 0);
            break;
        case 4:
            mostra_quarto(q, 15);
            break;
        } // switch

    } while (op != 5);

    system("pause");
    return 0;

} // main

void aloca_quarto(quarto **pq, int qq)
{
    if (((*pq = (quarto *)realloc(*pq, qq * sizeof(quarto))) == NULL))
        exit(1);
} // Alocação de Quartos

void aloca_hospede(hospede **ph, int qh)
{
    if (((*ph = (hospede *)realloc(*ph, qh * sizeof(hospede))) == NULL))
        exit(1);
} // Alocação de Hóspedes

int verifica_hospede()
{
    FILE *fh = NULL;
    long int q;

    if ((fh = open("hospede.bin", "rb")) == NULL)
        return 0;

    fseek(fh, 0, 2);
    q = ftell(fh) / sizeof(hospede);
    fclose(fh);

    return q;
} // Retorna o numero de hospedes

void cadastro_quarto(quarto *pq, int qq)
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
} // Cadastro dos Quartos

void cadastro_hospede(hospede *ph, quarto *pq, int qq)
{
    int qtdhosp, pos;
    system("cls");
    qtdhosp = verifica_hospede(); // qtde de hospedes
    pos = busca_vago(ph, qtdhosp);

    printf("\nNome: ");
    gets(ph->nome);
    fflush(stdin);

    do
    {
        printf("\nAcompanhantes (Máx 3): ");
        scanf("%i", &(ph->acompanhante));
        fflush(stdin);
    } while (ph->acompanhante < 0 || ph->acompanhante > 3);

    if(ph->acompanhante = 0)
    {
        busca_quarto(pq, qq, 'S');
    }
    else
    {
        busca_quarto(pq, qq, 'F');
    }

    printf("Número do Quarto: %i", ph->quarto);

    if(ph->quarto == -1)
    {
        printf("Hotel Lotado");
    }

    printf("\nDias: ");
    scanf("%i", &(ph->dias));
    fflush(stdin);

    if(pos == -1) // Se não há hospede vago
    {
        grava_hospede(ph, 'ab', 1); // Grava no Final
    }
    else // Senão
    {
        grava_hospede(ph, 'rb+', pos); // Reescreve no hóspede vago
    }
} // Cadastro de Hospede
