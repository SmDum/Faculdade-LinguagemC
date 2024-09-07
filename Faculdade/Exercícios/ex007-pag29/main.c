#include <stdio.h>
#include <stdlib.h>

#define NUM_VALORES 10

void lerValores(int *valores);
void ordenarValores(int *valores);
void imprimir(int* valores);

int main()
{
    int valores = (int *)malloc(NUM_VALORES * sizeof(int));

    if(valores == NULL)
    {
        printf("\nErro ao alocar mem�ria...\n");
        return 1;
    }

    lerValores(valores);
    ordenarValores(valores);
    imprimir(valores);

    free(valores);

    return 0;
}

void lerValores(int *valores)
{
    for(int i = 0; i<NUM_VALORES; i++)
    {
        printf("Valor %i: " , i+1);
        scanf("%i", valores+i);
    }
}

void ordenarValores(int *valores)
{
    // Implementação do Bubble Sort
    for (int i = 0; i < NUM_VALORES - 1; i++)
    {
        for (int j = 0; j < NUM_VALORES - i - 1; j++)
        {
            if (*(valores + j) > *(valores + j + 1))
            {
                // Troca os valores
                int temp = *(valores + j);
                *(valores + j) = *(valores + j + 1);
                *(valores + j + 1) = temp;
            }
        }
    }
}

void imprimir(int* valores)
{
    printf("\nValores em Ordem Crescente:\n");

    for(int i = 0; i<NUM_VALORES; i++)
    {
        printf("%i\t", *(valores+i));
    }

    printf("\n");
}
