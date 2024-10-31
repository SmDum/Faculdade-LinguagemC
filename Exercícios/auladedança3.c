#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

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

void aloca_aluno(aluno **p_aluno, int qtd);
void aloca_dance(dance **p_dance, int qtd);

void cadastra_aluno(aluno *p_aluno, dance *p_dance);
void cadastra_dance(dance *p_dance, int qtd);

int busca_dance(dance *p_dance, char aux_modalidade, char aux_turno);

void mostra_aluno(aluno *p_aluno, int qtd);
void mostra_dance(dance *p_dance, int qtd);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int opc, qtd = 6, cont = 0;
    aluno *p_aluno = NULL;
    dance *p_dance = NULL;

    aloca_dance(&p_dance, qtd);
    cadastra_dance(p_dance, qtd);

    do
    {
        printf("[1] - Cadastro\n[2] - Mostrar Alunos\n[3] - Fim\nOpção: ");
        scanf("%i", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            mostra_dance(p_dance, qtd);
            aloca_aluno(&p_aluno, cont+1);
            cadastra_aluno(p_aluno + cont, p_dance);
            cont++;
            system("pause");
            system("cls");
            break;

        case 2:
            mostra_aluno(p_aluno, cont);
            system("pause");
            system("cls");
            break;

        case 3:
            printf("\nSaindo...");
            break;
        }

    } while (opc != 3);

    return 0;
}

void aloca_aluno(aluno **p_aluno, int qtd)
{
    if ((*p_aluno = (aluno *)realloc(*p_aluno, qtd * sizeof(aluno))) == NULL)
    {
        exit(1);
    }
}
void aloca_dance(dance **p_dance, int qtd)
{
    if ((*p_dance = (dance *)realloc(*p_dance, qtd * sizeof(dance))) == NULL)
    {
        exit(1);
    }
}

void cadastra_aluno(aluno *p_aluno, dance *p_dance)
{
    char aux_modalidade, aux_turno;

    printf("\nNome: ");
    fgets(p_aluno->nome, 80, stdin);
    fflush(stdin);

    printf("\nCPF: ");
    fgets(p_aluno->CPF, 13, stdin);
    fflush(stdin);

    printf("\nModalidade\n[B]allet  [S]apateado\nOpção: ");
    scanf("%c", &aux_modalidade);
    fflush(stdin);
    aux_modalidade = toupper(aux_modalidade);

    printf("\nTurno\n[M]anhã  [T]arde  [N]oite\nOpção: ");
    scanf("%c", &aux_turno);
    fflush(stdin);
    aux_turno = toupper(aux_turno);

    p_aluno->num_aula = busca_dance(p_dance, aux_modalidade, aux_turno);

    if (p_aluno->num_aula == -1)
    {
        printf("\nAula não encontrada...");
    }
    else
    {
        printf("\nCadastro realizado com sucesso!\nSua aula é %i\nValor: %.2f", p_aluno->num_aula, ((p_dance + p_aluno->num_aula-1)->valor));
    }
}

void cadastra_dance(dance *p_dance, int qtd)
{
    int i;

    for (i = 0; i < qtd; i++, p_dance++)
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

int busca_dance(dance *p_dance, char aux_modalidade, char aux_turno)
{
    int i;

    for (i = 0; i < 6; i++, p_dance++)
    {
        if (p_dance->modalidade == aux_modalidade && p_dance->turno == aux_turno)
        {
            p_dance->qtd_aluno++;
            return p_dance->reg_aula;
        }
    }
    return -1;
}

void mostra_aluno(aluno *p_aluno, int qtd)
{
    int i;

    for (i = 0; i < qtd; i++, p_aluno++)
    {
        printf("\nNome: %s\nCPF: %s\nAula: %i\n\n\n", p_aluno->nome, p_aluno->CPF, p_aluno->num_aula);
    }
}

void mostra_dance(dance *p_dance, int qtd)
{
    int i;

    for (i = 0; i < qtd; i++, p_dance++)
    {
        printf("ID: %i\nModalidade: %c\nTurno: %c\nQtd de Alunos: %i\nValor: %.2f\n\n\n", p_dance->reg_aula, p_dance->modalidade, p_dance->turno, p_dance->qtd_aluno, p_dance->valor);
    }
}
