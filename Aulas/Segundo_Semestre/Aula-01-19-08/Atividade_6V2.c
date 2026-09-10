#include <stdio.h>
#include <string.h>

// Função que limpa o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função que le o texto e remove o \n do final (Enter).
void lerStringObrigatoria(char destino[], int tamanho, char mensagem[]) {
    do {
        printf("%s", mensagem);
        fgets(destino, tamanho, stdin);
        destino[strcspn(destino, "\n")] = '\0';

        if (strlen(destino) == 0) {
            printf("ERRO: O campo nao pode ser vazio.\n");
        }
    } while (strlen(destino) == 0);
}

// Função que garante a leitura de um número inteiro positivo
int lerInteiroPositivo(char mensagem[]) {
    int valor;
    int entradaValida;
    do {
        printf("%s", mensagem);
        entradaValida = scanf("%d", &valor);
        limparBuffer();
        if (entradaValida != 1 || valor < 0) {
            printf("ERRO: O valor deve ser um numero valido e positivo.\n");
        }
    } while (entradaValida != 1 || valor < 0);
    return valor;
}

// Função que garante a leitura de um valor em float positivo
float lerFloatPositivo(char mensagem[]) {
    float valor;
    int entradaValida;
    do {
        printf("%s", mensagem);
        entradaValida = scanf("%f", &valor);
        limparBuffer();
        if (entradaValida != 1 || valor <= 0) {
            printf("ERRO: O valor deve ser maior que zero.\n");
        }
    } while (entradaValida != 1 || valor <= 0);
    return valor;
}

// Configura os dados da empresa e retorna 1 para sucesso;
int configurarEmpresa(char razao[], char cnpj[], char endereco[]) {
    printf("\n--- Configurar Dados da Empresa ---\n");
    lerStringObrigatoria(razao, 100, "Digite a razao social da empresa: ");
    lerStringObrigatoria(cnpj, 30, "Digite o CNPJ da empresa: ");
    lerStringObrigatoria(endereco, 150, "Digite o endereco completo da empresa: ");

    printf("\nDados da empresa configurados com sucesso!\n");
    return 1;
}

// Calcula o salário base limitando a multiplicação a 220 horas
float calcularSalarioBase(int horas, float valorHora) {
    if (horas <= 220) {
        return horas * valorHora;
    } else {
        return 220 * valorHora;
    }
}

// Retorna apenas a quantidade de horas extras realizadas;
int calcularQtdHorasExtras(int horas) {
    if (horas > 220) {
        return horas - 220;
    } else {
        return 0;
    }
}

// Calcula o valor em Reais das horas extras
// 25% até 240horas, 50% acima de 240horas
float calcularValorHorasExtras(int horas, float valorHora) {
    if (horas <= 220) {
        return 0.0;
    }
    if (horas <= 240) {
        int qtdExtras = horas - 220;
        return qtdExtras * (valorHora * 1.25);
    }

    // Se trabalhou mais de 240 horas
    int extrasAte240 = 20;
    int extrasAlem240 = horas - 240;

    float valorFaixa1 = extrasAte240 * (valorHora * 1.25);
    float valorFaixa2 = extrasAlem240 * (valorHora * 1.50); // CORRIGIDO: 1.50 com ponto

    return valorFaixa1 + valorFaixa2;
}

// Soma a base e as extras para gerar o salario bruto
float calcularSalarioBruto(float base, float valorExtras) {
    return base + valorExtras;
}

// Calcula o INSS de forma progressiva confrome tabela de 2026
float calcularINSS(float salarioBruto) {
    float inss = 0.0;
    float baseINSS = salarioBruto;

    // Aplica o teto do INSS
    if (baseINSS > 8475.55) {
        baseINSS = 8475.55;
    }

    if (baseINSS <= 1621.00) {
        inss = baseINSS * 0.075;
    } else if (baseINSS <= 2902.84) {
        inss = (1621.00 * 0.075) + ((baseINSS - 1621.00) * 0.09);
    } else if (baseINSS <= 4354.27) {
        inss = (1621.00 * 0.075) + ((2902.84 - 1621.00) * 0.09) + ((baseINSS - 2902.84) * 0.12);
    } else {
        inss = (1621.00 * 0.075) + ((2902.84 - 1621.00) * 0.09) + ((4354.27 - 2902.84) * 0.12) + ((baseINSS - 4354.27) * 0.14);
    }

    return inss;
}

