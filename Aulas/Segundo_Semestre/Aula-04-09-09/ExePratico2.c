#include <stdio.h>

int main () {
    int numero = 10;
    int *p = &numero;

    *p = 50;

    printf("%d\n", numero);
    printf("%d\n", *p);

    return 0;
}