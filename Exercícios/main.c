#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct hospede {
    int quarto;
    char nome[80];
    int acompanhante;
    char categoria;
    int dias;
}hospede;

typedef struct quarto {
    int num;
    char categoria;
    char status;
}quarto;

void aloca_quarto(quarto **quarto, int quant_quartos);
void aloca_hospede(hospede **hospede, int quant_hospedes);

void cadastra_quarto(quarto *quarto, int quant_quartos);
void cadastra_hospede(hospede *hospede, quarto *quarto, int quant_quarto);

int  busca_quarto(quarto *quarto, int quant_quarto, char categoria);
int  busca_hospede(hospede *hospede, int quant_hosp, int num_quarto);

void check_out(hospede *hospede, int quant_hosp, quarto *quarto);

void mostra_quarto(quarto *quarto, int quant_quarto);
void mostra_hospede(hospede *hospede, int quant_hospede);

int main()
{
    setlocale(LC_ALL, "portuguese");

    return 0;
}
