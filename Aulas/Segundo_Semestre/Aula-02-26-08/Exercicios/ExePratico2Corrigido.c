#include <stdio.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nome[50];
    float media;
} Aluno;

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void ler_string(char destino[], int tamanho, char mensagem[])
{
    do
    {
        printf("%s", mensagem);
        fgets(destino, tamanho, stdin);
        destino[strcspn(destino, "\n")] = '\0';

        if (strlen(destino) == 0)
        {
            printf("ERRO: O campo nao pode ser vazio.\n");
        }
    } while (strlen(destino) == 0);
}

void imprimirAluno(Aluno aluno)
{
    printf("Matrícula: %d\n", aluno.matricula);
    printf("Nome: %s.\n", aluno.nome);
    printf("Média: %.2f.\n", aluno.media);
}

void imprimirTurma(Aluno aluno[], int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        imprimirAluno(aluno[i]);
    }
}

int buscarMatricula(Aluno aluno[], int qtd, int matricula)
{
    for (int i = 0; i < qtd; i++)
    {
        if (aluno[i].matricula == matricula)
        {
            return i;
        }
    }
    return -1;
}

int contarAprovados(Aluno aluno[], int qtd)
{
    int contador = 0;
    for (int i = 0; i < qtd; i++)
    {
        if (aluno[i].media >= 7.0)
        {
            contador++;
        }
    }
    return contador;
}

void listarAprovado(Aluno aluno[], int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        if (aluno[i].media >= 7.0)
        {
            imprimirAluno(aluno[i]);
        }
    }
}

int main()
{
    int qtd;
    int opcao;

    printf("Informe a quantidade de alunos que deseja cadastrar: ");
    scanf("Sua resposta: ");
    scanf("%d", &qtd);
    limparBuffer();
    Aluno aluno[qtd];

    for (int i = 0; i < qtd; i++)
    {
        printf("===== CADASTRO DE ALUNO %d de %d =====\n", i + 1, qtd);
        do
        {
            printf("Informe a matrícula do aluno: ");
            scanf("%d", &aluno[i].matricula);
            if (aluno[i].matricula < 0)
            {
                printf("ERRO: Valor não pode ser menor que zero!\n");
            }
        } while (aluno[i].matricula < 0);
        limparBuffer();

        ler_string(aluno[i].nome, 50, "Informe o nome do aluno: ");

        do
        {
            printf("Informe a média do aluno: ");
            scanf("%f", &aluno[i].media);
            if (aluno[i].media < 0)
            {
                printf("ERRO: Valor não pode ser menor que zero!\n");
            }
        } while (aluno[i].media < 0);
        limparBuffer();
    }

    printf("==== CADASTRO CONCLUÍDO! ====\n");
    printf("==== TURMA REGISTRADA ====\n");
    imprimirTurma(aluno, qtd);

    do
    {
        do
        {
            printf("\nO que deseja realizar?\n");
            printf("1 - Calcular a média da turma\n");
            printf("2 - Verificar maior média\n");
            printf("3 - Localizar matrícula\n");
            printf("4 - Verificar e listar aprovados\n");
            printf("0 - Sair\n");
            printf("Sua escolha: ");
            scanf("%d", &opcao);
            if (opcao < 0 || opcao > 4)
            {
                printf("ERRO: Opção inválida!\n");
            }
        } while (opcao < 0 || opcao > 4);

        switch (opcao)
        {
        case 0:
            printf("Saindo...\n");
            return 0;
            break;
        case 1:
            float soma = 0.0;
            float mediaTurma = 0.0;

            for (int i = 0; i < qtd; i++)
            {
                soma += aluno[i].media;
            }
            mediaTurma = soma / qtd;

            printf("A média da turma é de %.2f.\n", mediaTurma);
            break;
        case 2:
            int indiceMaior = 0;

            for (int i = 1; i < qtd; i++)
            {
                if (aluno[i].media > aluno[indiceMaior].media)
                {
                    indiceMaior = i;
                }
            }
            printf("O aluno com a maior média é %s.\n", aluno[indiceMaior].nome);
            printf("Sua média é de %.2f.\n", aluno[indiceMaior].media);
            break;
        case 3:
            int matriculaDesejada;
            int achouMatricula = 0;
            printf("Digite uma matrícula para pesquisar: ");
            scanf("%d", &matriculaDesejada);
            limparBuffer();
            achouMatricula = buscarMatricula(aluno, qtd, matriculaDesejada);

            if (achouMatricula != -1)
            {
                imprimirAluno(aluno[achouMatricula]);
            }
            else
            {
                printf("Aluno não encontrado!\n");
            }
            break;
        case 4:
            int QtdAprovados = contarAprovados(aluno, qtd);
            printf("A quantidade de aprovados são de %d alunos.\n", QtdAprovados);
            printf("==== LISTA DE APROVADOS ====\n");
            listarAprovado(aluno, qtd);
            break;
        default:
            printf("ERRO: Opção inválida!\n");
        }

    } while (opcao != 0);
    return 0;
}