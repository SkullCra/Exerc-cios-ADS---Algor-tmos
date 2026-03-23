#include <stdio.h>

int main () {
int idade, iDias, iAnos, iMeses;

printf ("Informe a sua idade: ");
scanf ("%d", &idade);

iDias = idade * 365;
iMeses = idade * 12;

printf ("A sua idade expressa em dias é de: %d.\n", iDias);
printf ("A sua idade expressa em anos é: %d.\n", idade);
printf ("A sua idade expressa em meses é: %d.\n", iMeses);

return 0;

}