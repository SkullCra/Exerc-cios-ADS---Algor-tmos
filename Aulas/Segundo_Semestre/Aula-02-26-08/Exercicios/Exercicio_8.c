#include <stdio.h>

struct Data
{
    int dia;
    int mes;
    int ano;
};

int main()
{
    struct Data d1, d2;

    printf("Informe a primeira data:\n");
    printf("Dia: ");
    scanf("%d", &d1.dia);
    printf("Mês: ");
    scanf("%d", &d1.mes);
    printf("Ano: ");
    scanf("%d", &d1.ano);
    printf("Informe a segunda data:\n");
    printf("Dia: ");
    scanf("%d", &d2.dia);
    printf("Mês: ");
    scanf("%d", &d2.mes);
    printf("Ano: ");
    scanf("%d", &d2.ano);

    if (d1.ano == d2.ano && d1.mes == d2.mes && d1.dia == d2.dia)
    {
        printf("As duas datas são iguais: %d/%d/%d\n", d1.dia, d1.mes, d1.ano);
    }
    else
    {
        int d1_maisAntiga = 0;
        if (d1.ano < d2.ano)
        {
            d1_maisAntiga = 1;
        }
        else if (d1.ano == d2.ano && d1.mes < d2.mes)
        {
            d1_maisAntiga = 1;
        }
        else if (d1.ano == d2.ano && d1.mes == d2.mes && d1.dia < d2.dia)
        {
            d1_maisAntiga = 1;
        }

        if (d1_maisAntiga == 1)
        {
            printf("A data mais antiga é %d/%d/%d.\n", d1.dia, d1.mes, d1.ano);
            printf("A data mais recente é: %d/%d/%d.\n", d2.dia, d2.mes, d2.ano);
        }
        else
        {
            printf("A data mais antiga é %d/%d/%d.\n", d2.dia, d2.mes, d2.ano);
            printf("A data mais recente é: %d/%d/%d.\n", d1.dia, d1.mes, d1.ano);
        }
    }

    return 0;
}