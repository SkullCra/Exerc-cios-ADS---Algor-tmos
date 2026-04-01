#include <stdio.h>

int main () {
    int senha;

    printf ("Informe a senha para acessar o dispositivo: ");
    scanf ("%d", &senha);

    if (senha == 1234) {
        printf ("ACESSO PERMITIDO\n\n");
    }
    else {
        printf ("ACESSO NEGADO\n\n");
    }

    return 0;
}