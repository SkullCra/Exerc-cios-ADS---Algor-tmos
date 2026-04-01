#include <stdio.h>
#include <math.h>

int main () {
    float angulo;

    printf ("Informe o primeiro ângulo do triângulo: ");
    scanf ("%f", &angulo);

    if (angulo == 90) {
        printf ("É um triângulo retângulo.\n");
    }
    else if (angulo > 90) {
        printf ("É um triângulo obtusângulo.\n");
    }
    else if (angulo < 90) {
        printf ("É um triângulo acutângulo.\n");

    }

    return 0;
}