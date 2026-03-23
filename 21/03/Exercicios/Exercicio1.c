#include <stdio.h>

int main (){
float nota1, nota2, nota3, media;

printf("Insira a primeira nota: ");
scanf("%f", &nota1);

printf("Insira a segunda nota: ");
scanf("%f", &nota2);

printf("Insira a terceira nota: ");
scanf("%f", &nota3);

media = (nota1 + nota2 + nota3) / 3;

printf("A média das notas é: %.2f\n", media);
printf("Suas notas são: %.1f, %.1f, %.1f\n", nota1, nota2, nota3);
}






