// Lista Encadeada

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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
        printf("\nLista está vazia!");
        return;
    }
    else
    {
        no *temp;
        temp = le->prox;

        while (temp != NULL)
        {
            printf("%i ", temp->valor);
            temp = temp->prox;
        }
        printf("\n\n\n");
    }
}

void insereInicio(no *le)
{
    no *novo = (no *)malloc(sizeof(no));
    if (!novo)
    {
        printf("\nSem memória disponível...");
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
        printf("\nSem memória disponível...");
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

void opcao(no *le, int opc)
{
    switch (opc)
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

    default:
        printf("\nComando Inválido!");
        break;
    }
}

int menu()
{
    int opc;

    printf("\n[0] - Sair\n[1] - Exibir\n[2] - Adicionar nó no início\n[3] - Adicionar nó no Fim\n[4] - Zerar Lista\nOpção: ");
    scanf("%i", &opc);
    return opc;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    no *le = (no *)malloc(sizeof(no));

    if (!le)
    {
        printf("\nSem memória...");
        exit(1);
    }

    inicia(le);

    int opc;

    do
    {
        opc = menu();
        opcao(le, opc);
    } while (opc);

    free(le);
    return 0;
}
