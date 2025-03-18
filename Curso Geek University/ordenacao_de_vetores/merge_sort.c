#include <stdio.h>

void merge(int vetor[], int inicio1, int fim1, int inicio2, int fim2)
{
    int temp[50];

    int i, j, k;
    i = inicio1;
    j = inicio2;
    k = 0;

    while (i <= fim1 && j <= fim2)
    {
        if (vetor[i] < vetor[j])
        {
            temp[k++] = vetor[i++];
        }
        else
        {
            temp[k++] = vetor[j++];
        }
    }

    while (i <= fim1)
    {
        temp[k++] = vetor[i++];
    }

    while (j <= fim2)
    {
        temp[k++] = vetor[j++];
    }

    for (i = inicio1, j = 0; i <= fim2; i++, j++)
    {
        vetor[i] = temp[j];
    }
}

void merge_sort(int vetor[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;

        merge_sort(vetor, inicio, meio);

        merge_sort(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, meio + 1, fim);
    }
}

int main()
{
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    merge_sort(vetor, 0, 6 - 1);

    for (int i = 0; i < 6; i++)
    {
        printf("%i\n", vetor[i]);
    }

    return 0;
}