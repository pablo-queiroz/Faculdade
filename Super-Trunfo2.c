#include <stdio.h>
#include <stdlib.h>

#define QTD_CARTAS 2
#define TAM_CODIGO 4
#define TAM_NOME 50

// Estrutura para a carta
typedef struct {
    char estado;
    char codigo[TAM_CODIGO];
    char nomeCidade[TAM_NOME];
    int populacao;
    float area;
    float pib;
    int numPontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para cadastro da carta
void lerCarta(Carta *carta, int numero) {
    printf("\n--- Inserir dados da Carta %d ---\n", numero + 1);

    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

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
}

// Função para obter o valor de um atributo por índice
float obterValorAtributo(const Carta *carta, int atributo) {
    switch (atributo) {
        case 1: return (float)carta->populacao;
        case 2: return carta->area;
        case 3: return carta->pib;
        case 4: return (float)carta->numPontosTuristicos;
        case 5: return carta->densidadePopulacional;
        default: return -1;
    }
}

// Função para obter o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        default: return "Desconhecido";
    }
}

// Função para mostrar o menu e obter a escolha do usuário
int escolherAtributo(int atributoJaEscolhido) {
    int opcao;

    printf("\nEscolha um atributo:\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributoJaEscolhido) {
            printf("%d - %s\n", i, nomeAtributo(i));
        }
    }
    printf("Opção: ");
    scanf("%d", &opcao);

    // Validação
    if (opcao < 1 || opcao > 5 || opcao == atributoJaEscolhido) {
        printf("Opção inválida. Tente novamente.\n");
        return escolherAtributo(atributoJaEscolhido);
    }

    return opcao;
}

// Função principal para comparação
void compararCartas(Carta *c1, Carta *c2) {
    int attr1 = escolherAtributo(0);               // Primeiro atributo
    int attr2 = escolherAtributo(attr1);           // Segundo atributo (diferente)

    float v1_c1 = obterValorAtributo(c1, attr1);
    float v1_c2 = obterValorAtributo(c2, attr1);
    float v2_c1 = obterValorAtributo(c1, attr2);
    float v2_c2 = obterValorAtributo(c2, attr2);

    printf("\n--- Comparação das Cartas ---\n");
    printf("Carta 1 - %s\n", c1->nomeCidade);
    printf("  %s: %.2f\n", nomeAtributo(attr1), v1_c1);
    printf("  %s: %.2f\n", nomeAtributo(attr2), v2_c1);
    printf("  Soma: %.2f\n", v1_c1 + v2_c1);

    printf("\nCarta 2 - %s\n", c2->nomeCidade);
    printf("  %s: %.2f\n", nomeAtributo(attr1), v1_c2);
    printf("  %s: %.2f\n", nomeAtributo(attr2), v2_c2);
    printf("  Soma: %.2f\n", v1_c2 + v2_c2);

    // Ajuste para regra especial: densidade demográfica (menor vence)
    float pontos_c1 = 0, pontos_c2 = 0;

    // Primeiro atributo
    if (attr1 == 5) {
        pontos_c1 += (v1_c1 < v1_c2) ? 1 : (v1_c1 > v1_c2) ? 0 : 0.5;
        pontos_c2 += (v1_c2 < v1_c1) ? 1 : (v1_c1 > v1_c2) ? 0 : 0.5;
    } else {
        pontos_c1 += (v1_c1 > v1_c2) ? 1 : (v1_c1 < v1_c2) ? 0 : 0.5;
        pontos_c2 += (v1_c2 > v1_c1) ? 1 : (v1_c1 < v1_c2) ? 0 : 0.5;
    }

    // Segundo atributo
    if (attr2 == 5) {
        pontos_c1 += (v2_c1 < v2_c2) ? 1 : (v2_c1 > v2_c2) ? 0 : 0.5;
        pontos_c2 += (v2_c2 < v2_c1) ? 1 : (v2_c1 > v2_c2) ? 0 : 0.5;
    } else {
        pontos_c1 += (v2_c1 > v2_c2) ? 1 : (v2_c1 < v2_c2) ? 0 : 0.5;
        pontos_c2 += (v2_c2 > v2_c1) ? 1 : (v2_c1 < v2_c2) ? 0 : 0.5;
    }

    printf("\nResultado Final:\n");

    if (pontos_c1 > pontos_c2) {
        printf("Carta 1 (%s) venceu com %.1f pontos!\n", c1->nomeCidade, pontos_c1);
    } else if (pontos_c2 > pontos_c1) {
        printf("Carta 2 (%s) venceu com %.1f pontos!\n", c2->nomeCidade, pontos_c2);
    } else {
        printf("Empate! Ambas as cartas somaram %.1f pontos.\n", pontos_c1);
    }
}

int main() {
    Carta cartas[QTD_CARTAS];

    // Leitura das cartas
    for (int i = 0; i < QTD_CARTAS; i++) {
        lerCarta(&cartas[i], i);
    }

    // Comparação das cartas com dois atributos
    compararCartas(&cartas[0], &cartas[1]);

    return 0;
}
