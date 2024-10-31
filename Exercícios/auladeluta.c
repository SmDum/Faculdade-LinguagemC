#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Definição das structs ----------------------------------------------

// Estrutura para armazenar informações sobre as aulas de dança
typedef struct dance
{
    int reg_aula;    // Registro da aula (identificador)
    int qtd_aluno;   // Quantidade de alunos matriculados na aula
    char modalidade; //[B]allet ou [S]apateado
    char turno;      //[M]anhã, [T]arde ou [N]oite
    float valor;     // Valor da aula
} dance;

// Estrutura para armazenar informações sobre os alunos
typedef struct aluno
{
    char CPF[13];    // CPF do aluno
    char nome[80];   // Nome do aluno
    int num_aula;    // Número do registro da aula em que o aluno está matriculado
} aluno;

// Declarações das Funções de Alocação --------------------------------

// Função para alocar memória para o array de alunos
void aloca_aluno(aluno **p_aluno, int qtd_aluno);

// Função para alocar memória para o array de aulas de dança
void aloca_dance(dance **p_dance, int qtd_dance);

// Declarações das Funções de Cadastro --------------------------------

// Função para cadastrar um novo aluno
void cadastra_aluno(aluno *p_aluno, int qtd_aluno, dance *p_dance, int qtd_dance);

// Função para cadastrar as aulas de dança
void cadastra_dance(dance *p_dance, int qtd_dance);

// Declaração da Função de Busca --------------------------------------

// Função para buscar uma aula com base no turno e modalidade
int busca_dance(dance *p_dance, int qtd_dance, char aux_turno, char aux_modalidade);

// Declarações das Funções de Exibição --------------------------------

// Função para mostrar informações dos alunos cadastrados
void mostra_aluno(aluno *p_aluno, int qtd_aluno);

// Função para mostrar informações das aulas cadastradas
void mostra_dance(dance *p_dance, int qtd_dance);

// Função Principal ---------------------------------------------------

int main()
{
    setlocale(LC_ALL, "portuguese"); // Define o idioma para português
    dance *p_dance = NULL;           // Ponteiro para o array de aulas de dança
    aluno *p_aluno = NULL;           // Ponteiro para o array de alunos
    int opc, qtd = 6, cont = 0;      // Variáveis para opção do menu, quantidade de aulas e contador de alunos

    aloca_dance(&p_dance, qtd);      // Aloca memória para o array de aulas de dança
    cadastra_dance(p_dance, qtd);    // Cadastra as informações das aulas de dança

    do
    {
        // Menu de opções
        printf("[1] - Cadastro de Aluno\n[2] - Mostrar Alunos\n[3] - Fim\nOpção: ");
        scanf("%i", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            mostra_dance(p_dance, qtd);          // Mostra as aulas cadastradas
            aloca_aluno(&p_aluno, cont + 1);     // Aloca memória para o próximo aluno
            cadastra_aluno(p_aluno, cont, p_dance, qtd); // Cadastra o aluno
            cont++;                              // Incrementa o contador de alunos
            system("pause");
            system("cls");
            break;

        case 2:
            mostra_aluno(p_aluno, cont); // Mostra informações dos alunos cadastrados
            system("pause");
            system("cls");
            break;

        default:
            break;
        }

    } while (opc != 3); // Continua até que o usuário escolha a opção "Fim"

    // Libera a memória alocada para os arrays de alunos e aulas
    free(p_aluno);
    free(p_dance);

    return 0;
}

// Função para Alocar Memória para Alunos -----------------------------

void aloca_aluno(aluno **p_aluno, int qtd_aluno)
{
    // Realoca memória para o array de alunos com a nova quantidade
    if ((*p_aluno = (aluno *)realloc(*p_aluno, qtd_aluno * sizeof(aluno))) == NULL)
    {
        printf("\nErro ao alocar memória...");
        exit(1); // Encerra o programa em caso de erro
    }
}

// Função para Alocar Memória para Aulas ------------------------------

void aloca_dance(dance **p_dance, int qtd_dance)
{
    // Realoca memória para o array de aulas de dança
    if ((*p_dance = (dance *)realloc(*p_dance, qtd_dance * sizeof(dance))) == NULL)
    {
        printf("\nErro ao alocar memória...");
        exit(1); // Encerra o programa em caso de erro
    }
}

// Função para Cadastrar Alunos ---------------------------------------

