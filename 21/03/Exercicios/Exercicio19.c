#include <stdio.h>

int main (){
    int a, b, c, d, e, f, x, y;

    printf("Escreva o valor de a: ");
    scanf("%d", &a);

    printf("Escreva o valor de b: ");
    scanf("%d", &b);

    printf("Escreva o valor de c: ");
    scanf("%d", &c);

    printf("Escreva o valor de d: ");
    scanf("%d", &d);

    printf("Escreva o valor de e: ");
    scanf("%d", &e);

    printf("Escreva o valor de f: ");
    scanf("%d", &f);

    x = (c * e) - (b * f) / (a * e) - (b * d);
    y = (a * f) - (c * d) / (a * e) - (b *d);

    printf("Os valores de x e y, respectivamente, são: %d e %d.\n", x, y);

    return 0;

}