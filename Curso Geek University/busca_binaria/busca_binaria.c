#include <stdio.h>

int busca_binaria(int vetor[], int chave, int tam)
{
    int inicio = 0;
    int fim = tam - 1;

    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;

        if (chave == vetor[meio])
        {
            return meio;
        }

        if (chave < vetor[meio])
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }
    }

    return -1;
}

int main()
{
    int vetor[6] = {1, 3, 5, 8, 12, 42};
    int chave = 12;

    int ret = busca_binaria(vetor, chave, 6);

    printf("\nO elemento %i esta na posicao %i", chave, ret);

    return 0;
}
