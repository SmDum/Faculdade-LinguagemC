#include <stdio.h>
#include <stdlib.h>

typedef struct agenda
{
    int reg;
    char nome[80];
    float nota;
} agenda;

agenda cadastro(agenda a[], int tam);

void mostra(agenda a[], int tam);

int main()
{
    int tam;

    printf("Digite o tamanho: ");
    scanf("%i", &tam);

    agenda ag[tam];

    printf("\n");

    cadastro(ag, tam);
    mostra(ag, tam);

    return 0;
}

agenda cadastro(agenda a[10], int tam)
{
    int i;
    static int reg = 24000;

    for (i = 0; i < tam; i++)
    {
        a[i].reg = reg;

        printf("RA: %i\n", a[i].reg );
        fflush(stdin);
        printf("Nome: ");
        gets(a[i].nome);
        fflush(stdin);
        printf("Nota: ");
        scanf("%f", &a[i].nota);
        fflush(stdin);
        printf("\n");
        reg++;
    }
}

void mostra(agenda a[10], int tam)
{
    int i;

    printf("\n====================\n\n");

    for (i = 0; i < tam; i++)
    {
        printf("RA: %i\n", a[i].reg);
        printf("Nome: %s\n", a[i].nome);
        printf("Nota: %.2f\n", a[i].nota);
        printf("\n====================\n\n");
    }
    printf("\n");
}
