#include <stdio.h>

int main()
{
    int num1, num2;

    scanf("%i\n%i", &num1, &num2);

    printf("%i equivale a %i\n%i equivale a %i\n", &num1, num1, &num2, num2);


    if(&num1 > &num2)
    {
        printf("%i", &num1);
    }
    else
    {
        printf("%i", &num2);
    }

    return 0;
}
