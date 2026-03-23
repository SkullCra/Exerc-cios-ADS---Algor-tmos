#include <stdio.h>

int main (){
    float metros, deci, centi, mili;

    printf("Insira o valor em metros que deseja ser convertido: ");
    scanf("%f", &metros);

    deci = (metros * 10);
    centi = (metros * 100);
    mili = (metros * 1000);

    printf("Os valores de %.2f metros convertidos, são de: \n", metros);
    printf("Em decímetros: %.2f\n", deci);
    printf("Em centímetros: %.2f\n", centi);
    printf("Em milímetros: %.2f\n", mili);

    return 0;
}