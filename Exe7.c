#include <stdio.h>

int main () {
    float maçãs, totalCompra;

    printf ("Quantas maçãs você comprou? ");
    scanf ("%f", &maçãs);

    if (maçãs < 12) {
        totalCompra = (maçãs * 0.30);
        printf ("O valor total da compra é de: R$ %.2f.\n", totalCompra);
    }
    else if (maçãs >= 12) {
        totalCompra = (maçãs * 0.25);
        printf ("O valor total da compra é de: R$ %.2f.\n", totalCompra);
    }

    return 0;
}