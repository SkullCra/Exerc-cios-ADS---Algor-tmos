#include <stdio.h>
int main(void)
{
    int valores[] = {10, 20, 30, 40, 50};
    int quantidade = sizeof(valores) / sizeof(valores[0]);
    int *p = valores;
    for (int i = 0; i < quantidade; i++)
    {
        printf("valores[%d] = %d\n", i, *(p + i));
    }
    return 0;
}