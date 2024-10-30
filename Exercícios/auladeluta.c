#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

typedef struct aluno
{
    int id_aula;
    char CPF[13];
    char nome[50];
} aluno;

typedef struct luta
{
    int reg_aula;
    int qtd_alunos;
    char modalidade;
    char turno;
    float valor;
} luta;

void aloca_aluno(aluno **p_aluno, int qtd_aluno);
void aloca_luta(luta **p_luta, int qtd_luta);

void cadastra_aluno(aluno *p_aluno, luta *p_luta, int qtd_luta);
void cadastra_luta(luta *p_luta, int qtd_luta);

int busca_luta(luta p_luta, int qtd_luta, char aux_modalidade);

void mostra_alunos(aluno *p_aluno, luta *p_luta, int qtd_aluno);
void mostra_lutas(luta *p_luta, int qtd_luta);

int main()
{
    setlocale(LC_ALL, "portuguese");

    aluno *p_aluno = NULL;
    luta *p_luta = NULL;
    int opc, cont = 0, qtd = 20;

    aloca_luta(&p_luta, qtd);
    cadastra_luta(p_luta, qtd);

    do
    {
        printf("[1] - Cadastro\n[2] - Mostra Alunos\n[3] - Mostra Salas\n[4] - Fim\nOpção: ");
        scanf("%i", &opc);

        switch (opc)
        {
        case 1:
            aloca_aluno(&p_aluno, cont + 1);
            cadastra_aluno(p_aluno + cont, p_luta, qtd);
            cont++;
            system("pause");
            system("cls");
            break;

        case 2:
            mostra_alunos(p_aluno, cont);
            system("pause");
            system("cls");
            break;

        case 3:
            mostra_lutas(p_luta, qtd);
            system("pause");
            system("cls");
            break;

        default:
            break;
        }

    } while (opc != 4);

    free(p_aluno);
    free(p_luta);

    return 0;
}

void aloca_aluno(aluno **p_aluno, int qtd_aluno)
{
    if ((*p_aluno = (aluno *)realloc(p_aluno, qtd_aluno * sizof(aluno))) == NULL)
    {
        printf("\nErro ao alocar memória...");
        exit(1);
    }
}

void aloca_luta(luta **p_luta, int qtd_luta)
{
    if ((*p_luta = (luta *)realloc(p_luta, qtd_luta * sizeof(luta))) == NULL)
    {
        printf("\nErro ao alocar memória...");
        exit(1);
    }
}

void cadastra_aluno(aluno *p_aluno, luta *p_luta, int qtd_luta)
{
    char aux_Modalidade;

    printf("\nSelecione a Modalidade:\n[B] - Boxe\n[J] - Judô\nOpção: ");
    scanf(" %c", &aux_Modalidade);
    aux_Modalidade = toupper(aux_Modalidade);
    fflush(stdin);

    int pos = busca_luta(p_luta, qtd_luta, aux_Modalidade);

    if (pos == -1)
    {
        printf("\nSala Lotada");
    }
    else
    {
        printf("\nNome: ");
        fgets(p_aluno->nome, 50, stdin);
        fflush(stdin);

        printf("\nCPF: ");
        fgets(p_aluno->CPF, 13, stdin);
        fflush(stdin);

        printf("\nTurno\n[M] - Manhã\n[T] - Tarde\n[N] - Noite\nOpção: ");
        scanf("%c", p_luta->turno);

        p_aluno->id_aula = pos;

        printf("\nCadastro Realizado com Sucesso!");
    }
}

void cadastra_luta(luta *p_luta, int qtd_luta)
{
    int i;

    for (i = 0; i < qtd_luta; i++, p_luta++)
    {
        if (i < 10)
        {
            p_luta->modalidade = 'B';
        }
        else
        {
            p_luta->modalidade = 'J';
        }
    }
}

int busca_luta(luta p_luta, int qtd_luta, char aux_modalidade)
{
    int i;

    for (i = 0; i < qtd_luta; i++, qtd_luta++)
    {
        if (strcmp(aux_modalidade, p_luta->modalidade) == 0)
        {
            return i;
        }
    }
    return -1;
}

void mostra_alunos(aluno *p_aluno, luta *p_luta, int qtd_aluno)
{
    int i;

    for (i - 0; i < qtd_aluno; i++)
    {
        printf("\nNome: %s\nCPF: %s\nID: %i\nModalidade: %c\nTurno: %c")
    }
}

void mostra_lutas(luta *p_luta, int qtd_luta)
{
}