#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structs

typedef struct carreira{
	int reg;
	int qmilitar;
	char org[20];
	char patente[20];
	float salario;
}carreira;

typedef struct militar{
	char CPF[13];
	char nome[20];
	int numreg;
}militar;

//prototipos

void aloca_carreira(carreira **c, int qc);
void cadastro_carreira(carreira *c, int qc);
void mostra_carreira(carreira *c, int qc);

void maiuscula(char *p);

int main(){
	
	carreira *pc = NULL;
	int qc = 5;
	
	aloca_carreira(&pc, qc);
	cadastro_carreira(pc, qc);
	mostra_carreira(pc, qc);
	
	return 0;
}//main

void aloca_carreira(carreira **c, int qc){
	if((*c = (carreira*)realloc(*c, qc * sizeof(carreira))) == NULL)
		exit(1);	
}//aloca_carreira

void cadastro_carreira(carreira *c, int qc){
	
	static int r = 1;
	int i;
	
	for(i = 0; i < qc; i++, c++){
		
		c->reg = r++;
		
		c->qmilitar = 0;
		
		printf("\nOrganizacao (Exercito\tAeronautica\tMarinha):\nOpcao: ");
		gets(c->org);
		fflush(stdin);
		maiuscula(c->org);
		
		printf("\nPatente: ");
		gets(c->patente);
		fflush(stdin);
		maiuscula(c->patente);
		
		printf("Salario: R$");
		scanf("%f", &c->salario);
		fflush(stdin);
		
	}//for
}

void maiuscula(char *p){
	int tam = strlen(p), i;
	for(i = 0; i < tam; i++, p++)
		if(*p >='a' && *p <= 'z')
			*p-=32;
}//maiuscula

void mostra_carreira(carreira *c, int qc){
	int i;
	for(i = 0; i < qc; i++, c++)
		printf("\nRegistro: %i\nQtde militares: %i\nOrganizacao: %s\nPatente: %s\nSalario: R$%.2f\n\n", c->reg, c->qmilitar, c->org, c->patente, c->salario);
	system("pause");
}//mostra_carreira
