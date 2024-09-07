#include <stdio.h>
#include <stdlib.h>

#define NUM_ALUNOS 100
#define NUM_NOTAS 2

void ler_notas(float *notas); //Cabeçalho da Função de Ler Notas
float calcular_media(float *notas); //Cabeçalho da Função de Calcular Média
void status(float media, int aluno); //Cabeçalho da Função de Status


int main()
{
    float *notas = (int *)malloc(NUM_ALUNOS * NUM_NOTAS * sizeof(int)); //Declaração da Variável Notas
    float *media = (int *)malloc(NUM_ALUNOS * sizeof(int)); //Declaração da Variável Média

    if(notas == NULL || media == NULL) //Verificação de Espaço na Memória
    {
        printf("\nErro ao alocar memoria...\n");
        return 1;
    }

    for(int i = 0; i<NUM_ALUNOS; i++) // Verificação de cada Aluno
    {
        ler_notas(notas+ i*NUM_NOTAS);
        *(media+i) = calcular_media(notas + i*NUM_NOTAS);
        status(*(media + i), i);
    }

    free(notas); //Limpeza da Memória Notas
    free(media); //Limpeza da Memória Média

    return 0;
}

ler_notas(float *notas)
{
    for(int i = 0; i<NUM_NOTAS; i++) //Verificação das Notas do Aluno
    {
        do
        {
           printf("\nDigite a nota %i do Aluno: " , i+1);
           scanf("%f", notas + i);
        }while(*(notas+i)<0 || *(notas+i)>10);
    }
}

float calcular_media(float *notas) //Cálculo da Média
{
    return  (*notas + *(notas + 1))/ 2;
}

void status(float media, int aluno) //Verificação de Status do Aluno
{
    if(media<4)
    {
        printf("\nAluno %i - Media %.2f - Reprovado\n", aluno+1, media);
    }
    else if(media>=4 && media<7)
    {
        printf("\nAluno %i - Media %.2f - EXAME\n", aluno+1, media);
    }
    else
    {
        printf("\nAluno %i - Media %.2f - APROVADO\n", aluno+1, media);
    }
}
