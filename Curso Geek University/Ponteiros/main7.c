/*
Fila / Queue

- Fila de Banco;
- O elemento que entra primeiro, sai primeiro;
- Sempre que um elemento é adicionado na fila, ele vai para o final dela;
- Sempre que removemos um elemento, o primeiro é removido.

FIFO - First in / First Out

enqueue() - Adiciona o elemento na fila.
dequeue() - Remove o elemento da fila.
clear() - Limpa a fila.

Estrutura da Fila.

fila[10] - [0][1][2][3][4][5][6][7][8][9]

head - Cabeça da fila, indica quem é o primeiro da fila.
tail - Calda da fila, indica quantos elementos tem na fila.

Aplicação: Em qualquer situação onde a gente tenha que organizar o atendimento
de elementos.

*/

#include <stdio.h>
#include <locale.h>

#define TAMFILA 10

// File /Queue
int fila[TAMFILA] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int head = 0;
int tail = 0;

void lista_elementos()
{
    int i;
    printf("\n======== Fila Atual ========\n\n");
    for (i = 0; i < TAMFILA; i++)
    {
        printf("%i", fila[i]);
        printf("-");
    }
    printf("\n");
    printf("\nHead: %i\n", head);
    printf("\nTail: %i\n", tail);
    printf("\n\n");
}

void enqueue()
{
    int val;
    if (tail < TAMFILA)
    {
        printf("Informe o elemento para adicionar na fila: ");
        scanf("%i", &val);
        fila[tail] = val;
        tail = tail + 1;
        lista_elementos();
    }
    else
    {
        printf("\nFila Cheia...\n");
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
        printf("A fila está vazia...");
    }
}

void clear()
{
    int i;

    for (i = 0; i < TAMFILA; i++)
    {
        fila[i] = 0;
    }
    head = 0;
    tail = 0;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int opc = 0;

    do
    {
        printf("Selecione a opção: \n\n");
        printf("[1] - Inserir (enqueue)\n[2] - Remover (dequeue)\n[3] - Listar\n[4] - Limpar a Fila\n[-1] - Sair\n");
        printf("\nOpção: ");
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
            break;

        default:
            printf("\nOpção Inválida...\n");
        }

    } while (opc != -1);

    return 0;
}
