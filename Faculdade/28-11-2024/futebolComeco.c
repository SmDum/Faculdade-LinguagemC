/*

Fazer um programa de Sistema de Reserva de Ingressos para Jogos. Alocar dinamicamente espaco e cadastrar 3 jogos, iniciar a quantidade de ingressos com 100. Em seguida, fazer o menu para:

[1] Cadastrar Jogo: receber os dados do jogo e guardar no arquivo

[2] Comprar Ingresso: Mostre todas as informacoes das structs jogos e em seguida receber o CPF, id do jogo e a quantidade de ingressos. Buscar o id do jogo e a quantidade de ingressos disponiveis para validar a compra. Apresentar o numero, nome do jogo e valor total a ser pago pelo cliente.

[3] Devolucao de Ingresso: devolve o ingresso pelo CPF do torcedor. Mostrar o nome do torcedor, o nome do jogo, a quantidade de ingressos que haviam sido reservados e valor total a ser devolvido para o torcedor.

[4] Mostrar torcedores

[5] Mostrar Jogos

[6] Encerrar

struct jogo {
    int ID;
    char times[50];
    int ingressos;
    float valor;
}

struct torcedor {
    char CPF[13];
    char nome[80];
    int jogo;
    int qtdIngressos;
}

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jogo {
    int ID;
    char nomeJogo[50];
    int ingressos;
    float valor;
} Jogo;

typedef struct torcedor {
    char CPF[13];
    int jogoID;
    char jogo[50];
    int qtdIngressos;
    float pagamento;
    int status;
} Torcedor;

void alocaJogo(Jogo **pJogo, int q);
void alocaTorcedor(Torcedor **pTorcedor, int q);

int main() {

    int op;
    
    do {

        system("cls");
        printf("\n[1] Cadastrar Jogo");
        printf("\n[2] Comprar Ingresso");
        printf("\n[3] Devolucao de Ingresso");
        printf("\n[4] Mostrar Torcedores");
        printf("\n[5] Mostrar Jogos");
        printf("\n[6] Encerrar\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
            {

                break;
            }
            case 2:
            {

                break;
            }
            case 3:
            {

                break;
            }
            case 4:
            {

                break;
            }
            case 5:
            {

                break;
            }
            case 6:
            {
                continue;
            }
        }
        
    } while(op != 6);

    return 0;
}

void alocaJogo(Jogo **pJogo, int q) {

    *pJogo = (Jogo*) realloc(*pJogo, q * sizeof(Jogo));

    if(*pJogo == NULL) {
        exit(1);
    }
}

void alocaTorcedor(Torcedor **pTorcedor, int q) {

    *pTorcedor = (Torcedor*) realloc(*pTorcedor, (q * sizeof(Jogo)));

    if(*pTorcedor == NULL) {
        exit(1);
    }
}