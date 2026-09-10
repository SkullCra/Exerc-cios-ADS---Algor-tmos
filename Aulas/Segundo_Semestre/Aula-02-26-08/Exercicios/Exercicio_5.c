#include <stdio.h>

enum CorSemaforo
{
    VERMELHO,
    VERDE,
    AMARELO
};

void cor_atual(int cor)
{
    if (cor == VERMELHO)
    {
        printf("vermelho.\n");
    }
    else if (cor == VERDE)
    {
        printf("verde.\n");
    }
    else if (cor == AMARELO)
    {
        printf("amarelo.\n");
    }
}

int main()
{
    enum CorSemaforo cor_sinal;
    int opcao;
    cor_sinal = VERMELHO;

    do
    {
        for (int i = 0; i < 3; i++)
        {
            printf("A cor atual é");
            cor_atual(cor_sinal);
            printf("Deseja avançar o sinal? 1 - Sim | 2 - Não\n");
            printf("Resposta: ");
            scanf("%d", &opcao);
            cor_sinal++;
            if (cor_sinal > AMARELO)
            {
                cor_sinal = VERMELHO;
            }
            if (opcao == 2)
            {
                printf("Ok, parando.\n");
                break;
            }
        }
    } while (opcao != 2);

    return 0;
}