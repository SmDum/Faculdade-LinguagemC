#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct hospede
{
    int quarto;
    char nome[80];
    int acompanhante;
    char categoria;
    int dias;
} hospede;

typedef struct quarto
{
    int num;
    char categoria;
    char status;
} quarto;

void aloca_quarto(quarto **p_quarto, int quant_quartos);
void aloca_hospede(hospede **p_hospede, int quant_hospedes);

void cadastra_quarto(quarto *p_quarto, int quant_quartos);
void cadastra_hospede(hospede *p_hospede, quarto *quarto, int quant_quarto);

int busca_quarto(quarto *p_quarto, int quant_quarto, char categoria);
int busca_hospede(hospede *p_hospede, int quant_hosp, int num_quarto);

void check_out(hospede *p_hospede, int quant_hosp, quarto *quarto);

void mostra_quarto(quarto *p_quarto, int quant_quarto);
void mostra_hospede(hospede *p_hospede, int quant_hospede);

int main()
{
    setlocale(LC_ALL, "portuguese");

    quarto *p_quarto = NULL;
    hospede *p_hospede = NULL;
    int opc, cont = 0, quant = 15, pos;

    aloca_quarto(&p_quarto, quant);
    cadastra_quarto(p_quarto, quant);

    do
    {
        system("cls");

        printf("//////HOTEL FAZENDA RIBEIRAO//////\n\n[1]Check-in\n[2]Check-out\n[3]Mostra Quarto\n[4]Mostra Hospede\n[5]Fim\nOpcao: ");
        scanf("%i", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            pos = busca_hospede(p_hospede, cont, -1);
            if (pos == -1)
            {
                aloca_hospede(&p_hospede, cont + 1);
                cadastra_hospede(p_hospede + cont, p_quarto, quant);
                cont++;
            }
            else
            {
                cadastra_hospede(p_hospede + pos, p_quarto, quant);
            }
            break;

        case 2:
            check_out(p_hospede, cont, p_quarto);
            break;

        case 3:
            mostra_quarto(p_quarto, quant);
            break;

        case 4:
            mostra_hospede(p_hospede, cont);
            break;
        }

    } while (opc != 5);

    free(p_quarto);
    free(p_hospede);

    return 0;
}

void aloca_quarto(quarto **p_quarto, int quant_quartos)
{
    if ((*p_quarto = (quarto *)realloc(*p_quarto, quant_quartos * sizeof(quarto))) == NULL)
    {
        printf("Erro ao Alocar Memória...");
        exit(1);
    }
}
void aloca_hospede(hospede **p_hospede, int quant_hospedes)
{
    if ((*p_hospede = (hospede *)realloc(*p_hospede, quant_hospedes * sizeof(hospede))) == NULL)
    {
        printf("Erro ao Alocar Memória...");
        exit(1);
    }
}

void cadastra_quarto(quarto *p_quarto, int quant_quartos)
{
    int i;

    for (i = 0; i < quant_quartos; i++, p_quarto++)
    {
        p_quarto->num = i + 1;
        p_quarto->status = 'L';

        if (i < 5)
        {
            p_quarto->categoria = 'S';
        }
        else
        {
            p_quarto->categoria = 'F';
        }
    }
}

void cadastra_hospede(hospede *p_hospede, quarto *quarto, int quant_quarto)
{

    printf("\nNome: ");
    gets(p_hospede->nome);
    fflush(stdin);

    do
    {
        printf("Digite o número de acompanhantes: ");
        scanf("%i", &(p_hospede->acompanhante));
        fflush(stdin);
    } while (p_hospede->acompanhante < 0 || p_hospede->acompanhante > 3);

    if (p_hospede->acompanhante == 0)
    {
        p_hospede->categoria = 'S';
    }
    else
    {
        p_hospede->categoria = 'F';
    }

    printf("Dias: ");
    scanf("%i", &(p_hospede->dias));
    fflush(stdin);

    p_hospede->quarto = busca_quarto(quarto, quant_quarto, p_hospede->categoria);

    if (p_hospede->quarto == -1)
    {
        printf("\nNão há quartos disponíveis na categoria desejada...");
    }
    else
    {
        printf("\nCadastro Realizado! - Seu quarto é o %i", p_hospede->quarto);
    }

    printf("\n\n\n");
    system("pause");
}

int busca_quarto(quarto *p_quarto, int quant_quarto, char categoria)
{
    int i;

    for (i = 0; i < quant_quarto; i++, p_quarto++)
    {
        if (p_quarto->categoria == categoria && p_quarto->status == 'L')
        {
            p_quarto->status = 'O';
            return p_quarto->num;
        }
    }
    return -1;
}

int busca_hospede(hospede *p_hospede, int quant_hosp, int num_quarto)
{

    int i;

    for (i = 0; i < quant_hosp; i++, p_hospede++)
    {
        if (p_hospede->quarto == num_quarto)
        {
            return i;
        }
    }
    return -1;
}

void check_out(hospede *p_hospede, int quant_hosp, quarto *p_quarto)
{
    int aux_quarto, achou;
    float valor;

    printf("\nDigite o Quarto: ");
    scanf("%i", &aux_quarto);
    fflush(stdin);

    achou = busca_hospede(p_hospede, quant_hosp, aux_quarto);

    if (achou == -1)
    {
        printf("\nQuarto Inexistente...");
        system("pause");
        return; // Sai da função se o quarto não for encontrado
    }

    // Cálculo do valor
    if ((p_hospede + achou)->categoria == 'S')
        valor = (p_hospede + achou)->dias * 85;
    else
        valor = (p_hospede + achou)->dias * (((p_hospede + achou)->acompanhante) + 1) * 65;

    // Exibir informações
    printf("\nNome: %s\nAcompanhantes: %i\nCategoria: %c\nDias: %i\nValor a ser pago: R$ %.2f\n\n",
           (p_hospede + achou)->nome, (p_hospede + achou)->acompanhante,
           (p_hospede + achou)->categoria, (p_hospede + achou)->dias, valor);

    // Liberar o quarto
    int num_quarto = (p_hospede + achou)->quarto; // Pega o número do quarto do hóspede
    for (int i = 0; i < quant_hosp; i++)          // Corrigido para `quant_quarto`
    {
        if ((p_quarto + i)->num == num_quarto)
        {
            (p_quarto + i)->status = 'L'; // Atualiza o status do quarto para livre
            break;
        }
    }

    system("pause");
}

void mostra_quarto(quarto *p_quarto, int quant_quarto)
{
    int i;

    for (i = 0; i < quant_quarto; i++, p_quarto++)
    {
        printf("\nNúmero: %i\nCategoria: %c\nStatus: %c\n", p_quarto->num, p_quarto->categoria, p_quarto->status);
        printf("\n");
    }

    system("pause");
}

void mostra_hospede(hospede *p_hospede, int quant_hospede)
{
    int i;
    printf("\n--LISTA DE HOSPEDES--\n");
    for (i = 0; i < quant_hospede; i++, p_hospede++)
    {
        printf("\nQuarto: %i\nNome: %s\nAcompanhantes: %d\nCategoria: %c\nDias: %d", p_hospede->quarto, p_hospede->nome, p_hospede->acompanhante, p_hospede->categoria, p_hospede->dias);
        printf("\n");
    }

    printf("\n\n\n");

    system("pause");
}
