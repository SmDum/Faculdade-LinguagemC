/*
Controle de Vendas: Crie um programa para gerenciar as vendas de uma loja. O sistema deve permitir o cadastro de vendas, adicionar produtos à venda, e gerar um relatório final da venda. Utilize alocação dinâmica e ponteiros.
Funções:
[1] Cadastro de Venda - Receber o ID da venda e permitir a adição de produtos, com seus códigos e quantidades, calculando o total da venda.
[2] Exibir Venda - Permitir consultar uma venda pelo ID e exibir os produtos vendidos e o total.
struct venda {
    int idVenda;
    char produto[50];
    int qtdProdutos;
    int preco;
    float total;
};

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct venda
{
    int idVenda;
    char produto[50];
    int qtdProdutos;
    int preco;
    float total;
} venda;

void aloca(venda *p_venda, int qtd);
void cadastro(venda *p_venda, int qtd);
void cadastro_venda(venda *p_venda, int qtd);
int busca_produto(venda *p_venda, int qtd);
void exibir_venda(venda *p_venda, int qtd);
void mostra_vendas(venda *p_venda, int qtd);
void remover_produto(venda *p_venda, int qtd);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int opc, qtd = 15, pos, cont = 0;
    venda *produto = NULL;

    do
    {
        aloca(&produto, qtd);
        cadastro(produto, qtd);

        printf("[1]-Cadastro de Venda\n[2] - Busca Produto\n[3] - Remover Produto\n[4] - Exibir Vendas\n[5] - Sair\n\n");
        scanf("%i", &opc);

        switch (opc)
        {
        case 1:
            pos = busca_produto(produto, qtd);
            if (pos == -1)
            {
                aloca(&ph, cont + 1);
                pos = cont;
                cont++;
            }
            cadastro_venda(produto+pos, qtd);
            system("pause");
            system("cls");
            break;

        case 2:
            exibir_venda(produto, qtd);
            system("pause");
            system("cls");
            break;
        
        case 3:
            remover_produto(produto, qtd);
            system("pause");
            system("cls");
            break;

        case 4:
            mostra_vendas(produto, qtd);
            system("pause");
            system("cls");
            break;

        default:
            break;
        }
    } while (opc != 5);

    return 0;
}

void aloca(venda *p_venda, int qtd)
{
    if ((*p_venda = (venda *)realloc(*p_venda, qtd * sizeof(venda))) == NULL)
    {
        printf("\nErro ao alocar memória...");
        exit(1);
    }
}
void cadastro(venda *p_venda, int qtd)
{
    int i;

    for (i = 0; i < qtd; i++, p_venda++)
    {
        p_venda->idVenda = i;
        p_venda->produtos = "-";
        p_venda->qtdProdutos = 0;
        p_venda->total = 0.0;
    }
}

void cadastro_venda(venda *p_venda)
{
    printf("\nNome do Produto: ");
    gets(p_venda->produto);
    fflush(stdin);

    printf("\nQuantidade de Produtos: ");
    scanf("%i", &(p_venda->qtdProdutos));
    fflush(stdin);

    printf("\nPreço: ");
    scanf("%i", &(p_venda->preco));
    fflush(stdin);

     p_venda->idVenda = busca_produto(p_venda, qtd);
    if (p_venda->idVenda == -1)
        printf("\nProduto Inválido...\n\n");
    else
        printf("\nCadastro com sucesso - Produto = %i\n\n", p_venda->idVenda);
    printf("\n\n\n");
    system("pause");
}

int busca_produto(venda *p_venda, int qtd)
{
    int i, cod;

    printf("\nDigite o código do produto a ser buscado: ");

    for (i = 0; i < qtd; i++, p_venda++)
    {
        if (strcmp(cod, p_venda->idVenda) == 0)
        {
            return i;
        }
    }
    return -1;
}

void exibir_venda(venda *p_venda, int qtd)
{
    int achou = busca_produto(p_venda, qtd);

    if (achou == -1)
    {
        printf("\nProduto Inválido");
    }
    else
    {
        printf("\nCódigo: %i\nNome do produto: %s\nQuantidade: %i\nPreço: %.2f\nTotal: %.2f\n\n\n", p_venda + achou->idVenda, p_venda + achou->produto, p_venda + achou->qtdProdutos, p_venda + achou->preco, (p_venda + achou->qtdProdutos * p_venda + achou->qtdProdutos));
    }
}

void mostra_vendas(venda *p_venda, int qtd)
{
    int i;

    for (i = 0; i < qtd; i++, p_venda++)
    {
        if (p_venda->idVenda != "-")
        {
            printf("\nCódigo: %i\nNome do produto: %s\nQuantidade: %i\nPreço: %.2f\nTotal: %.2f\n\n\n", p_venda->idVenda, p_venda->produto, p_venda->qtdProdutos, p_venda->preco, (p_venda->qtdProdutos * p_venda->qtdProdutos));
        }
    }
}

void remover_produto(venda *p_venda, int qtd)
{
    int achou = busca_produto(p_venda, qtd);

    if (achou == -1)
    {
        printf("\nProduto Inválido");
    }
    else
    {
        p_venda + achou->idVenda = -1;
    }

    p_venda->idVenda = busca_produto(p_venda, qtd);
    if (p_venda->idVenda == -1)
        printf("\nProduto Inválido...\n\n");
    else
        printf("\nProduto removido com sucesso! - Produto = %i\n\n", p_venda->idVenda);
    printf("\n\n\n");
    system("pause");
}