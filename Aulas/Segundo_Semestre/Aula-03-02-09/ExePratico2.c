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
    int qtd = 5;
    Aluno aluno[5];

    for (int i = 0; i < qtd; i++)
    {
        printf("Informe a matrícula do aluno: ");
        scanf("%d", &aluno[i].matricula);
        limparBuffer();

        ler_string(aluno[i].nome, 50, "Informe o nome do aluno: ");

        printf("Informe a média do aluno: ");
        scanf("%f", &aluno[i].media);
    }

    imprimirTurma(aluno, 5);

    float soma = 0.0;
    float mediaTurma = 0.0;

    for (int i = 0; i < qtd; i++)
    {
        soma += aluno[i].media;
    }

    mediaTurma = soma / qtd;

    printf("A média da turma é de %.2f.\n", mediaTurma);

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

    int matriculaDesejada;
    int achouMatricula = 0;
    printf("Digite uma matrícula para pesquisar: ");
    scanf("%d", &matriculaDesejada);
    limparBuffer();
    achouMatricula = buscarMatricula(aluno, 5, matriculaDesejada);

    if (achouMatricula != -1)
    {
        imprimirAluno(aluno[achouMatricula]);
    }
    else
    {
        printf("Aluno não encontrado!\n");
    }

    int QtdAprovados = contarAprovados(aluno, 5);
    listarAprovado(aluno, 5);

    return 0;
}