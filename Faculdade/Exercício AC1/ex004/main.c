#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void aloca(int **p, int tam);
void recebe(int *p);
void mostra(int *p, int tam);
int pares(int *p, int tam, int qtdpares, int **pares);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int *num = NULL, cont = 0, qtdpar = 0, *numpar = NULL;
    char opc;

    do
    {
        aloca(&num, cont + 1);
        recebe(num + cont);
        cont++;
        printf("\nDeseja Continuar <S/N>: ");
        scanf(" %c", &opc);
        fflush(stdin);

    } while (opc == 's' || opc == 'S');

    system("cls");

    qtdpar = pares(num, cont, qtdpar, &numpar);

    printf("\nNúmeros Digitados:\n");
    mostra(num, cont);
    printf("\n-----------------------------\n");
    printf("\n Números Pares:\n");
    mostra(numpar, qtdpar);

    free(num);
    free(numpar);

    return 0;
}

void aloca(int **p, int tam)
{
    if ((*p = (int *)realloc(*p, tam * sizeof(int))) == NULL)
    {
        printf("\nErro ao Alocar Memória...\n");
        exit(1);
    }
}

void recebe(int *p)
{
    printf("\nDigite um Número: ");
    scanf("%i", p);
}

void mostra(int *p, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("\n%i\n", *(p + i));
    }
}

int pares(int *p, int tam, int qtdpares, int **pares)
{
    int i, soma;

    for(i = 0; i<tam-1; i+=2)
    {
        soma = *(p+i) + *(p+i+1);

        if(soma%2==0)
        {
            aloca(pares, qtdpares+1);
            *(*pares + qtdpares) = soma;
            qtdpares++;
        }
    }

    if(tam%2!=0)
    {
        int UltElemento = *(p+tam-1);

        if(UltElemento%2==0)
        {
            aloca(pares, qtdpares+1);
            *(*pares + qtdpares) = UltElemento;
            qtdpares++;
        }
    }

    return qtdpares;
}
