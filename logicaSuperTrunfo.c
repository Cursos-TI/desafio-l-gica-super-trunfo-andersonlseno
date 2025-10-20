#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char estado[3];           // Sigla do estado (ex: SP)
    char codigo[4];           // Código da carta (ex: A01)
    char nomeCidade[50];      // Nome da cidade
    int populacao;            // População
    float area;               // Área (km²)
    float pib;                // PIB (em bilhões)
    int pontosTuristicos;     // Número de pontos turísticos
    float densidadePop;       // Calculada: População / Área
    float pibPerCapita;       // Calculada: PIB / População
} Carta;

int main() {
    Carta carta1, carta2;
    int opcao;

    // Entrada dos dados da primeira carta
    printf("===== Cadastro da Carta 1 =====\n");
    printf("Estado: ");
    scanf("%s", carta1.estado);
    printf("Código da carta: ");
    scanf("%s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Cálculos automáticos
    carta1.densidadePop = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    // Cadastro da segunda carta
    printf("\n===== Cadastro da Carta 2 =====\n");
    printf("Estado: ");
    scanf("%s", carta2.estado);
    printf("Código da carta: ");
    scanf("%s", carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculos automáticos
    carta2.densidadePop = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // Menu de comparação
    printf("\n===== MENU DE COMPARAÇÃO =====\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha o atributo para comparar: ");
    scanf("%d", &opcao);

    float valorCarta1 = 0, valorCarta2 = 0;
    char atributoUsado[50];

    // Estrutura de decisão usando switch
    switch(opcao) {
        case 1:
            valorCarta1 = carta1.populacao;
            valorCarta2 = carta2.populacao;
            strcpy(atributoUsado, "População");
            break;
        case 2:
            valorCarta1 = carta1.area;
            valorCarta2 = carta2.area;
            strcpy(atributoUsado, "Área");
            break;
        case 3:
            valorCarta1 = carta1.pib;
            valorCarta2 = carta2.pib;
            strcpy(atributoUsado, "PIB");
            break;
        case 4:
            valorCarta1 = carta1.pontosTuristicos;
            valorCarta2 = carta2.pontosTuristicos;
            strcpy(atributoUsado, "Número de Pontos Turísticos");
            break;
        case 5:
            valorCarta1 = carta1.densidadePop;
            valorCarta2 = carta2.densidadePop;
            strcpy(atributoUsado, "Densidade Demográfica");
            break;
        default:
            printf("Opção inválida! Encerrando o programa.\n");
            return 1;
    }

    // Exibição dos resultados
    printf("\n===== Comparação de Cartas =====\n");
    printf("Atributo: %s\n", atributoUsado);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, valorCarta1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, valorCarta2);

    // Regras de comparação
    if (opcao == 5) {
        // Densidade demográfica: menor vence
        if (valorCarta1 < valorCarta2)
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else if (valorCarta2 < valorCarta1)
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        else
            printf("\nResultado: Empate!\n");
    } else {
        // Demais atributos: maior vence
        if (valorCarta1 > valorCarta2)
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else if (valorCarta2 > valorCarta1)
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        else
            printf("\nResultado: Empate!\n");
    }

    return 0;
}
