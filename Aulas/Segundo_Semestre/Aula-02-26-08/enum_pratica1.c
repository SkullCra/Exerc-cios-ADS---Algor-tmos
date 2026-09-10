#include <stdio.h>

enum dias_semana
{
    DOMINGO,
    SEGUNDA,
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO
};

int main()
{
    int opcao;
    enum dias_semana dia_selecionado;

    do
    {
        printf("Selecione um dia da semana:\n");
        printf("0 - Domingo\n");
        printf("1 - Segunda\n");
        printf("2 - Terça\n");
        printf("3 - Quarta\n");
        printf("4 - Quinta\n");
        printf("5 - Sexta\n");
        printf("6 - Sábado\n");
        printf("Sua escolha: ");
        scanf("%d", &opcao);

        if (opcao < DOMINGO || opcao > SABADO)
        {
            printf("Erro: Dia da semana selecionado não existe!\n");
        }
    } while (opcao < DOMINGO || opcao > SABADO);

    dia_selecionado = (enum dias_semana)opcao;

    switch (dia_selecionado)
    {
    case DOMINGO:
        printf("Hoje é domingo, dia %d!\n", DOMINGO);
        break;
    case SEGUNDA:
        printf("Hoje é segunda-feira, dia %d!\n", SEGUNDA);
        break;
    case TERCA:
        printf("Hoje é terça-feira, dia %d!\n", TERCA);
        break;
    case QUARTA:
        printf("Hoje é quarta-feira, dia %d!\n", QUARTA);
        break;
    case QUINTA:
        printf("Hoje é quinta-feira, dia %d!\n", QUINTA);
        break;
    case SEXTA:
        printf("Hoje é sexta-feira, dia %d!\n", SEXTA);
        break;
    case SABADO:
        printf("Hoje é sábado, dia %d!\n", SABADO);
        break;
    default:
        printf("Erro: Opção inválida!\n");
        break;
    }

    return 0;
}