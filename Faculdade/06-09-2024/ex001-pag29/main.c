#include <stdio.h>
#include <stdlib.h>

void somaVetores(int *A, int *B, int *C, int qtde);
void capturarVetor(int *vetor, int qtd);
void imprime(int *vetor, int qtd);

int main()
{
    int tamanho;

    do
    {
        printf("\nDigite o Tamanho dos Vetores: ");
        scanf("%i", &tamanho);
    }while(tamanho<1 || tamanho>10);

    int *A = (int*)malloc(tamanho*sizeof(int));
    int *B = (int*)malloc(tamanho*sizeof(int));
    int *C = (int*)malloc(tamanho*sizeof(int));

    if(A==NULL || B==NULL || C==NULL)
    {
        printf("\nErro ao alocar memória\n");
        return 1;
    }

    capturarVetor(A, tamanho);
    capturarVetor(B, tamanho);

    somaVetores(A,B,C,tamanho);

    printf("\nVetor A:\n");
    imprime(A, tamanho);

    printf("\nVetor B:\n");
    imprime(B, tamanho);

    printf("\nVetor C:\n");
    imprime(C, tamanho);

    free(A);
    free(B);
    free(C);

    return 0;
}

void capturarVetor(int *vetor, int qtd)
{
    printf("\nDigite os Valores do Vetor:\n");

    for(int i = 0; i<qtd; i++)
    {
        scanf("%i" , vetor+i);
    }
}

void somaVetores(int *A, int *B, int *C, int qtd)
{
    for(int i = 0; i<qtd; i++)
    {
        *(C+i) = *(A+i) + *(B+i);
    }

}

void imprime(int *vetor, int qtd)
{
    for(int i = 0; i<qtd; i++)
    {
        printf("[%i]\t", *(vetor+i));
    }
}
