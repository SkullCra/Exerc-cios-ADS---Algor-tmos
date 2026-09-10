#include <stdio.h>
int main(void)
{
    int numero = 10;
    int *p = &numero;
    printf("Endereço de numero: %p\n", (void *)&numero);
    printf("Valor armazenado em p: %p\n", (void *)p);
    printf("Endereço da própria variável p: %p\n", (void *)&p);
    return 0;
}