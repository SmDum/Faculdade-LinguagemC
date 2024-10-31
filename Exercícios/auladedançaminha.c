#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// structs ----------------------------------------------

typedef struct dance
{
    int reg_aula;    // registro da aula
    int qtd_aluno;   // registra a quantidade de alunos matriculados
    char modalidade; //[B]allet, [S]apatadeado
    char turno;      //[M]anha | [T]arde | [N]oite
    float valor;     // valor da aula
} dance;

typedef struct aluno
{
    char CPF[13];  // CPF do aluno
    char nome[80]; // nome do aluno
    int num_aula;  // numero do registro da aula
} aluno;

void aloca_aluno(aluno **p_aluno, int qtd_aluno);
void aloca_dance(dance **p_dance, int qtd_dance);

void cadastra_aluno(aluno *p_aluno, int qtd_aluno, dance *p_dance, int qtd_dance);
void cadastra_dance(dance *p_dance, int qtd_dance);

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
    char aux_modalidade, aux_turno;

    printf("\nNome: ");
    fgets(p_aluno->nome, 80, stdin);
    fflush(stdin);

    printf("\nCPF: ");
    fgets(p_aluno->CPF, 13, stdin);
    fflush(stdin);

    printf("\nModalidade\n[B] - Ballet\n[S] - Sapateado\nOpção: ");
    scanf("%c", &aux_modalidade);
    fflush(stdin);
    aux_modalidade = toupper(aux_modalidade);

    printf("\nTurno\n[M] - Manhã\n[T] - Tarde\n[N] - Noite\nOpção: ");
    scanf("%c", &aux_turno);
    fflush(stdin);
    aux_turno = toupper(aux_turno);

    p_aluno->num_aula = busca_dance(p_dance, qtd_dance, aux_turno, aux_modalidade);

    if (p_aluno->num_aula == -1)
    {
        printf("\nTipo de Aula não Encontrada...");
    }
    else
    {
        printf("\nCadastro Realizado com Sucesso! Seja bem vindo!\n Sua aula é: %i.\nValor: %.2f\n\n\n", p_aluno->num_aula + 1, p_dance + (p_aluno->num_aula)->valor);
    }
}

void cadastra_dance(dance *p_dance, int qtd_dance)
{
    int i;

    for (i = 0; i < qtd_dance; i++)
    {
        p_dance->qtd_aluno = 0;
        p_dance->reg_aula = i + 1;

        switch (i)
        {
        case 0:
            p_dance->modalidade = 'B';
            p_dance->turno = 'M';
            break;

        case 1:
            p_dance->modalidade = 'B';
            p_dance->turno = 'T';
            break;

        case 2:
            p_dance->modalidade = 'B';
            p_dance->turno = 'N';
            break;

        case 3:
            p_dance->modalidade = 'S';
            p_dance->turno = 'M';
            break;

        case 4:
            p_dance->modalidade = 'S';
            p_dance->turno = 'T';
            break;

        case 5:
            p_dance->modalidade = 'S';
            p_dance->turno = 'N';
            break;
        }

        switch (p_dance->turno)
        {
        case 'M':
            p_dance->valor = 300;
            break;

        case 'T':
            p_dance->valor = 250;
            break;

        case 'N':
            p_dance->valor = 350;
            break;
        }
    }
}

int busca_dance(dance p_dance, int qtd_dance, char aux_turno, char aux_modalidade)
{
    int i;

    for (i = 0; i < qtd_dance; i++, p_dance++)
    {
        if (p_dance->modalidade == aux_modalidade && p_dance->turno == aux_turno)
        {
            p_dance->qtd_aluno++;
            return i;
        }
    }
    return -1;
}

void mostra_aluno(aluno *p_aluno, int qtd_aluno)
{
    int i;

    for (i = 0; i < qtd_aluno; i++, p_aluno++)
    {
        printf("\nNome: %s\nCPF: %s\nNumero de Aula: %i", p_aluno->nome, p_aluno->CPF, p_aluno->num_aula);
        printf("\n\n\n");
    }
}

void mostra_dance(dance *p_dance, int qtd_dance)
{
    int i;

    for (i = 0; i < qtd_dance; i++, qtd_dance++)
    {
        printf("\nRegistro da Aula: %i\nModalidade: %c\nTurno: %c\nQtd de Alunos: %i\nValor: %.2f", p_dance->reg_aula, p_dance->modalidade, p_dance->turno, p_dance->qtd_aluno, p_dance->valor);
        printf("\n\n\n");
    }
}