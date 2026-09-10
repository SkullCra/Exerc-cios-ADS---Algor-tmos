#include <stdio.h>

int main()
{
    int idade = 10;
    int *ptr = &idade;

    printf("O valor da variável idade é: %d.\n", idade);
    printf("O valor acessado por meio do ponteiro ptr é %d.\n", *ptr);
    printf("O endereço da variável idade é %p.\n", (void *)&idade);
    printf("O endereço armazenado no ponteiro ptr é %p.\n", (void *)&ptr);

    return 0;
}
