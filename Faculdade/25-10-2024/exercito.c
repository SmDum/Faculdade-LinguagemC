#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// structs

typedef struct carreira
{
	int reg;
	int qmilitar;
	char org[20];
	char patente[20];
	float salario;
} carreira;

typedef struct militar
{
	char CPF[13];
	char nome[20];
	int numreg;
} militar;

// prototipos

void aloca_carreira(carreira **c, int qc);
void aloca_militar(militar **m, int qm);
void cadastro_carreira(carreira *c, int qc);
void cadastro_militar(militar *m, carreira *c, int qc);
void mostra_carreira(carreira *c, int qc);
int busca_patente(carreira *c, int qc, char *porg, char *ppat);
void troca_patente(militar *m, int qm, carreira *c, int qc);
int busca_CPF(militar *m, int qm, char *aux_CPF);
void mostra_militar(militar *m, int qm);

void maiuscula(char *p);

int main()
{

	setlocale(LC_ALL, "portuguese");

	carreira *pc = NULL;
	militar *pm = NULL;
	int qc = 5, qm = 0, op;

	aloca_carreira(&pc, qc);
	cadastro_carreira(pc, qc);

	do
	{
		system("cls");
		printf("[1] - Cadastrar Militar\n[2] - Troca Patente\n[3] - Mostra Patente\n[4] - Mostra Militar\n[5] - Sair\nOpção: ");
		scanf("%i", &op);
		fflush(stdin);

		switch (op)
		{
		case 1:
			aloca_militar(&pm, qm + 1);
			cadastro_militar(pm + qm, pc, qc);
			qm++;
			break;

		case 2:
			troca_patente(pm, qm, pc, qc);
			break;

		case 3:
			mostra_carreira(pc, qc);
			break;

		case 4:
			mostra_militar(pm, qm);

		default:
			printf("\nOpção Inválida...\n");
		}

	} while (op != 5);

	return 0;
} // main

void aloca_carreira(carreira **c, int qc)
{
	if ((*c = (carreira *)realloc(*c, qc * sizeof(carreira))) == NULL)
		exit(1);
} // aloca_carreira

void aloca_militar(militar **m, int qm)
{
	if ((*m = (militar *)realloc(*m, qm * sizeof(militar))) == NULL)
	{
		printf("\nErro ao alocar memória...\n");
		exit(1);
	}
} // aloca_militar

void cadastro_carreira(carreira *c, int qc)
{
	int i;

	for (i = 0; i < qc; i++, c++)
	{

		c->reg = i + 1;

		c->qmilitar = 0;

		printf("\nOrganizacao (Exercito\tAeronautica\tMarinha):\nOpcao: ");
		gets(c->org);
		fflush(stdin);
		maiuscula(c->org);

		printf("\nPatente: ");
		gets(c->patente);
		fflush(stdin);
		maiuscula(c->patente);

		printf("Salario: R$");
		scanf("%f", &c->salario);
		fflush(stdin);

	} // for
}

void maiuscula(char *p)
{
	int tam = strlen(p), i;
	for (i = 0; i < tam; i++, p++)
		if (*p >= 'a' && *p <= 'z')
			*p -= 32;
} // maiuscula

void mostra_carreira(carreira *c, int qc)
{
	int i;
	for (i = 0; i < qc; i++, c++)
		printf("\nRegistro: %i\nQtde militares: %i\nOrganizacao: %s\nPatente: %s\nSalario: R$%.2f\n\n", c->reg, c->qmilitar, c->org, c->patente, c->salario);
	system("pause");
} // mostra_carreira

void cadastro_militar(militar *m, carreira *c, int qc)
{
	char aux_org[20], aux_pat[20];

	printf("\nCPF: ");
	gets(m->CPF);
	fflush(stdin);

	printf("\nNome: ");
	gets(m->nome);
	fflush(stdin);

	printf("\nOrganização: ");
	gets(aux_org);
	fflush(stdin);
	maiuscula(aux_org);

	printf("\nPatente: ");
	gets(aux_pat);
	fflush(stdin);
	maiuscula(aux_pat);

	m->numreg = busca_patente(c, qc, aux_org, aux_pat);

	if (m->numreg == -1)
	{
		printf("\nOrganização e patente inválidos...\n");
	}
	else
	{
		printf("Militar cadastrado com sucesso - Patente: %i\tSalário: %.2f\n", m->numreg, (c + (m->numreg) - 1)->salario);
	}
	system("pause");
} // cadastro militar

int busca_patente(carreira *c, int qc, char *porg, char *ppat)
{
	int i;

	for (i = 0; i < qc; i++, c++)
	{
		if ((strcmp(c->org, porg) == 0) && (strcmp(c->patente, ppat) == 0))
		{
			c->qmilitar++;
			return c->reg;
		} // if

		return -1;
	}
} // busca patente

void troca_patente(militar *m, int qm, carreira *c, int qc)
{
	char aux_CPF[13], aux_org[20], aux_pat[20];

	printf("\nCPF: ");
	gets(aux_CPF);
	fflush(stdin);

	int pos = busca_CPF(m, qm, aux_CPF);

	if (pos == -1)
	{
		printf("\nCPF Inválido...\n");
	}
	else
	{
		printf("\nNova Organização: ");
		gets(aux_org);
		fflush(stdin);
		maiuscula(aux_org);

		printf("\nNova Patente: ");
		gets(aux_pat);
		fflush(stdin);
		maiuscula(aux_pat);

		// atualização - decrementar a patente atual

		(c + (m->numreg) - 1)->qmilitar--; // deu baixa na patente
		m->numreg = busca_patente(c, qc, aux_org, aux_pat);
		if (m->numreg == -1)
		{
			printf("\nOrganização e patente inexistentes...\n");
		}
		else
		{
			printf("\nMilitar cadastrado com sucesso - Patente: %i\tSalário: %.2f\n", m->numreg, (c + (m->numreg) - 1)->salario);
		}
		system("pause");
	}
} // troca patente

int busca_CPF(militar *m, int qm, char *aux_CPF)
{
	int i;

	for (i = 0; i < qm; i++, m++)
	{
		if (strcmp(m->CPF, aux_CPF) == 0)
		{
			return i; // posiçao do militar na estrutura
		}
		return -1;
	}
} // busca CPF

void mostra_militar(militar *m, int qm)
{
	int i;
	
	for(i = 0; i<qm;i++, m++)
	{
		printf("\nCPF: %s\nNome: %s\nReistro da patente: %i\n\n", m->CPF, m->nome, m->numreg);
	}
}