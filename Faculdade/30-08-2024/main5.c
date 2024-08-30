#include <stdio.h>
#include <string.h>

int acharLetra(char letra , char str[100]);

int main()
{
    char str[100], letra;

    printf("Digite uma Frase (ate 99 caracteres): ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    fflush(stdin);   
    printf("Digite um Letra: ");
    scanf("%c" , &letra);

    int res = acharLetra(letra, str);
    
    printf("A frase '%s' contem %i %c.", str, res, letra);

    return 0;
}

int acharLetra(char letra , char str[100])
{
    int inicio = 0;
    int comprimento = strlen(str);
    int fim = comprimento - 1;
    int cont = 0;

    for (; inicio<fim; inicio++)
    {
        if(str[inicio] == letra)
        {
            cont++;
        }
    }

    return cont;
}