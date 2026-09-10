#include <stdio.h>

enum Status_Pedido
{
    RECEBIDO = 1,
    EM_PREPARACAO = 2,
    ENVIADO = 3,
    ENTREGUE = 4,
    CANCELADO = 5
};

int main()
{
    int opcao_menu;
    enum Status_Pedido Status_Selecionado;

    do
    {
        printf("Informe o status do pedido:\n");
        printf("1 - Recebido\n");
        printf("2 - Em preparação\n");
        printf("3 - Enviado\n");
        printf("4 - Entregue\n");
        printf("5 - Cancelado\n");
        printf("Sua escolha: ");
        scanf("%d", &opcao_menu);

        if (opcao_menu < RECEBIDO || opcao_menu > CANCELADO)
        {
            printf("ERRO: Opção inválida!\n");
        }
    } while (opcao_menu < RECEBIDO || opcao_menu > CANCELADO);

    Status_Selecionado = (enum Status_Pedido)opcao_menu;

    switch (Status_Selecionado)
    {
    case RECEBIDO:
        printf("Pedido recebido.\n");
        break;
    case EM_PREPARACAO:
        printf("Pedido em preparação.\n");
        break;
    case ENVIADO:
        printf("Pedido enviado.\n");
        break;
    case ENTREGUE:
        printf("Pedido entregue.\n");
        break;
    case CANCELADO:
        printf("Pedido cancelado.\n");
        break;
    default:
        printf("ERRO: Opção inválida!\n");
        break;
    }

    return 0;
}