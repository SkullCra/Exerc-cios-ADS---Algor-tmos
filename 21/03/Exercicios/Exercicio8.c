#include <stdio.h>

int main () {
    int ced1, ced2, ced5, ced10, ced20, ced50, ced100, ced200, valor, qtdCedulas, resto;

    printf("Insira o valor que deseja sacar: ");
    scanf("%i", &valor);

        ced200 = valor / 200;
    resto = valor % 200;
    ced100 = resto / 100;
    resto = resto % 100;
    ced50 = resto / 50;
    resto = resto % 50;
    ced20 = resto / 20;
    resto = resto % 20;
    ced10 = resto / 10;
    resto = resto % 10;
    ced5 = resto / 5;
    resto = resto % 5;
    ced2 = resto / 2;
    resto = resto % 2;
    ced1 = resto / 1;
    resto = resto % 1;

    printf("Para o saque de R$%i serão necessárias: \n", valor);
    printf("%i notas de R$ 200. \n", ced200);
    printf("%i notas de R$ 100. \n", ced100);
    printf("%i notas de R$ 50. \n", ced50);
    printf("%i notas de R$ 20. \n", ced20);
    printf("%i notas de R$ 10. \n", ced10);
    printf("%i notas de R$ 5. \n", ced5);
    printf("%i notas de R$ 2. \n", ced2);
    printf("%i notas de R$ 1. \n", ced1);

    return 0;


}