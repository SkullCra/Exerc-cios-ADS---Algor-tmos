#include <stdio.h>

float calcular_desconto(float valor_venda, float percentual_venda)
{
    return valor_venda * percentual_venda / 100.0;
}

float calcular_valor_final(float valor_venda, float desconto)
{
    return valor_venda - desconto;
}

int main()
{
    float venda = 0.0;
    float percentual = 0.0;
    float desconto_aplicado = 0.0;
    float valor_final = 0.0;

    printf("Informe o valor da venda: ");
    scanf("%f", &venda);

    printf("Informe o percentual de desconto: ");
    scanf("%f", &percentual);

    desconto_aplicado = calcular_desconto(venda, percentual);
    valor_final = calcular_valor_final(venda, desconto_aplicado);

    printf("O valor original do produto era de R$ %.2f.\n", venda);
    printf("O desconto aplicado foi de R$ %.2f.\n", desconto_aplicado);
    printf("O valor final ficou em R$ %.2f.\n", valor_final);

    return 0;
}