#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct st_arvore
{
    int valor;
    struct st_arvore *sad; // sub-árvore direita
    struct st_arvore *sae; // sub-árvore esquerda
};

typedef struct st_arvore arvore;

arvore *criaArvore()
{
    return NULL;
}

int arvoreEstaVazia(arvore *t)
{
    return t == NULL;
}

void mostraArvore(arvore *t)
{
    printf("<");
    if (!arvoreEstaVazia(t))
    {
        printf("%i", t->valor);
        mostraArvore(t->sae);
        mostraArvore(t->sad);
    }
    printf(">");
}

void insereDadoArvore(arvore **t, int num)
{
    if (*t == NULL)
    {
        *t = (arvore *)malloc(sizeof(arvore));
        (*t)->sae = NULL;
        (*t)->sad = NULL;
        (*t)->valor = num;
    }
    else
    {
        if (num < (*t)->valor)
        {
            insereDadoArvore(&(*t)->sae, num);
        }
        if (num > (*t)->valor)
        {
            insereDadoArvore(&(*t)->sad, num);
        }
    }
}

int estanaArvore(arvore *t, int num)
{
    if (arvoreEstaVazia(t))
    {
        return 0;
    }
    return t->valor == num || estanaArvore(t->sae, num) || estanaArvore(t->sad, num);
}

void liberaArvore(arvore *t)
{
    if (t != NULL)
    {
        liberaArvore(t->sae);
        liberaArvore(t->sad);
        free(t);
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    arvore *t = criaArvore();

    insereDadoArvore(&t, 12);
    insereDadoArvore(&t, 15);
    insereDadoArvore(&t, 10);
    insereDadoArvore(&t, 13);

    mostraArvore(t);

    if (arvoreEstaVazia(t))
    {
        printf("\n\nÁrvore Vazia!\n");
    }
    else
    {
        printf("\n\nÁrvore NÃO Vazia!\n");
    }

    if (estanaArvore(t, 15))
    {
        printf("\nO elemento 15 está na árvore!\n");
    }
    else
    {
        printf("\nO elemento 15 NÃO está na árvore!\n");
    }

    if (estanaArvore(t, 22))
    {
        printf("\nO elemento 22 está na árvore!\n");
    }
    else
    {
        printf("\nO elemento 22 NÃO está na árvore!\n");
    }

    liberaArvore(t);

    return 0;
}
