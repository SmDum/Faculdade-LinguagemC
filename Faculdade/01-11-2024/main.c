/*
Arquivos em I/O

Modo Texto - Imita arquivos UNIX
Modo Binário - Imita arquvivos MS-DOS

Para trabalharmos com arquivos, precisamos declarar um ponteiro para o tipo FILE(arquivo).

Sintaxe: 

FILE *fptr;

Função fopen() - Utilizada para criar(abrir) um arquivo e, retorna um ponteiro para o tipo FILE.

fptr = fopen("xxxxxxxx.xxx", "tipo_abertura");

r - Leitura
w - Escrita
a - Adicionar dados
b - Binário
+ - Atualiza

rb
ab
rb+
ab+ 

Funçao fclose() - É utilizada para fechar um arquivo.

Sintaxe:

fclose(fptr);

onde:

fptr - Corresponde ao ponteiro do arquivo a ser fechado.

Tentar ler arquivo sem alocar espaço dá erro.

Leitura de Arquivo.

fread(p, tam, qtde, fptr);

p - Ponteiro.
tam - Tamanho em bytes do tipo de dados a ser lido.
qtde - Qtde de itens a serem lidos.
fptr - Ponteiro do FILE.

Escrita no Arquivo.

fwrite(p, tam, qtde, fptr);
p - Ponteiro.
tam - Tamanho em bytes do tipo de dados a ser lido.
qtde - Qtde de itens a serem lidos.
fptr - Ponteiro do FILE.

Ponteiro para Arquivo

Função fseek()

Sintaxe:

fseek(fptr, offset, modo);

fptr - Corresponde ao ponteiro para arquivo FILE.
offset - Consiste no n° de byts de deslocamento, a partir do modo - dese ser do tipo long int.
modo - especifica a posição desejada.

Modos:

0 ou SEEK_SER - Começo do Arquivo.
1 ou SEEK_CUR - Posição corrente do ponteiro.
2 ou SEEK_END - Fim do Arquivo.

Função frell();

Retorna a posição do ponteiro de um arquivo bunário em à posição atual;

sintaxe:

pos = ftell(fptr);

pos - n° de bytes do começo do arquivo até a posição atual - deve ser do tipo long int.
fptr - Corresponde ao ponteiro para o arquivo.

*/