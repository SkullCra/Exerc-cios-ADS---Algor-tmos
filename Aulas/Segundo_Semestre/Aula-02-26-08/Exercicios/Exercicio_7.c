#include <stdio.h>
#include <string.h>

struct Aluno {
    int matricula;
    char nome[50];
    float nota1;
    float nota2;
    float media;
};

void limparBuffer() {
    int c;                                  
    while ((c = getchar()) != '\n' && c != EOF);
}

float calcular_media (float primeira_nota, float segunda_nota) {
    float media_final = (primeira_nota + segunda_nota) / 2;
    return media_final;
}

void verificar_aprovacao (float media) {
    if (media >= 7.0) {
        printf("O aluno está aprovado.\n");
    }
    else {
        printf("O aluno está reprovado.\n");
    }
}

void ler_string(char destino[], int tamanho, char mensagem[]) {
    do {
        printf("%s", mensagem);
        fgets(destino, tamanho, stdin);
        destino[strcspn(destino, "\n")] = '\0';

        if (strlen(destino) == 0) {
            printf("ERRO: O campo nao pode ser vazio.\n");
        }
    } while (strlen(destino) == 0);
}

int main (){
    struct Aluno a1, a2, a3, a4, a5;

    printf("=== Cadastro de aluno 1 de 5 ===\n");
    printf("Informe o número da matrícula: ");
    scanf("%d", &a1.matricula);
    limparBuffer();
    ler_string(a1.nome, 50, "Nome: ");
    printf("Primeira nota: ");
    scanf("%f", &a1.nota1);
    printf("Segunda nota: ");
    scanf("%f", &a1.nota2);
    a1.media = calcular_media(a1.nota1, a1.nota2);
    verificar_aprovacao(a1.media);

    printf("=== Cadastro de aluno 2 de 5 ===\n");
    printf("Informe o número da matrícula: ");
    scanf("%d", &a2.matricula);
    limparBuffer();
    ler_string(a2.nome, 50, "Nome: ");
    printf("Primeira nota: ");
    scanf("%f", &a2.nota1);
    printf("Segunda nota: ");
    scanf("%f", &a2.nota2);
    a2.media = calcular_media(a2.nota1, a2.nota2);
    verificar_aprovacao(a2.media);

    printf("=== Cadastro de aluno 3 de 5 ===\n");
    printf("Informe o número da matrícula: ");
    scanf("%d", &a3.matricula);
    limparBuffer();
    ler_string(a3.nome, 50, "Nome: ");
    printf("Primeira nota: ");
    scanf("%f", &a3.nota1);
    printf("Segunda nota: ");
    scanf("%f", &a3.nota2);
    a3.media = calcular_media(a3.nota1, a3.nota2);
    verificar_aprovacao(a3.media);

    printf("=== Cadastro de aluno 4 de 5 ===\n");
    printf("Informe o número da matrícula: ");
    scanf("%d", &a4.matricula);
    limparBuffer();
    ler_string(a4.nome, 50, "Nome: ");
    printf("Primeira nota: ");
    scanf("%f", &a4.nota1);
    printf("Segunda nota: ");
    scanf("%f", &a4.nota2);
    a4.media = calcular_media(a4.nota1, a4.nota2);
    verificar_aprovacao(a4.media);

    printf("=== Cadastro de aluno 5 de 5 ===\n");
    printf("Informe o número da matrícula: ");
    scanf("%d", &a5.matricula);
    limparBuffer();
    ler_string(a5.nome, 50, "Nome: ");
    printf("Primeira nota: ");
    scanf("%f", &a5.nota1);
    printf("Segunda nota: ");
    scanf("%f", &a5.nota2);
    a5.media = calcular_media(a5.nota1, a5.nota2);
    verificar_aprovacao(a5.media);

    printf("=== Alunos cadastrados ===\n");
    printf("Nome: %s.\n", a1.nome);
    printf("Primeira nota: %.2f.\n", a1.nota1);
    printf("Segunda nota: %.2f.\n", a1.nota2);
    printf("Média final: %.2f.\n", a1.media);
    verificar_aprovacao(a1.media);
    printf("=========================\n");
    printf("Nome: %s.\n", a2.nome);
    printf("Primeira nota: %.2f.\n", a2.nota1);
    printf("Segunda nota: %.2f.\n", a2.nota2);
    printf("Média final: %.2f.\n", a2.media);
    verificar_aprovacao(a2.media);
    printf("=========================\n");
    printf("Nome: %s.\n", a3.nome);
    printf("Primeira nota: %.2f.\n", a3.nota1);
    printf("Segunda nota: %.2f.\n", a3.nota2);
    printf("Média final: %.2f.\n", a3.media);
    verificar_aprovacao(a3.media);
    printf("=========================\n");
    printf("Nome: %s.\n", a4.nome);
    printf("Primeira nota: %.2f.\n", a4.nota1);
    printf("Segunda nota: %.2f.\n", a4.nota2);
    printf("Média final: %.2f.\n", a4.media);
    verificar_aprovacao(a4.media);
    printf("=========================\n");
    printf("Nome: %s.\n", a5.nome);
    printf("Primeira nota: %.2f.\n", a5.nota1);
    printf("Segunda nota: %.2f.\n", a5.nota2);
    printf("Média final: %.2f.\n", a5.media);
    verificar_aprovacao(a5.media);

    return 0;
}