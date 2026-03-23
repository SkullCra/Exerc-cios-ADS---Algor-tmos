#include <stdio.h>

int main () {
    int tempF, tempC;
    float formula;
    
    printf("Insira a temperatura em Fahrenheit que deseja converter para Celsius: ");
    scanf("%d", &tempF);

    formula = (tempF - 32.0) * (5.0/9.0);

    tempC = formula;

    printf("A temperatura em graus Celsius é de: %d\n", tempC);

    return 0;

}

//Este código está errado propositalmente, pois o professor pediu para usar exatamente
//essa fórmula para calcular, porém, temos de forçar o cálculo para Float, sendo assim,
// o cálculo real deveria ser: tempC = (tempF - 32) * (5.0/9.0);
