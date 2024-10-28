#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

void aloca_carro(carro **pcar, int qcar);
void aloca_cliente(cliente **pcli, int qcli);

void cadastra_carro(carro *pcar, int qcar);
void cadastra_cliente(cliente *pcli, carro *pcar);

void devolucao(cliente *pcli, int qcli, carro *pcar, int qcar);

int busca_carro(carro *pcar, char tipo_car);
int busca_CPF(cliente *pcli, int qcli, char *aux);

void mostra_carro(carro *pcar, int qcar);

int main()
{
    carro *car = NULL;
    cliente *cli = NULL;
    int op, cont = 0;

    aloca_carro(&car, 15);   // aloca carro
    cadastra_carro(car, 15); // chamada da funcao cadastra_carro

    do
    {
        system("cls");
        printf("[1] Locacao\n[2] Devolucao\n[3] Fim\nOpcao: ");
        scanf("%i", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            mostra_carro(car, 15);
            aloca_cliente(&cli, cont + 1);     // aloca cliente
            cadastra_cliente(cli + cont, car); // chamada da funcao cadastra_cliente
            cont++;
            break;

        case 2:
            devolucao(cli, cont, car, 15); // chamada da funcao devolucao
            break;
        }
    } while (op != 3);

    return 0;
}

void aloca_carro(carro **pcar, int qcar)
{
    if ((*pcar = (carro *)realloc(*pcar, qcar * sizeof(carro))) == NULL)
    { // comando p/ alocar carro
        exit(1);
    }
}

void aloca_cliente(cliente **pcli, int qcli)
{
    if ((*pcli = (cliente *)realloc(*pcli, qcli * sizeof(cliente))) == NULL) // comando p/ alocar cliente
        exit(1);
}

void cadastra_carro(carro *pcar, int qcar)
{
    int i;
    for (i = 0; i < qcar; i++, pcar++)
    {
        pcar->reg_carro = i + 1; // numero do registro do carro
        pcar->status = 'L';

        if (i < 5)
            pcar->tipo = 'P'; // 5 carros pequenos
        else if (i < 10)
            pcar->tipo = 'M'; // 5 carros medios
        else
            pcar->tipo = 'G'; // 5 carros grandes
    }
}

void cadastra_cliente(cliente *pcli, carro *pcar)
{
    char tipcar;
    int numcar;

    printf("\nTipo de carro [P - M - G]: ");
    scanf("%c", &tipcar);
    fflush(stdin);

    tipcar = toupper(tipcar);

    numcar = busca_carro(pcar, tipcar);
    if (numcar == -1)
        printf("\nNao ha carros disponiveis desse tipo\n\n\n");
    else
    {
        pcli->num_reg = numcar;

        printf("\nCPF: ");
        fgets(pcli->CPF, sizeof(pcli->CPF), stdin);
        pcli->CPF[strcspn(pcli->CPF, "\n")] = '\0';

        printf("\nNome: ");
        fgets(pcli->nome, sizeof(pcli->nome), stdin);
        pcli->nome[strcspn(pcli->nome, "\n")] = '\0';

        printf("\nQtos dias: ");
        scanf("%i", &(pcli->dias));
        fflush(stdin);

        printf("\nCadastro feito com sucesso\nCarro: %i\n\n\n", pcli->num_reg);
    }

    system("pause");
}

void devolucao(cliente *pcli, int qcli, carro *pcar, int qcar)
{
    char aux_cpf[13], tip;
    int pos, reg, tempo;

    printf("\nCPF a ser encerrado: ");
    fgets(aux_cpf, sizeof(aux_cpf), stdin);
    aux_cpf[strcspn(aux_cpf, "\n")] = '\0';

    pos = busca_CPF(pcli, qcli, aux_cpf);
    if (pos == -1)
    {
        printf("\nCPF invalido\n");
    }
    else
    {
        reg = (pcli + pos)->num_reg;
        (pcar + reg - 1)->status = 'L';
        tip = (pcar + reg - 1)->tipo;
        tempo = (pcli + pos)->dias;

        printf("\nNome: %s\nCarro: %i\nTipo de carro: %c\nDias: %i\n", (pcli + pos)->nome, reg, tip, tempo);
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
    }
    system("pause");
}

int busca_carro(carro *pcar, char tipo_car)
{
    int i;
    for (i = 0; i < 15; i++)
    {
        if ((pcar + i)->tipo == tipo_car && (pcar + i)->status == 'L')
        {
            (pcar + i)->status = 'O';
            return (pcar + i)->reg_carro;
        }
    }
    return -1;
}

int busca_CPF(cliente *pcli, int qcli, char *aux)
{
    int i;
    for (i = 0; i < qcli; i++, pcli++)
        if (strcmp(pcli->CPF, aux) == 0)
            return i;

    return -1;
}

void mostra_carro(carro *pcar, int qcar)
{
    int i;
    for (i = 0; i < qcar; i++, pcar++)
        printf("\nRegistro Carro: %i\nTipo: %c\nStatus: %c\n\n", pcar->reg_carro, pcar->tipo, pcar->status);

    printf("\n\n\n");
}
