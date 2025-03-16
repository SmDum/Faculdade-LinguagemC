/*
Fila / Queue

- Fila de banco;
- O elemento que entra primeiro, sai primeiro;
- Sempre que um elemento é adicionado na fila, ele vai para o final dela;
- Sempre que removemos um elemento, o primeiro é removido;
- FIFO - First in / First Out

enqueue() --> Adiciona elemento na fila;
dequeue() --> Remove o elemento da fila;
clear() --> Limpa a fila;

Estrutura da fila

fila[10] - [0][1][2][3][4][5][6][7][8][9]

head --> Cabeça da fila, indica quem é o primeiro da fila;
tail --> Calda da fila, indica quantos elementos tem na fila;

Aplicação: Em qualquer situação onde a gente tenha que organizar o atendimento de elementos;

*/

#include <stdio.h>

#define TAMFILA 10

int fila[TAMFILA] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int head = 0; // Próximo a ser atendido
int tail = 0; // Último da fila

void lista_elementos()
{
    printf("\n=====Fila Atual=====\n");
    for (int i = 0; i < TAMFILA; i++)
    {
        printf("-");
        printf("|%i|", fila[i]);
        printf("-");
    }
    printf("\nHead: %i\n", head);
    printf("Tail: %i\n", tail);
    printf("\n\n");
}

void enqueue()
{
    int val;
    if (tail < TAMFILA)
    {
        printf("\nInforme o elemento para ser adicionado na fila: ");
        scanf("%i", &val);
        fila[tail] = val;
        tail++;
        lista_elementos();
    }
    else
    {
        printf("\nA fila esta cheia...");
    }
}

void dequeue()
{
    if (head < tail)
    {
        fila[head] = 0;
        head++;
        lista_elementos();
    }
    else
    {
        printf("\nA fila está vazia...");
    }
}

void clear()
{
    for (int i = 0; i < TAMFILA; i++)
    {
        fila[i] = 0;
    }
    head = 0;
    tail = 0;
}

int main()
{
    int opc = 0;

    do
    {
        printf("\nSelecione a opcao");
        printf("\n[1] - Inserir (enqueue)\n[2] - Remover (dequeue)\n[3] - Listar\n[4] - Limpar a fila\n[-1] - Sair\nOpcao: ");
        scanf("%i", &opc);

        switch (opc)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
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
