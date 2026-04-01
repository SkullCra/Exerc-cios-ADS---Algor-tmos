#include <stdio.h>

int main () {
    int num1, num2, num3;

    printf("--- Organizador de números inteiros ---\n");
    printf("Seus números serão organizados de forma crescente.\n\n");
    
    printf("Informe o primeiro número: ");
    scanf("%d", &num1);

    printf("Informe o segundo número: ");
    scanf("%d", &num2);

    printf("Informe o terceiro número: ");
    scanf("%d", &num3);

    if (num1 > num2 && num2 > num3) {
        printf ("A sequência é %d, %d, %d.", num3, num2, num1);
    }
    else if (num2 < num3 && num3 < num1) {
        printf ("A sequência é %d, %d, %d.", num2, num3, num1);
    }
    else if (num2 > num1 && num1 > num3) {
        printf ("A sequência é %d, %d, %d.", num3, num1, num2);
    }
    else if (num1 < num3 && num3 < num2) {
        printf ("A sequência é %d, %d, %d.", num1, num3, num2);
    }
    else if (num3 > num1 && num1 > num2) {
        printf ("A sequência é %d, %d, %d.", num2, num1, num3);
    }
    else if (num3 < num1 && num1 < num2) {
        printf ("A sequência é %d, %d, %d.", num3, num1, num2);
    }
    else if (num1 < num2 && num2 < num3) {
        printf ("A sequência é %d, %d, %d.", num1, num2, num3);
    }
    return 0;
}