#include <stdio.h>
int main () {
    int a, b, c, d, r, s;

    printf("Informe o valor de a: ");
    scanf("%d", &a);
    printf("Informe o valor de b: ");
    scanf("%d", &b);
    printf("Informe o valor de c: ");
    scanf("%d", &c);
    
    r = (a + b) * (a + b);
    s = (b + c) * (b + c);

    d = (r + s) / 2;

    printf ("O valor de d é: %d.\n", d);

    return 0;
}