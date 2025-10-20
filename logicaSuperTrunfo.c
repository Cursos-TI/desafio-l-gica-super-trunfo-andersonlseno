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

    // Cálculos da carta 1
    carta1.densidadePop = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    // Entrada dos dados da segunda carta
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

    // Cálculos da carta 2
    carta2.densidadePop = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // Escolha do atributo para comparação (alterar conforme desejado)
    // Opções: populacao, area, pib, densidadePop, pibPerCapita
    char atributoEscolhido[20] = "pibPerCapita"; // Exemplo: comparando PIB per capita

    printf("\n===== Comparação de Cartas (Atributo: %s) =====\n", atributoEscolhido);

    float valorCarta1, valorCarta2;

    if (strcmp(atributoEscolhido, "populacao") == 0) {
        valorCarta1 = carta1.populacao;
        valorCarta2 = carta2.populacao;
    } else if (strcmp(atributoEscolhido, "area") == 0) {
        valorCarta1 = carta1.area;
        valorCarta2 = carta2.area;
    } else if (strcmp(atributoEscolhido, "pib") == 0) {
        valorCarta1 = carta1.pib;
        valorCarta2 = carta2.pib;
    } else if (strcmp(atributoEscolhido, "densidadePop") == 0) {
        valorCarta1 = carta1.densidadePop;
        valorCarta2 = carta2.densidadePop;
    } else if (strcmp(atributoEscolhido, "pibPerCapita") == 0) {
        valorCarta1 = carta1.pibPerCapita;
        valorCarta2 = carta2.pibPerCapita;
    } else {
        printf("Atributo inválido!\n");
        return 1;
    }

    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, valorCarta1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, valorCarta2);

    if (strcmp(atributoEscolhido, "densidadePop") == 0) {
        // Menor densidade vence
        if (valorCarta1 < valorCarta2) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valorCarta2 < valorCarta1) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    } else {
        // Maior valor vence
        if (valorCarta1 > valorCarta2) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valorCarta2 > valorCarta1) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    }

    return 0;
}
