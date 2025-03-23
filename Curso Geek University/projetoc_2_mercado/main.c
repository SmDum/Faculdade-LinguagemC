#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

typedef struct
{
    int codigo;
    char nome[30];
    float preco;
} Produto;

typedef struct
{
    Produto produto;
    int quantidade;
} Carrinho;

void infoProduto(Produto prod);
void menu();
void cadastrarProduto();
void listarProdutos();
void comprarProduto();
void visualizarCarrinho();
Produto pegarProdutoPorCodigo(int codigo);
int *temNoCarrinho(int codigo);
void fecharPedido();

static int contador_produto = 0;
static int contador_carrinho = 0;
static Carrinho carrinho[50];
static Produto produtos[50];

int main()
{
    setlocale(LC_ALL, "portuguese");
    menu();
    return 0;
}

void infoProduto(Produto prod)
{
    printf("\nCódigp do produto: %i\nNome: %s\nPreço: %.2f\n", prod.codigo, strtok(prod.nome, "\n"), prod.preco);
}

void menu()
{
    printf("=================================\n");
    printf("========== Bem-Vindo(a) =========\n");
    printf("=================================\n");

    printf("\nSelecione uma opção abaixo: ");
    printf("\n[1] - Cadastrar Produto");
    printf("\n[2] - Listar Produtos");
    printf("\n[3] - Comprar Produto");
    printf("\n[4] - Visualizar Carrinho");
    printf("\n[5] - Fechar Pedido");
    printf("\n[6] - Sair do Sistema");
    printf("\nOpção: ");

    int opcao;

    scanf("%i", &opcao);
    getchar();

    switch (opcao)
    {
    case 1:
        cadastrarProduto();
        break;

    case 2:
        listarProdutos();
        break;

    case 3:
        comprarProduto();
        break;

    case 4:
        visualizarCarrinho();
        break;

    case 5:
        fecharPedido();
        break;

    case 6:
        printf("\nVolte sempre!");
        Sleep(2);
        exit(0);

    default:
        printf("\nOpção Inválida...");
        Sleep(2);
        menu();
        break;
    }
}

void cadastrarProduto()
{
    printf("\nCadastro de Produto");
    printf("\n===================");

    printf("\nInforme o nome do produto: ");
    fgets(produtos[contador_produto].nome, 30, stdin);

    printf("\nInforme o preço do produto: ");
    scanf("%f", &produtos[contador_produto].preco);

    printf("\n O produto %s foi cadastrado com sucesso!", strtok(produtos[contador_produto].nome, "\n"));

    produtos[contador_produto].codigo = (contador_produto + 1);
    contador_produto++;

    Sleep(2);
    menu();
}

void listarProdutos()
{
    if (contador_produto > 0)
    {
        printf("\nListagem de produtos");
        printf("\n--------------------");

        for (int i = 0; i < contador_produto; i++)
        {
            infoProduto(produtos[i]);
            printf("\n--------------------");
            Sleep(1);
        }
        Sleep(2);
        menu();
    }
    else
        printf("\nNão temos ainda produtos cadastrados...");
        Sleep(2);
        menu();
}

void comprarProduto()
{
    if (contador_produto > 0)
    {
        printf("\nInforme o código o produto que deseja adicionar ao carrinho.");
        printf("\n============ Produtos Disponíveis ============");
        for (int i = 0; i < contador_produto; i++)
        {
            infoProduto(produtos[i]);
            printf("\n-------------------------------------------");
            Sleep(1);
        }

        int codigo;

        scanf("%i", &codigo);
        getchar();

        int tem_mercado = 0;

        for (int i = 0; i < contador_produto; i++)
        {
            if (produtos[i].codigo == codigo)
            {
                tem_mercado = 1;

                if (contador_carrinho > 0)
                {
                    int *retorno = temNoCarrinho(codigo);
                    carrinho[retorno[1]].quantidade++;
                    printf("\nAumentei a quantidade do produto %s já existente no carrinho", strtok(carrinho[retorno[1]].produto.nome, "\n"));
                    Sleep(2);
                    menu();
                }
                else
                {
                    Produto p = pegarProdutoPorCodigo(codigo);
                    carrinho[contador_carrinho].produto = p;
                    carrinho[contador_carrinho].quantidade = 1;
                    contador_carrinho++;
                    printf("\nO produto %s foi adicionado ao carrinho", strtok(p.nome, "\n"));
                    Sleep(2);
                    menu();
                }
            }
            else
            {
                Produto p = pegarProdutoPorCodigo(codigo);
                carrinho[contador_carrinho].produto = p;
                carrinho[contador_carrinho].quantidade = 1;
                contador_carrinho++;
                printf("\nO produto %s foi adicionado ao carrinho", strtok(p.nome, "\n"));
                Sleep(2);
                menu();
            }
        }
        if (tem_mercado < 1)
        {
            printf("\nNão foi encontrado o produto com código %i", codigo);
            Sleep(2);
            menu();
        }
    }
    else
    {
        printf("\nAinda não existem produtos para vender...");
        Sleep(2);
        menu();
    }
}

void visualizarCarrinho()
{
    if (contador_carrinho > 0)
    {
        printf("\nProdutos no Carrinho");
        printf("\n--------------------");

        for (int i = 0; i < contador_carrinho; i++)
        {
            infoProduto(carrinho[i].produto);
            printf("\nQuantidade: %i", carrinho[i].quantidade);
            printf("\n--------------------");
            Sleep(1);
        }
        Sleep(2);
        menu();
    }
    else
    {
        printf("\nNão temos ainda produtos no carrinho...");
        Sleep(2);
        menu();
    }

}

Produto pegarProdutoPorCodigo(int codigo)
{
    Produto p;

    for (int i = 0; i < contador_produto; i++)
    {
        if (produtos[i].codigo == codigo)
            p = produtos[i];
    }

    return p;
}

int *temNoCarrinho(int codigo)
{
    int static retorno[] = {0, 0};

    for (int i = 0; i < contador_carrinho; i++)
    {
        if (carrinho[i].produto.codigo == codigo)
        {
            retorno[0] = 1; // Tem o produto com este código no carrinho
            retorno[1] = i; // O índice do produto no carrinho
        }
    }

    return retorno;
}

void fecharPedido()
{
    if (contador_carrinho > 0)
    {
        float valorTotal = 0.0;

        printf("\nProdutos do Carrinho");
        printf("\n--------------------");

        for (int i = 0; i < contador_carrinho; i++)
        {
            Produto p = carrinho[i].produto;
            int quantidade = carrinho[i].quantidade;

            valorTotal += p.preco * quantidade;

            infoProduto(p);
            printf("\nQuantidade: %i", quantidade);
            Sleep(1);
        }
        printf("\nSua fatura é R$%.2f", valorTotal);

        contador_carrinho = 0;
        printf("\nObrigado pela preferência!");
        Sleep(5);
        menu();
    }

    else
    {
        printf("\nVocê não tem nenhum produto no carrinho ainda...");
        Sleep(3);
        menu();
    }
}