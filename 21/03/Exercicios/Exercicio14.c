#include <stdio.h>

int main (){
    float valorCompra, tempoCompra, mediaAnual, taxa, valorAtual;

    printf("Informe o valor da compra: ");
    scanf("%f", &valorCompra);

    printf("Informe o tempo até pagar a compra(ANOS): ");
    scanf("%f", &tempoCompra);

    printf("Informe o valor médio anual de depreciação: ");
    scanf("%f", &mediaAnual);

    valorAtual = valorCompra - (mediaAnual * tempoCompra);
    taxa = (mediaAnual / valorCompra) * 100;

    printf("O valor depreciado da máquina após realizar o pagamento total será de: R$ %.2f, com uma taxa de depreciação anual de: %.2f por cento ao ano.\n", valorAtual, taxa);

    return 0;
}