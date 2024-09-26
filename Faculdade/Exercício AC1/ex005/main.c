#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void aloca(int **p, int tam);
void recebe(int *p);
void mostra(int *p, int tam);
int subpar(int *p, int tam, int qp, int **np);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int *num=NULL, cont=0, qtdpar=0, *numpar=NULL;
    char opc;

    do
    {
        aloca(&num, cont+1);
        recebe(num+cont);
        cont++;
        printf("\nDeseja Continuar <S/N>: ");
        scanf(" %c", &opc);
        fflush(stdin);

    }while(opc=='S' || opc=='s');

    system("cls");
    qtdpar = subpar(num, cont, qtdpar, &numpar);

    printf("\n==========================\n");
    printf("\nNúmeros Digitados:\n");
    mostra(num, cont);
    printf("\n==========================\n");
    printf("\nNúmeros Pares:\n");
    mostra(numpar, qtdpar);

    return 0;
}

void aloca(int **p, int tam)
{
    if((*p=(int*)realloc(*p, tam*sizeof(int)))==NULL)
    {
        printf("Erro ao Alocar Memória...");
        exit(1);
    }
}

void recebe(int *p)
{
    printf("\nDigite um Número: ");
    scanf("%i", p);
    fflush(stdin);
}

void mostra(int *p, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("\nNúmero Digitado: %i\nEndereço de Memória: %u\n" , *(p+i), (p+i));
    }
}

int subpar(int *p, int tam, int qp, int **np)
{
    int i, sub;

    for(i=tam-1; i>0; i-=2)
    {
        sub = *(p+i) - *(p+(i-1));

        if(sub%2==0)
        {
            aloca(np, qp+1);
            *(*np + qp) = sub;
            qp++;
        }
    }


        if(tam%2!=0)
        {
            int PriElemento = *(p+0);
            if(PriElemento%2==0)
            {
                aloca(np, qp+1);
                *(*np + qp) = PriElemento;
                qp++;
            }
        }

    return qp;
}
