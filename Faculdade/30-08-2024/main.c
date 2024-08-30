#include <stdio.h>
#include <string.h>

void InverterStrings(char v[100]);

int main()
{
    char str[100];

    printf("Digite uma Frase de ate 99 Caracteres: "); // Pedir a Frase
    fgets(str, sizeof(str), stdin); // Pega a Frase

    size_t len = sizeof(str); // Define o Tamanho da Frase

    if(len>0 && str[len-1] == '\n') //Se o tamanho for maior que 0 e o último for quebra de Linha , trocar por ENTER
    {
        str[len-1] = '\0';
    }

    InverterStrings(str); // Aplicação da Função

    printf("Resultado: %s\n", str); // Printar o Resultado

    return 0;
}

void InverterStrings(char str[100]) //Declaração da Função
{
    int comprimento = strlen(str); //Pega o Comprimento
    int inicio = 0; //Variável Inicial
    int fim = comprimento - 1; //Variável Final
    char temp; //Variável Temporárira

    for(; inicio<fim; inicio++, fim--)
    {
        temp = str[inicio]; // Atribui o Caractere Inicial a variável Temporária
        str[inicio] = str[fim]; //Passa o Primeiro Caractere pro Final
        str[fim] = temp; //Atribui o Caractere Final para a variável Temporária
    }
}