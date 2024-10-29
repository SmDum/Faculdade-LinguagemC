/*
Sistema de Reserva de Passagens Aéreas
Desenvolva um programa para uma agência de viagens que faz reservas de voos. O avião possui 100 assentos, sendo 10 na primeira classe e 90 na classe econômica.
•	[1] Nova Reserva - Cadastrar passageiros, pedindo o nome, classe (primeira ou econômica) e número do voo. O programa deve alocar dinamicamente uma estrutura para armazenar os dados e atribuir assento disponível. Para a classe econômica, priorizar assentos próximos.
•	[2] Cancelamento de Reserva - Permitir o cancelamento de uma reserva, liberando o assento correspondente.
•	[3] Relatório de Voos - Apresentar um relatório completo dos passageiros por voo, incluindo classe e assento.
c
Copiar código
struct passageiro {
    char CPF[13];
    char nome[80];
    char classe; // 'P' Primeira, 'E' Econômica
    int assento;
};

struct voo {
    int num_poltrona;
    char status;
    char tipo;
};
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct passageiro {
    char CPF[13];
    char nome[80];
    char classe; // 'P' Primeira, 'E' Econômica
    int assento;
}passageiro;

typedef struct voo {
    int num_poltrona;
    char status;
    char tipo;
}voo;

void aloca_passageiro(passageiro **p_passageiro, int qtd_assentos);
void aloca_voo(voo **p_voo, int qtd_assentos);

void cadastra_passageiro(passageiro *p_passageiro, voo *p_voo, int qtd_assentos);
void cadastra_voo(voo *p_voo, int qtd_assentos);

int busca_passageiro(passageiro *p_passageiro, int qtd_passageiro);
int busca_assento(voo *p_voo, int qtd_assentos);

void cancelamento(passageiro *p_passageiro, voo *p_voo, int qtd_assentos);

void mostra_poltronas(voo p_voo, int qtd_assentos);
void mostra_passageiros(passageiro *p_passageiro, voo *p_voo, int qtd_assentos);


int main()
{
    setlocale (LC_ALL, "portuguese");
    
    passageiro *p_passageiro = NULL;
    voo *p_voo = NULL;
    int opc, cont = 0, qtd_assentos = 100;

    aloca_voo(&p_voo, qtd_assentos);
    cadastra_voo(p_voo, qtd_assentos);

    do
    {   
        printf("[1] - Cadastro\n[2] - Cancelamento\n[3] - Mostrar Assentos\n[4] - Mostrar Passageiros\n[5] - Fim");
        scanf("%i", &opc);
        
        switch (opc)
        {
        case 1:
            aloca_passageiro(&p_passageiro, cont+1);
            cadastra_passageiro(p_passageiro+cont, p_voo, qtd_assentos);
            cont++;
            system("pause");
            system("cls");
            break;
        
        case 2:
            cancelamento(p_passageiro+cont, p_voo, qtd_assentos);
            system("pause");
            system("cls");
            break;
        
        case 3:
            mostra_poltronas(p_voo, qtd_assentos);
            system("pause");
            system("cls");
            break;
        
        case 4:
            mostra_passageiros(p_passageiro, p_voo, qtd_assentos);
            system("pause");
            system("cls");
            break;
        
        default:
            break;
        }
    } while (opc!=5);
    
    free(*p_passageiro);
    free(*p_voo);

    return 0;
}

void aloca_passageiro(passageiro **p_passageiro, int qtd_assentos)
{
    if((*p_passageiro=(passageiro *)realloc(*p_passageiro, qtd_assentos*sizeof(passageiro)))==NULL)
    {
        printf("\nErro ao alocar memória...");
        exit(1);
    }
}

void aloca_voo(voo **p_voo, int qtd_assentos)
{
    if((*p_voo = (voo *)realloc(*p_voo,qtd_assentos*sizeof(voo)))==NULL)
    {
        printf("\nErro ao alocar memória...");
        exit(1);
    }
}

void cadastra_passageiro(passageiro *p_passageiro, voo *p_voo, int qtd_assentos)
{

}

void cadastra_voo(voo *p_voo, int qtd_assentos)
{

}

int busca_passageiro(passageiro *p_passageiro, int qtd_passageiro, char aux_CPF)
{

}

int busca_assento(voo *p_voo, int qtd_assentos, char tipo_assento)
{

}

void cancelamento(passageiro *p_passageiro, voo p_voo, int qtd_assentos)
{

}

void mostra_poltronas(voo p_voo, int qtd_assentos)
{

}

void mostra_passageiros(passageiro *p_passageiro, voo *p_voo, int qtd_assentos)
{

}