void cadastra_aluno(aluno *p_aluno, int qtd_aluno, dance *p_dance, int qtd_dance)
{
    char aux_modalidade, aux_turno;

    // Coleta informações do aluno
    printf("\nNome: ");
    fgets(p_aluno->nome, 80, stdin);
    fflush(stdin);

    printf("\nCPF: ");
    fgets(p_aluno->CPF, 13, stdin);
    fflush(stdin);

    // Seleciona modalidade da aula
    printf("\nModalidade\n[B] - Ballet\n[S] - Sapateado\nOpção: ");
    scanf("%c", &aux_modalidade);
    fflush(stdin);
    aux_modalidade = toupper(aux_modalidade);

    // Seleciona turno da aula
    printf("\nTurno\n[M] - Manhã\n[T] - Tarde\n[N] - Noite\nOpção: ");
    scanf("%c", &aux_turno);
    fflush(stdin);
    aux_turno = toupper(aux_turno);

    // Busca a aula correspondente
    p_aluno->num_aula = busca_dance(p_dance, qtd_dance, aux_turno, aux_modalidade);

    // Exibe mensagem conforme o resultado da busca
    if (p_aluno->num_aula == -1)
    {
        printf("\nTipo de Aula não Encontrada...");
    }
    else
    {
        printf("\nCadastro Realizado com Sucesso! Seja bem-vindo!\n Sua aula é: %i.\nValor: %.2f\n\n\n", 
               (p_aluno->num_aula) + 1, (p_dance + (p_aluno->num_aula))->valor);
    }
}

// Função para Cadastrar Aulas de Dança -------------------------------

void cadastra_dance(dance *p_dance, int qtd_dance)
{
    int i;

    for (i = 0; i < qtd_dance; i++, p_dance++)
    {
        p_dance->qtd_aluno = 0;       // Inicializa quantidade de alunos
        p_dance->reg_aula = i + 1;    // Define o registro da aula

        // Define modalidade e turno com base no índice
        switch (i)
        {
        case 0:
            p_dance->modalidade = 'B';
            p_dance->turno = 'M';
            break;
        case 1:
            p_dance->modalidade = 'B';
            p_dance->turno = 'T';
            break;
        case 2:
            p_dance->modalidade = 'B';
            p_dance->turno = 'N';
            break;
        case 3:
            p_dance->modalidade = 'S';
            p_dance->turno = 'M';
            break;
        case 4:
            p_dance->modalidade = 'S';
            p_dance->turno = 'T';
            break;
        case 5:
            p_dance->modalidade = 'S';
            p_dance->turno = 'N';
            break;
        }

        // Define valor com base no turno
        switch (p_dance->turno)
        {
        case 'M':
            p_dance->valor = 300;
            break;
        case 'T':
            p_dance->valor = 250;
            break;
        case 'N':
            p_dance->valor = 350;
            break;
        }
    }
}

// Função para Buscar Aula por Turno e Modalidade ---------------------

int busca_dance(dance *p_dance, int qtd_dance, char aux_turno, char aux_modalidade)
{
    int i;

    // Percorre as aulas cadastradas
    for (i = 0; i < qtd_dance; i++, p_dance++)
    {
        // Verifica se a aula tem o turno e modalidade especificados
        if (p_dance->modalidade == aux_modalidade && p_dance->turno == aux_turno)
        {
            p_dance->qtd_aluno++; // Incrementa a quantidade de alunos
            return i;             // Retorna o índice da aula encontrada
        }
    }
    return -1; // Retorna -1 se a aula não foi encontrada
}

// Função para Mostrar Alunos -----------------------------------------

void mostra_aluno(aluno *p_aluno, int qtd_aluno)
{
    int i;

    // Percorre o array de alunos e exibe suas informações
    for (i = 0; i < qtd_aluno; i++, p_aluno++)
    {
        printf("\nNome: %s\nCPF: %s\nNúmero de Aula: %i", p_aluno->nome, p_aluno->CPF, p_aluno->num_aula);
        printf("\n\n\n");
    }
}

// Função para Mostrar Aulas ------------------------------------------

void mostra_dance(dance *p_dance, int qtd_dance)
{
    int i;

    // Percorre o array de aulas e exibe suas informações
    for (i = 0; i < qtd_dance; i++, p_dance++)
    {
        printf("\nRegistro da Aula: %i\nModalidade: %c\nTurno: %c\nQtd de Alunos: %i\nValor: %.2f", 
               p_dance->reg_aula, p_dance->modalidade, p_dance->turno, p_dance->qtd_aluno, p_dance->valor);
        printf("\n\n\n");
    }
}
