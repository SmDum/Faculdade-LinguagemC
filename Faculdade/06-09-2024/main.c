#include <stdio.h>

void leitura(float *temperatura, int tamanho_vetor);
void maior_temp(float *temperatura, int tamanho_vetor);
float media_temp(float *temperatura, int tamanho_vetor);
float menor_temp(float *temperatura, int tamanho_vetor, float media, int *pos);
void imprime(int *pos, int qtde, float *temperatura);

int main()
{
    float temp[31], media;
    int dias, pos_inf[31], qtde;

    printf("\n Temperaturas Diarias\n");
    printf("Qtde de Dias: ");
    scanf("%i", &dias);

    leitura(temp, dias);
    maior_temp(temp, dias);

    media = media_temp(temp, dias);
    printf("Media = %.2f", media);

    qtde = menor_temp(temp, dias, media, *pos_inf);

    imprime(*pos_inf, qtde, *temp);

    return 0;
}

void leitura(float *temperatura, int tamanho_vetor)
{

    for(int i=0; i<tamanho_vetor; i++)
    {
        printf("\nTemperatura - %i dia: ", i+1);
        scanf("%f", temperatura++);
    }
}

void maior_temp(float *temperatura, int tamanho_vetor)
{
    float maior_temp;
    int dia;
    maior_temp = *temperatura;
    dia = 1;


    for(int i = 1; i<tamanho_vetor; i++, temperatura++)
    {
        if(*temperatura > maior_temp)
        {
            maior_temp = *(temperatura+1);
            dia = i+1;
        }
    }

    printf("\nA maior temperatura: %.2f graus\nOcorreu no dia %i\n", maior_temp, dia);
}

float media_temp(float *temperatura, int tamanho_vetor)
{
    float media = 0;

    for(int i = 0; i<tamanho_vetor; i++)
    {
        media += *(temperatura+i);
    }

    return (media/=tamanho_vetor);
}

float menor_temp(float *temperatura, int tamanho_vetor, float media, int *pos)
{
    for(int i = 0, int j = 0; i<tamanho_vetor; i++)
    {
        if(*(temperatura+1)<media)
        {
            *(pos+j) = i;
            j++;
        }
    }
    return j;
}

void imprime(int *pos, int qtde, float *temperatura)
{
    printf(Temperaturas Inferiores a Media:);

    for(int i = 0; i<qtde; i++)
    {
        printf("\nTemperatura; %.2f\nDia: %i\n" , *(temperatura+(pos+i)), *(pos+i)+1);
    }

    return();
}
