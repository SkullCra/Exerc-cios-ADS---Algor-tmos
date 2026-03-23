#include <stdio.h>

int main (){
    float valorVisita, valorServico, totalServico, horasTrab, valorTotal, horasTotal, totalVisitas;
    int qtdVisitas;

    printf("Quantas visitas você fez hoje? ");
    scanf("%d", &qtdVisitas);

    printf("Qual o valor por visita? ");
    scanf("%f", &valorVisita);

    printf("Quanto tempo você trabalhou hoje? ");
    scanf("%f", &horasTrab);

    printf("Qual o valor do serviço prestado? ");
    scanf("%f", &valorServico);

    totalVisitas = (valorVisita * qtdVisitas);
    totalServico = (valorServico * horasTrab);
    valorTotal = (totalVisitas + totalServico);
    
    printf("O valor que deverá ser cobrado é de: %.2f reais. \n", valorTotal);
    printf("Em um mês você receberá: %.2f reais.\n", valorTotal * 30);
    return 0;
}