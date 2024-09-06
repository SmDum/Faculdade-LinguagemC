#include <stdio.h>

int main()
{
    /*

    ===Chamada por Valor===

    ---Função Troca---

    int main()
    {
        int a, b;
        a = 10;
        b = 20;
        
        troca(a, b);

        return 0;
    }

    void troca(int x, int y)
    {
        int temp;
        temp = x;
        x = y;
        y = temp;
    }

    ================================================

    ===Chamada por Referência===

    ---Função Troca---

    int main()
    {
        int a, b;
        a = 10;
        b = 20;

        troca(&a, &b);

        return 0;
    }

    void troca(int *x,int *y)
    {
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }
    
     ================================================

     ---Alocação Dinâmica---

     malloc();
     calloc();
     realloc();
     free();

    *****Todos eles tem que usar biblioteca <stdlib.h>*****

    ----------

    malloc(); --> Função de alocação de memória em C. Tem que especificar o número de bytes necessarios. Ela localiza e reserva um bloco de memória de tamanho apropriado e retonra o enderço do primeiro byte desse bloco. Ela é do tipo Void, visto que se usa ponteiros genérios com ela. 

    Sintaxe: 

    void* malloc(tamanho);

    Devemos informar o tamanho do bloco que queremos guardar. Para isso, devemos usar a função chamada sizeof(), que fornece um inteiro, igual ao tamanho da variável que você precisa.

    Ex.1:

    char *ptr;
    ptr = (char*)malloc(1); ou ptr = (char*)malloc(sizeof(char));

    Melhor usar sizeof(), visto que a quantidade de bytes entre os diferentes sistemas operacionais são diferentes.

    Ex.2:
    
    char *ptr;
    if(ptr=(char*)malloc(8*sizeof(char))==NULL)
    {
        printf("\nErro");
    }

    Ex.3:
    
    int *ptr;
    if(ptr=(int*)malloc(2*sizeof(int))==NULL)
    {
        printf("\nErro");
    }

    Ex.4:
    
    double *ptr;
    if(ptr=(double*)malloc(sizeof(double))==NULL)
    {
        printf("\nErro");
    }
    
    ==========

    calloc(); --> Faz a mesma coisa que a malloc, só que não precisa fazer a conta para calcular o tamanho.

    ----------

    Ex.:

    int *ptr;
    if(ptr=(int*)malloc(2, sizeof(int))==NULL)
    {
        printf("\nErro");
    }

    ==========

    realloc(); --> Recebe um ponteiro e o tamanho. Se houver espaço suficiente para expandir o bloco de memória, a memória é realocada. Se não tiver espaço, ele cria um novo bloco do tamanho especificado e libera o espaço antigo. Se colocar 0 no tamanho, a função funciona como free();.

    ----------

    Sintaxe: 

    void* realloc(*ptr, tamanho);

    ----------

    Ex.1:

    1° Vez:

    int *ptr=NULL;
    if((ptr = int(int*)realloc(ptr,sizeof(int)))==NULL)
    {
        printf("\nErro");
    }

    2° Vez:

    if((ptr=(int*)realloc(ptr,2*sizeof(int)))==NULL)
    {
        printf("\nErro");
    }

    ==========

    free(); --> Libera espaço no bloco de memória.

    ----------

    Sintaxe:

    void* realloc(*ptr, tamanho);


    ================================================

    *ptr --> Endereço de Valor.
    **ptr --> Endereço de Ponteiro.
    
    */
    return 0;
}