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
    float superPoder;                 // Super poder (não será usado neste nível)
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

    // Cálculos dos atributos derivados
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;

    // Super poder (não usado neste nível)
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

// Função para comparar as cartas com base na População
void compararPorPopulacao(const Carta *c1, const Carta *c2) {
    printf("\n--- Comparação de Cartas (Atributo: População) ---\n");
    printf("Carta 1 - %s (%c): %d habitantes\n", c1->nomeCidade, c1->estado, c1->populacao);
    printf("Carta 2 - %s (%c): %d habitantes\n", c2->nomeCidade, c2->estado, c2->populacao);

    // Lógica de comparação usando if-else
    if (c1->populacao > c2->populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1->nomeCidade);
    } else if (c2->populacao > c1->populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2->nomeCidade);
    } else {
        printf("Resultado: Empate! Ambas as cidades têm a mesma população.\n");
    }
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

    // Comparação baseada em População
    compararPorPopulacao(&cartas[0], &cartas[1]);

    return 0;
}
