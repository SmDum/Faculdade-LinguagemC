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
void cadastra_cliente(cliente *p_cliente, carro *p_carro, int qtd_carro);

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

    aloca_carro(&p_carro, qtd_carros);   // aloca carro
    cadastra_carro(p_carro, qtd_carros); // chamada da funcao cadastra_carro

    do
    {
        system("cls");
        printf("[1] Locacao\n[2] Devolucao\n[3] Mostra Carros\n[4] Fim\nOpcao: ");
        scanf("%i", &opc);
        getchar(); // Limpa o buffer

        switch (opc)
        {
        case 1:
            aloca_cliente(&p_cliente, cont + 1);
            cadastra_cliente(p_cliente + cont, p_carro, qtd_carros);
            cont++;
            system("pause");
            break;

        case 2:
            devolucao(p_cliente, cont, p_carro, qtd_carros);
            system("pause");
            break;

        case 3:
            mostra_carro(p_carro, qtd_carros);
            system("pause");
            break;

        default:
            break;
        }
    } while (opc != 4);

    free(p_carro);
    free(p_cliente);

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
    for (int i = 0; i < qtd; i++)
    {
        p_carro[i].reg_carro = i;
        p_carro[i].status = 'L';

        if (i < 5)
        {
            p_carro[i].tipo = 'P';
        }
        else if (i < 10)
        {
            p_carro[i].tipo = 'M';
        }
        else
        {
            p_carro[i].tipo = 'G';
        }
    }
}

void cadastra_cliente(cliente *p_cliente, carro *p_carro, int qtd_carro)
{
    char tipcar;
    int numcar;

    printf("\nTipo de Carro: ");
    scanf(" %c", &tipcar); // O espaço antes de %c descarta espaços em branco

    tipcar = toupper(tipcar);

    numcar = busca_carro(p_carro, tipcar, qtd_carro);

    if (numcar == -1)
    {
        printf("\nNão há carros dessa categoria...\n\n");
    }
    else
    {
        p_cliente->num_reg = numcar;

        printf("\nCPF: ");
        scanf("%s", p_cliente->CPF);

        printf("\nNome: ");
        getchar(); // Limpa o buffer antes de ler o nome
        fgets(p_cliente->nome, sizeof(p_cliente->nome), stdin);
        p_cliente->nome[strcspn(p_cliente->nome, "\n")] = 0; // Remove a nova linha

        printf("\nQtos dias: ");
        scanf("%i", &(p_cliente->dias));

        p_carro->status = 'O';

        printf("\nCadastro feito com sucesso\nCarro: %i\n\n", p_cliente->num_reg);
    }
}

int busca_carro(carro *p_carro, char tipo_car, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        if (p_carro[i].tipo == tipo_car && p_carro[i].status == 'L')
        {
            return i;
        }
    }
    return -1;
}

int busca_CPF(cliente *p_cliente, int qtd, char *aux)
{
    for (int i = 0; i < qtd; i++)
    {
        if (strcmp(p_cliente[i].CPF, aux) == 0)
        {
            return i;
        }
    }
    return -1;
}

void devolucao(cliente *p_cliente, int qtd_cli, carro *p_carro, int qtd_car)
{
    char aux_CPF[13];
    int pos, reg, tempo;

    printf("\nDigite o CPF a ser encerrado: ");
    scanf("%s", aux_CPF);

    pos = busca_CPF(p_cliente, qtd_cli, aux_CPF);

    if (pos == -1)
    {
        printf("\nCPF Inválido...\n\n");
    }
    else
    {
        reg = (p_cliente + pos)->num_reg;
        char tip = (p_carro + reg)->tipo;
        (p_carro + reg)->status = 'L';
        tempo = (p_cliente + pos)->dias;

        printf("\nNome: %s\nCarro: %i\nTipo de carro: %c\nDias: %i\n", p_cliente[pos].nome, reg, tip, tempo);

        switch (tip)
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

        strcpy((p_cliente + pos)->CPF, "-1");
    }
}

void mostra_carro(carro *p_carro, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        printf("\nRegistro Carro: %i\nTipo: %c\nStatus: %c\n\n", p_carro[i].reg_carro, p_carro[i].tipo, p_carro[i].status);
    }
}
