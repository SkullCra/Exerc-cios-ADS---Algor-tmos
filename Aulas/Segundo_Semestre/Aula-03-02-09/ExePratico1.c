#include <stdio.h>
#include <string.h>

struct Aluno
{
    int matricula;
    char nome[50];
    float nota1;
    float nota2;
    float media;
};

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

float calcular_media(float primeira_nota, float segunda_nota)
{
    float media_final = (primeira_nota + segunda_nota) / 2;
    return media_final;
}

int main()
{
    struct Aluno alunos[2];
    float maior_media = 0.0;
    int indice_maior_media = 0;
    float media_turma = 0.0;

    for (int a = 0; a < 2; a++)
    {
        printf("Informe a matrícula do aluno: ");
        scanf("%d", &alunos[a].matricula);
        limparBuffer();

        printf("Informe o nome do aluno: ");
        fgets(alunos[a].nome, sizeof(alunos[a].nome), stdin);
        alunos[a].nome[strcspn(alunos[a].nome, "\n")] = '\0';

        printf("Informe a primeira nota: ");
        scanf("%f", &alunos[a].nota1);
        limparBuffer();

        printf("Informe a segunda nota: ");
        scanf("%f", &alunos[a].nota2);
        limparBuffer();

        alunos[a].media = calcular_media(alunos[a].nota1, alunos[a].nota2);
    }

    for (int a = 0; a < 2; a++)
    {
        printf("ALUNO: %s.\n", alunos[a].nome);
        printf("MATRÍCULA: %d.\n", alunos[a].matricula);
        printf("PRIMEIRA NOTA: %.2f.\n", alunos[a].nota1);
        printf("SEGUNDA NOTA: %.2f.\n", alunos[a].nota2);
        printf("MÉDIA FINAL: %.2f.\n", alunos[a].media);
    }

    maior_media = alunos[0].media;

    for (int a = 1; a < 2; a++)
    {
        if (alunos[a].media > maior_media)
        {
            indice_maior_media = a;
        }
    }

    for (int a = 0; a < 5; a++)
    {
        media_turma += alunos[a].media;
    }

    media_turma /= 2;

    printf("O aluno com maior média foi o aluno: %s.\n", alunos[indice_maior_media].nome);
    printf("Matrícula: %d.\n", alunos[indice_maior_media].matricula);
    printf("Com média de: %.2f.\n", alunos[indice_maior_media].media);
    printf("A média da turma é de %.2f.\n", media_turma);

    return 0;
}