#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Alocar dinamicamente a seqüência de números int digitados pelo usuário,
até que este escolha a opção Não. Em seguida, deve-se subtrair o último
do 1º, o penúltimo do 2º e assim por diante, e ir alocando dinamicamente
os números que tiverem como resultado da subtração o valor ÍMPAR.
Utilizar funções e ponteiros.
*/

void adicionarNumero(int **numeros, int *tamanho, int valor);
void subtracao(int *p, int tam, int **resultado, int *tamanhoResultado);
void mostra(int *p, int tam);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int *numeros = NULL;
    int tam = 0; 
    int valor; 
    int tam_R = 0; 
    int *resultado = NULL; 
    char opc; 

    do
    {
        printf("\nDigite um Numero: ");
        scanf("%d", &valor);
        adicionarNumero(&numeros, &tam, valor);
        tam++;
        printf("\nDeseja Continuar <S/N>: "); 
        scanf(" %c", &opc); 
        fflush(stdin); 
    } while (opc == 's' || opc == 'S');

    subtracao(numeros, tam, &resultado, &tam_R);

    if (tam_R > 0) {
        printf("\nResultados das subtrações ímpares:\n"); 
        mostra(resultado, tam_R);
    } else {
        printf("\nNenhuma subtração ímpar foi encontrada.\n");
    }

    free(numeros);
    free(resultado);

    return 0;
}


void adicionarNumero(int **numeros, int *tamanho, int valor)
{
    if((*numeros = (int *) realloc(*numeros, (*tamanho + 1) * sizeof(int)))==NULL)
    {
        printf("\nErro de alocação de memória!\n");
        exit(1);
    }
    
    *(*numeros + *tamanho) = valor;
}

void subtracao(int *p, int tam, int **resultado, int *tamanhoResultado)
{
    int *inicio = p; 
    int *fim = p + tam - 1;

    while (inicio < fim)
    {
        int dif = *fim - *inicio;

        if (dif % 2 != 0)
        {
            *resultado = (int *) realloc(*resultado, (*tamanhoResultado + 1) * sizeof(int));

            if (*resultado == NULL)
            {
                printf("\nErro de Alocação de Memoria...\n");
                exit(1);
            }

            *(*resultado + *tamanhoResultado) = dif;
            (*tamanhoResultado)++;
        }

        inicio++;
        fim--;
    }
}

void mostra(int *p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("\n%i\n", *(p + i));
    }
}
