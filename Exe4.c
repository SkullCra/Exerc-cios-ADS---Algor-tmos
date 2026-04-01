#include <stdio.h>

int main () {
    float preço;

    printf ("----Simulador de BRASIL (Inflacionador de preços)----\n");
    printf ("Este programa irá inflacionar o valor de um produto em 15%% caso seja menor que 100,\n e em 25%% caso seja maior ou igual a 100.\n\n");
    printf ("Informe o valor do produto: ");
    scanf ("%f", &preço);

    if (preço < 100){
        preço = (preço * 0.15) + preço;
        printf ("O valor foi inflacionado em 15%%, e é de: %.2f.\n", preço); 
    }
    else if (preço >= 100){
        preço = (preço * 0.25) + preço;
        printf ("O valor foi inflacionado em 25%%, e é de: %.2f\n.", preço);
    }

    return 0;
    }