/*
Árvore Binária - Binary Tree

- São estruturas caraterizadas por:

- Ou, não tem elemento algum (árvore vazia);
- Ou tem um elemento distinto, denominado raiz, com dois apontamentos para duas estruturas diferentes, denominadas sub-árvore esquerda e sub-árvore direita;
*/

#include <stdio.h>
#include <stdlib.h>

struct st_arvore
{
    int valor;
    struct st_arvore *sad;
    struct st_arvore *sae;
};

typedef struct st_arvore arvore;

arvore* criaArvore()
{
    return NULL;
}

int arvoreEstaVazia(arvore* t)
{
    return t == NULL;
}

void mostraArvore(arvore* t)
{
    printf("<");
    if(!arvoreEstaVazia(t))
    {
        printf("%i " , t->valor);
        mostraArvore(t->sae);
        mostraArvore(t->sad);
    }
    printf(">");
}

void insereDadoArvore(arvore** t, int num)
{
    if(*t == NULL)
    {
        *t = (arvore*)malloc(sizeof(arvore));
        (*t)->sae = NULL;
        (*t)->sad = NULL;
        (*t)->valor = num;
    }
    else
    {
        if(num<(*t)->valor)
        {
            insereDadoArvore(&(*t)->sae, num);
        }
        if(num>(*t)->valor)
        {
            insereDadoArvore(&(*t)->sad, num);
        }
    }
}

int estaNaArvore(arvore* t, int num)
{
    if(arvoreEstaVazia(t))
    {
        return 0;
    }

    return t->valor == num || estaNaArvore(t->sae, num) || estaNaArvore(t->sad, num);

}


int main()
{

    arvore *t = criaArvore();

    insereDadoArvore(&t, 12);
    insereDadoArvore(&t, 15);
    insereDadoArvore(&t, 10);
    insereDadoArvore(&t, 13);
    mostraArvore(t);

    if(arvoreEstaVazia(t))
        printf("\nArvore vazia!");
    else
        printf("\nArvore nao vazia!");
    
    if(estaNaArvore(t, 15))
        printf("\nO elemento 15 pertence a arvore!");
    else
        printf("\nO elemento 15 nao pertence a arvore!");

    
    if(estaNaArvore(t, 22))
        printf("\nO elemento 22 pertence a arvore!");
    else
        printf("\nO elemento 22 nao pertence a arvore!");

    
    free(t);

    return 0;
}