/*
Lista Encadeada / Lista Ligada / Linked List

Lista encadeada possui além de seu valor, um ponteiro apontando para o próximo elemento;
Podemos inserir elementos no inicio e no fim;
*/

#include <stdio.h>
#include <stdlib.h>

struct st_no
{
    int valor;
    struct st_no *prox;
};

typedef struct st_no no;

int vazia(no *le)
{
    if (le->prox == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void inicia(no *le)
{
    le->prox = NULL;
}

void libera(no *le)
{
    if (!vazia(le))
    {
        no *proxNo, *atual;
        atual = le->prox;
        while (atual != NULL)
        {
            proxNo = atual->prox;
            free(atual);
            atual = proxNo;
        }
    }
}

void exibe(no *le)
{
    if (vazia(le))
    {
        printf("\nLista esta vazia!\n\n");
        return;
    }
    no *temp;
    temp = le->prox;

    while (temp != NULL)
    {
        printf("%i", temp->valor);
        temp = temp->prox;
    }
    printf("\n\n");
}

void insereInicio(no *le)
{
    no *novo = (no *)malloc(sizeof(no));
    if (!novo)
    {
        printf("\nSem memoria disponivel...");
        exit(1);
    }
    printf("\nInforme o valor: ");
    scanf("%i", &novo->valor);

    no *oldHead = le->prox;
    le->prox = novo;
    novo->prox = oldHead;
}

void insereFim(no *le)
{
    no *novo = (no *)malloc(sizeof(no));
    if (!novo)
    {
        printf("\nSem memoria disponivel...");
        exit(1);
    }
    printf("\nInforme o valor: ");
    scanf("%i", &novo->valor);
    novo->prox = NULL;

    if (vazia(le))
    {
        le->prox = novo;
    }
    else
    {
        no *temp = le->prox;

        while (temp->prox != NULL)
        {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

void opcao(no *le, int op)
{
    switch (op)
    {
    case 0:
        libera(le);
        break;

    case 1:
        exibe(le);
        break;

    case 2:
        insereInicio(le);
        break;

    case 3:
        insereFim(le);
        break;

    case 4:
        inicia(le);
        break;

    case -1:
        printf("\nSaindo...");
        break;

    default:
        printf("\nComando Invalido");
    }
}

int menu()
{
    int opc;

    printf("\nSelecione a opcao");

    printf("\n[1] - Exibir\n[2] - Adicionar no inicio\n[3] - Adicionar no fim\n[4] - Zerar Lista\n[-1] - Sair\nOpcao: ");

    scanf("%i", &opc);

    return opc;
}

int main()
{

    no *le = (no *)malloc(sizeof(no));

    if (!le)
    {
        printf("\nErro ao alocar memoria...");
        exit(1);
    }

    inicia(le);
    int opc;

    do
    {
        opc = menu();
        opcao(le, opc);
    } while (opc != -1);

    free(le);
    return 0;
}
