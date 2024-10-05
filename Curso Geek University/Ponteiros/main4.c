#include <stdio.h>
#include <locale.h>

#ifndef PI
#define PI 3.14567
#endif

// ifdef - Derivativa de Compilação

int main()
{
    setlocale(LC_ALL, "portuguese");
    int valor = 5;

    printf("O valor é %i\n", valor);
    printf("PI vale %f\n", PI);

#ifdef PI
    printf("O Valor de PI é %f\n", PI);
#endif

    return 0;
}