// Calcula o IRPF abatendo INSS e dependentes (R$ 189,59 cada)
float calcularIRPF(float salarioBruto, float inss, int dependentes) {
    float baseIRPF = salarioBruto - inss - (189.59 * dependentes);
    float irpf = 0.0;

    if (baseIRPF <= 2428.80) {
        irpf = 0.0;
    } else if (baseIRPF <= 2826.65) {
        irpf = (baseIRPF * 0.075) - 182.16;
    } else if (baseIRPF <= 3751.05) {
        irpf = (baseIRPF * 0.15) - 394.16;
    } else if (baseIRPF <= 4664.68) {
        irpf = (baseIRPF * 0.225) - 675.49;
    } else {
        irpf = (baseIRPF * 0.275) - 908.73;
    }
    
    if (irpf < 0.0) {
        irpf = 0.0;
    }
    
    return irpf;
}

// Calcula o valor final a ser recebido
float calcularSalarioLiquido(float bruto, float inss, float irpf) {
    return bruto - inss - irpf;
}

// Desenha o contracheque recebendo todas as variaveis calculadas pela main
void imprimirContracheque(char mes[], char razao[], char cnpj[], char endereco[], 
                          char nome[], char nasc[], char cargo[], int dependentes, 
                          int horasTrabalhadas, float valorHora, int horasExtras, 
                          float salarioBase, float totalHorasExtras, float salarioBruto, 
                          float inss, float irpf, float totalDescontos, float salarioLiquido) {
    
    printf("\n==================================================================\n");
    printf("                    CONTRACHEQUE - %s\n", mes);
    printf("==================================================================\n");
    printf("EMPRESA: %s\n", razao);
    printf("CNPJ: %s\n", cnpj);
    printf("ENDERECO: %s\n", endereco);
    printf("------------------------------------------------------------------\n");
    printf("FUNCIONARIO: %s\n", nome);
    printf("DATA DE NASCIMENTO: %s\n", nasc);
    printf("CARGO: %s\n", cargo);
    printf("DEPENDENTES: %d\n", dependentes);
    printf("------------------------------------------------------------------\n");
    printf("HORAS TRABALHADAS: %d h\n", horasTrabalhadas);
    printf("VALOR DA HORA: R$ %.2f\n", valorHora);
    printf("HORAS EXTRAS: %d h\n", horasExtras);

    if (horasExtras == 0) {
        printf("ADICIONAL APLICADO: 0%%\n");
    } else if (horasTrabalhadas <= 240) {
        printf("ADICIONAL APLICADO: 25%%\n");
    } else {
        printf("ADICIONAL APLICADO: 25%% (primeiras 20h) + 50%% (demais)\n");
    }

    printf("------------------------------------------------------------------\n");
    printf("VENCIMENTOS\n");
    printf("------------------------------------------------------------------\n");
    printf("SALARIO BASE: R$ %.2f\n", salarioBase);
    printf("HORAS EXTRAS: R$ %.2f\n", totalHorasExtras);
    printf("------------------------------------------------------------------\n");
    printf("TOTAL VENCIMENTOS: R$ %.2f\n", salarioBruto);
    printf("------------------------------------------------------------------\n");
    printf("DESCONTOS\n");
    printf("------------------------------------------------------------------\n");
    printf("INSS: R$ %.2f\t\tIRPF: R$ %.2f\n", inss, irpf);
    printf("------------------------------------------------------------------\n");
    printf("TOTAL DESCONTOS: R$ %.2f\n", totalDescontos);
    printf("SALARIO LIQUIDO: R$ %.2f\n", salarioLiquido);
    printf("==================================================================\n");
}

