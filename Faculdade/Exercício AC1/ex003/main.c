#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void aloca(int **p, int tam);
void recebe(int *p);
void mostra(int *p, int tam);
int pares(int *p, int tam, int qtdpar, int **npares);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int *num = NULL, cont = 0, qtdpares = 0, *numpar = NULL;
    char opc;

    do
    {
        aloca(&num, cont + 1);
        recebe(num + cont);
        cont++;
        printf("\nDeseja Continuar<S/N>: ");
        scanf(" %c", &opc);
        fflush(stdin);

    } while (opc == 's' || opc == 'S');

    qtdpares = pares(num, cont, qtdpares, &numpar);

    printf("\nNumeros Digitados:\n");
    mostra(num, cont);
    printf("\n--------------------------------\n");
    printf("\nNumeros Pares:\n");
    mostra(numpar, qtdpares);

    free(num);
    free(numpar);

    return 0;
}

void aloca(int **p, int tam)
{
    if ((*p = (int *)realloc(*p, tam * sizeof(int))) == NULL)
    {
        printf("\nErro ao Alocar Memória\n");
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

int pares(int *p, int tam, int qtdpar, int **npares)
{
    int i, sub;

    for (i = 0; i < tam - 1; i += 2)
    {
        sub = *(p + i + 1) - *(p + i);

        if (sub % 2 == 0)
        {
            aloca(npares, qtdpar + 1);
            *(*npares + qtdpar) = sub;
            qtdpar++;
        }
    }

    int UltElemento = *(p + tam - 1);

    if (tam % 2 != 0)
    {
        if (UltElemento % 2 == 0)
        {
            aloca(npares, qtdpar);
            *(*npares + qtdpar) = UltElemento;
            qtdpar++;
        }
    }

    return qtdpar;
}
