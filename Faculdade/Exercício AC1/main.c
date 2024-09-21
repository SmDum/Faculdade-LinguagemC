#include <stdio.h>
#include <stdlib.h>

/*
Alocar dinamicamente a seqüência de números int digitados pelo usuário,
até que este escolha a opção Não. Em seguida, deve-se subtrair o último
do 1º, o penúltimo do 2º e assim por diante, e ir alocando dinamicamente
os números que tiverem como resultado da subtração o valor ÍMPAR.
Utilizar funções e ponteiros.
*/

// Declaração de funções
void adicionarNumero(int **numeros, int *tamanho, int valor);
void subtracao(int *p, int tam, int **resultado, int *tamanhoResultado);
void mostra(int *p, int tam);

int main()
{
    // Inicialização de variáveis
    int *numeros = NULL; // Ponteiro para armazenar os números digitados
    int tam = 0; // Tamanho atual do array de números
    int valor; // Variável para armazenar o número digitado pelo usuário
    int tam_R = 0; // Tamanho do array de resultados
    int *resultado = NULL; // Ponteiro para armazenar os resultados das subtrações
    char opc; // Variável para armazenar a opção do usuário

    // Loop para entrada de números
    do
    {
        printf("Digite um Numero: "); // Solicita que o usuário digite um número
        scanf("%d", &valor); // Lê o número digitado
        adicionarNumero(&numeros, &tam, valor); // Adiciona o número ao array de números
        printf("Deseja Continuar <S/N>: "); // Pergunta se o usuário quer continuar
        scanf(" %c", &opc); // Lê a opção do usuário
        fflush(stdin); // Limpa o buffer de entrada
    } while (opc == 's' || opc == 'S'); // Continua enquanto a opção for 's' ou 'S'

    // Chama a função de subtração e passa o tamanho do resultado por referência
    subtracao(numeros, tam, &resultado, &tam_R);

    // Exibe resultados apenas se tam_R for maior que zero
    if (tam_R > 0) {
        printf("Resultados das subtrações ímpares:\n"); // Mensagem antes de mostrar resultados
        mostra(resultado, tam_R); // Chama a função para mostrar os resultados
    } else {
        printf("Nenhuma subtração ímpar foi encontrada.\n"); // Mensagem se não houver resultados
    }

    // Liberar a memória alocada
    free(numeros); // Libera a memória do array de números
    free(resultado); // Libera a memória do array de resultados

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}

// Função para adicionar um número ao array dinamicamente
void adicionarNumero(int **numeros, int *tamanho, int valor)
{
    // Realoca memória para o array de números com espaço para um novo número
    *numeros = (int *) realloc(*numeros, (*tamanho + 1) * sizeof(int));
    // Verifica se a realocação foi bem-sucedida
    if (*numeros == NULL) {
        printf("Erro de alocação de memória!\n"); // Mensagem de erro
        exit(1); // Encerra o programa com erro
    }
    // Adiciona o novo número ao final do array
    *(*numeros + *tamanho) = valor;
    (*tamanho)++; // Atualiza o tamanho do array
}

// Função para calcular subtrações e armazenar resultados ímpares
void subtracao(int *p, int tam, int **resultado, int *tamanhoResultado)
{
    int *inicio = p; // Ponteiro para o início do array de números
    int *fim = p + tam - 1; // Ponteiro para o fim do array de números

    // Enquanto o ponteiro de início for menor que o de fim
    while (inicio < fim)
    {
        // Calcula a diferença entre o fim e o início
        int dif = *fim - *inicio;

        // Verifica se a diferença é ímpar
        if (dif % 2 != 0)
        {
            // Realoca memória para o array de resultados com espaço para um novo resultado
            *resultado = (int *) realloc(*resultado, (*tamanhoResultado + 1) * sizeof(int));
            // Verifica se a realocação foi bem-sucedida
            if (*resultado == NULL)
            {
                printf("Erro de Alocação de Memoria...");
                exit(1); // Encerra o programa com erro
            }

            // Armazena a diferença no array de resultados
            *(*resultado + *tamanhoResultado) = dif;
            (*tamanhoResultado)++; // Atualiza o tamanho do array de resultados
        }

        // Move os ponteiros para o próximo par de números a serem subtraídos
        inicio++;
        fim--;
    }
}

// Função para mostrar os resultados
void mostra(int *p, int tam)
{
    // Loop para imprimir todos os resultados
    for (int i = 0; i < tam; i++)
    {
        printf("%i\n", *(p + i)); // Imprime o resultado atual
    }
}
