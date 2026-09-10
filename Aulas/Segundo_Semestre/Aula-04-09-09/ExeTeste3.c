#include <stdio.h>
int main(void)
{
    int primeiro = 10;
    int segundo = 20;
    int *p;
    p = &primeiro;
    printf("Valor apontado: %d\n", *p);
    p = &segundo;
    printf("Novo valor apontado: %d\n", *p);
    return 0;
}

//Alterar o destino de p não altera automaticamente primeiro ou segundo
//Apenas muda o endereço armazenado no ponteiro