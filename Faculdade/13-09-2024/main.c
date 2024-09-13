#include <stdio.h>
#include <stdlib.h>

/*
Alocar espaço para 10 números reais. Mostrar o endereço e receber do usuário os valores. Em
seguida, alterar esses valores, somando 30 a cada elemento. Mostrar novamente o endereço (que
deve ser o mesmo) com o novo valor. Utilizar função para alocação dinâmica
*/

void aloca(float **p, int tam);
void pegaNumeros(float *numeros);
void somaNumeros(float *numeros);
void printaNumeros(float *numeros);

int main()
{
    float *numeros = NULL;

    aloca(&numeros, 10);
    pegaNumeros(numeros);
    printaNumeros(numeros);
    printf("\n===================================\n");
    somaNumeros(numeros);
    printaNumeros(numeros);

    return 0;
}

void aloca(float **p, int tam)
{
    if((*p = (float *)realloc(*p,tam*sizeof(float)))==NULL)
    {
        printf("Erro na Alocacao de Memoria...");
        exit(1);
    }

    printf("\nEndereco Novo: %u\n", *p);

}

void pegaNumeros(float *numeros)
{
    int i;

    for(i = 0; i<10; i++)
    {
        printf("\nDigite o numero %i vetor: ", i+1);
        scanf("%f", (numeros+i));
    }
}

void printaNumeros(float *numeros)
{
    int i;

    for(i = 0; i<10; i++)
    {
        printf("\n Numero %i - Endereco %u: %.2f", i+1, numeros+i, *(numeros+i));
    }
}

void somaNumeros(float *numeros)
{
    int i;

    for(i =0; i<10; i++)
    {
        *(numeros+i) += 30;
    }
}