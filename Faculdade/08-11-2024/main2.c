#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct dados
{
    int reg;
    char produto[20];
    int qtde;
    float preco;
} dados;

void aloca(dados **p, int tam);
void cadastro(dados *p, int qreg);
void grava(dados *p);
int verifica();
void mostra(dados *p, int qreg);

int main()
{
    setlocale(LC_ALL, "portuguese");

    dados *pd = NULL;
    char op;
    int qreg;

    aloca(&pd, 1);

    qreg = verifica();

    do
    {
        cadastro(pd, qreg + 1);
        qreg++;
        printf("\nDeseja Continuar? <S/N>");
        scanf("%c", &op);
        fflush(stdin);

    } while (op != 'n' && op != 'N');

    mostra(pd, qreg);

    return 0;
}

void aloca(dados **p, int tam)
{
    if ((*p = (dados *)realloc(*p, tam * sizeof(dados))) == NULL)
    {
        printf("\nErro ao alocar memória...");
        exit(1);
    }
}

void cadastro(dados *p, int qreg)
{
    p->reg = qreg;

    printf("\nRegistro: %i", p->reg);
    
    printf("\nProduto: ");
    gets(p->produto);
    fflush(stdin);

    printf("\nQtde Estoque: ");
    scanf("%i", &(p->qtde));
    fflush(stdin);

    printf("\nPreço: ");
    scanf("%f", &(p->preco));
    fflush(stdin);

    grava(p);
}

void grava(dados *p)
{
    FILE *fptr = NULL;

    if ((fptr = fopen("estoque.bin", "ab")) == NULL)
    {
        printf("\nErro ao abrir o arquivo");
    }
    else
    {
        fwrite(p, sizeof(dados), 1, fptr);
    }
    fclose(fptr);
}

int verifica()
{
    long int cont = 0;
    FILE *fptr = NULL;

    if ((fptr = fopen("estoque.bin", "rb")) == NULL)
    {
        return cont;
    }
    else
    {
        fseek(fptr, 0, SEEK_END);
        cont = ftell(fptr) / sizeof(dados);
        fclose(fptr);
        return cont;
    }
}

void mostra(dados *p, int qreg)
{
    int i;
    FILE *fptr = NULL;

    if ((fptr = fopen("estoque.bin", "rb")) == NULL)
    {
        printf("\nErro ao abrir o arquivo...");
    }
    else
    {
        for(i=0;i<qreg;i++)
        {
            fseek(fptr, i*sizeof(dados), SEEK_SET);
            fread(p, sizeof(dados), 1, fptr);
            printf("\nReistro: %i\nProduto: %s\nQtde: %i\nPreço: %.2f", p->reg, p->produto, p->qtde, p->preco);
        }
        fclose(fptr);
    }
    system("pause");
    system("cls");
}