int main() {
    // Variaveis da empresa (persistem durante toda a execucao)
    char razaoSocial[100] = "";
    char cnpj[30] = "";
    char endereco[150] = "";
    int empresaConfigurada = 0; // Flag de controle (0 = falso, 1 = verdadeiro)
    
    int opcao = 0;
    int entradaValida = 0;

    do {
        printf("\n============================================================\n");
        printf("                 PROGRAMA FOLHA DE PAGAMENTO\n");
        printf("============================================================\n");
        printf("1 - Configurar dados da empresa\n");
        printf("2 - Calcular salario mensal\n");
        printf("3 - Sair\n");
        printf("Selecione a opcao desejada: ");

        entradaValida = scanf("%d", &opcao);
        limparBuffer();
        if (entradaValida != 1) {
            opcao = 0; 
        }

        switch (opcao) {
            case 1:
                // Atualiza a flag para 1 se a configuracao ocorrer com sucesso
                empresaConfigurada = configurarEmpresa(razaoSocial, cnpj, endereco);
                break;

            case 2:
                if (empresaConfigurada == 0) {
                    printf("\nAntes de calcular o salario, configure os dados da empresa.\n");
                    break;
                }

                char novaOperacao = 'N';
                do {
                    // Variaveis do funcionario (recriadas a cada novo calculo)
                    char mes[30], nomeFuncionario[100], dataNascimento[20], cargo[80];
                    int dependentes, horasTrabalhadas, horasExtras;
                    float valorHora, salarioBase, totalHorasExtras;
                    float salarioBruto, inss, irpf, salarioLiquido, totalDescontos;

                    // 1. Coleta de dados usando as funcoes de validacao
                    printf("\n--- Dados do Funcionario ---\n");
                    lerStringObrigatoria(mes, sizeof(mes), "Digite o mes de referencia: ");
                    lerStringObrigatoria(nomeFuncionario, sizeof(nomeFuncionario), "Nome completo: ");
                    lerStringObrigatoria(dataNascimento, sizeof(dataNascimento), "Data de nascimento: ");
                    lerStringObrigatoria(cargo, sizeof(cargo), "Cargo: ");
                    
                    dependentes = lerInteiroPositivo("Numero de dependentes: ");
                    horasTrabalhadas = lerInteiroPositivo("Horas trabalhadas no mes: ");
                    valorHora = lerFloatPositivo("Valor da hora: R$ ");

                    // 2. Chamadas sequenciais das funcoes de calculo
                    salarioBase = calcularSalarioBase(horasTrabalhadas, valorHora);
                    horasExtras = calcularQtdHorasExtras(horasTrabalhadas);
                    totalHorasExtras = calcularValorHorasExtras(horasTrabalhadas, valorHora);
                    salarioBruto = calcularSalarioBruto(salarioBase, totalHorasExtras);
                    
                    inss = calcularINSS(salarioBruto);
                    irpf = calcularIRPF(salarioBruto, inss, dependentes);
                    salarioLiquido = calcularSalarioLiquido(salarioBruto, inss, irpf);
                    totalDescontos = inss + irpf;

                    // 3. Impressao delegada a funcao especifica
                    imprimirContracheque(mes, razaoSocial, cnpj, endereco, nomeFuncionario, 
                                         dataNascimento, cargo, dependentes, horasTrabalhadas, 
                                         valorHora, horasExtras, salarioBase, totalHorasExtras, 
                                         salarioBruto, inss, irpf, totalDescontos, salarioLiquido);

                    // 4. Controle de repeticao do calculo
                    do {
                        printf("\nDeseja calcular outro salario? (S/N): ");
                        entradaValida = scanf(" %c", &novaOperacao);
                        limparBuffer();
                        if (novaOperacao != 'S' && novaOperacao != 's' && novaOperacao != 'N' && novaOperacao != 'n') {
                            printf("Leitura invalida. Digite apenas S ou N.\n");
                        }
                    } while (novaOperacao != 'S' && novaOperacao != 's' && novaOperacao != 'N' && novaOperacao != 'n');

                } while (novaOperacao == 'S' || novaOperacao == 's');
                break;

            case 3:
                printf("\nEncerrando o programa...\n");
                break;
                
            default:
                printf("\nOpcao invalida. Digite uma opcao entre 1 e 3.\n");
                break;
        }

    } while (opcao != 3);

    return 0;
}