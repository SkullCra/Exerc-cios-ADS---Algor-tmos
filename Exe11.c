#include <stdio.h>
#include <math.h>

int main () {
    float lado1, lado2, lado3, lado4, lado5, lado6, area, s;
    int lados;

    printf("*** Programa de identificação de polígonos regulares ***\n\n");
    printf("Quantos lados serão informados?\n");
    scanf("%d", &lados);

    if (lados == 3) {
        printf("É um triângulo.\n");
        printf ("Informe o primeiro lado: ");
        scanf ("%f", &lado1);

        printf ("Informe o segundo lado: ");
        scanf ("%f", &lado2);

        printf ("Informe o terceiro lado: ");
        scanf ("%f", &lado3);

        s = (lado1 + lado2 + lado3) / 2;
        area = sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));

        printf ("O valor da área do triângulo é de: %.2f.", area);
    }
    else if (lados == 4) {
        printf("É um quadrado.\n");
        printf("Informe o valor do lado: ");
        scanf("%f", &lado1);
        
        area = pow(lado1, 2);

        printf ("O valor da área do quadrado é de: %.2f.", area);
    }
    else if (lados == 5) {
        printf("É um pentágono.\n");
        printf("Informe o valor do lado: ");
        scanf("%f", &lado1);

        area = (pow(lado1, 2) * sqrt (25 + 10 * sqrt(5))) / 4;

        printf ("O valor da área do quadrado é de: %.2f.", area);
    }
    else if (lados < 3) {
        printf ("Não é um polígono, saindo...");
    }
    else if (lados > 5) {
        printf ("Polígono não identificado, saindo...");
    }
    return 0;
    }