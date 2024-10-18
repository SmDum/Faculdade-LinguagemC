#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct aluno {
    char *nome;
    char *RA;
    float *nota;
    float media;
} aluno;

void aloca_aluno(aluno **p_aluno, int qnt_alunos);
void aloca_char(char **p_aluno, int qnt_alunos);
void aloca_float(float **p_aluno, int qnt_alunos);
void cadastro_aluno(aluno *p_aluno);
aluno* busca_aluno(aluno *p_aluno, int qnt_alunos, char *ra_busca);
void controle(aluno *p_aluno);

int main() {
    setlocale(LC_ALL, "portuguese");
    aluno *alunos = NULL; // Renomeado para plural
    int cont = 0;
    int opc;
    char ra_busca[8]; // Aumentado para incluir o caractere nulo

    do {
        printf("[1] - Cadastro de Aluno\n[2] - Cadastro de Notas\n[3] - Sair\n");
        printf("\nOpção: ");
        scanf("%i", &opc);
        getchar(); // Limpa o buffer do teclado após scanf

        switch (opc) {
            case 1: {
                cont++;
                aloca_aluno(&alunos, cont);
                cadastro_aluno(&alunos[cont - 1]); // Passa o último aluno usando ponteiro
                break;
            }

            case 2: {
                printf("Digite o RA do aluno: ");
                scanf("%7s", ra_busca); // Limitar a 7 caracteres + '\0'
                getchar(); // Limpa o buffer do teclado

                aluno *p_encontrado = busca_aluno(alunos, cont, ra_busca);
                if (p_encontrado != NULL) {
                    controle(p_encontrado); // Passa o aluno encontrado diretamente
                } else {
                    printf("\nEsse RA não existe, tente novamente...\n");
                }
                break;
            }

            case 3:
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpção Inválida...\n");
        }
    } while (opc != 3);

    // Libera a memória alocada para cada aluno
    for (int i = 0; i < cont; i++) {
        free(alunos[i].nome);
        free(alunos[i].RA);
        free(alunos[i].nota);
    }
    free(alunos); // Libera a memória alocada para o array de alunos

    return 0;
}

void aloca_aluno(aluno **p_aluno, int qnt_alunos) {
    if ((*p_aluno = (aluno *)realloc(*p_aluno, qnt_alunos * sizeof(aluno))) == NULL) {
        printf("Erro ao Alocar Memória...");
        exit(1);
    }
}

void aloca_char(char **p_aluno, int qnt_alunos) {
    if ((*p_aluno = (char *)malloc(qnt_alunos * sizeof(char))) == NULL) {
        printf("Erro ao Alocar Memória...");
        exit(1);
    }
}

void aloca_float(float **p_aluno, int qnt_alunos) {
    if ((*p_aluno = (float *)malloc(qnt_alunos * sizeof(float))) == NULL) {
        printf("Erro ao Alocar Memória...");
        exit(1);
    }
}

void cadastro_aluno(aluno *p_aluno) {
    char nome_temp[80], ra_temp[8];

    printf("\nDigite o Nome do Aluno: ");
    fgets(nome_temp, sizeof(nome_temp), stdin);
    nome_temp[strcspn(nome_temp, "\n")] = '\0';
    aloca_char(&p_aluno->nome, strlen(nome_temp) + 1);
    strcpy(p_aluno->nome, nome_temp);

    printf("\nDigite o RA do Aluno: ");
    fgets(ra_temp, sizeof(ra_temp), stdin);
    ra_temp[strcspn(ra_temp, "\n")] = '\0';
    aloca_char(&p_aluno->RA, strlen(ra_temp) + 1);
    strcpy(p_aluno->RA, ra_temp);

    aloca_float(&p_aluno->nota, 2);
    p_aluno->nota[0] = 0.0;
    p_aluno->nota[1] = 0.0;
    p_aluno->media = 0.0;

    printf("\nCadastro Realizado com Sucesso!\n");
}

aluno* busca_aluno(aluno *p_aluno, int qnt_alunos, char *ra_busca) {
    for (int i = 0; i < qnt_alunos; i++) {
        // Usando ponteiros para acessar o RA
        if (strcmp((p_aluno + i)->RA, ra_busca) == 0) {
            return (p_aluno + i); // Retorna o ponteiro do aluno encontrado
        }
    }
    return NULL; // Retorna NULL se não encontrar
}

void controle(aluno *p_aluno) {
    printf("Aluno Encontrado: %s", p_aluno->nome);

    printf("\nDigite a Primeira Nota: ");
    scanf("%f", &p_aluno->nota[0]); // Passa o endereço da nota

    printf("\nDigite a Segunda Nota: ");
    scanf("%f", &p_aluno->nota[1]); // Passa o endereço da nota

    p_aluno->media = (p_aluno->nota[0] + p_aluno->nota[1]) / 2.0;

    printf("Notas atualizadas!\n");
    printf("Nota 1: %.2f, Nota 2: %.2f, Média: %.2f\n", p_aluno->nota[0], p_aluno->nota[1], p_aluno->media);
}
