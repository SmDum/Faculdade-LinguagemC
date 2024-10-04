/*

=====   Estruturas Complexas   =====

struct peça{
    int num;
    char nome[10];
};

struct peça *p_peça, produto;
p_peça = &produto;

-----------------------------------------

Operador de Acesso Indireto:

É o mais comum. Consiste dos símbolos -> . Quando utilizados, acessa o membro da estrutura especificado.

p_peça -> numero;

-----------------------------------------

Operador de Indireção:

Devemos aplica o operador ponto (.) para acessarmos elementos individuais do produto.

Ex.:

(*p_peça).numero = 100; // Atribui o valor 100 a produto.numero;

-----------------------------------------

Duas Maneiras:

(*p_peça).numero = 100;
p_peça -> numero = 100;

-----------------------------------------

struct peka{
    int numero;
    char nome[10];
}

struct peça dados[100], p_peka;

p_peka = dados;

-----------------------------------------

Operador de Acesso Indireto:

scanf("%i" , &(p_peka -> numero));
gets(p_peka -> nome);

printf("%i %s", p_peka->numero, p_peka->nome);

-----------------------------------------

Operador Indireção:

scanf("%i", &(*p_peka).numero);
gets((*p.peka).nome);

printf("%i %s", (*p_peka).numero, (*p_peka).nome);

-----------------------------------------

*/