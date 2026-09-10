#include <stdio.h>
#include <string.h>

struct Produto
{
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
};

void limparBuffer() {
    int c;                                  
    while ((c = getchar()) != '\n' && c != EOF);
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

int main()
{
    struct Produto p1, p2, p3;
    float total_p1, total_p2, total_p3, total_geral;

    printf("=== Cadastro do Produto 1 ===\n");
    printf("Código: ");
    scanf("%d", &p1.codigo);
    limparBuffer();

    ler_string(p1.nome, 50, "Nome: ");

    printf("Preço: ");
    scanf("%f", &p1.preco);
    printf("Quantidade: ");
    scanf("%d", &p1.quantidade);

    printf("=== Cadastro do Produto 2 ===\n");
    printf("Código: ");
    scanf("%d", &p2.codigo);
    limparBuffer();

    ler_string(p2.nome, 50, "Nome: ");

    printf("Preço: ");
    scanf("%f", &p2.preco);
    printf("Quantidade: ");
    scanf("%d", &p2.quantidade);

    printf("=== Cadastro do Produto 3 ===\n");
    printf("Código: ");
    scanf("%d", &p3.codigo);
    limparBuffer();

    ler_string(p3.nome, 50, "Nome: ");

    printf("Preço: ");
    scanf("%f", &p3.preco);
    printf("Quantidade: ");
    scanf("%d", &p3.quantidade);

    //Calculos

    total_p1 = p1.preco * p1.quantidade;
    total_p2 = p2.preco * p2.quantidade;
    total_p3 = p3.preco * p3.quantidade;
    total_geral = total_p1 + total_p2 + total_p3;

    printf("\n================ RELATORIO DE ESTOQUE ================\n");
    printf("PRODUTO 1 - Cod: %d | Nome: %s | Preco: R$%.2f | Qtd: %d | Total: R$%.2f\n", 
           p1.codigo, p1.nome, p1.preco, p1.quantidade, total_p1);
           
    printf("PRODUTO 2 - Cod: %d | Nome: %s | Preco: R$%.2f | Qtd: %d | Total: R$%.2f\n", 
           p2.codigo, p2.nome, p2.preco, p2.quantidade, total_p2);
           
    printf("PRODUTO 3 - Cod: %d | Nome: %s | Preco: R$%.2f | Qtd: %d | Total: R$%.2f\n", 
           p3.codigo, p3.nome, p3.preco, p3.quantidade, total_p3);

    printf("------------------------------------------------------\n");
    printf("VALOR TOTAL GERAL EM ESTOQUE: R$%.2f\n", total_geral);
    printf("======================================================\n");

    return 0;
}