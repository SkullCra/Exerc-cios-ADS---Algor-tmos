#include <stdio.h>
#include <string.h>

void limparBuffer() {                       // Função usada para limpar o buffer do teclado.
    int c;                                  
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() { 

    // Constantes 
    const int HORAS_MES_BASE = 220;              // Jornada mensal padrão em horas.
    const int HORAS_EXTRA_LIMITE = 240;          // Limite para adicional de 25%; acima disso, há adicional de 50%.

    const float ADICIONAL_25 = 1.25;            // Multiplicador para horas extras com adicional de 25%.
    const float ADICIONAL_50 = 1.50;            // Multiplicador para horas extras com adicional de 50%.

    const float TETO_INSS = 8475.55;            // Teto da base de cálculo do INSS.
    const float INSS_FAIXA1_MAX = 1621.00;      // Limite superior da 1ª faixa do INSS.
    const float INSS_FAIXA2_MAX = 2902.84;      // Limite superior da 2ª faixa do INSS.
    const float INSS_FAIXA3_MAX = 4354.27;      // Limite superior da 3ª faixa do INSS.
    const float INSS_ALIQ1 = 0.075;             // Alíquota da 1ª faixa do INSS: 7,5%.
    const float INSS_ALIQ2 = 0.09;              // Alíquota da 2ª faixa do INSS: 9%.
    const float INSS_ALIQ3 = 0.12;              // Alíquota da 3ª faixa do INSS: 12%.
    const float INSS_ALIQ4 = 0.14;              // Alíquota da 4ª faixa do INSS: 14%.

    const float IRPF_ISENTO_MAX = 2428.80;      // Limite de isenção do IRPF.
    const float IRPF_FAIXA1_MAX = 2826.65;      // Limite superior da 1ª faixa tributável do IRPF.
    const float IRPF_FAIXA2_MAX = 3751.05;      // Limite superior da 2ª faixa tributável do IRPF.
    const float IRPF_FAIXA3_MAX = 4664.68;      // Limite superior da 3ª faixa tributável do IRPF.
    const float IRPF_ALIQ1 = 0.075;             // Alíquota da 1ª faixa tributável do IRPF: 7,5%.
    const float IRPF_ALIQ2 = 0.15;              // Alíquota da 2ª faixa tributável do IRPF: 15%.
    const float IRPF_ALIQ3 = 0.225;             // Alíquota da 3ª faixa tributável do IRPF: 22,5%.
    const float IRPF_ALIQ4 = 0.275;             // Alíquota da 4ª faixa tributável do IRPF: 27,5%.
    const float IRPF_PARCELA1 = 182.16;         // Parcela a deduzir da 1ª faixa tributável do IRPF.
    const float IRPF_PARCELA2 = 394.16;         // Parcela a deduzir da 2ª faixa tributável do IRPF.
    const float IRPF_PARCELA3 = 675.49;         // Parcela a deduzir da 3ª faixa tributável do IRPF.
    const float IRPF_PARCELA4 = 908.73;         // Parcela a deduzir da 4ª faixa tributável do IRPF.
    const float DEDUCAO_DEPENDENTE = 189.59;    // Dedução por dependente na base de cálculo do IRPF.

    // Dados da empresa — declarados no escopo do main pois persistem entre cálculos
    char razaoSocial[100];                  // Armazena a razão social da empresa.
    char cnpj[30];                          // Armazena o CNPJ da empresa.
    char endereco[150];                     // Armazena o endereço completo da empresa.

    int opcao = 0;                          // Armazena a opção escolhida no menu.
    int empresaConfigurada = 0;             // Controla se os dados da empresa já foram cadastrados.
    int entradaValida = 0;                 // Verifica se a leitura com scanf foi realizada corretamente.
    char novaOperacao = 'N';              // Armazena a resposta sobre realizar novo cálculo.

    do {                                    // Início do laço principal do menu.

        printf("\n============================================================\n");
        printf("                 PROGRAMA FOLHA DE PAGAMENTO\n");
        printf("============================================================\n");
        printf("1 - Configurar dados da empresa\n");
        printf("2 - Calcular salario mensal\n");
        printf("3 - Sair\n");
        printf("Selecione a opcao desejada: ");

        entradaValida = scanf("%d", &opcao); // Lê a opção escolhida.
        limparBuffer();                      // Limpa o buffer após o scanf.

        if (entradaValida != 1) {            // Verifica se a entrada não foi um número inteiro.
            opcao = 0;                       // Define uma opção inválida.
        }

        switch (opcao) {                     // Avalia a opção escolhida.

            case 1:                          // Opção para configurar os dados da empresa.

                do {
                    printf("\nDigite a razao social da empresa: ");
                    fgets(razaoSocial, sizeof(razaoSocial), stdin);
                    razaoSocial[strcspn(razaoSocial, "\n")] = '\0';
                    if (strlen(razaoSocial) == 0)
                        printf("Entrada invalida. A razao social nao pode ser vazia.\n");
                } while (strlen(razaoSocial) == 0);

                do {
                    printf("Digite o CNPJ da empresa: ");
                    fgets(cnpj, sizeof(cnpj), stdin);
                    cnpj[strcspn(cnpj, "\n")] = '\0';
                    if (strlen(cnpj) == 0)
                        printf("Entrada invalida. O CNPJ nao pode ser vazio.\n");
                } while (strlen(cnpj) == 0);

                do {
                    printf("Digite o endereco completo da empresa: ");
                    fgets(endereco, sizeof(endereco), stdin);
                    endereco[strcspn(endereco, "\n")] = '\0';
                    if (strlen(endereco) == 0)
                        printf("Entrada invalida. O endereco nao pode ser vazio.\n");
                } while (strlen(endereco) == 0);

                empresaConfigurada = 1;      // Marca que a empresa foi configurada.
                printf("\nDados da empresa configurados com sucesso!\n");

                break;

            case 2:                          // Opção para calcular o salário mensal.

                if (empresaConfigurada == 0) {
                    printf("\nAntes de calcular o salario, configure os dados da empresa.\n");
                    break;
                }

                do { // Permite calcular mais de um salário.

                    // --------------------------------------------------------
                    // Variáveis do funcionário — declaradas dentro do laço,
                    // pois só existem durante o cálculo de um contracheque.
                    // --------------------------------------------------------
                    char mes[30];
                    char nomeFuncionario[100];
                    char dataNascimento[20];
                    char cargo[80];

                    int dependentes = 0;
                    int horasTrabalhadas = 0;
                    int horasExtras = 0;   // Inicializado aqui para evitar valor indefinido

                    float valorHora = 0.0;
                    float salarioBase = 0.0;
                    float valorHoraExtra = 0.0;  // Inicializado aqui para evitar valor indefinido
                    float totalHorasExtras = 0.0;  // Inicializado aqui para evitar valor indefinido
                    float salarioBruto = 0.0;
                    float baseINSS = 0.0;
                    float inss = 0.0;
                    float baseIRPF = 0.0;
                    float irpf = 0.0;
                    float salarioLiquido = 0.0;
                    float totalDescontos = 0.0;

                    // --- Coleta de dados do funcionário ---

                    do {
                        printf("\nDigite o mes de referencia: ");
                        fgets(mes, sizeof(mes), stdin);
                        mes[strcspn(mes, "\n")] = '\0';
                        if (strlen(mes) == 0)
                            printf("Entrada invalida. O mes nao pode ser vazio.\n");
                    } while (strlen(mes) == 0);

                    do {
                        printf("Digite o nome completo do funcionario: ");
                        fgets(nomeFuncionario, sizeof(nomeFuncionario), stdin);
                        nomeFuncionario[strcspn(nomeFuncionario, "\n")] = '\0';
                        if (strlen(nomeFuncionario) == 0)
                            printf("Entrada invalida. O nome nao pode ser vazio.\n");
                    } while (strlen(nomeFuncionario) == 0);

                    do {
                        printf("Digite a data de nascimento: ");
                        fgets(dataNascimento, sizeof(dataNascimento), stdin);
                        dataNascimento[strcspn(dataNascimento, "\n")] = '\0';
                        if (strlen(dataNascimento) == 0)
                            printf("Entrada invalida. A data de nascimento nao pode ser vazia.\n");
                    } while (strlen(dataNascimento) == 0);

                    do {
                        printf("Digite o cargo do funcionario: ");
                        fgets(cargo, sizeof(cargo), stdin);
                        cargo[strcspn(cargo, "\n")] = '\0';
                        if (strlen(cargo) == 0)
                            printf("Entrada invalida. O cargo nao pode ser vazio.\n");
                    } while (strlen(cargo) == 0);

                    do {
                        printf("Digite o numero de dependentes: ");
                        entradaValida = scanf("%d", &dependentes);
                        limparBuffer();
                        if (entradaValida != 1 || dependentes < 0)
                            printf("Entrada invalida. O numero de dependentes nao pode ser negativo.\n");
                    } while (entradaValida != 1 || dependentes < 0);

                    do {
                        printf("Digite o numero de horas trabalhadas no mes: ");
                        entradaValida = scanf("%d", &horasTrabalhadas);
                        limparBuffer();
                        if (entradaValida != 1 || horasTrabalhadas < 0)
                            printf("Entrada invalida. As horas trabalhadas nao podem ser negativas.\n");
                    } while (entradaValida != 1 || horasTrabalhadas < 0);

                    do {
                        printf("Digite o valor da hora trabalhada: R$ ");
                        entradaValida = scanf("%f", &valorHora);
                        limparBuffer();
                        if (entradaValida != 1 || valorHora <= 0)
                            printf("Entrada invalida. O valor da hora deve ser maior que zero.\n");
                    } while (entradaValida != 1 || valorHora <= 0);

                    // --- Cálculo do salário base ---
                    // Usa as horas efetivamente trabalhadas (até o limite de 220h),
                    // em vez de fixar sempre em 220h independentemente do que foi digitado.
                    if (horasTrabalhadas <= HORAS_MES_BASE) {
                        salarioBase = horasTrabalhadas * valorHora; // Paga exatamente o que trabalhou
                    } else {
                        salarioBase = HORAS_MES_BASE * valorHora;   // Teto normal; o excedente vira hora extra
                    }

                    // --- Cálculo das horas extras ---
                    // Trata os dois níveis de adicional separadamente.
                    // Horas de 221 a 240 → 25%; horas acima de 240 → 50%.
                    // O código anterior aplicava 50% em TODAS as horas extras quando > 240h.
                    if (horasTrabalhadas <= HORAS_MES_BASE) {
                        horasExtras = 0;
                        valorHoraExtra = 0.0;
                        totalHorasExtras = 0.0;
                    } else if (horasTrabalhadas <= HORAS_EXTRA_LIMITE) {
                        // Apenas horas com adicional de 25%
                        horasExtras = horasTrabalhadas - HORAS_MES_BASE;
                        valorHoraExtra = valorHora * ADICIONAL_25;
                        totalHorasExtras = horasExtras * valorHoraExtra;
                    } else {
                        // Horas de 221–240 com 25% + horas acima de 240 com 50%
                        int extrasAte240 = HORAS_EXTRA_LIMITE - HORAS_MES_BASE; // sempre 20h
                        int extraAlem240 = horasTrabalhadas - HORAS_EXTRA_LIMITE;
                        horasExtras = horasTrabalhadas - HORAS_MES_BASE;
                        totalHorasExtras = (extrasAte240 * valorHora * ADICIONAL_25) + (extraAlem240 * valorHora * ADICIONAL_50);
                        // valorHoraExtra não representa mais uma única taxa; zerado para evitar uso indevido
                        valorHoraExtra = 0.0;
                    }

                    salarioBruto = salarioBase + totalHorasExtras; // Calcula o salário bruto.

                    // --- Cálculo do INSS (progressivo por faixas) ---
                    baseINSS = salarioBruto;
                    if (baseINSS > TETO_INSS)
                        baseINSS = TETO_INSS;

                    if (baseINSS <= INSS_FAIXA1_MAX) {
                        inss = baseINSS * INSS_ALIQ1;
                    } else if (baseINSS <= INSS_FAIXA2_MAX) {
                        inss  = INSS_FAIXA1_MAX * INSS_ALIQ1;
                        inss += (baseINSS - INSS_FAIXA1_MAX) * INSS_ALIQ2;
                    } else if (baseINSS <= INSS_FAIXA3_MAX) {
                        inss  = INSS_FAIXA1_MAX * INSS_ALIQ1;
                        inss += (INSS_FAIXA2_MAX - INSS_FAIXA1_MAX) * INSS_ALIQ2;
                        inss += (baseINSS - INSS_FAIXA2_MAX) * INSS_ALIQ3;
                    } else {
                        inss  = INSS_FAIXA1_MAX * INSS_ALIQ1;
                        inss += (INSS_FAIXA2_MAX - INSS_FAIXA1_MAX) * INSS_ALIQ2;
                        inss += (INSS_FAIXA3_MAX - INSS_FAIXA2_MAX) * INSS_ALIQ3;
                        inss += (baseINSS - INSS_FAIXA3_MAX) * INSS_ALIQ4;
                    }

                    // --- Cálculo do IRPF ---
                    baseIRPF = salarioBruto - inss - (DEDUCAO_DEPENDENTE * dependentes);

                    if (baseIRPF <= IRPF_ISENTO_MAX) {
                        irpf = 0.0;
                    } else if (baseIRPF <= IRPF_FAIXA1_MAX) {
                        irpf = (baseIRPF * IRPF_ALIQ1) - IRPF_PARCELA1;
                    } else if (baseIRPF <= IRPF_FAIXA2_MAX) {
                        irpf = (baseIRPF * IRPF_ALIQ2) - IRPF_PARCELA2;
                    } else if (baseIRPF <= IRPF_FAIXA3_MAX) {
                        irpf = (baseIRPF * IRPF_ALIQ3) - IRPF_PARCELA3;
                    } else {
                        irpf = (baseIRPF * IRPF_ALIQ4) - IRPF_PARCELA4;
                    }

                    if (irpf < 0.0)
                        irpf = 0.0;

                    totalDescontos = inss + irpf;
                    salarioLiquido = salarioBruto - totalDescontos;

                    // --- Impressão do contracheque ---
                    printf("\n==================================================================\n");
                    printf("                    CONTRACHEQUE - %s\n", mes);
                    printf("==================================================================\n");
                    printf("EMPRESA: %s\n", razaoSocial);
                    printf("CNPJ: %s\n", cnpj);
                    printf("ENDERECO: %s\n", endereco);
                    printf("------------------------------------------------------------------\n");
                    printf("FUNCIONARIO: %s\n", nomeFuncionario);
                    printf("DATA DE NASCIMENTO: %s\n", dataNascimento);
                    printf("CARGO: %s\n", cargo);
                    printf("DEPENDENTES: %d\n", dependentes);
                    printf("------------------------------------------------------------------\n");
                    printf("HORAS TRABALHADAS: %d h\n", horasTrabalhadas);
                    printf("VALOR DA HORA: R$ %.2f\n", valorHora);
                    printf("HORAS EXTRAS: %d h\n", horasExtras);

                    if (horasExtras == 0) {
                        printf("ADICIONAL APLICADO: 0%%\n");
                    } else if (horasTrabalhadas <= HORAS_EXTRA_LIMITE) {
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

                    do {
                        printf("\nDeseja calcular outro salario? (S/N): ");
                        entradaValida = scanf(" %c", &novaOperacao);
                        limparBuffer();
                        if (novaOperacao != 'S' && novaOperacao != 's' &&
                            novaOperacao != 'N' && novaOperacao != 'n')
                            printf("Leitura invalida. Digite apenas S ou N.\n");
                    } while (novaOperacao != 'S' && novaOperacao != 's' &&
                             novaOperacao != 'N' && novaOperacao != 'n');

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