#include <stdio.h>
#include <stdlib.h>

#define NUM_VALORES 10

void ler_valores(int *valores);
int maior(int *valores);
void imprimir(int maior);


int main()
{
    int *valores = (int *)malloc(NUM_VALORES * sizeof(int));

    if(valores == NULL)
    {
        printf("\nErro ao alocar memoria...\n");
        return 1;
    }

    ler_valores(valores);
    int maior_num = maior(valores);
    imprimir(maior_num);

    free(valores);

    return 0;
}

void ler_valores(int *valores)
{
    for(int i = 0; i<NUM_VALORES; i++)
    {
        printf("Digite o valor %i: " , i+1);
        scanf("%i", valores+i);
    }
}

int maior(int *valores)
{
    int maior_num = *valores;

    for(int i = 1; i<NUM_VALORES; i++)
    {
        if(*(valores+i)>maior_num)
        {
            maior_num = *(valores+i);
        }
    }

    return maior_num;
}

void imprimir(int maior)
{
    printf("O numero %i equivale ao maior numero", maior);
}
