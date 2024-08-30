#include <stdio.h>
#include <string.h>

void inverterString(const char str[], char strInvertida[]);

int main() {
    char str[100]; // Declara um array para armazenar a string original
    char strInvertida[100]; // Declara um array para armazenar a string invertida

    // Solicitar ao usuário a string
    printf("Digite uma string (máximo 99 caracteres): ");
    fgets(str, sizeof(str), stdin); // Lê a string do usuário, incluindo espaços

    // Remover o caractere de nova linha, se presente
    size_t len = strlen(str); // Calcula o comprimento da string
    if (len > 0 && str[len - 1] == '\n') { // Verifica se o último caractere é '\n'
        str[len - 1] = '\0'; // Substitui '\n' por '\0' para terminar a string corretamente
    }

    // Inverter a string e armazenar na string auxiliar
    inverterString(str, strInvertida);

    // Exibir o resultado
    printf("Resultado: %s\n", strInvertida);

    return 0; // Finaliza o programa com sucesso
}

void inverterString(const char str[], char strInvertida[])
{
    int comprimento = strlen(str); // Calcula o comprimento da string original
    int inicio = 0; // Inicializa o ponteiro para o início da string
    int fim = comprimento - 1; // Inicializa o ponteiro para o final da string

    // Inverter a string e armazenar no array strInvertida
    while (inicio < comprimento) {
        strInvertida[inicio] = str[fim]; // Copia o caractere da posição fim para a posição inicio
        inicio++;
        fim--;
    }
    strInvertida[comprimento] = '\0'; // Adiciona o caractere nulo no final da string invertida
}