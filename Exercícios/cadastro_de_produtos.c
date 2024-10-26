#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct produto
{
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
} produto;

void aloca(produto **p_produto, int qtd_produtos);
void cadastra(produto *p_produto, int qtd_produtos);
void cadastra_produto(produto *p_produto);
int busca_produto(produto *p_produto, int qtd_produtos);
void muda_estoque(produto *p_produto, int qtd_produtos);
void mostra_estoque(produto *p_produto, int qtd_produtos);

int main()
{
    setlocale(LC_ALL, "portuguese");

    produto *p_produto = NULL;
    int qtd = 20, cont = 0, opc;

    aloca(&p_produto, qtd);
    cadastra(p_produto, qtd);

    do
    {

        printf("\n[1] - Cadastro de Produto\n[2] - Atualização de Estoque\n[3] - Ver Estoque\n[4] - Sair\nOpção: ");
        scanf("%i", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            if (cont < qtd)
            {
                cadastra_produto(p_produto + cont);
                cont++;
            }
            else
            {
                printf("Estoque cheio! Não é possível cadastrar mais produtos.\n");
            }
            system("pause");
            system("cls");
            break;

        case 2:
            muda_estoque(p_produto, qtd);
            system("pause");
            system("cls");
            break;

        case 3:
            mostra_estoque(p_produto, qtd);
            system("pause");
            system("cls");
            break;

        default:
            printf("\nOpção Inválida...");
            break;
        }
    } while (opc != 4);

    free(p_produto);

    return 0;
}

void aloca(produto **p_produto, int qtd_produtos)
{
    if ((*p_produto = (produto *)realloc(*p_produto, qtd_produtos * sizeof(produto))) == NULL)
    {
        printf("\nErro ao alocar memória...");
        exit(1);
    }
}
void cadastra(produto *p_produto, int qtd_produtos)
{
    int i;

    for (i = 0; i < qtd_produtos; i++, p_produto++)
    {
        p_produto->codigo = i + 1;
        strcpy(p_produto->nome, "-");
        p_produto->preco = 0.00;
        p_produto->quantidade = 0;
    }
}

void cadastra_produto(produto *p_produto)
{
    printf("\nNome do Produto: ");
    gets(p_produto->nome);
    fflush(stdin);

    printf("\nPreço: ");
    scanf("%f", &p_produto->preco);
    fflush(stdin);

    printf("\nQuantidade: ");
    scanf("%i", &p_produto->quantidade);
    fflush(stdin);
}

int busca_produto(produto *p_produto, int qtd_produtos)
{
    int i, codigo;

    printf("\nDigite o código do produto que deseja buscar: ");
    scanf("%i", &codigo);

    for (i = 0; i < qtd_produtos; i++, p_produto++)
    {
        if (p_produto->codigo == codigo)
        {
            return i;
        }
    }
    return -1;
}

void muda_estoque(produto *p_produto, int qtd_produtos)
{
    int achou = busca_produto(p_produto, qtd_produtos), opc;

    if (achou == -1)
    {
        printf("\nProduto não encontrado...");
    }
    else
    {
        printf("\nProduto: %s\nPreço: %.2f\nQuantidade: %i\n", p_produto->nome, p_produto->preco, p_produto->quantidade);

        do
        {
            printf("Item que deseja alterar:\n[1] - Nome\n[2] - Preço\n[3] - Quantidade\nOpção: ");
            scanf("%i", &opc);
            fflush(stdin);

        } while (opc==4);

        switch (opc)
        {
        case 1:
            printf("\nDigite o novo nome: ");
            gets(p_produto->nome);
            fflush(stdin);
            break;

        case 2:
            printf("\nDigite o novo preço: ");
            scanf("%f", &p_produto->preco);
            fflush(stdin);
            break;

        case 3:
            printf("\nDigite a nova quantidade: ");
            scanf("%i", &p_produto->quantidade);
            fflush(stdin);
            break;

        default:
            break;
        }
    }
}

void mostra_estoque(produto *p_produto, int qtd_produtos)
{
    int i;

    for (i = 0; i < qtd_produtos; i++, p_produto++)
    {
        printf("\nCódigo: %i\nProduto: %s\nPreço: %.2f\nQuantidade: %i\n", p_produto->codigo, p_produto->nome, p_produto->preco, p_produto->quantidade);
    }
}
