#include <stdio.h>

int main () {
    int fahrenheit, celsius;

    printf("Informe o valor em Fahrenheit: ");
    scanf("%d", &fahrenheit);

    celsius = ((float) fahrenheit - 32) * ((float) 5/9);

    printf("O valor em Celsius é de: %d", celsius);

    return 0;
}
