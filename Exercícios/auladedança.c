#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// structs ----------------------------------------------

typedef struct dance
{
	int regaula;	 // registro da aula
	int qaluno;		 // registra a quantidade de alunos matriculados
	char modalidade; //[B]allet, [S]apatadeado
	char turno;		 //[M]anha | [T]arde | [N]oite
	float valor;	 // valor da aula
} dance;

typedef struct aluno
{
	char CPF[13];  // CPF do aluno
	char nome[80]; // nome do aluno
	int numaula;   // numero do registro da aula
} aluno;

// prototipos das funcoes -------------------------------

void aloca_dance(dance **d, int tam);
void aloca_aluno(aluno **a, int tam);

void cadastra_dance(dance *d, int tam);
void cadastra_aluno(aluno *a, dance *d);

void mostra_dance(dance *d, int tam);
void mostra_aluno(aluno *a, int tam);

int busca_dance(char m, char t, dance *d);
//------------------------------------------------------
int main()
{
	int qtd_aulas = 6, cont_aluno = 0, op;

	dance *p_dance = NULL;
	aluno *p_aluno = NULL;

	aloca_dance(&p_dance, qtd_aulas);
	cadastra_dance(p_dance, qtd_aulas);

	do
	{
		system("cls");

		printf("-[-[-[-[ ACADEMIA DE DANCA ]-]-]-]-\n\n[1]Matricula\n[2]Mostra Aluno\n[3]Fim\nOpcao: ");
		scanf("%d", &op);
		fflush(stdin);

		switch (op)
		{

		case 1:
			mostra_dance(p_dance, qtd_aulas);
			aloca_aluno(&p_aluno, cont_aluno + 1);
			cadastra_aluno(p_aluno + cont_aluno, p_dance);
			cont_aluno++;
			break;

		case 2:
			mostra_aluno(p_aluno, cont_aluno);
			break;
		}
	} while (op < 3);

	return 0;
} // main

void aloca_dance(dance **d, int tam)
{
	if ((*d = (dance *)realloc(*d, tam * sizeof(dance))) == NULL)
		exit(1);
} // aloca_dance

void aloca_aluno(aluno **a, int tam)
{
	if ((*a = (aluno *)realloc(*a, tam * sizeof(aluno))) == NULL)
		exit(1);
} // aloca_aluno

void cadastra_dance(dance *d, int tam)
{
	int i;

	for (i = 0; i < tam; i++, d++)
	{
		d->regaula = i + 1;
		d->qaluno = 0;

		if (i < 3)
		{
			d->modalidade = 'B';
			switch (i)
			{
			case 0:
				d->turno = 'M';
				break;
			case 1:
				d->turno = 'T';
				break;
			case 2:
				d->turno = 'N';
				break;
			}
		}
		else
		{
			d->modalidade = 'S';
			switch (i)
			{
			case 3:
				d->turno = 'M';
				break;
			case 4:
				d->turno = 'T';
				break;
			case 5:
				d->turno = 'N';
				break;
			}
		}

		switch (d->turno)
		{
		case 'M':
			d->valor = 300.00;
			break;
		case 'T':
			d->valor = 250.00;
			break;
		case 'N':
			d->valor = 350.00;
			break;
		}
	}
} // cadastra_dance
void cadastra_aluno(aluno *a, dance *d)
{
	char aux_mod, aux_tur;

	printf("\nDigite seu nome: ");
	gets(a->nome);
	fflush(stdin);

	printf("\nCPF: ");
	gets(a->CPF);
	fflush(stdin);

	printf("\nModalidades: [B]allet [S]apateado\nModalidade desejada: ");
	scanf("%c", &aux_mod);
	fflush(stdin);
	aux_mod = toupper(aux_mod);

	printf("\nTurnos: [M]anha [T]arde [N]oite\nTurno desejado: ");
	scanf("%c", &aux_tur);
	fflush(stdin);
	aux_tur = toupper(aux_tur);

	a->numaula = busca_dance(aux_mod, aux_tur, d);

	if (a->numaula == -1)
	{
		printf("\nAula desejada nao encontrada\n\n\n");
	}
	else
	{
		printf("\nCadastro do aluno bem efetuado. Seja bem-vindo(a)!\nSua aula eh: %d\nO valor eh: R$%.2f\n\n\n", a->numaula, (d + (a->numaula) - 1)->valor);
	}

	system("pause");

} // cadastra_aluno

void mostra_dance(dance *d, int tam)
{
	int i;

	printf("\nRegaula\tQaluno\tModalidade\tTurno\tValor\n");
	for (i = 0; i < tam; i++, d++)
	{
		printf("%d\t%d\t%c\t\t%c\t%.2f\t\n", d->regaula, d->qaluno, d->modalidade, d->turno, d->valor);
	}

} // mostra_dance

void mostra_aluno(aluno *a, int tam)
{
	int i;
	printf("\nCPF\t\tNome\t\tNumaula\n");
	for (i = 0; i < tam; i++, a++)
	{
		printf("%s\t%s\t%d\n", a->CPF, a->nome, a->numaula);
	}
	printf("\n\n\n");
	system("pause");
} // mostra aluno

int busca_dance(char m, char t, dance *d)
{
	int i;
	// printf("\n\n%c %c", m, t);
	for (i = 0; i < 6; i++, d++)
	{
		// printf("\n%c %c", d->modalidade, d->turno);
		if ((d->modalidade == m) && (d->turno == t))
		{
			d->qaluno++;
			return d->regaula;
		}
	}
	return -1;
} // busca_dance