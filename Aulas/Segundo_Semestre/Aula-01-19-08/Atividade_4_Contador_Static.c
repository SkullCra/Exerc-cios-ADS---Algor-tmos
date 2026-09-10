#include <stdio.h>

int registrar_acesso(void)
{
    static int acessos = 0;
    acessos++;

    return acessos;
}

int main()
{
    int opcao = 0;

    do
    {
        printf("%dº Acesso.\n", registrar_acesso());
        printf("Deseja realizar um novo acesso? 1 - Sim | 0 - Não\n");
        printf("Sua escolha: ");
        scanf("%d", &opcao);
    } while (opcao == 1);

    return 0;
}