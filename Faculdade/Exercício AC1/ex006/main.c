#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int *num = NULL, cont = 0, qtdneg = 0, *numneg = NULL;
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
    qtdneg = negativos(num, cont, qtdneg, &numneg);

    printf("\n==============================\n");
    printf("\nNúmeros Digitados:\n");
    mostra(num, cont);
    printf("\nNúmeros Negativos:\n");
    mostra(numneg, qtdneg);

    free(num);
    free(numneg);

    return 0;
}

void aloca(int **p, int tam)
{
    if ((*p = (int *)realloc(*p, tam * sizeof(int))) == NULL)
    {
        printf("\nErro de Alocação de Memória...\n");
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

int negativos(int *p, int tam, int qneg, int **nneg)
{
    int i, sub;

    for (i = 0; i < (tam / 2); i++)
    {
        sub = *(p + (tam - 1 - i)) - *(p + i);

        if (sub < 0)
        {
            aloca(nneg, qneg + 1);
            *(*nneg + qneg) = sub;
            qneg++;
        }
    }

    if (tam % 2 != 0)
    {
        int MeioEle = *(p + (tam / 2));
        if (MeioEle < 0)
        {
            aloca(nneg, qneg + 1);
            *(*nneg + qneg) = MeioEle;
            qneg++;
        }
    }

    return qneg;
}
