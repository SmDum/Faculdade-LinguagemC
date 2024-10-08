#include <stdio.h>
#include <locale.h>

void aloca(int **p, int tam);
void recebe(int *p);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int tam = 5, *p = NULL, i;

    for (i = 0; i < tam; i++)
    {
        aloca(&p, i + 1);
        recebe(p + i);
    }

    for (i = 0; i < tam; i++)
    {
        printf("\n%i\n", *(p + i));
    }

    free(p);

    return 0;
}

void aloca(int **p, int tam)
{
    if ((*p = (int *)realloc(*p, tam * sizeof(int))) == NULL)
    {
        printf("\nErro ao alocar memória...\n");
        exit(1);
    }
}

void recebe(int *p)
{
    printf("\nDigite um Número: ");
    scanf("%i", p);
}
