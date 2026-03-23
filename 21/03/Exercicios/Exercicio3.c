#include <stdio.h>

int main () {
    float numero1, numero2, soma, sub, div, mult;

    printf("Insira o primeiro número: ");
    scanf("%f", &numero1);

    printf("Insira o segundo número: ");
    scanf("%f", &numero2);

    soma = (numero1 + numero2);
    sub = (numero1 - numero2);
    div = (numero1 / numero2);
    mult = (numero1 * numero2);

    printf("A soma dos seus numeros é: %.2f\n", soma);
    printf("A subtração dos seus números é: %.2f\n", sub);
    printf("A divisão dos seus números é: %.2f\n", div);
    printf("A multiplicação dos seus números é: %.2f\n", mult);

    return 0;
}