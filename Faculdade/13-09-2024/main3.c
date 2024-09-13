#include <stdio.h>
#include <stdlib.h>

void aloca(int **p, int tam);
void leitura(int *p);
void mostra(int *p, int tam);


int main()
{
    int *ptr = NULL, cont=0;
    char op;

    do
    {
        aloca(&ptr, cont+1);
        leitura(ptr+cont);
        cont++;
        printf("\nDeseja Continuar? <S/N>: ");
        scanf("%c", &op);

    }while(op!='n' && op!='N');

    system("cls");

    mostra(ptr, cont);

    return 0;
}

void aloca(int **p, int tam)
{
    if((*p =(int *)realloc(*p, tam*sizeof(int)))==NULL)
    {
       printf("Erro na Alocacao de Memoria...");
       exit(1);
    }
}

void leitura(int *p)
{
    printf("\nDigite um numero: ");
    scanf("%i", p);
    fflush(stdin);
}

void mostra(int *p, int tam)
{
    int i;
    p = p+tam-1;
    for(i=0;i<tam;i++,p--)
    {
        printf("%i\n", *p);
    }
    printf("\n\n\n");
    system("pause");
}
