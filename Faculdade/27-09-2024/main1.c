#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
        char nome[20];
        int idade;
        float nota;
}aluno;

aluno cadastro();

int main()
{

    aluno alu[10];
    char op;
    int cont=0;

    do
    {
        if(cont<10)
        {
            alu[cont]=cadastro();
            cont++;
        }
        else
        {
            printf("\nCadastro Lotado\n");
        }

        printf("\nDeseja Continuar <S/N>: ");
        scanf(" %c", &op);
        fflush(stdin);

    } while (op=='s'||op=='S');

    system("cls");

    int i;
    for(i=0; i<cont; i++)
    {
        printf("\nAluno %i\nNome: %s\nIdade: %i\nNota: %.2f\n", i+1, alu[i].nome, alu[i].idade, alu[i].nota);
    }


    return 0;
}

aluno cadastro()
{
    aluno x;
    printf("\nNome : ");
    gets(x.nome);
    fflush(stdin);
    printf("\nIdade : ");
    scanf("%i", &(x.idade));
    fflush(stdin);
    printf("\nNota: ");
    scanf("%f",  &(x.nota));
    fflush(stdin);
    printf("\n\n\n");
}
