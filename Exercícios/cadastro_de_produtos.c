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
void cadastra_produto(produto *p_produto, int qtd_produtos, int *cont);
produto *busca_produto(produto *p_produto, int qtd_produtos);
void muda_estoque(produto *p_produto, int qtd_produtos);
void mostra_estoque(produto *p_produto, int qtd_produtos);
void remove_produto(produto *p_produto, int *qtd_produtos);

int main()
{
    setlocale(LC_ALL, "portuguese");

    produto *p_produto = NULL;
    int qtd = 20, cont = 0, opc;

    aloca(&p_produto, qtd);
    cadastra(p_produto, qtd);

    do
    {
        printf("\n[1] - Cadastro de Produto\n[2] - Atualização de Estoque\n[3] - Ver Estoque\n[4] - Remover Produto\n[5] - Sair\nOpção: ");
        scanf("%i", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            cadastra_produto(p_produto, qtd, &cont);
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

        case 4:
            remove_produto(p_produto, &cont);
            system("pause");
            system("cls");
            break;

        case 5:
            printf("Saindo do sistema...\n");
            break;

        default:
            printf("\nOpção Inválida...");
            break;
        }
    } while (opc != 5);

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
    for (produto *p = p_produto; p < p_produto + qtd_produtos; p++)
    {
        p->codigo = (p - p_produto) + 1;
        strcpy(p->nome, "-");
        p->preco = 0.00;
        p->quantidade = 0;
    }
}

void cadastra_produto(produto *p_produto, int qtd_produtos, int *cont)
{
    int encontrou_vazio = 0;

    for (produto *p = p_produto; p < p_produto + qtd_produtos; p++)
    {
        if (strcmp(p->nome, "-") == 0)
        {
            encontrou_vazio = 1;
            printf("\nNome do Produto: ");
            fgets(p->nome, sizeof(p->nome), stdin);
            p->nome[strcspn(p->nome, "\n")] = 0; // Remover newline
            fflush(stdin);

            printf("\nPreço: ");
            scanf("%f", &p->preco);
            fflush(stdin);

            printf("\nQuantidade: ");
            scanf("%i", &p->quantidade);
            fflush(stdin);

            (*cont)++;
            printf("Produto cadastrado com o código %d.\n", p->codigo);
            break;
        }
    }

    if (!encontrou_vazio)
    {
        printf("Estoque cheio! Não é possível cadastrar mais produtos.\n");
    }
}

produto *busca_produto(produto *p_produto, int qtd_produtos)
{
    int codigo;
    printf("\nDigite o código do produto que deseja buscar: ");
    scanf("%i", &codigo);

    for (produto *p = p_produto; p < p_produto + qtd_produtos; p++)
    {
        if (p->codigo == codigo)
        {
            return p;
        }
    }
    return NULL;
}

void muda_estoque(produto *p_produto, int qtd_produtos)
{
    produto *p = busca_produto(p_produto, qtd_produtos);
    if (p == NULL)
    {
        printf("\nProduto não encontrado...");
    }
    else
    {
        int opc;
        printf("\nProduto: %s\nPreço: %.2f\nQuantidade: %i\n", p->nome, p->preco, p->quantidade);

        do
        {
            printf("Item que deseja alterar:\n[1] - Nome\n[2] - Preço\n[3] - Quantidade\n[4] - Sair\nOpção: ");
            scanf("%i", &opc);
            fflush(stdin);

            switch (opc)
            {
            case 1:
                printf("\nDigite o novo nome: ");
                fgets(p->nome, sizeof(p->nome), stdin);
                p->nome[strcspn(p->nome, "\n")] = 0;
                break;

            case 2:
                printf("\nDigite o novo preço: ");
                scanf("%f", &p->preco);
                fflush(stdin);
                break;

            case 3:
                printf("\nDigite a nova quantidade: ");
                scanf("%i", &p->quantidade);
                fflush(stdin);
                break;

            default:
                break;
            }
        } while (opc != 4);
    }
}

void mostra_estoque(produto *p_produto, int qtd_produtos)
{
    for (produto *p = p_produto; p < p_produto + qtd_produtos; p++)
    {
        if (strcmp(p->nome, "-") != 0) // Ignora produtos removidos
        {
            printf("\nCódigo: %i\nProduto: %s\nPreço: %.2f\nQuantidade: %i\n", p->codigo, p->nome, p->preco, p->quantidade);
        }
    }
}

void remove_produto(produto *p_produto, int *qtd_produtos)
{
    produto *p = busca_produto(p_produto, *qtd_produtos);

    if (p == NULL)
    {
        printf("\nProduto não encontrado...");
    }
    else
    {
        strcpy(p->nome, "-");
        p->preco = 0.00;
        p->quantidade = 0;
        printf("\nProduto removido com sucesso!\n");

        (*qtd_produtos)--; // Reduz a quantidade de produtos cadastrados
    }
}
