#include <stdio.h>
#include <math.h>

int main () {
    float num1, num2, resultado;
    int opção;

    printf("Digite o primeiro número: ");
    scanf("%f", &num1);

    printf("Digite o segundo número: ");
    scanf("%f", &num2);

    printf("--- Menu ---\n");
    printf("1 - Soma\n");
    printf("2 - Subtração\n");
    printf("3 - Multiplicação\n");
    printf("4 - Divisão\n");
    printf("5 - Potenciação\n");
    printf("6 - Radiciação\n");
    printf("0 - Sair\n");
    printf("%d", &opção);

    switch (opção) {
        case 1: {
            resultado = num1 + num2;
            printf ("A soma dos números é: %.2f", resultado);
        }
        break;
        case 2: {
            resultado = num1 - num2;
            printf ("A subtração dos números é: %.2f", resultado);
        }
        break;
        case 3: {
            resultado = num1 * num2;
            printf ("A multiplicação dos números é: %.2f", resultado);
        }
        break;
        case 4: {
            if (num1 != 0 && num2 != 0) {
                printf("Divisão: %.2f / %.2f\n", num1, num2, num1 / num2);
            }
            else {
                printf("Divisão: Não é possível dividir por zero!\n");
            }
        }
        break;
        case 5: {
            resultado = pow(num1, num2);
            if (isnan(resultado)) {
                printf("Erro - Resultado indeferido (NaN)!\n");
            }
            else {
                printf ("Resultado: %.2f", resultado);
            }
        }
        break;
        case 6: {
            /* code */
        }
        break;
        case 7: {
            /* code */
        }
        break;
        case 0: {

        }
    }
    
}