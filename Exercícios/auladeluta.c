#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

typedef struct aluno {
    int id;
    char CPF[13];
    char nome[50];
    char turno;
}aluno;

typedef struct aa{

}aa;

void aloca_aluno(aluno **p_aluno, int qtd_aluno);
void aloca_aa(aa **p_aa, int qtd_aa);

void cadastra_aluno(aluno *p_aluno, int qtd_aluno,);

int main()
{

    return 0;
}
