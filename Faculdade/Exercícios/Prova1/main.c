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
    int *num = NULL, cont = 0, qtdpares = 0, *numpares = NULL;
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

    qtdpares = pares(num, cont, qtdpares, &numpares);

    printf("\nNumeros Digitados\n");
    mostra(num, cont);
    printf("\n===============================================\n");
    printf("\nSubtrações Pares:\n");
    mostra(numpares, qtdpares);

    return 0;
}

void aloca(int **p, int tam)
{
    if ((*p = (int *)realloc(*p, tam * sizeof(int))) == NULL)
    {
        printf("Erro ao Alocar Memória...");
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
    int i, j, sub;
    for (i = 0, j = i + 1; j < tam; i++, j++)
    {
        sub = *(p + j) - *(p + i);

        if (sub % 2 == 0)
        {
            aloca(pares, qtdpares + 1);
            *(*pares + qtdpares) = sub;
            qtdpares++;
        }
    }

    return qtdpares;
}
