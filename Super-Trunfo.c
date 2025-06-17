#include <stdio.h>
#include <stdlib.h>

#define QTD_CARTAS 2
#define TAM_CODIGO 4
#define TAM_NOME 50

// Estrutura para representar uma carta
typedef struct {
    char estado;                        // Letra de 'A' a 'H'
    char codigo[TAM_CODIGO];           // Ex: "A01"
    char nomeCidade[TAM_NOME];         // Nome da cidade
    int populacao;                     // Número de habitantes
    float area;                        // Área em km²
    float pib;                         // PIB da cidade
    int numPontosTuristicos;          // Número de pontos turísticos
} Carta;

void lerCarta(Carta *carta, int numero) {
    printf("\n--- Inserir dados da Carta %d ---\n", numero + 1);

    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade); // Lê até a quebra de linha

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB: ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->numPontosTuristicos);
}

void exibirCarta(const Carta *carta, int numero) {
    printf("\n--- Dados da Carta %d ---\n", numero + 1);
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Cidade: %s\n", carta->nomeCidade);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f\n", carta->pib);
    printf("Pontos Turísticos: %d\n", carta->numPontosTuristicos);
}

int main() {
    Carta cartas[QTD_CARTAS];

    // Leitura das duas cartas
    for (int i = 0; i < QTD_CARTAS; i++) {
        lerCarta(&cartas[i], i);
    }

    // Exibição dos dados
    for (int i = 0; i < QTD_CARTAS; i++) {
        exibirCarta(&cartas[i], i);
    }

    return 0;
}
