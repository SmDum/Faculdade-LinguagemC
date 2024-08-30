#include <stdio.h>

int main()
{
    int var = 10;
    int *ptr;
    ptr=&var;
    printf("Mostra o conteudo de var");

    printf("\nAcesso direto - var = %i", var);
    printf("\nAcesso indireto - var = %i", *ptr);

    printf("\n\nMostra o endereco de var\n\n");

    printf("\nPonteiro Constante - var = %i", &var);
    printf("\nAcesso Variavel - var = %i", ptr);

    return 0;
}

/*
&mat[2] == mat+2
mat[2] == *(mat+2)
*/
