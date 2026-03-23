#include <stdio.h>

int main () {
    float a, b, c, delta;

    printf("Informe o valor de a: ");
    scanf("%f", &a);

    printf("Informe o valor de b: ");
    scanf("%f", &b);

    printf("Informe o valor de c: ");
    scanf("%f", &c);

    delta = (b * b) - (4 * a * c);

    printf("O delta é: %.2f\n", delta);
    
    return 0;
}