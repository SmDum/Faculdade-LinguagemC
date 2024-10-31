#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

typedef struct luta
{
    int reg_aula;    // registro da aula
    int qtd_aluno;   // registra a quantidade de alunos matriculados
    char modalidade; //[B]oxe, [S]umô
    char turno;      //[M]anha | [T]arde | [N]oite
    float valor;     // valor da aula
} luta;

typedef struct aluno
{
    char CPF[13];  // CPF do aluno
    char nome[80]; // nome do aluno
    int num_aula;  // numero do registro da aula
} aluno;

void aloca_aluno(aluno **p_aluno, int qtd);
void aloca_luta(luta **p_luta, int qtd);

void cadastra_aluno(aluno *p_aluno, luta *p_luta);
void cadastra_luta(luta *p_luta, int qtd);

int busca_luta(luta *p_luta, char aux_modalidade, char aux_turno);

void mostra_aluno(aluno *p_aluno, int qtd);
void mostra_luta(luta *p_luta, int qtd);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int opc, qtd = 6, cont = 0;
    aluno *p_aluno = NULL;
    luta *p_luta = NULL;

    aloca_luta(&p_luta, qtd);
    cadastra_luta(p_luta, qtd);

    do
    {
        printf("[1] - Cadastro\n[2] - Mostrar Alunos\n[3] - Sair\nOpção: ");
        scanf("%i", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            mostra_luta(p_luta, qtd);
            aloca_aluno(&p_aluno, cont + 1);
            cont++;
            cadastra_aluno(p_aluno+cont, p_luta);
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
            system("pause");
            system("cls");
            break;
        }
    } while (opc != 3);

    free(p_aluno);
    free(p_luta);

    return 0;
}

void aloca_aluno(aluno **p_aluno, int qtd)
{
    if ((*p_aluno = (aluno *)realloc(*p_aluno, qtd * sizeof(aluno))) == NULL)
    {
        exit(1);
    }
}

void aloca_luta(luta **p_luta, int qtd)
{
    if ((*p_luta = (luta *)realloc(*p_luta, qtd * sizeof(luta))) == NULL)
    {
        exit(1);
    }
}

void cadastra_aluno(aluno *p_aluno, luta *p_luta)
{
    char aux_modalidade, aux_turno;

    printf("\nNome: ");
    fgets(p_aluno->nome, 80, stdin);
    fflush(stdin);

    printf("\nCPF: ");
    fgets(p_aluno->CPF, 13, stdin);
    fflush(stdin);

    printf("\nModalidade\n[B]oxe\n[S]umô\nOpção: ");
    scanf(" %c", &aux_modalidade);
    fflush(stdin);
    aux_modalidade = toupper(aux_modalidade);

    printf("\nTurno\n[M]anhã\n[T]arde\n[N]oite\nOpção: ");
    scanf(" %c", &aux_turno);
    fflush(stdin);
    aux_turno = toupper(aux_turno);

    p_aluno->num_aula = busca_luta(p_luta, aux_modalidade, aux_turno);

    if (p_aluno->num_aula == -1)
    {
        printf("\nAula não encontrada...");
    }
    else
    {
        printf("\nCadastro realizado com sucesso!\nSeja bem-vindo!\nAula: %i\nValor: %.2f\n\n\n", p_aluno->num_aula, ((p_luta + p_aluno->num_aula - 1)->valor));
    }
}

void cadastra_luta(luta *p_luta, int qtd)
{
    int i;

    for (i = 0; i < qtd; i++, p_luta++)
    {
        p_luta->qtd_aluno = 0;
        p_luta->reg_aula = i + 1;

        switch (i)
        {
        case 0:
            p_luta->modalidade = 'B';
            p_luta->turno = 'M';
            break;

        case 1:
            p_luta->modalidade = 'B';
            p_luta->turno = 'T';
            break;

        case 2:
            p_luta->modalidade = 'B';
            p_luta->turno = 'N';
            break;

        case 3:
            p_luta->modalidade = 'S';
            p_luta->turno = 'M';
            break;

        case 4:
            p_luta->modalidade = 'S';
            p_luta->turno = 'T';
            break;

        case 5:
            p_luta->modalidade = 'S';
            p_luta->turno = 'N';
            break;
        }

        switch (p_luta->turno)
        {
        case 'M':
            p_luta->valor = 300;
            break;

        case 'T':
            p_luta->valor = 250;
            break;

        case 'N':
            p_luta->valor = 350;
            break;
        }
    }
}

int busca_luta(luta *p_luta, char aux_modalidade, char aux_turno)
{
    int i;

    for (i = 0; i < 6; i++, p_luta++)
    {
        if (p_luta->modalidade == aux_modalidade && p_luta->turno == aux_turno)
        {
            p_luta->qtd_aluno++;
            return p_luta->reg_aula;
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

void mostra_luta(luta *p_luta, int qtd)
{
    int i;

    for (i = 0; i < qtd; i++, p_luta++)
    {
        printf("\nID: %i\nModalidade: %c\nTurno: %c\nQtd de Aluno: %i\nValor: %.2f\n\n\n", p_luta->reg_aula, p_luta->modalidade, p_luta->turno, p_luta->qtd_aluno, p_luta->valor);
    }
}
