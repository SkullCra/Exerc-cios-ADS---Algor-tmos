#include <stdio.h>
#include <math.h>

int main () {
    float nota1, nota2, nota3, media;

    printf ("Informe a primeira nota: ");
    scanf ("%f", &nota1);
    
    printf ("Informe a segunda nota: ");
    scanf ("%f", &nota2);

    printf ("Informe a terceira nota: ");
    scanf ("%f", &nota3);

    media = (nota1 + nota2 + nota3) / 3;

    if (media >= 7){
        printf ("Parabéns, você está aprovado.\n");
    }
    else {
        printf ("Infelizmente você foi reprovado.\n");
    }

    printf ("Suas notas foram: %.2f, %.2f e %.2f, e sua média foi de %.2f.\n", nota1, nota2, nota3, media);

    return 0;
}