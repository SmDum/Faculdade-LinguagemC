#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam); // Alocação
void pegarNumeros(float *p);    // Leitura de Numeros
void mostra(float *p, int tam); // Printa Numeros
void maiormenorMedia(float *p, int tam, float **p_maior, int *qtdMaior, float **p_menor, int *qtdMenor);
// Indica Menor e Maior que a Média

int main()
{
    float *numeros = NULL, *maior = NULL, *menor = NULL;
    int tam = 0, qtdMaior = 0, qtdMenor = 0;
    char opc;

    do
    {
        aloca(&numeros, tam + 1);
        pegarNumeros(numeros + tam);
        tam++;
        printf("\nDeseja Continuar? <S/N>: ");
        scanf(" %c", &opc);
        fflush(stdin);

    } while (opc == 's' || opc == 'S');

    mostra(numeros, tam);
    printf("\n======================\n");
    maiormenorMedia(numeros, tam, &maior, &qtdMaior, &menor, &qtdMenor);
    printf("\nMaiores que a Media:\n");
    mostra(maior, qtdMaior);
    printf("\nMenores que a Media:\n");
    mostra(menor, qtdMenor);

    return 0;
}

void aloca(float **p, int tam)
{
    if ((*p = (float *)realloc(*p, tam * sizeof(float))) == NULL)
    {
        printf("Erro ao Alocar Memoria...");
        exit(1);
    }
}

void pegarNumeros(float *p)
{
    printf("\nDigite um numero: ");
    scanf("%f", p);
    fflush(stdin);
}

void mostra(float *p, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf("\n%.2f\n", *(p + i));
    }
}

void maiormenorMedia(float *p, int tam, float **p_maior, int *qtdMaior, float **p_menor, int *qtdMenor)
{
    int i;
    float m = 0;

    for (i = 0; i < tam; i++)
    {
        m += *(p + i);
    }

    m /= tam;

    printf("\nMedia: %.2f\n", m);

    for (i = 0; i < tam; i++)
    {
        if (*(p + i) > m)
        {
            aloca(p_maior, (*qtdMaior) + 1);
            *(*p_maior + *qtdMaior) = *(p + i);
            (*qtdMaior)++;
        }
    }

    for (i = 0; i < tam; i++)
    {
        if (*(p + i) < m)
        {
            aloca(p_menor, (*qtdMenor) + 1);
            *(*p_menor + *qtdMenor) = *(p + i);
            (*qtdMenor)++;
        }
    }
}
