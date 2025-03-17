#include <stdio.h>


insert_sort(int vetor[], int tam)
{
    int troca;

    for(int i=1; i<tam; i++)
    {
        int proximo = i;

        while((proximo != 0) && (vetor[proximo] < vetor[proximo-1]))
        {
            troca = vetor[proximo];
            vetor[proximo] = vetor[proximo-1];
            vetor[proximo-1] = troca;
            proximo--;
        }
    }
}

int main()
{

    int vetor[6] = {8, 3, 1, 42, 12, 5};
    
    insert_sort(vetor, 6);

    for(int i = 0; i<6; i++)
    {
        printf("%i\n", vetor[i]);
    }
    
    return 0;
}