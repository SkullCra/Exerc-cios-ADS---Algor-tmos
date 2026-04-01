#include <stdio.h>

int main () {
    int nascimento, anoEleitoral, voto;

    printf ("Informe qual o ano eleitoral atual: ");
    scanf ("%d", &anoEleitoral);

    printf ("Informe o ano do seu nascimento: ");
    scanf ("%d", &nascimento);

    voto = (anoEleitoral - nascimento);

    if (voto >= 16) {
        printf ("Você pode votar.\n");
    }
    else {
        printf ("Você não pode votar.");
    }

    return 0;
}