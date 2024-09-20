#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam);
void pegarNumeros(float *p);
void mostra(float *p, int tam);
float maiorMedia(float *p, int tam, float **p_m);


int main()
{
    float *numeros = NULL, *maior=NULL, *menor=NULL;
    int tam = 0, qtdMaior, qtdMenor;
    char opc;

    do
    {
        aloca(&numeros, tam+1);
        pegarNumeros(numeros+tam);
        tam++;
        printf("\nDeseja Continuar? <S/N>: ");
        scanf("%c", &opc);
        fflush(stdin);

    }while(opc=='s'||opc=='S');

    mostra(numeros, tam);
    printf("\n======================\n");
    qtdMaior = maiorMedia(numeros, tam, &maior);
    printf("\nMaiores que a Media:\n");
    mostra(maior, qtdMaior);


    return 0;
}

void aloca(float **p, int tam)
{
    if((*p=(float *)realloc(*p, tam*sizeof(float)))==NULL)
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

   for(i=0; i<tam; i++)
   {
       printf("\n%.2f\n", *(p+i));
   }
}

float mediaNumeros(float *p, int tam)
{
    int i;
    float soma = 0;

    for(i=0; i<tam; i++)
    {
        soma += *(p+i);
    }

    float media = soma/tam;
    return media;
}

float maiorMedia(float *p, int tam, float **p_m)
{
    int i, qtdM=0;
    float m=0;

    for(i=0;i<tam;i++)
    {
        m += *(p+i);
    }

    m/= tam;

    printf("Media: %.2f", m);

    for(i=0;i<tam;i++)
    {
        if(*(p+i)>m)
        {
            aloca((p_m+i), qtdM+1);
            *(*p_m+qtdM)=*p;
            qtdM++;
        }
    }

    return qtdM;
}
