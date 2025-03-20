#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    int dificuldade;
    int valor1;
    int valor2;
    int operacao;
    int resultado;
} Calcular;

void jogar();
void mostrarInfo(Calcular calc);
int somar(int resposta, Calcular calc);
int diminuir(int resposta, Calcular calc);
int multiplicar(int resposta, Calcular calc);

int pontos = 0;

int main()
{
    setlocale(LC_ALL, "portuguese");
    // Deve ser chamado apenas 1 vez.
    srand(time(NULL));
    jogar();
    return 0;
}

void jogar()
{
    Calcular calc;
    int dificuldade;

    printf("\nInforme o nível de dificuldade desejada [1-4]: ");
    scanf("%i", &dificuldade);

    calc.dificuldade = dificuldade;
    calc.operacao = rand() % 3; // Gera um valor randomico entre 0 e 2

    if (calc.dificuldade == 1)
    {
        calc.valor1 = rand() % 11;
        calc.valor2 = rand() % 11;
    }
    else if (calc.dificuldade == 2)
    {
        calc.valor1 = rand() % 101;
        calc.valor2 = rand() % 101;
    }
    else if (calc.dificuldade == 3)
    {
        calc.valor1 = rand() % 1001;
        calc.valor2 = rand() % 1001;
    }
    else if (calc.dificuldade == 4)
    {
        calc.valor1 = rand() % 10001;
        calc.valor2 = rand() % 10001;
    }
    else
    {
        calc.valor1 = rand() % 100001;
        calc.valor2 = rand() % 100001;
    }

    int resposta;
    printf("\nInforme o resultado para a seguinte operação:");

    if (calc.operacao == 0)
    {
        printf("%i + %i = ", calc.valor1, calc.valor2);
        scanf("%i", &resposta);

        if (somar(resposta, calc) == 1)
        {
            pontos++;
            printf("\nVocê tem %i ponto(s)", pontos);
        }
    }

    else if (calc.operacao == 1)
    {
        printf("%i - %i = ", calc.valor1, calc.valor2);
        scanf("%i", &resposta);

        if (diminuir(resposta, calc) == 1)
        {
            pontos++;
            printf("\nVocê tem %i ponto(s)", pontos);
        }
    }

    else if (calc.operacao == 2)
    {
        printf("%i * %i = ", calc.valor1, calc.valor2);
        scanf("%i", &resposta);

        if (multiplicar(resposta, calc) == 1)
        {
            pontos++;
            printf("\nVocê tem %i ponto(s)", pontos);
        }
    }

    else
        printf("\nOperação %i desconhecida...", calc.operacao);

    printf("\nDeseja continuar jogando?\n[0] - Não\n[1] - Sim\nOpção: ");
    int continuar;
    scanf("%i", &continuar);

    if (continuar)
        jogar();
    else
    {
        printf("\nVocê finalizou com %i ponto(s)!", pontos);
        printf("\nAté a próxima.");
        exit(0);
    }
}

void mostrarInfo(Calcular calc)
{
    char op[25];

    if (calc.operacao == 0) // 0 = Somar
        sprintf(op, "\nSomar");

    else if (calc.operacao == 1) // 1 = Diminuir
        sprintf(op, "\nDiminuir");

    else if (calc.operacao == 2) // 2 = Multiplicar
        sprintf(op, "\nMultiplicar");

    else
        sprintf(op, "\nOperação Desconhecida");

    printf("\nValor 1: %i\nValor 2: %i\nDificuldade: %iOperação: %s",
           calc.valor1, calc.valor2, calc.dificuldade, op);
}

int somar(int resposta, Calcular calc)
{
    int resultado = calc.valor1 + calc.valor2;
    calc.resultado = resultado;

    int certo = 0;

    if (resposta == calc.resultado)
    {
        printf("\nResposta Correta!");
        certo = 1;
    }

    else
        printf("\nResposta Errada...");

    printf("\n%i + %i = %i", calc.valor1, calc.valor2, calc.resultado);

    return certo;
}

int diminuir(int resposta, Calcular calc)
{
    int resultado = calc.valor1 - calc.valor2;
    calc.resultado = resultado;

    int certo = 0;

    if (resposta == calc.resultado)
    {
        printf("\nResposta Correta!");
        certo = 1;
    }

    else
        printf("\nResposta Errada...");

    printf("\n%i - %i = %i", calc.valor1, calc.valor2, calc.resultado);

    return certo;
}

int multiplicar(int resposta, Calcular calc)
{
    int resultado = calc.valor1 * calc.valor2;
    calc.resultado = resultado;

    int certo = 0;

    if (resposta == calc.resultado)
    {
        printf("\nResposta Correta!");
        certo = 1;
    }

    else
        printf("\nResposta Errada...");

    printf("\n%i * %i = %i", calc.valor1, calc.valor2, calc.resultado);

    return certo;
}
