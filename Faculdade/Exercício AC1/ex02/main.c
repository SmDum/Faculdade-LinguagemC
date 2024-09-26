#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void aloca(int **p, int tam);
void recebe(int *p);
void mostra(int *p, int tam);
int impares(int *p, int tam, int qtdimp, int **impar);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int *num = NULL, *numimpar = NULL, cont = 0, qtdimp = 0;
    char opc;

    do
    {
        aloca(&num, cont + 1);
        recebe(num + cont);
        printf("\nDeseja Continuar <S/N>: ");
        scanf(" %c", &opc);
        cont++;
        fflush(stdin);

    } while (opc == 's' || opc == 'S');

    system("cls");
    qtdimp = impares(num, cont, qtdimp, &numimpar);

    printf("\nNúmeros Digitados:\n");
    mostra(num, cont);
    printf("\n------------------------------------------------------------\n");
    printf("\nÍmpares:\n");
    mostra(numimpar, qtdimp);

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
    fflush(stdin);
}

void mostra(int *p, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf("\n%i\n", *(p + i));
    }
}

int impares(int *p, int tam, int qtdimp, int **impar)
{
    int i, soma;

    for (i = 0; i < (tam - 1); i += 2)
    {
        soma = *(p + i) + *(p + i + 1);

        if (soma % 2 != 0)
        {
            aloca(impar, qtdimp + 1);
            *(*impar + qtdimp) = soma;
            qtdimp++;
        }
    }

    if (tam % 2 != 0)
    {
        int ultEle = *(p + (tam - 1));
        if (ultEle % 2 != 0)
        {
            aloca(impar, qtdimp + 1);
            *(*impar + qtdimp) = ultEle;
            qtdimp++;
        }
    }

    return qtdimp;
}
