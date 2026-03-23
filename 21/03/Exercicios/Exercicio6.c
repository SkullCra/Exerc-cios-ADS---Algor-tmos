#include <stdio.h>

int main (){
    float preco, inflacao, corrigido;

    printf("Insira o valor do produto para realizar o cálculo de inflação: ");
    scanf("%f", &preco);

    printf("Insira o valor da inflação atual: ");
    scanf("%f", &inflacao);

    corrigido = (preco * inflacao) / 100 + preco;

    printf("O valor corrigido do seu produto é de: %.2f\n", corrigido);
    printf("O valor original era de: %.2f\n", preco);
    printf("A inflação aplicada foi de: %.2f por cento.\n", inflacao);

    return 0;
}