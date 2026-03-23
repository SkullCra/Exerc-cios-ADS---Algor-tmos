#include <stdio.h>

int main () {
    float tempo, deslocamento, velMedia;

    printf("Informe o intervalo de deslocamento: ");
    scanf("%f", &deslocamento);

    printf("Informe o tempo em que a distância foi percorrida(horas): ");
    scanf("%f", &tempo);

    velMedia = (deslocamento / tempo);

    printf("A velocidade média foi de: %.2f km/h", velMedia);

    return 0;
}