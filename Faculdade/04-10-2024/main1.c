#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct cliente
{
    char nome[30];
    int conta;
    float saldo;
} cliente;

void cadastro(cliente *p);
int busca(cliente *p, int tam);
void movimenta(cliente *p, int opc);

int main()
{
    setlocale(LC_ALL, "portuguese");
    cliente cli[10];
    int cont = 0, opc, achou;

    do
    {
        printf("\n[1]Cadastro\n[2]Depósito\n[3]Retirada\n[4]Fim\nOpção: ");
        scanf("%i", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            cadastro(cli + cont);
            cont++;
            break;

        case 2:
        case 3:
            achou = busca(cli, cont);
            if (achou == -1)
            {
                printf("\nConta Inválida\n\n");
            }
            else
            {
                movimenta(cli + achou, opc);
            }
            break;
        }

    } while (opc != 4 || opc != 4);

    return 0;
}

void cadastro(cliente *p)
{
    static int n = 1000;
    printf("\nNome: ");
    gets(p->nome);
    fflush(stdin);
    p->conta = n;
    n++;
    p->saldo = 0;
    printf("\nConta Cadastrada com Sucesso: %i\n\n", p->conta);
}

int busca(cliente *p, int tam)
{
    int aux_conta, i;
    printf("\nConta a ser movimentada: ");
    scanf("%i", &aux_conta);
    fflush(stdin);

    for (i = 0; i < tam; i++, p++)
    {
        if (p->conta == aux_conta)
        {
            return i;
        }

        return -1;
    }
}

void movimenta(cliente *p, int opc)
{
    float valor;
    printf("\nValor a ser depositado/retirado: ");
    scanf("%f", &valor);
    fflush(stdin);

    if (opc == 2)
    {
        p->saldo += valor;
    }

    else
    {
        if (p->saldo >= valor)
        {
            p->saldo -= valor;
        }

        else
        {
            printf("\nSaldo Insuficiente\n\n");
        }
    }

    printf("Saldo Atual: %.2f\n\n", p->saldo);
    system("pause");
}
