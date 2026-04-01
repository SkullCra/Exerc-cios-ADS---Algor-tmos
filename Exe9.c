#include <stdio.h>
#include <math.h>

int main () {
    float altura, pesoIdeal;
    int sexo, opção;

    printf("*** Descubra seu peso ideal ***\n");
    printf("*** Insira ele como o seguinte exemplo: 1.80. ***\n");
    printf("--- Menu ---\n");
    printf("1 - Feminino\n");
    printf("2 - Masculino\n");
    printf("0 - Sair\n\n");
    scanf("%d", &opção);

    switch (opção) {
        case 1: {
            printf("Informe a sua altura: ");
            scanf("%f", &altura);
            pesoIdeal = (62.1 * altura) - 44.7;
            printf ("Seu peso ideal é: %.2f kg.", pesoIdeal);
        }
        break;
        case 2: {
            printf("Informe a sua altura: ");
            scanf("%f", &altura);
            pesoIdeal = (72.7 * altura) - 58;
            printf ("Seu peso ideal é: %.2f kg.", pesoIdeal);
        }
        break;
        case 0: {
            printf("Saindo...\n");
            return 0;
        }
    }
    return 0;
}