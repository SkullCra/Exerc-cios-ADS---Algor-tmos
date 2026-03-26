#include <stdio.h>

int main () {
    float fahrenheit, celsius, resultado;
    printf("Informe o valor em Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32.0) * (5.0/9.0);

    printf("O valor em Celsius é de: %.2f\n", celsius);

    return 0;
}