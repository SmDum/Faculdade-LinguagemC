#include <stdio.h>
#include <stdlib.h>

// struct

typedef struct hospede
{
	int quarto; // n�mero do quarto
	char nome[80];
	int acompanhante; // quantidade de acompanhantes
	char categoria;	  // [S]olteiro / [F]amiliar
	int dias;		  // tempo de perman�ncia � em dias
} hospede;

typedef struct quarto
{
	int num;		// n�mero do quarto
	char categoria; // [S]olteiro / [F]amiliar
	char status;	// [L]ivre / [O]cupado
} quarto;

// prototipos
void aloca_quarto(quarto **q, int quant_quartos);
void aloca_hospede(hospede **h, int quant_hospedes);

void cadastra_quarto(quarto *q, int qq);
void cadastra_hospede(hospede *h, quarto *q, int qq);

int busca_quarto(quarto *q, int qq, char categoria);
int busca_hospede(hospede *h, int qh, int n_quarto);

void check_out(hospede *h, int qh, quarto *q);

int main()
{

	quarto *p_quarto = NULL;
	hospede *p_hospede = NULL;
	int op, cont = 0, quant = 15;

	aloca_quarto(&p_quarto, quant);	  // aloca o espaco para os quartos
	cadastra_quarto(p_quarto, quant); // cadastra os quartos como L e S/F

	do
	{
		system("cls");

		printf("//////HOTEL FAZENDA RIBEIRAO//////\n\n[1]Check-in\n[2]Check-out\n[3]Fim\nOpcao: ");
		scanf("%i", &op);
		fflush(stdin);

		switch (op)
		{
		case 1:
			aloca_hospede(&p_hospede, cont + 1);
			cadastra_hospede(p_hospede + cont, p_quarto, quant);
			cont++;
			break;
		case 2:
			check_out(p_hospede, cont, p_quarto);
			break;

		} // switch

	} while (op != 3);

	return 0;
} // main

void aloca_quarto(quarto **q, int quant_quartos)
{
	if ((*q = (quarto *)realloc(*q, quant_quartos * sizeof(quarto))) == NULL)
		exit(1);

} // aloca_quarto

void aloca_hospede(hospede **h, int quant_hospedes)
{
	if ((*h = (hospede *)realloc(*h, quant_hospedes * sizeof(hospede))) == NULL)
		exit(1);
} // aloca_hospede

void cadastra_quarto(quarto *q, int qq)
{
	int i;

	for (i = 0; i < qq; i++, q++)
	{
		q->num = i + 1;
		q->status = 'L'; // todos os quartos livres
		if (i < 5)
			q->categoria = 'S'; // 5 de solteiro
		else
			q->categoria = 'F'; // 10 de familiar
	} // for

} // cadastra_quarto

void cadastra_hospede(hospede *h, quarto *q, int qq)
{

	printf("\nNome: ");
	gets(h->nome);
	fflush(stdin);

	do
	{
		printf("\nQuantidade de acompanhantes (Max. 3): ");
		scanf("%i", &(h->acompanhante));
		fflush(stdin);
	} while (h->acompanhante < 0 || h->acompanhante > 3);

	if (h->acompanhante == 0)
		h->categoria = 'S';
	else
		h->categoria = 'F';

	printf("\nDias: ");
	scanf("%i", &(h->dias));
	fflush(stdin);

	h->quarto = busca_quarto(q, qq, h->categoria);
	if (h->quarto == -1)
		printf("\nNao ha quartos com a categoria desejada\n\n");
	else
		printf("\nCadastro bem-sucedido - Seu quarto eh: %i", h->quarto);

	printf("\n\n\n");
	system("pause");

} // cadastra_hospede

int busca_quarto(quarto *q, int qq, char categoria)
{
	int i;
	for (i = 0; i < qq; i++, q++)
	{
		if (q->categoria == categoria && q->status == 'L')
		{
			q->status = 'O';
			return q->num;
		} // if
	} // for

	return -1; // nao tem quartos livres
} // busca_quarto

int busca_hospede(hospede *h, int qh, int n_quarto)
{
	int i;
	for (i = 0; i < qh; i++, h++)
	{
		if (h->quarto == n_quarto)
		{
			return i; // posicao do hospede na estrutura
		} // if
	} // for

	return -1; // nao achou o hospede nesse quarto
} // busca_hospede

void check_out(hospede *h, int qh, quarto *q)
{
	int n_quarto, achou;
	float valor;

	printf("\nQual quarto?: ");
	scanf("%i", &n_quarto);
	fflush(stdin);

	achou = busca_hospede(h, qh, n_quarto);
	if (achou == -1)
	{
		printf("\nEsse quarto nao existe\n\n");
	}
	else
	{
		if ((h + achou)->categoria == 'S')
			valor = (h + achou)->dias * 85;
		else
			valor = (h + achou)->dias * (((h + achou)->acompanhante) + 1) * 65;

		printf("\nNome: %s\nAcompanhantes: %i\nCategoria: %c\nDias: %i\nValor a ser pago: R$ %.2f\n\n", (h + achou)->nome, (h + achou)->acompanhante, (h + achou)->categoria, (h + achou)->dias, valor);
	} // else

	(q + n_quarto - 1)->status = 'L'; // libera o quarto

	system("pause");

} // check_out