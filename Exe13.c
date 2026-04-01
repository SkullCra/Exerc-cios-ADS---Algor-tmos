#include <stdio.h>
#include <math.h>

int main () {
    float lado1, lado2, lado3;

    printf("--- Identificador de tipos de triângulos ---\n\n");
    
    printf("Informe o valor do primeiro lado: ");
    scanf("%d", &lado1);

    printf("Informe o valor do segundo lado: ");
    scanf("%d", &lado2);

    printf("Informe o valor do terceiro lado: ");
    scanf("%d", &lado3);

    if (lado1 == lado2 & lado2 == lado3) {
        printf ("É um triângulo equilátero.\n");
    }
    else if (lado1 == lado2 && lado2 != lado3) {
        printf ("É um triângulo isóscele.\n");
    }
    else if (lado1 == lado3 && lado2 != lado1) {
        printf ("É um triângulo isóscele.\n");
    }
    else if(lado1 != lado2 && lado2 == lado3) {
        printf ("É um triângulo isóscele.\n");
    }
    else if (lado1 != lado2 && lado2 != lado3 && lado1 != lado3) {
        printf ("É um triângulo escaleno.\n");
    }
}