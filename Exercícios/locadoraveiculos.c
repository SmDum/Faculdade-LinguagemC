#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct carro
{
    int reg_carro;
    char tipo;
    char status;
} carro;

typedef struct cliente
{
    char CPF[13];
    char nome[80];
    int num_reg;
    int dias;
} cliente;

void aloca_carro(carro **p_carro, int qtd);
void aloca_cliente(cliente **p_cliente, int qtd);

void cadastra_carro(carro *p_carro, int qtd);
void cadastra_cliente(cliente *p_cliente, carro *p_carro);

int busca_carro(carro *p_carro, char tipo_car);
int busca_CPF(cliente *p_cliente, int qtd, char *aux);

void devolucao(cliente *p_cliente, int qtd_cli, carro *p_carro, int qtd_car);
void mostra_carro(carro *p_carro, int qtd);

int main()
{
    setlocale(LC_ALL, "portuguese");

    carro *p_carro = NULL;
    cliente *p_cliente = NULL;
    int qtd_carros = 15, cont = 0, opc;

    do
    {
        switch (opc)
        {
        case 1:
            system("pause");
            system("cls");
            break;

        case 2:
            system("pause");
            system("cls");
            break;

        case 3:
            system("pause");
            system("cls");
            break;

        default:
            break;
        }
    } while (opc != 4);

    return 0;
}

void aloca_carro(carro **p_carro, int qtd)
{
    if ((*p_carro = (carro *)realloc(*p_carro, qtd * sizeof(carro))) == NULL)
    {
        printf("Erro ao alocar memória...");
        exit(1);
    }
}

void aloca_cliente(cliente **p_cliente, int qtd)
{
    if ((*p_cliente = (cliente *)realloc(*p_cliente, qtd * sizeof(cliente))) == NULL)
    {
        printf("Erro ao alocar memória...");
        exit(1);
    }
}

void cadastra_carro(carro *p_carro, int qtd)
{
    int i;

    for (i = 0; i < qtd; i++, p_carro++)
    {
        p_carro->reg_carro = i;
        p_carro->status = 'L';

        if (i < 5)
        {
            p_carro->tipo = 'P';
        }
        if (i >= 5 && i <= 10)
        {
            p_carro->tipo = 'M';
        }
        else
        {
            p_carro->tipo = 'G';
        }
    }
}

void cadastra_cliente(cliente *p_cliente, carro *p_carro)
{
    char tipcar;
    int numcar;

    printf("\nTipo de Carro: ");
    scanf("%i", &tipcar);

    tipcar = toupper(tipcar);

    numcar = busca_carro(p_carro, tipcar);

    if(numcar==-1)
    {
        printf("\nNão há carros dessa categoria...\n\n\n");
    }
    else
    {
        p_cliente->num_reg = numcar;

        printf("\nCPF: ");
        scanf("%c", &(p_cliente->CPF));
        fflush(stdin);

        printf("\nNome: ");
        gets(p_cliente->nome);
        fflush(stdin);

        printf("\nQtos dias: ");
        scanf("%i", &(pcli->dias));
        fflush(stdin);

        printf("\nCadastro feito com sucesso\nCarro: %i\n\n\n", pcli->num_reg);

    }

}

int busca_carro(carro *p_carro, char tipo_car)
{
    
}

int busca_CPF(cliente *p_cliente, int qtd, char *aux)
{
}

void devolucao(cliente *p_cliente, int qtd_cli, carro *p_carro, int qtd_car)
{
}

void mostra_carro(carro *p_carro, int qtd)
{
}
