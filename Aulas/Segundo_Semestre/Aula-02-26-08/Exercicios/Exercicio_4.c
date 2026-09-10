#include <stdio.h>

enum Faixa_Temperatura
{
    MUITO_FRIO,
    FRIO,
    AGRADAVEL,
    QUENTE,
    MUITO_QUENTE
};

int leitor_temperatura(temp)
{
    float temperatura_atual = 0;
    if (temp < 10)
    {
        temperatura_atual = MUITO_FRIO;
    }
    else if (temp >= 10 && temp <= 17.9)
    {
        temperatura_atual = FRIO;
    }
    else if (temp >= 18 && temp <= 25)
    {
        temperatura_atual = AGRADAVEL;
    }
    else if (temp >= 25.1 && temp <= 32)
    {
        temperatura_atual = QUENTE;
    }
    else
    {
        temperatura_atual = MUITO_QUENTE;
    }

    return temperatura_atual;
}

int main()
{
    enum Faixa_Temperatura faixa_final;
    float temperatura;

    printf("Informe uma temperatura para que seja classificada\n");
    printf("Temperatura: ");
    scanf("%f", &temperatura);
    faixa_final = (enum Faixa_Temperatura)leitor_temperatura(temperatura);

    switch (faixa_final)
    {
    case 0:
        printf("Muito frio!\n");
        break;
    case 1:
        printf("Frio!\n");
        break;
    case 2:
        printf("Agradável!\n");
        break;
    case 3:
        printf("Quente!\n");
        break;
    case 4:
        printf("Muito quente!\n");
        break;
    default:
        printf("ERRO!\n");
        break;
    }

    return 0;
}