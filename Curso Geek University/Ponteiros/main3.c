#include <stdio.h>
#include <locale.h>

#ifndef PI
#define PI 3.14567
#endif

// ifndef - Derivativa de Compilação

int main()
{
    setlocale(LC_ALL, "portuguese");
    int valor = 5;

    printf("O valor é %i\n", valor);
    printf("PI vale %f\n", PI);

    return 0;
}
