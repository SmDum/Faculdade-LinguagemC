#include <stdio.h>
#include <string.h>
#include <ctype.h> 

// Função para inverter uma string e alterar maiúsculas para minúsculas e vice-versa
void inverterEAlternarString(const char str[], char strAlterada[]); 

int main() {
    char str[100]; // Declara um array para armazenar a Palavra
    char strAlterada[100]; // Declara um array para armazenar a Palavra Invertida

    // Solicitar ao usuário a Frase
    printf("Digite uma string (máximo 99 caracteres): ");
    fgets(str, sizeof(str), stdin); // Lê a Frase do usuário, incluindo espaços

    // Remover o caractere de nova linha, se presente
    size_t len = strlen(str); // Calcula o comprimento da string
    if (len > 0 && str[len - 1] == '\n') { // Verifica se o último caractere é '\n'
        str[len - 1] = '\0'; // Substitui '\n' por '\0' para terminar a string corretamente
    }

    // Inverter a string e alternar maiúsculas/minúsculas
    inverterEAlternarString(str, strAlterada);

    // Exibir o resultado
    printf("Resultado: %s\n", strAlterada);

    return 0; // Finaliza o programa com sucesso
}

void inverterEAlternarString(const char str[], char strAlterada[])
{
    int comprimento = strlen(str); // Pega o Comprimento
    int inicio = 0; // Inicializa o começo da Palavra
    int fim = comprimento - 1; // Inicializa para o final da Palavra

    // Inverter a string e alternar maiúsculas/minúsculas
    while (inicio < comprimento) {
        char ch = str[fim]; // Obtém o caractere da posição fim

        // Alternar entre maiúsculas e minúsculas
        if (ch >= 'A' && ch <= 'Z') {
            strAlterada[inicio] = ch + 32; // Converte maiúscula para minúscula
        } else if (ch >= 'a' && ch <= 'z') {
            strAlterada[inicio] = ch - 32; // Converte minúscula para maiúscula
        } else {
            strAlterada[inicio] = ch; // Mantém caracteres não alfabéticos
        }

        inicio++;
        fim--;
    }
    strAlterada[comprimento] = '\0'; // Adiciona o caractere nulo no final da string alterada
}