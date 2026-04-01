#include <stdio.h>
#include <math.h>

int main () {
    float lado1, lado2, lado3, lado4, lado5, lado6, triangulo, s;
    int lados;

    printf("*** Programa de identificação de polígonos regulares ***\n\n");
    printf("Quantos lados serão informados?\n ");
    scanf("%d", &lados);

    if (lados == 3) {
        printf("É um triângulo.\n");
        printf ("Informe o primeiro lado: ");
        scanf ("%f", &lado1);

        printf ("Informe o segundo lado: ");
        scanf ("%f", &lado2);

        printf ("Informe o terceiro lado: ");
        scanf ("%f", &lado3);

        s = (lado1 + lado2 + lado3) / 2.0;
        triangulo = sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));

        printf ("O valor da área do triângulo é de: %.2f.", triangulo);
    }
    else if (lados = 4) {
        printf("É um quadrado.\n");
        printf("Informe o primeiro lado: ");
        scanf("%f", &lado1);
        
        printf("Informe o segundo lado: ");
        scanf("%f", &lado2);

        

    }

    return 0;
}