#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// structs ----------------------------------------------

typedef struct dance
{
    int regaula;     // registro da aula
    int qaluno;      // registra a quantidade de alunos matriculados
    char modalidade; //[B]allet, [S]apatadeado
    char turno;      //[M]anha | [T]arde | [N]oite
    float valor;     // valor da aula
} dance;

typedef struct aluno
{
    char CPF[13];  // CPF do aluno
    char nome[80]; // nome do aluno
    int numaula;   // numero do registro da aula
} aluno;

void aloca_aluno(aluno **p_aluno, int qtd_aluno);
void aloca_dance(dance **p_dance, int qtd_dance);

void cadastra_aluno(aluno *p_aluno, int qtd_aluno, dance *p_dance, int qtd_dance);
void cadastra_dance(aluno *p_aluno, dance *p_dance, int qtd_dance);

int busca_dance(dance p_dance, int qtd_dance, char aux_turno, char aux_modalidade);

void mostra_aluno(aluno *p_aluno, int qtd_aluno);
void mostra_dance(dance *p_dance, int qtd_dance);

int main()
{
    dance *p_dance = NULL;
    aluno *p_aluno = NULL;
    int opc, qtd = 6, cont = 0;

    aloca_dance(&p_dance, qtd);
    cadastra_dance(p_dance, qtd);

    do
    {
        printf("[1] - Cadaastro\n[2] - Mostrar Alunos\n[3] - Fim\nOpção: ");
        scanf("%i", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            mostra_dance(p_dance, qtd);
            aloca_aluno(&p_alunom cont + 1);
            cadastra_aluno(p_aluno, cont, p_dance, qtd);
            cont++;
            system("pause");
            system("cls");
            break;

        case 2:
            mostra_aluno(p_aluno, cont);
            system("pause");
            system("cls");
            break;

        default:
            break;
        }

    } while (opc != 3);

    free(p_aluno);
    free(p_dance);

    return 0;
}

void aloca_aluno(aluno **p_aluno, int qtd_aluno)
{
    if ((*p_aluno = (aluno *)realloc(*p_aluno, qtd_aluno * sizeof(aluno))) == NULL)
    {
        printf("\nErro ao alocar memória...");
        exit(1);
    }
}

void aloca_dance(dance **p_dance, int qtd_dance)
{
    if ((*p_dance = (dance *)realloc(*p_dance, qtd_dance * sizeof(dance))) == NULL)
    {
        printf("\nErro ao alocar memória...");
        exit(1);
    }
}

void cadastra_aluno(aluno *p_aluno, int qtd_aluno, dance *p_dance, int qtd_dance)
{
    
}

void cadastra_dance(aluno *p_aluno, dance *p_dance, int qtd_dance)
{
}

int busca_dance(dance p_dance, int qtd_dance, char aux_turno, char aux_modalidade)
{
}

void mostra_aluno(aluno *p_aluno, int qtd_aluno)
{
}

void mostra_dance(dance *p_dance, int qtd_dance)
{
}