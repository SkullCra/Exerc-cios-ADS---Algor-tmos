#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, x2, y2, d;
    float x, temp;
    float n;

    printf("Informe x1: ");
    scanf("%f", &x1);
    printf("Informe y1: ");
    scanf("%f", &y1);
    printf("Informe x2: ");
    scanf("%f", &x2);
    printf("Informe y2: ");
    scanf("%f", &y2);

    d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    printf("Distancia: %.2f\n", d);

    return 0;

}