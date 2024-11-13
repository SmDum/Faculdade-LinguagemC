// Pilha / Stack

#include <stdio.h>
#include <locale.h>

#define TAMPILHA 10

int pilha[TAMPILHA] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int topo = 0;

void lista_elementos()
{
    int i;

    printf("\n===== Pilha Atual =====\n");

    for (i = 0; i < TAMPILHA; i++)
    {
        printf("-");
        printf("|%i|", pilha[i]);
        printf("-");
    }
    printf("\nTopo: %i", topo);
    printf("\n\n\n");
}

void push()
{
    int val;
    printf("\nInforme o valor: ");
    scanf("%i", &val);

    if (topo < TAMPILHA)
    {
        pilha[topo] = val;
        topo++;
        lista_elementos();
    }
    else
    {
        printf("\nPilha cheia...");
    }
}

void pop()
{
    if (topo >= 0)
    {
        pilha[topo - 1] = 0;
        topo--;
        lista_elementos();
    }
    else
    {
        printf("\nPilha Vazia...");
    }
}

void clear()
{
    int i;
    for (i = 0; i < TAMPILHA; i++)
    {
        pilha[i] = 0;
    }
    topo=0;
    
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    int opc = 0;

    do
    {
        printf("\n[1] - Inserir (Push)\n[2] - Remover (Pop)\n[3] - Listar\n[4] - Limpar (Clear)\n[-1] - Sair\nSelecione a Opção: ");
        scanf("%i", &opc);

        switch (opc)
        {
        case 1:
            push();
            break;
        
        case 2:
            pop();
            break;
        
        case 3:
            lista_elementos();
            break;
        
        case 4:
            clear();
            break;
        
        case -1:
            break;
        
        default:
            printf("\nOpção Inválida");
            break;
        }

    } while (opc != -1);
    
    return 0;
}