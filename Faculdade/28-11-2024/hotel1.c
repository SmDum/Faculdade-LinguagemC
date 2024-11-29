#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct quarto
{
    int num;
    char categoria;
    char status; // L-ivre ou O-cupado
} quarto;

typedef struct hospede
{
    int quarto;
    char nome[80];
    int acompanhante;
    char categoria;
    int dias;
} hospede;

void aloca_quarto(quarto **pq, int qq);
void aloca_hospede(hospede **ph, int qh);

int verifica_quarto();
int verifica_hospede();

void cadastro_quarto(quarto *pq, int qq);
void cadastro_hospede(hospede *ph, quarto *pq, int qq);

void grava_quarto(quarto *pq);
void grava_hospede(hospede *ph, char *aux, int pos);

void atualiza_quarto(quarto *pq, int n_quarto);

int busca_quarto(quarto *pq, int qq, char cat);
int busca_hospede(hospede *ph, int n_quarto);
int busca_vago(hospede *ph, int qh);

void check_out(hospede *ph, quarto *pq);

void mostra_quarto(quarto *pq);
void mostra_hospede(hospede *ph);

int main()
{
    quarto *pq = NULL;
    hospede *ph = NULL;
    int op, qquarto;

    aloca_quarto(&pq, 1);
    qquarto = verifica_quarto();

    if (qquarto == 0)
        cadastro_quarto(pq, 15);

    aloca_hospede(&ph, 1);

    do
    {
        system("cls");
        printf("\n[1]Check-in\n[2]Check-out\n[3]Mostra Quarto\n[4]Mostra Hospede\n[5]Fim\nOpcao: ");
        scanf("%i", &op);
        fflush(stdin);
        switch (op)
        {
        case 1:
            cadastro_hospede(ph, pq, 15);
            system("cls");
            system("pause");
            break;
        case 2:
            check_out(ph, pq);
            system("cls");
            system("pause");
            break;
        case 3:
            mostra_quarto(pq);
            system("cls");
            system("pause");
            break;
        case 4:
            mostra_hospede(ph);
            system("cls");
            system("pause");
            break;
        } // switch
    } while (op != 5);

    return 0;
}

void aloca_quarto(quarto **pq, int qq)
{
    if (((*pq = (quarto *)realloc(*pq, qq * sizeof(quarto))) == NULL))
        exit(1);
} // Alocação de Quartos

void aloca_hospede(hospede **ph, int qh)
{
    if (((*ph = (hospede *)realloc(*ph, qh * sizeof(hospede))) == NULL))
        exit(1);
} // Alocação de Hóspedes

int verifica_quarto()
{
    FILE *fq = NULL;
    long int q = 0;

    if ((fq = fopen("quartos.bin", "rb")) == NULL)
    {
        return q;
    }

    fseek(fq, 0, 2);

    q = ftell(fq) / sizeof(quarto);
    fclose(fq);

    return q;
}

int verifica_hospede()
{
    FILE *fh = NULL;
    long int q = 0;

    if ((fh = fopen("hospede.bin", "rb")) == NULL)
        return q;

    fseek(fh, 0, 2);
    q = ftell(fh) / sizeof(hospede);
    fclose(fh);

    return q;
} // Retorna o numero de hospedes

void cadastro_quarto(quarto *pq, int qq)
{
    int i;

    for (i = 0; i < qq; i++)
    {
        pq->num = i + 1;
        pq->status = 'L';

        if (i < 5)
        {
            pq->categoria = 'S';
        }
        else
        {
            pq->categoria = 'F';
        }

        grava_quarto(pq);
    }
} // Cadastro dos Quartos

void cadastro_hospede(hospede *ph, quarto *pq, int qq)
{
    int qtdhosp, pos;
    system("cls");

    qtdhosp = verifica_hospede(); // qtde de hospedes
    pos = busca_vago(ph, qtdhosp);

    printf("\nNome: ");
    gets(ph->nome);
    fflush(stdin);

    do
    {
        printf("\nAcompanhantes (Máx 3): ");
        scanf("%i", &(ph->acompanhante));
        fflush(stdin);
    } while (ph->acompanhante < 0 || ph->acompanhante > 3);

    if (ph->acompanhante == 0)
    {
        ph->categoria = 'S';
    }
    else
    {
        ph->categoria = 'F';
    }

    printf("\nDias: ");
    scanf("%i", &(ph->dias));
    fflush(stdin);

    ph->quarto = busca_quarto(pq, qq, ph->categoria);

    if (ph->quarto == -1)
    {
        printf("\nHotel Lotado nessa categoria!");
    }

    else
    {
        printf("\nCadastro realizado com sucesso!\nQuarto: %i\n\n", ph->quarto);

        if (pos == -1) // Se não há hospede vago
        {
            grava_hospede(ph, "ab", 1); // Grava no Final
        }
        else // Senão
        {
            grava_hospede(ph, "rb+", pos); // Reescreve no hóspede vago
        }
    }

} // Cadastro de Hospede

void grava_quarto(quarto *pq)
{
    FILE *fq = NULL;

    if ((fq = fopen("quartos.bin", "ab")) == NULL)
    {
        printf("\nErro\n\n");
    }
    else
    {
        fwrite(pq, sizeof(quarto), 1, fq);
    }
    fclose(fq);
}

