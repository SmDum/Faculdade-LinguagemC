#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct passageiro
{
    char CPF[13];
    char nome[80];
    char classe; // 'P' Primeira, 'E' Econômica
    int assento;
} passageiro;

typedef struct voo
{
    int num_poltrona;
    char status;
    char tipo;
} voo;

void aloca_passageiro(passageiro **p_passageiro, int qtd_assentos);
void aloca_voo(voo **p_voo, int qtd_assentos);

void cadastra_passageiro(passageiro *p_passageiro, voo *p_voo, int qtd_assentos);
void cadastra_voo(voo *p_voo, int qtd_assentos);

int busca_passageiro(passageiro *p_passageiro, int qtd_passageiro, char *aux_CPF);
int busca_assento(voo *p_voo, int qtd_assentos, char tipo_assento);

void cancelamento(passageiro *p_passageiro, int qtd_passageiros, voo *p_voo, int qtd_assentos);

void mostra_poltronas(voo *p_voo, int qtd_assentos);
void mostra_passageiros(passageiro *p_passageiro, int qtd_assentos);

int main()
{
    setlocale(LC_ALL, "portuguese");

    passageiro *p_passageiro = NULL;
    voo *p_voo = NULL;
    int opc, cont = 0, qtd_assentos = 100;

    aloca_voo(&p_voo, qtd_assentos);
    cadastra_voo(p_voo, qtd_assentos);

    do
    {
        printf("[1] - Cadastro\n[2] - Cancelamento\n[3] - Mostrar Assentos\n[4] - Mostrar Passageiros\n[5] - Fim\nOpção: ");
        scanf("%i", &opc);

        switch (opc)
        {
        case 1:
            aloca_passageiro(&p_passageiro, cont + 1);
            cadastra_passageiro(p_passageiro + cont, p_voo, qtd_assentos);
            cont++;
            system("pause");
            system("cls");
            break;

        case 2:
            cancelamento(p_passageiro, cont, p_voo, qtd_assentos);
            system("pause");
            system("cls");
            break;

        case 3:
            mostra_poltronas(p_voo, qtd_assentos);
            system("pause");
            system("cls");
            break;

        case 4:
            mostra_passageiros(p_passageiro, cont);
            system("pause");
            system("cls");
            break;

        default:
            break;
        }
    } while (opc != 5);

    free(p_passageiro);
    free(p_voo);

    return 0;
}

void aloca_passageiro(passageiro **p_passageiro, int qtd_assentos)
{
    if ((*p_passageiro = (passageiro *)realloc(*p_passageiro, qtd_assentos * sizeof(passageiro))) == NULL)
    {
        printf("\nErro ao alocar memória...");
        exit(1);
    }
}

void aloca_voo(voo **p_voo, int qtd_assentos)
{
    if ((*p_voo = (voo *)realloc(*p_voo, qtd_assentos * sizeof(voo))) == NULL)
    {
        printf("\nErro ao alocar memória...");
        exit(1);
    }
}

void cadastra_passageiro(passageiro *p_passageiro, voo *p_voo, int qtd_assentos)
{
    char tip_assento;

    printf("\n\n\n");
    printf("Tipo de Assento\n(E - Econômica)\n(P - Primeira Classe)\nOpção: ");
    scanf(" %c", &tip_assento);
    fflush(stdin);

    tip_assento = toupper(tip_assento);

    int num_assento = busca_assento(p_voo, qtd_assentos, tip_assento);

    if (num_assento == -1)
    {
        printf("\nNão há assentos disponíveis...");
    }
    else
    {
        printf("\nCPF: ");
        fgets(p_passageiro->CPF, 13, stdin);
        fflush(stdin);

        printf("\nNome: ");
        fgets(p_passageiro->nome, 80, stdin);
        fflush(stdin);

        p_passageiro->assento = num_assento;
        p_passageiro->classe = tip_assento;
        (p_voo + num_assento - 1)->status = 'O';

        printf("\nCadastro Realizado com Sucesso! Número do assento: %i\n\n\n", p_passageiro->assento);
    }
}

void cadastra_voo(voo *p_voo, int qtd_assentos)
{
    for (int i = 1; i <= qtd_assentos; i++, p_voo++)
    {
        p_voo->num_poltrona = i;

        if (i <= 10)
        {
            p_voo->tipo = 'P';
        }
        else
        {
            p_voo->tipo = 'E';
        }

        p_voo->status = 'L';
    }
}

int busca_passageiro(passageiro *p_passageiro, int qtd_passageiro, char *aux_CPF)
{
    for (int i = 1; i <= qtd_passageiro; i++, p_passageiro++)
    {
        if (strcmp(aux_CPF, p_passageiro->CPF) == 0)
        {
            return i;
        }
    }
    return -1;
}

int busca_assento(voo *p_voo, int qtd_assentos, char tipo_assento)
{
    for (int i = 1; i <= qtd_assentos; i++, p_voo++)
    {
        if (tipo_assento == p_voo->tipo && p_voo->status == 'L')
        {
            return i;
        }
    }
    return -1;
}

void mostra_poltronas(voo *p_voo, int qtd_assentos)
{
    for (int i = 1; i <= qtd_assentos; i++, p_voo++)
    {
        printf("\nID: %i\nStatus: %c\nTipo: %c\n\n", p_voo->num_poltrona, p_voo->status, p_voo->tipo);
    }
}

void mostra_passageiros(passageiro *p_passageiro, int qtd_passageiros)
{
    for (int i = 1; i <= qtd_passageiros; i++, p_passageiro++)
    {
        printf("\nCPF: %s\nNome: %s\nClasse: %c\n\nAssento: %i\n\n", p_passageiro->CPF, p_passageiro->nome, p_passageiro->classe, p_passageiro->assento);
    }
}

void cancelamento(passageiro *p_passageiro, int qtd_passageiros, voo *p_voo, int qtd_assentos)
{
    char aux_CPF[13];

    fflush(stdin);
    printf("\nDigite o CPF a ser cancelado: ");
    fgets(aux_CPF, 13, stdin);
    fflush(stdin);

    int pos = busca_passageiro(p_passageiro, qtd_passageiros, aux_CPF);

    if (pos == -1)
    {
        printf("\nCPF Inválido...");
    }
    else
    {
        int assento = (p_passageiro + pos - 1)->assento;
        printf("\nCancelamento do passageiro %s do assento %i Confirmado!", (p_passageiro + pos - 1)->nome, assento);
        (p_voo + assento - 1)->status = 'L';
        strcpy((p_passageiro + pos - 1)->CPF, "-1");
    }
}
