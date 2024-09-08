#include <stdio.h>

int main()
{
    int valor_int = 1;
    float valor_float = 1.1;
    char valor_char = 103;

    int *p_int;
    float *p_float;
    char *p_char;

    printf("Valor - Antes: %i\n" , valor_int);
    printf("Valor - Antes: %f\n" , valor_float);
    printf("Valor - Antes: %c\n" , valor_char);

    p_int = &valor_int;
    p_float = &valor_float;
    p_char = &valor_char;

    printf("Valor - Apos: %i\n" , valor_int);
    printf("Valor - Apos: %f\n" , valor_float);
    printf("Valor - Apos: %c\n" , valor_char);


    return 0;
}
