/*

Fazer um programa de Sistema de Reserva de Ingressos para Jogos. Iniciar a quantidade de ingressos com 100. Em seguida, fazer o menu para:

[1] Cadastrar Jogo: receber os dados do jogo e guardar no arquivo. Cadastrar um jogo de cada vez;

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
void cadastraJogo(void);
void comprarIngresso(void);
void devolucaoIngresso(void);
int buscaJogo(int id, int ingressos);
int buscaTorcedor(char *cpf);
void atualizaJogo(int id, int ingressos, int type);
void atualizaTorcedor(char *cpf);
void cadastraTorcedor(int id, int ingressos);
void buscaJogoEspecifico(Jogo *pJogo, int id);
void buscaTorcedorEspecifico(Torcedor *pTorcedor, char *cpf);
void mostraJogos(void);
void mostraTorcedores(void);

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
                cadastraJogo();

                break;
            }
            case 2:
            {
                comprarIngresso();

                break;
            }
            case 3:
            {
                devolucaoIngresso();

                break;
            }
            case 4:
            {

                mostraTorcedores();

                break;
            }
            case 5:
            {

                mostraJogos();
                
                break;
            }
            case 6:
            {
                continue;
            }
        }

        printf("\n");

        system("pause");

    } while(op != 6);

    return 0;
}

void alocaJogo(Jogo **pJogo, int q) {

    *pJogo = (Jogo*) realloc(*pJogo, (q * sizeof(Jogo)));

    if(*pJogo == NULL) {
        exit(1);
    }
}

void alocaTorcedor(Torcedor **pTorcedor, int q) {

    *pTorcedor = (Torcedor*) realloc(*pTorcedor, (q * sizeof(Torcedor)));

    if(*pTorcedor == NULL) {
        exit(1);
    }
}

void cadastraJogo(void) {

    Jogo *pJogo = NULL;

    alocaJogo(&pJogo, 1);

    FILE *fptr = NULL;

    fptr = fopen("jogos.bin", "ab");

    if(fptr == NULL) exit(1);

    fseek(fptr, 0, 2);

    long int bytes = ftell(fptr);

    int id = bytes / sizeof(Jogo);

    pJogo->ID = id + 1;

    printf("Nome do jogo: ");
    fflush(stdin);
    gets(pJogo->nomeJogo);

    pJogo->ingressos = 100;

    pJogo->valor = (id + 1) * 10;

    fwrite(pJogo, sizeof(Jogo), 1, fptr);

    fclose(fptr);
}

void comprarIngresso(void) {

    int auxID, auxIngresso;

    mostraJogos();

    printf("\nID do jogo: ");
    scanf("%d", &auxID);

    printf("\nIngressos: ");
    scanf("%d", &auxIngresso);

    int retornoBuscaJogo = buscaJogo(auxID, auxIngresso);

    if(retornoBuscaJogo == -1) {
        printf("\nJogo Invalido. Encerrando a operacao\n");
    } else {

        atualizaJogo(auxID, auxIngresso, 1);

        cadastraTorcedor(auxID, auxIngresso);

        printf("\nTorcedor cadastrado\n");
    }
}

void devolucaoIngresso(void) {

    char auxCPF[13];

    printf("\nCPF do desistente: ");
    fflush(stdin);
    gets(auxCPF);

    int retornoBuscaTorcedor = buscaTorcedor(auxCPF);

    if(retornoBuscaTorcedor == -1) {
        printf("\nCPF invalido. Encerrando a operacao.\n");
    } else {

        Torcedor *pTorcedor = NULL;

        alocaTorcedor(&pTorcedor, 1);

        buscaTorcedorEspecifico(pTorcedor, auxCPF);

        atualizaJogo((pTorcedor->jogoID), (pTorcedor->qtdIngressos), -1);

        atualizaTorcedor(auxCPF);

        printf("\nDesistencia realizada\n");
    }
}

int buscaJogo(int id, int ingressos) {

    Jogo *pJogo = NULL;

    alocaJogo(&pJogo, 1);

    FILE *fptr = NULL;

    fptr = fopen("jogos.bin", "rb");

    if(fptr == NULL) {

        printf("\nNao ha jogos cadastrados\n");

        fclose(fptr);

        return -1;

    } else {

        fseek(fptr, 0, 2);

        long int bytes = ftell(fptr);

        int qtdJogos = bytes / sizeof(Jogo);

        for(int i = 0; i < qtdJogos; i++) {

            fseek(fptr, (i * sizeof(Jogo)), 0);

           fread(pJogo, sizeof(Jogo), 1, fptr);

           if(pJogo->ID == id && ingressos <= pJogo->ingressos) {

                fclose(fptr);

                return 1;
           }
        }

        fclose(fptr);

        return -1;
    }
}

int buscaTorcedor(char *cpf) {

    Torcedor *pTorcedor = NULL;

    alocaTorcedor(&pTorcedor, 1);

    FILE *fptr = NULL;

    fptr = fopen("torcedores.bin", "rb");

    if(fptr == NULL) {

        printf("\nNao ha torcedores cadastrados\n");

        fclose(fptr);

        return -1;

    } else {

        fseek(fptr, 0, 2);

        long int bytes = ftell(fptr);

        int qtdTorcedores = bytes / sizeof(Torcedor);

        for(int i = 0; i < qtdTorcedores; i++) {

            fseek(fptr, (i * sizeof(Torcedor)), 0);

            fread(pTorcedor, sizeof(Torcedor), 1, fptr);

            if(strcmp((pTorcedor->CPF), cpf) == 0) {

                fclose(fptr);

                return 1;
            }
        }

        fclose(fptr);

        return -1;
    }
}

void atualizaJogo(int id, int ingressos, int type) {

    Jogo *pJogo = NULL;

    alocaJogo(&pJogo, 1);

    FILE *fptr = NULL;

    fptr = fopen("jogos.bin", "rb+");

    fseek(fptr, 0, 2);

    long int bytes = ftell(fptr);

    int qtdJogos = bytes / sizeof(Jogo);

    for(int i = 0; i < qtdJogos; i++) {

        fseek(fptr, (i * sizeof(Jogo)), 0);

        fread(pJogo, sizeof(Jogo), 1, fptr);

        if(pJogo->ID == id) {

            if(type == 1) {
                pJogo->ingressos -= ingressos;
            } else if (type == -1) {
                pJogo->ingressos += ingressos;
            }
            

            fseek(fptr, (i * sizeof(Jogo)), 0);

            fwrite(pJogo, sizeof(Jogo), 1, fptr);
        }
    }

    fclose(fptr); 
}

void atualizaTorcedor(char *cpf) {

    Torcedor *pTorcedor = NULL;

    alocaTorcedor(&pTorcedor, 1);

    FILE *fptr = NULL;

    fptr = fopen("torcedores.bin", "rb+");

    fseek(fptr, 0, 2);

    long int bytes = ftell(fptr);

    int qtdTorcedores = bytes / sizeof(Torcedor);

    for(int i = 0; i < qtdTorcedores; i++) {

        fseek(fptr, (i * sizeof(Torcedor)), 0);

        fread(pTorcedor, sizeof(Torcedor), 1, fptr);

        if(strcmp((pTorcedor->CPF), cpf) == 0) {

            pTorcedor->status = 0;

            fseek(fptr, (i * sizeof(Torcedor)), 0);

            fwrite(pTorcedor, sizeof(Torcedor), 1, fptr);

            break;
        }
    }

    fclose(fptr);
}

void cadastraTorcedor(int id, int ingressos) {

    char auxCPF[13];

    printf("\nCPF: ");
    fflush(stdin);
    gets(auxCPF);

    Jogo *pJogo = NULL;

    alocaJogo(&pJogo, 1);

    buscaJogoEspecifico(pJogo, id);

    Torcedor *pTorcedor = NULL;

    alocaTorcedor(&pTorcedor, 1);

    FILE *fptr = NULL;

    fptr = fopen("torcedores.bin", "ab");

    if(fptr == NULL) exit(1);

    pTorcedor->jogoID = id;
    strcpy((pTorcedor->CPF), auxCPF);
    strcpy((pTorcedor->jogo), (pJogo->nomeJogo));
    pTorcedor->pagamento = (ingressos * (pJogo->valor));
    pTorcedor->qtdIngressos = ingressos;
    pTorcedor->status = 1;

    fwrite(pTorcedor, sizeof(Torcedor), 1, fptr);

    fclose(fptr);
}

void buscaJogoEspecifico(Jogo *pJogo, int id) {

    FILE *fptr = NULL;

    fptr = fopen("jogos.bin", "rb");

    fseek(fptr, 0, 2);

    long int bytes = ftell(fptr);

    int qtdJogos = bytes / sizeof(Jogo);

    for(int i = 0; i < qtdJogos; i++) {

        fseek(fptr, (i * sizeof(Jogo)), 0);

        fread(pJogo, sizeof(Jogo), 1, fptr);

        if(pJogo->ID == id) {

            break;
        }
    }

    fclose(fptr);
}

void buscaTorcedorEspecifico(Torcedor *pTorcedor, char *cpf) {

    FILE *fptr = NULL;

    fptr = fopen("torcedores.bin", "rb");

    fseek(fptr, 0, 2);

    long int bytes = ftell(fptr);

    int qtdTorcedores = bytes / sizeof(Torcedor);

    for(int i = 0; i < qtdTorcedores; i++) {

        fseek(fptr, (i * sizeof(Torcedor)), 0);

        fread(pTorcedor, sizeof(Torcedor), 1, fptr);

        if(strcmp((pTorcedor->CPF), cpf) == 0) {

            break;
        }
    }

    fclose(fptr);
}

void mostraJogos(void) {

    Jogo *pJogo = NULL;

    alocaJogo(&pJogo, 1);

    FILE *fptr = NULL;

    fptr = fopen("jogos.bin", "rb");

    if(fptr == NULL) {

        printf("\nNao ha jogos cadastrados\n");

    } else {

        fseek(fptr, 0, 2);

        long int bytes = ftell(fptr);

        int qtdJogos = bytes / sizeof(Jogo);

        for(int i = 0; i < qtdJogos; i++) {

            fseek(fptr, (i * sizeof(Jogo)), 0);

            fread(pJogo, sizeof(Jogo), 1, fptr);

            printf("\n===========================================\n");

            printf("\nID do jogo: %d", pJogo->ID);
            printf("\nNome do Jogo: %s", pJogo->nomeJogo);
            printf("\nIngressos: %d", pJogo->ingressos);
            printf("\nValor de cada ingresso: %.2f\n", pJogo->valor);
        }

        printf("\n===========================================\n");
    }

    fclose(fptr);
}

void mostraTorcedores(void) {

    Torcedor *pTorcedor = NULL;

    alocaTorcedor(&pTorcedor, 1);

    FILE *fptr = NULL;

    fptr = fopen("torcedores.bin", "rb");

    if(fptr == NULL) {

        printf("\nNao ha torcedores cadastrados\n");

    } else {

        fseek(fptr, 0, 2);

        long int bytes = ftell(fptr);

        int qtdTorcedores = bytes / sizeof(Torcedor);

        for(int i = 0; i < qtdTorcedores; i++) {

            fseek(fptr, (i * sizeof(Torcedor)), 0);

            fread(pTorcedor, sizeof(Torcedor), 1, fptr);

            printf("\n===========================================\n");

            printf("\nCPF: %s", pTorcedor->CPF);
            printf("\nID do jogo: %d", pTorcedor->jogoID);
            printf("\nNome do Jogo: %s", pTorcedor->jogo);
            printf("\nIngressos: %d", pTorcedor->qtdIngressos);
            printf("\nPagamento: %.2f", pTorcedor->pagamento);
            printf("\nStatus: %s\n", pTorcedor->status == 1 ? "Ativo" : "Inativo");
        }

        printf("\n===========================================\n");
    }

    fclose(fptr);
}
