#include <stdio.h>

int main () {
    float altura, vel, vel2, velQuadrado, tempo, g;

    g = 9.8;

    printf("Insira a altura da queda (em metros): ");
    scanf("%f", &altura);

    vel2 = (2 * g * altura);

    vel = 1.0;
    vel = 0.5 * (vel + (vel2 / vel));
    vel = 0.5 * (vel + (vel2 / vel));
    vel = 0.5 * (vel + (vel2 / vel));
    vel = 0.5 * (vel + (vel2 / vel));
    vel = 0.5 * (vel + (vel2 / vel));

    printf("A velocidade de queda do objeto é de: %.2f m/s\n", vel);

    return 0;
}