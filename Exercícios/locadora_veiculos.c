/*
Fazer um programa para LOCADORA DE VEICULOS. Alocar dinamicamente espaço e cadastrar 15 
carros, sendo 5 [P]equenos, 5 [M]édios e 5 [G]randes (iniciar o status como [L]ivre). 
Em seguida, fazer o menu para:

[1]Locação - mostrar todos os carros cadastrados. Em seguida alocar dinamicamente espaço 
para 1 cliente e, receber o CPF, nome do cliente, tipo de carro e o tempo de permanecia 
desejado. buscar o numero do carro disponivel, de acordo com o tipo. Não esquecer de:
    - Na estrutura cliente: guardar o numero do carro alugado.
    - Na estrutura carro: mudar o status para [O]cupado.

[2]Devolução - encerra a locação e apresenta o relatório, de acordo com o CPF do cliente. 
Mostrar o nome do cliente, o numero do registro do carro, o tipo do carro, o tempo de 
permanencia em dias e calcular o valor a ser pago. Não esquecer de:
    - na estrutura carro: mudar o status para [L]ivre.

[3]Fim

[P]equeno - diária R$150,00 / [M]édio - diária R$200,00 / [G]rande - diária R$250,00
*/ 

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct carro{
	int		reg_carro;
	char	tipo;
	char	status;
}carro;

typedef struct cleinte{
	char	CPF[13];
	char	nome[80];
	int		num_reg;
	int		dias;
}cliente;

void aloca_carro(carro **pcar, int qcar);
void aloca_cliente(cliente **pcli, int qcli);

void cadastra_carro(carro *pcar, int qcar);
void cadastra_cliente(cliente *pcli, carro *pcar);

void devolucao(cliente *pcli, int qcli, carro *pcar, int qcar);

int  busca_carro(carro *pcar, char tipo_car);
int  busca_CPF(cliente *pcli, int qcli, char *aux);

void mostra_carro(carro *pcar, int qcar);

int main(){
	
	carro 	*car = NULL;
	cliente *cli = NULL;
	int op, cont = 0, pos;
	
	aloca_carro(&car, 15);			//aloca carro
	cadastra_carro(car, 15);		//chamada da funcao cadastra_carro
	
	do{
		system("cls");
		printf("[1] Locacao\n[2] Devolucao\n[3] Fim\nOpcao: ");
		scanf("%i", &op);
		fflush(stdin);
		
		switch(op){
			case 1: mostra_carro(car, 15);
					aloca_cliente(&cli, cont + 1);			//aloca cliente
					cadastra_cliente(cli + cont, car);		//chamada da funcao cadastra_cliente
					cont++;
					break;
			
			case 2: devolucao(cli, cont, car, 15);			//chamada da funcao devolucao
					break;
		}//switch
		
	}while(op != 3);
	
	return 0;
	
}//main

void aloca_carro(carro **pcar, int qcar){
	if((*pcar = (carro*)realloc(*pcar, qcar * sizeof(carro))) == NULL){		//comando p/ alocar carro
		exit(1);
	}
}//aloca_carro

void aloca_cliente(cliente **pcli, int qcli){
	if((*pcli = (cliente*)realloc(*pcli, qcli * sizeof(cliente))) == NULL)	//comando p/ alocar cliente
		exit(1);
}//aloca_cliente

void cadastra_carro(carro *pcar, int qcar){
	
	int i;
	for(i - 0; i < qcar; i++, pcar++){
		(pcar->reg_carro = i + 1);			//numero do registro do carro
		
		pcar->status='L';
		
		if(i < 5)
			pcar->tipo = 'P';				// 5 carros pequenos
		else if(i < 10)
			pcar->tipo = 'M';				//5 carros medios
		else
			pcar->tipo = 'G';				//5 carros grandes
	}//for
	
}//cadastra_carro

void cadastra_cliente(cliente *pcli, carro *pcar){
	
	char tipcar;
	int  numcar;
	
	printf("\nTipo de carro [P - M - G]: ");
	scanf("%c", &tipcar);
	fflush(stdin);
	
	tipcar = toupper(tipcar);
	
	(numcar = busca_carro(pcar, tipcar));			//chamada da funcao busca_carro
	if(numcar == -1)
		printf("\nNao ha carros disponiveis desse tipo\n\n\n");
	else{
		(pcli->num_reg = numcar);					//atribuicao do numero do carro para o cliente
		
		printf("\nCPF: ");
		gets(pcli->CPF);
		fflush(stdin);
		
		printf("\nNome: ");
		gets(pcli->nome);
		fflush(stdin);
		
		printf("\nQtos dias: ");
		scanf("%i", &(pcli->dias));					//recebe a quantidade de dias
		fflush(stdin);
		
		printf("\nCadastro feito com sucesso\nCarro: %i\n\n\n", pcli->num_reg);
	}//else
	
	system("pause");
	
}//cadastro_cliente

void devolucao(cliente *pcli, int qcli, carro *pcar, int qcar){
	
	char aux_cpf[13], tip;
    int pos, reg, tempo;
    
    printf("\nCPF a ser encerrado: ");
    gets(aux_cpf);
    fflush(stdin);
    
    pos = busca_CPF(pcli, qcli, aux_cpf);
    if(pos == -1) {
        printf("\nCPF invalido\n");
    }
    else
    {
        reg  = (pcli + pos)->num_reg;
        (pcar + reg - 1)->status = 'L';
        tip = (pcar + reg - 1)->tipo;
        tempo = (pcli + pos)->dias;

        printf("Tipo de carro: %c\n", tip);
        switch(tip)
        {
            case 'P':
                printf("Valor a ser pago: R$%.2f\n", tempo * 150.00);
                break;
            case 'M':
                printf("Valor a ser pago: R$%.2f\n", tempo * 200.00);
                break;
            case 'G':
                printf("Valor a ser pago: R$%.2f\n", tempo * 250.00);
                break;
        }// switch
    }// else
    system("pause");
	
}//devolucao

int busca_carro(carro *pcar, char tipo_car){
	
	int i;
	for(i = 0; i < 15; i++){
		if((pcar + i)->tipo == tipo_car && (pcar + i)->status == 'L'){	//compara tipo e status Livre
			
			((pcar + i)->status = 'A');									//troca o status do carro para Alugado
			return((pcar + i)->reg_carro);								//retorna o registro do carro
		
		}//if
	}//for
	
	return -1;
	
}//busca_carro

int busca_CPF(cliente *pcli, int qcli, char *aux){
	
	int i, reg;
	
	for(i = 0; i < qcli; i++, pcli++)
		if(strcmp(pcli->CPF, aux) == 0){			//compara CPF
			printf("\nNome: %s\nCarro: %i\nDias: %i", pcli->nome, pcli->num_reg, pcli->dias);
			return(i);
		}//if
	
	return -1;
	
}//busca_CPF

void mostra_carro(carro *pcar, int qcar){
	int i;
	
	for(i = 0; i < qcar; i++, pcar++)
		printf("\nRegistro Carro: %i\nTipo: %c\nStatus: %c\n\n", pcar->reg_carro, pcar->tipo, pcar->status);
	
	printf("\n\n\n");
}//mostra_carro