void grava_hospede(hospede *ph, char *aux, int pos)
{
    FILE *fh = NULL;

    if ((fh = fopen("hospede.bin", "ab")) == NULL)
    {
        printf("\nErro\n\n");
    }
    else
    {
        if (strcmp(aux, "rb+") == 0)
        {
            fseek(fh, pos * sizeof(hospede), 0);
        }
        fwrite(ph, sizeof(hospede), 1, fh);
    }
    fclose(fh);
}

void atualiza_quarto(quarto *pq, int n_quarto)
{
    FILE *fq = NULL;

    int qq, i;

    qq = verifica_quarto();

    if ((fq = fopen("quartos.bin", "rb+")) == NULL)
    {
        printf("\n\nErro\n");
    }
    else
    {
        for (i = 0; i < qq; i++)
        {

            fseek(fq, i * sizeof(quarto), 0);
            fread(pq, i * sizeof(quarto), 1, fq);

            if (pq->num == n_quarto)
            {
                pq->status = 'L';
                fseek(fq, i * sizeof(quarto), 0); // volta para a posicao lida
                fwrite(pq, sizeof(quarto), 1, fq);
                i = qq; // forca a saida
            }
        }
    }
    fclose(fq);
}

int busca_quarto(quarto *pq, int qq, char cat)
{
    FILE *fq = NULL;
    int pos = -1, i;

    if ((fq = fopen("quartos.bin", "rb+")) == NULL)
    {
        printf("\n\nErro\n");
    }
    else
    {
        for (i = 0; i < qq; i++)
        {

            fseek(fq, i * sizeof(quarto), 0);
            fread(pq, i * sizeof(quarto), 1, fq);

            if (pq->categoria == cat && pq->status == 'L')
            {
                pq->status = 'O';
                fseek(fq, i * sizeof(quarto), 0); // volta para a posicao lida
                fwrite(pq, sizeof(quarto), 1, fq);
                pos = pq->num;
                i = qq;
            }
        }
    }
    fclose(fq);
    return pos;
}

int busca_hospede(hospede *ph, int n_quarto)
{
    FILE *fh = NULL;
    int pos = -1, i, qh;

    qh = verifica_hospede();

    if ((fh = fopen("hospede.bin", "rb+")) == NULL)
    {
        printf("\n\nErro\n");
    }
    else
    {
        for (i = 0; i < qh; i++)
        {

            fseek(fh, i * sizeof(quarto), 0);
            fread(ph, i * sizeof(quarto), 1, fh);

            if (ph->quarto == n_quarto)
            {
                ph->quarto = -1;
                fseek(fh, i * sizeof(quarto), 0); // volta para a posicao lida
                fwrite(ph, sizeof(quarto), 1, fh);
                pos = i;
                i = qh;
            }
        }
    }
    fclose(fh);
    return pos;
}

int busca_vago(hospede *ph, int qh)
{
    FILE *fh = NULL;
    int i;

    if ((fh = fopen("hospede.bin", "rb")) == NULL)
    {
        return -1;
    }
    else
    {
        for (i = 0; i < qh; i++)
        {

            fseek(fh, i * sizeof(quarto), 0);
            fread(ph, i * sizeof(quarto), 1, fh);

            if (ph->quarto == -1)
            {
                fclose(fh);
                return i;
            }
        }
        fclose(fh);
    }
    return -1;
}

void check_out(hospede *ph, quarto *pq)
{
    int achou, n_quarto;
    float valor;

    printf("\nQuarto a ser finalizado: ");
    scanf("%i", &n_quarto);
    fflush(stdin);

    achou = busca_hospede(ph, n_quarto);

    if (achou == -1)
    {
        printf("\nQuarto Inválido...\n\n");
    }
    else
    {
        if (ph->categoria == 'S')
            valor = ph->dias * 85;

        else
            valor = ph->dias * ((ph->acompanhante) + 1) * 65;

        printf("\nNome: %s\nAcompanhantes: %i\nCategoria: %c\nDias: %i\nValor a ser pago: %.2f\n\n", ph->nome, ph->acompanhante, ph->categoria, ph->dias, valor);

        atualiza_quarto(pq, n_quarto);
    } // else
}

void mostra_quarto(quarto *pq)
{
    int i, qq;
    FILE *fq = NULL;

    qq = verifica_quarto();

    if ((fq = fopen("quartos.bin", "rb")) == NULL)
    {
        printf("\nArquivo Inexistente...\n\n");
    }
    else
    {
        for (i = 0; i < qq; i++)
        {
            fseek(fq, i * sizeof(quarto), 0);
            fread(pq, i * sizeof(quarto), 1, fq);

            printf("\nQuarto: %i\nCategoria: %c\nStatus: %c\n\n", pq->num, pq->categoria, pq->status);
        }
        fclose(fq);
    }
}

void mostra_hospede(hospede *ph)
{
    int i, qh;
    FILE *fh = NULL;

    qh = verifica_quarto();

    if ((fh = fopen("hospedes.bin", "rb")) == NULL)
    {
        printf("\nArquivo Inexistente...\n\n");
    }
    else
    {
        for (i = 0; i < qh; i++)
        {
            fseek(fh, i * sizeof(quarto), 0);
            fread(ph, i * sizeof(quarto), 1, fh);

            printf("\nQuarto: %i\nNome: %s\nAcompanhantes: %i\nCategoria: %c\nDias: %i\n\n", ph->quarto, ph->nome, ph->acompanhante, ph->categoria, ph->dias);
        }
        fclose(fh);
    }
}