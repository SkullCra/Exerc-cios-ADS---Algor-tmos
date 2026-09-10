#include <stdio.h>

float calcularMedia(float nota1, float nota2)
{
    float media = (nota1 + nota2) / 2.0;
    return media;
}

int main()
{
    float primeira_nota = 0.0;
    float segunda_nota = 0.0;
    float media_final = 0.0;

    printf("Informe a primeira nota: ");
    scanf("%f", &primeira_nota);

    printf("Informe a segunda nota: ");
    scanf("%f", &segunda_nota);

    media_final = calcularMedia(primeira_nota, segunda_nota);

    printf("Média: %.2f\n", media_final);

    return 0;
}