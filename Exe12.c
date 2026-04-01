#include <stdio.h>
#include <math.h>

int main () {
    int valor1, valor2, valor3;

    printf("Informe o primeiro valor: ");
    scanf("%d", &valor1);

    printf("Informe o segundo valor: ");
    scanf("%d", &valor2);

    printf("Informe o terceiro valor: ");
    scanf("%d", &valor3);

    if (valor1 > valor2 && valor1 > valor3) {
    printf ("O primeiro é maior.");
    }
    else if (valor2 > valor1 && valor2 > valor3) {
    printf ("O segundo é o maior.");
    }
    else if (valor3 > valor1 && valor3 > valor2) {
    printf ("O terceiro é o maior.");
    }
    

    return 0;
}