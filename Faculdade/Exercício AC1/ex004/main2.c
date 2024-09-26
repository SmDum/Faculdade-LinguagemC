#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void aloca(int **p, int tam);
void recebe(int *p);
void mostra(int *p, int tam);
int impar(int *p, int tam, int qtdimpar, int **impar);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int *num = NULL, cont = 0, qtdimp = 0, *numimp = NULL;
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

    qtdimp = impar(num, cont, qtdimp, &numimp);

    printf("\nNúmeros Digitados:\n");
    mostra(num, cont);
    printf("\n-----------------------------\n");
    printf("\n Números Impares:\n");
    mostra(numimp, qtdimp);

    free(num);
    free(numimp);

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

int impar(int *p, int tam, int qtdimp, int **impar)
{
    int i, sub;

    for(i = 0; i<tam-1; i+=2)
    {
        sub = *(p+i) - *(p+i+1);

        if(sub%2!=0)
        {
            aloca(impar, qtdimp+1);
            *(*impar + qtdimp) = sub;
            qtdimp++;
        }
    }

    if(tam%2!=0)
    {
        int UltElemento = *(p+tam-1);

        if(UltElemento%2!=0)
        {
            aloca(impar, qtdimp+1);
            *(*impar + qtdimp) = UltElemento;
            qtdimp++;
        }
    }

    return qtdimp;
}
