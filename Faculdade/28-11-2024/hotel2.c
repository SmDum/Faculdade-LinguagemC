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

}

void aloca_hospede(hospede **ph, int qh)
{

}

int verifica_quarto()
{

}

int verifica_hospede()
{

}

void cadastra_quarto(quarto *pq, int qq)
{

}

void cadastra_hospede(hospede *ph, quarto *pq, int qh)
{

}

void grava_quarto(quarto *pq)
{

}

void grava_hospede(hospede *ph, char *aux, int pos)
{

}

int busca_quarto(quarto *pq, int qq, char cat)
{

}

int busca_hospede(hospede *ph, int n_quarto)
{

}

int busca_vago(hospede *ph, int qh)
{

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