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
    float pib;                         // PIB da cidade (em reais)
    int numPontosTuristicos;          // Número de pontos turísticos
    float densidadePopulacional;      // Habitantes por km²
    float pibPerCapita;               // PIB per capita
    float superPoder;                 //Super poder
} Carta;

// Função para ler os dados de uma carta
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

    printf("PIB (em reais): ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->numPontosTuristicos);

    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;

    // Super poder do Super Trunfo
        carta->superPoder = (float)carta->populacao +
                        carta->area +
                        carta->pib +
                        carta->numPontosTuristicos +
                        carta->pibPerCapita +
                        (1 / carta->densidadePopulacional);
}

// Função para exibir os dados de uma carta
void exibirCarta(const Carta *carta, int numero) {
    printf("\n--- Dados da Carta %d ---\n", numero + 1);
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Cidade: %s\n", carta->nomeCidade);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f reais\n", carta->pib);
    printf("Número de Pontos Turísticos: %d\n", carta->numPontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta->pibPerCapita);
}

// Comparando as cartas
void compararCartas(Carta *c1, Carta *c2) {
    printf("\n--- Comparação de Cartas ---\n");

    printf("População: Carta 1 venceu (%d)\n", c1->populacao > c2->populacao);
    printf("Área: Carta 1 venceu (%d)\n", c1->area > c2->area);
    printf("PIB: Carta 1 venceu (%d)\n", c1->pib > c2->pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", c1->numPontosTuristicos > c2->numPontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1->densidadePopulacional < c2->densidadePopulacional); // menor vence
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1->pibPerCapita > c2->pibPerCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1->superPoder > c2->superPoder);
}

int main() {
    Carta cartas[QTD_CARTAS];

    // Leitura das duas cartas
    for (int i = 0; i < QTD_CARTAS; i++) {
        lerCarta(&cartas[i], i);
    }
    
    // Exibição das duas cartas
    for (int i = 0; i < QTD_CARTAS; i++) {
        exibirCarta(&cartas[i], i);
    }

    // Comparação das duas cartas
    compararCartas(&cartas[0], &cartas[1]);

    return 0;
}