#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int qtd, soma = 0;

    printf("Quantos Números você quer somar? ");
    scanf("%i", &qtd);

    int i;

    for (i = 0; i < qtd; i++)
    {
        soma = soma + i * 2 + 3;
    }

    printf("A soma é %i", soma);

    return 0;
}
