#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Declaração de StructsF
typedef struct dados
{
    int reg;
    char produto[20];
    int qtde;
    float preco;
} dados;

// Função para carregar o último registro do arquivo
void carregarUltimoRegistro(int *ultimoReg);

// Função para gravar um registro no arquivo
void gravarRegistro(dados *novo);

// Função para ler e exibir todos os produtos cadastrados
void lerProdutos();

// Função principal com menu de opções
int main()
{
    setlocale(LC_ALL, "portuguese");

    dados *estoque;
    int ultimoReg = 0;
    int opcao;

    carregarUltimoRegistro(&ultimoReg); // Carrega o último registro do arquivo

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            // Aloca memória para um novo registro
            estoque = (dados *)malloc(sizeof(dados));
            if (estoque == NULL)
            {
                printf("Erro de alocação de memória!\n");
                return 1;
            }

            // Preenche os dados do produto
            estoque->reg = ++ultimoReg;
            printf("Produto: ");
            scanf(" %19s", estoque->produto);
            printf("Quantidade: ");
            scanf("%d", &estoque->qtde);
            printf("Preço: ");
            scanf("%f", &estoque->preco);

            // Grava no arquivo e libera a memória alocada
            gravarRegistro(estoque);
            free(estoque);
        }
        else if (opcao == 2)
        {
            lerProdutos(); // Chama a função para listar produtos
        }
        else if (opcao == 3)
        {
            printf("Saindo do programa.\n");
            break;
        }
        else
        {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

// Função para carregar o último registro do arquivo
void carregarUltimoRegistro(int *ultimoReg)
{
    FILE *arquivo = fopen("estoque.dat", "rb"); // Declaração de Ponteiros para arquivos
    dados temp;                                 // Declaração de variável do tamanho da struct Dados

    if (arquivo != NULL)
    { // Se o arquivo abrir
        while (fread(&temp, sizeof(dados), 1, arquivo))
        {                          // Enquanto ele ler o conteudo da Sturct que está no arquivo estoque.dat
            *ultimoReg = temp.reg; // Atualiza com o último registro lido
        }
        fclose(arquivo); // Fecha o arquivo.
    }
    else
    {
        *ultimoReg = 0; // Se o arquivo não existe, começa do zero
    }
}

// Função para gravar um registro no arquivo
void gravarRegistro(dados *novo)
{
    FILE *arquivo = fopen("estoque.dat", "ab"); // Cria um novo arquivo estoque.dat
    if (arquivo == NULL)
    { // Se não abrir
        printf("Erro ao abrir o arquivo para gravação!\n");
        return;
    }
    fwrite(novo, sizeof(dados), 1, arquivo); // Grava o registro no arquivo
    fclose(arquivo);                         // Fecha o arquivo
}

// Função para ler e exibir todos os produtos cadastrados
void lerProdutos()
{
    FILE *arquivo = fopen("estoque.dat", "rb"); // Abre o arquivo estoque.dat para leitura
    dados produto;

    if (arquivo == NULL)
    { // Se não tiver nada no arquivo.
        printf("Nenhum produto cadastrado ou erro ao abrir o arquivo!\n");
        return;
    }

    printf("\nLista de Produtos Cadastrados:\n");
    printf("-----------------------------------\n");
    printf("Reg | Produto           | Qtde | Preço\n");
    printf("-----------------------------------\n");

    while (fread(&produto, sizeof(dados), 1, arquivo))
    {
        printf("%-4d| %-18s| %-5d| R$ %.2f\n",
               produto.reg, produto.produto, produto.qtde, produto.preco);
    }

    fclose(arquivo); // Fecha o arquivo
    printf("-----------------------------------\n");
}