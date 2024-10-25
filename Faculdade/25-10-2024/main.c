#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
} data;

typedef struct pessoa
{
    char nome[31];
    char fone[21];
    data nasc;
} pessoa;

void aloca_pessoa(pessoa **p_pes, int cont);
void cadastra_pessoa(pessoa *p_pes);
void registra_nasc(data *nasc);
void mostrar_lista(pessoa *p_pes, int cont);
void buscar_pessoa(pessoa *p_pes, int cont);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int quant = 0, opc;
    pessoa *p_pessoas = NULL;

    do
    {

        printf("[1] - Cadastrar Pessoas\n[2] - Buscar Pessoa\n[3] - Mostrar Lista\n[4] - Sair\n");
        scanf("%i", &opc);

        switch (opc)
        {
        case 1:
            aloca_pessoa(&p_pessoas, quant + 1);
            cadastra_pessoa(p_pessoas + quant);
            quant++;
            break;
        case 2:
            buscar_pessoa(p_pessoas, quant);
            break;
        case 3:
            mostrar_lista(p_pessoas, quant);
            break;
        case 4:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opc != 4);

    free(p_pessoas); // Liberar a memória alocada

    return 0;
}

// Função para alocar memória para a lista de pessoas
void aloca_pessoa(pessoa **p_pes, int cont)
{
    *p_pes = (pessoa *)realloc(*p_pes, cont * sizeof(pessoa));
    if (*p_pes == NULL)
    {
        printf("\nErro ao alocar memória...\n");
        exit(1);
    }
}

// Função para cadastrar pessoas usando apenas ponteiros
void cadastra_pessoa(pessoa *p_pes)
{
    pessoa *ptr = p_pes; // Ponteiro auxiliar para percorrer a lista

    printf("\nDigite o nome da pessoa: ");
    scanf(" %s", ptr->nome); // Lê o nome com espaços

    printf("Digite o telefone da pessoa: ");
    scanf(" %s", ptr->fone); // Lê o telefone com espaços

    // Registra a data de nascimento
    registra_nasc(&(ptr->nasc));
}

// Função para registrar a data de nascimento usando ponteiros
void registra_nasc(data *nasc)
{
    printf("Digite a data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &nasc->dia, &nasc->mes, &nasc->ano);
}

void mostrar_lista(pessoa *p_pes, int cont)
{
    pessoa *ptr = p_pes;
    for (int i = 0; i < cont; i++, ptr++)
    {
        printf("Nome: %s\nData de Nascimento: %02d/%02d/%d\nTelefone: %s\n",
               ptr->nome, ptr->nasc.dia, ptr->nasc.mes, ptr->nasc.ano, ptr->fone);
    }
}

void buscar_pessoa(pessoa *p_pes, int cont)
{
    int i;
    char nome[31];

    printf("\nDigite o nome que deseja Buscar: ");
    fflush(stdin);
    gets(nome);
    fflush(stdin);

    for (i = 0; i < cont; i++, p_pes++)
    {
        if (strcmp(nome, p_pes->nome) == 0)
        {
            printf("\nO Telefone de %s é %s\n", p_pes->nome, p_pes->fone);
            return;
        }
    }
    printf("\nPessoa não encontrada...\n");
}