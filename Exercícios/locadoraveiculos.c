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

int busca_carro(carro *p_carro, char tipo_car, int qtd);
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

    if (numcar == -1)
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

int busca_carro(carro *p_carro, char tipo_car, int qtd)
{
    int i, id_carro;

    printf("\nDigite o ID do Veículo: ");
    scanf("%i", &id_carro);

    for (i = 0; i < qtd, i++, p_carro++)
    {
        if(id_carro==p_carro->reg_carro)
        {
            return i;
        }
    }
    return -1;
}

int busca_CPF(cliente *p_cliente, int qtd, char *aux)
{
    int i;

    for(i = 0; i<qtd; i++, p_cliente++)
    {
        if(strcmp(p_cliente->CPF, aux)==0)
        {
            return i;
        }
    } 
    return -1;
}

void devolucao(cliente *p_cliente, int qtd_cli, carro *p_carro, int qtd_car)
{
    char aux_CPF[13], tip;
    int pos, reg, tempo;

    pos = busca_CPF(p_cliente, qtd_cli, aux_CPF);

    if(pos==-1)
    {
        printf("\nCPF Inválido...\n\n\n");
    } 
    else
    {
        reg = (p_cliente+pos)->num_reg;
        tip = (p_carro+reg)->tipo;
        (p_carro + reg)->status = 'L';
        tempo = (p_cliente+pos)->dias;

        printf("\nNome: %s\nCarro: %i\nTipo de carro: %c\nDias: %i\n", (pcli + pos)->nome, reg, tip, tempo);

        switch(tip)
        {
            case 'P':
                printf("Valor a ser pago: R$%.2f\n", tempo * 150.00);
                break;

            case 'M':
                printf("Valor a ser pago: R$%.2f\n", tempo * 200.00);
                break;

            case 'G':
                printf("Valor a ser pago: R$%.2f\n", tempo * 250.00);
                break;   
        }
    }

}

void mostra_carro(carro *p_carro, int qtd)
{
    int i;

    for(i=0; i<qtd; i++, p_carro++)
    {
        printf("\nRegistro Carro: %i\nTipo: %c\nStatus: %c\n\n", pcar->reg_carro, pcar->tipo, pcar->status);

        printf("\n\n\n");
    }
}
