#include <stdio.h>

int main (){
    float salario, minimo, qtdSalarios;

    printf("Insira o salário mínimo atual: ");
    scanf("%f", &minimo);

    printf("Insira o seu salário atual: ");
    scanf("%f", &salario);

    qtdSalarios = (salario / minimo);

    printf("Você recebe: %.2f salários mínimos. \n", qtdSalarios);
}