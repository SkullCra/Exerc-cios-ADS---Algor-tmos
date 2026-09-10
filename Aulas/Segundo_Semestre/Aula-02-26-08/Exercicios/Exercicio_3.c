#include <stdio.h>

enum Operacao
{
    SAIR = 0,
    SOMAR = 1,
    SUBTRAIR = 2,
    MULTIPLICAR = 3,
    DIVIDIR = 4
};

float somar(float num1, float num2)
{
    float somado = num1 + num2;
    return somado;
}

float subtrair(float num1, float num2)
{
    float subtraido = num1 - num2;
    return subtraido;
}

float multiplicar(float num1, float num2)
{
    float multiplicado = num1 * num2;
    return multiplicado;
}

float dividir(float num1, float num2)
{
    float divisao = num1 / num2;
    return divisao;
}

int main()
{
    int opcao_menu;
    float numero_1 = 0.0, numero_2 = 0.0, resultado = 0.0;
    enum Operacao Operacao_Selecionada;

    do
    {
        do
        {
            printf("\n");
            printf("Selecione uma opção:\n");
            printf("1 - Somar\n");
            printf("2 - Subtrair\n");
            printf("3 - Multiplicar\n");
            printf("4 - Dividir\n");
            printf("0 - Sair\n");
            printf("Sua escolha: ");
            scanf("%d", &opcao_menu);
            if (opcao_menu < SAIR || opcao_menu > DIVIDIR)
            {
                printf("ERRO: Opção inválida!\n");
            }
        } while (opcao_menu < SAIR || opcao_menu > DIVIDIR);

        Operacao_Selecionada = (enum Operacao)opcao_menu;

        switch (Operacao_Selecionada)
        {
        case SAIR:
            printf("Você escolheu sair...\n");
            return 0;
            break;
        case SOMAR:
            printf("Informe o primeiro número: ");
            scanf("%f", &numero_1);
            printf("Informe o segundo número: ");
            scanf("%f", &numero_2);
            resultado = somar(numero_1, numero_2);
            printf("O resultado é %.2f.\n", resultado);
            break;
        case SUBTRAIR:
            printf("Informe o primeiro número: ");
            scanf("%f", &numero_1);
            printf("Informe o segundo número: ");
            scanf("%f", &numero_2);
            resultado = subtrair(numero_1, numero_2);
            printf("O resultado é %.2f.\n", resultado);
            break;
        case MULTIPLICAR:
            printf("Informe o primeiro número: ");
            scanf("%f", &numero_1);
            printf("Informe o segundo número: ");
            scanf("%f", &numero_2);
            resultado = multiplicar(numero_1, numero_2);
            printf("O resultado é %.2f.\n", resultado);
            break;
        case DIVIDIR:
            do
            {
                printf("Informe o primeiro número: ");
                scanf("%f", &numero_1);
                if (numero_1 == 0)
                {
                    printf("ERRO: Divisão por zero é impossível!\n");
                }
            } while (numero_1 == 0);

            do
            {
                printf("Informe o segundo número: ");
                scanf("%f", &numero_2);
                if (numero_2 == 0)
                {
                    printf("ERRO: Divisão por zero é impossível!\n");
                }
            } while (numero_2 == 0);
            resultado = dividir(numero_1, numero_2);
            printf("O resultado é %.2f.\n", resultado);
            break;
        }
    } while (opcao_menu != SAIR);

    return 0;
}