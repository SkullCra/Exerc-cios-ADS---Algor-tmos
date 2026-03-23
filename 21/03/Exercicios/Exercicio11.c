#include <stdio.h>

int main () {
    float tempo, distancia, velocidade;

    printf("Informe a velocidade média do veículo(Km/h): ");
    scanf("%f", &velocidade);

    printf("Informe o tempo do percurso(Min): ");
    scanf("%f", &tempo);

    tempo = (tempo / 60);
    distancia = (velocidade * tempo);
    
    printf("A distância percorrida pelo veículo foi de: %.2f km.", distancia);

    return 0;

}