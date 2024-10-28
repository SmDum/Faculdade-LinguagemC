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
void cadastra_cliente(cliente *p_cliente, int qtd);

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
    if((*p_carro = (carro*)realloc(*p_carro,qtd*sizeof(carro)))==NULL)
    {
        printf("Erro ao alocar memória...");
        exit(1);
    }
}

void aloca_cliente(cliente **p_cliente, int qtd)
{
    if((*p_cliente = (cliente*)realloc(*p_cliente,qtd*sizeof(cliente)))==NULL)
    {
        printf("Erro ao alocar memória...");
        exit(1);
    }
}

void cadastra_carro(carro *p_carro, int qtd)
{

}

void cadastra_cliente(cliente *p_cliente, int qtd)
{

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