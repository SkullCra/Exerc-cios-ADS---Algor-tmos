#include <stdio.h>

int main () {
    float tempF, tempC;
    
    printf("Insira a temperatura em Fahrenheit que deseja converter para Celsius: ");
    scanf("%f", &tempF);

    tempC = (tempF - 32.0) * (5.0/9.0);

    printf("A temperatura em graus Celsius é de: %.2f\n", tempC);
}