#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

typedef struct luta
{
    int reg_aula;    // registro da aula
    int qtd_aluno;   // registra a quantidade de alunos matriculados
    char modalidade; //[B]allet, [S]apatadeado
    char turno;      //[M]anha | [T]arde | [N]oite
    float valor;     // valor da aula
} luta;

typedef struct aluno
{
    char CPF[13];  // CPF do aluno
    char nome[80]; // nome do aluno
    int num_aula;  // numero do registro da aula
} aluno;

void aloca_aluno(aluno **p_a, int qa);
void aloca_luta(luta **p_l, int ql);

void cadastro_aluno(aluno *p_a, int ql, luta *p_l, int qa);
void cadastro_luta(luta *p_l, aluno *p_a, int ql);

int busca_luta(luta *p_l, int ql, char aux_modalidade, char aux_turno);

void mostra_aluno(aluno *p_a, int qa);
void mostra_luta(luta *p_l, int ql);

int main()
{
    setlocale(LC_ALL, "portuguese");

    aluno *p_aluno = NULL;
    luta *p_luta = NULL;
    int cont = 0, qtd = 6, opc;

    aloca_luta(&p_luta, qtd);
    cadastro_luta(p_luta, p_aluno, qtd);

    do
    {
        printf("[1] - Cadastro\n[2] - Mostrar Alunos\n[3] - Fim\nOpção: ");
        scanf("%i", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            mostra_luta(p_luta, qtd);
            aloca_aluno(&p_aluno, cont + 1);
            cadastro_aluno(p_aluno + cont, qtd, p_luta, cont);
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

    return 0;
}

void aloca_aluno(aluno **p_a, int qa)
{
    if ((*p_a = (aluno *)realloc(*p_a, qa * sizeof(aluno))) == NULL)
    {
        printf("\nErro ao alocar memória...");
        exit(1);
    }
}

void aloca_luta(luta **p_l, int ql)
{
    if ((*p_l = (luta *)realloc(*p_l, ql * sizeof(luta))) == NULL)
    {
        printf("\nErro ao alocar memória...");
        exit(1);
    }
}

void cadastro_aluno(aluno *p_a, int ql, luta *p_l, int qa)
{
    char aux_modalidade, aux_turno;

    printf("\nNome: ");
    fgets(p_a->nome, 80, stdin);
    fflush(stdin);

    printf("\nCPF: ");
    fgets(p_a->CPF, 13, stdin);
    fflush(stdin);

    printf("\nModalidade\n[B] - Boxe\n[J] - Judô\nOpção: ");
    scanf("%c", &aux_modalidade);
    fflush(stdin);
    aux_modalidade = toupper(aux_modalidade);

    printf("\nTurno\n[M] - Manhã\n[T] - Tarde\n[N] - Noite\nOpção: ");
    scanf("%c", &aux_turno);
    fflush(stdin);
    aux_turno = toupper(aux_turno);

    p_a->num_aula = busca_luta(p_l, ql, aux_modalidade, aux_turno);

    if (p_a->num_aula == -1)
    {
        printf("\nAula desejada não encontrada...");
    }
    else
    {
        printf("\nCadastro do aluno bem efetuado. Seja bem-vindo(a)!\nSua aula eh: %d\nO valor eh: R$%.2f\n\n\n", p_a->num_aula+1, (p_l + (p_a->num_aula))->valor);
    }
}

void cadastro_luta(luta *p_l, aluno *p_a, int ql)
{
    int i;

    for (i = 0; i < ql; i++, p_l++)
    {
        p_l->reg_aula = i + 1;
        p_l->qtd_aluno = 0;

        if (i < 3)
        {
            p_l->modalidade = 'B';
            switch (i)
            {
            case 0:
                p_l->turno = 'M';
                break;
            case 1:
                p_l->turno = 'T';
                break;
            case 2:
                p_l->turno = 'N';
                break;
            }
        }
        else
        {
            p_l->modalidade = 'J';
            switch (i)
            {
            case 3:
                p_l->turno = 'M';
                break;
            case 4:
                p_l->turno = 'T';
                break;
            case 5:
                p_l->turno = 'N';
                break;
            }
        }

        switch (p_l->turno)
        {
        case 'M':
            p_l->valor = 300.00;
            break;
        case 'T':
            p_l->valor = 250.00;
            break;
        case 'N':
            p_l->valor = 350.00;
            break;
        }
    }
} // cadastra_luta

int busca_luta(luta *p_l, int ql, char aux_modalidade, char aux_turno)
{
    int i;

    for (i = 0; i < ql; i++, p_l++)
    {
        if (p_l->modalidade == aux_modalidade && p_l->turno == aux_turno)
        {
            p_l->qtd_aluno++;
            return i;
        }
    }
    return -1;
}

void mostra_aluno(aluno *p_a, int qa)
{
    int i;
    for (i = 0; i < qa; i++, p_a++)
    {
        printf("\nNome: %s\nCPF: %s\nNúmero de Aula: %i", p_a->nome, p_a->CPF, p_a->num_aula);
    }
    printf("\n\n\n");
}

void mostra_luta(luta *p_l, int ql)
{
    int i;

    for (i = 0; i < ql; i++, p_l++)
    {
        printf("\nRegistro de Aula: %i\nModalidade: %c\nQuantidade de Alunos: %i\nTurno: %c\nValor: %.2f", p_l->reg_aula, p_l->modalidade, p_l->qtd_aluno, p_l->turno, p_l->valor);
        printf("\n\n");
    }
}
