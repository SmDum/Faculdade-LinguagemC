#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam);
void pegarNumeros(float **p, int *tam, char *opcao);
float mediaNumeros(float *p, int tam);
void menorMedia(float *p, int tam, float media);
void maiorMedia(float *p, int tam, float media);

int main()
{
    float *numeros = NULL, res;
    int tam = 1;
    char opc;

    pegarNumeros(&numeros, &tam, &opc);
    res = mediaNumeros(numeros, tam);
    printf("\nMedia = %.2f\n", res);
    printf("\n======================\n");
    menorMedia(numeros, tam, res);
    printf("\n======================\n");
    maiorMedia(numeros, tam, res);

    return 0;
}

void aloca(float **p, int tam)
{
    if ((*p = (float *)realloc(*p, tam * sizeof(float))) == NULL)
    {
        printf("\nErro de Alocacao de Memoria...\n");
        exit(1);
    }
}

float mediaNumeros(float *p, int tam)
{
    int i;
    float soma = 0, media;

    for (i = 0; i < tam; i++)
    {
        soma += *(p + i);
    }

    media = soma / tam;

    return (media);
}

void menorMedia(float *p, int tam, float media)
{
    int i;

    printf("\n=== Menores que a Media ===\n");
    for (i = 0; i < tam; i++)
    {
        if (*(p + i) < media)
        {
            printf("\n%.2f\n", *(p + i));
        }
    }
}

void maiorMedia(float *p, int tam, float media)
{
    int i;

    printf("\n=== Maiores que a Media ===\n");
    for (i = 0; i < tam; i++)
    {
        if (*(p + i) > media)
        {
            printf("\n%.2f\n", *(p + i));
        }
    }
}

void pegarNumeros(float **p, int *tam, char *opcao)
{
    do
    {
        aloca(p, *tam);
        printf("\nDigite um Numero: ");
        scanf("%f", (*p + *tam - 1));
        printf("\nDeseja Continuar? <S/N>: \n");
        scanf(" %c", opcao);

        if (*opcao == 'S' || *opcao == 's')
        {
            (*tam)++;
        }
    } while (*opcao == 'S' || *opcao == 's');
}
