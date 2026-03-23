#include <stdio.h>

int main () {
float base, altura, area;

printf("Insira a base do triângulo: ");
scanf("%f", &base);

printf("Insira a altura do triângulo: ");
scanf("%f", &altura);

area = (base * altura) / 2;

printf("A área do triângulo é: %.2f\n", area);

return 0;
}