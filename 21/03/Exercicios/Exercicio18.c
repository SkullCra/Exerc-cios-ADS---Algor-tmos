#include <stdio.h>

int main () {
    float custoFabrica, custoConsumidor, distribuidor, impostos, custoImposto;

    printf("Informe o custo de fábrica do veículo: ");
    scanf("%f", &custoFabrica);

    printf("Informe o imposto aplicado: ");
    scanf("%f", &impostos);

    printf("Informe a porcentagem do distribuidor: ");
    scanf("%f", &distribuidor);

    custoImposto = (custoFabrica * impostos) / 100;
    distribuidor = (custoFabrica * distribuidor) / 100;
    custoConsumidor = custoFabrica + distribuidor + custoImposto;

    printf ("O custo ao consumidor será de: R$ %.2f.\n", custoConsumidor);
    
}