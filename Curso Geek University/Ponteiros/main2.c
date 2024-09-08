#include <stdio.h>

int main()
{
    int v[5];

    for(int i=0; i<5; i++)
    {
        scanf("%i", &v[i]);
    }

    for(int i=0; i<5; i++)
    {
        printf("\nO dobro de %i equivale a %i\n", *(v+i), *(v+i)*2);
    }

    return 0;
}
