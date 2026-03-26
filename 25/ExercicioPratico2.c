#include <stdio.h>
#include <math.h>

int main (){
    int a, b, c;
    float delta;

    printf("------------ Cálculo do Delta ------------\n\n");

    printf("Informe o valor de a: ");
    scanf("%d", &a);

    printf("Informe o valor de b: ");
    scanf("%d", &b);

    printf("Informe o valor de c: ");
    scanf("%d", &c);

    delta = pow(b,2) - (4*a*c);

    printf("O valor de delta é: %.2f.\n", delta);

    return 0;

}