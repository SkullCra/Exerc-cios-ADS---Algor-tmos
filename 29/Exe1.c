#include <stdio.h>

int main () {
    int valor1, valor2;

    printf ("Informe o primeiro valor: ");
    scanf ("%d", &valor1);

    printf ("Informe o segundo valor: ");
    scanf ("%d", &valor2);

    if (valor1 < valor2) {
        printf ("O segundo valor é o maior.\n");
    }
    else if(valor1 == valor2) {
        printf ("Os valores são iguais.\n");
    }
    else {
        printf ("O primeiro valor é o maior.\n");
    }

    return 0;
}