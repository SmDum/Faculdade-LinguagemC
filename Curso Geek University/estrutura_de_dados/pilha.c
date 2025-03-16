/*
Pilha / Stack

FILO - First in / Last out
LIFO - Last in / Last Out

- Os dados são inseridos sempre no topo, ou seja, sempre que um novo elemento é inserido ele ocupa o topo da pilha;

- Só temos acesso ao elemento em que está no topo;

- O processo de inserir um elemento é chamado de push;

- O processo de remover um elemento é chamado de pop;

- Aplicação da pilha: CTRL + Z;

*/

#include <stdio.h>

#define TAMPILHA 10

int pilha[TAMPILHA] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int topo = 0;

void lista_elementos()
{
    printf("\n=====Pilha Atual=====");
    for (int i = 0; i < TAMPILHA; i++)
    {
        printf("-");
        printf("|%i|", pilha[i]);
        printf("-");
    }
    printf("\nTopo: %i", topo);
    printf("\n\n");
}

void push()
{
    int val;
    printf("\nInforme o valor: ");
    scanf("%i", &val);

    if (topo < TAMPILHA)
    {
        pilha[topo] = val;
        topo++;
        lista_elementos();
    }
    else
    {
        printf("\nPilha cheia...");
    }
}

void pop()
{
    if (topo >= 0)
    {
        pilha[topo - 1] = 0;
        topo--;
        lista_elementos();
    }
    else
    {
        printf("\nPilha esta vazia...");
    }
}

void clear()
{
    for (int i = 0; i < TAMPILHA; i++)
    {
        pilha[i] = 0;
    }
    topo = 0;
}

int main()
{

    int opc = 0;

    do
    {
        printf("\nSelecione a opcao");
        printf("\n[1] - Inserir (Push)\n[2] - Remover (Pop)\n[3] - Listar\n[4] - Limpar a Pilha\n[-1] - Sair\nOpcao: ");
        scanf("%i", &opc);

        switch (opc)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            lista_elementos();
            break;

        case 4:
            clear();
            break;

        case -1:
            printf("\nSaindo...");
            break;

        default:
            printf("\nOpcao Invalida...");
            break;
        }
    } while (opc != -1);

    return 0;
}