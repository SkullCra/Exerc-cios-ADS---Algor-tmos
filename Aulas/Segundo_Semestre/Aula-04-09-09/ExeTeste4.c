#include <stdio.h.>

int main()
{
    int numeros[] = {10, 20, 30, 40};
    int *p = numeros;
    printf("%d\n", *p); // 10
    p++;
    printf("%d\n", *p); // 20

    return 0;
}