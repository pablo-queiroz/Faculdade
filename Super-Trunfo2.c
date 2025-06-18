#include <stdio.h>
#include <stdlib.h>

#define QTD_CARTAS 2
#define TAM_CODIGO 4
#define TAM_NOME 50

// Estrutura de uma carta de país
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

// Função para ler dados da carta
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

// Função para exibir o resultado da comparação
void exibirResultado(const char* atributo, const Carta *c1, const Carta *c2, float valor1, float valor2, int vencedor) {
    printf("\n--- Comparação de Cartas (Atributo: %s) ---\n", atributo);
    printf("Carta 1 - %s: %.2f\n", c1->nomeCidade, valor1);
    printf("Carta 2 - %s: %.2f\n", c2->nomeCidade, valor2);

    if (vencedor == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1->nomeCidade);
    } else if (vencedor == 2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2->nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

// Menu e lógica de comparação
void menuComparacao(Carta *c1, Carta *c2) {
    int opcao;

    printf("\n--- MENU DE COMPARAÇÃO ---\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: { // População
            if (c1->populacao > c2->populacao)
                exibirResultado("População", c1, c2, c1->populacao, c2->populacao, 1);
            else if (c2->populacao > c1->populacao)
                exibirResultado("População", c1, c2, c1->populacao, c2->populacao, 2);
            else
                exibirResultado("População", c1, c2, c1->populacao, c2->populacao, 0);
            break;
        }

        case 2: { // Área
            if (c1->area > c2->area)
                exibirResultado("Área", c1, c2, c1->area, c2->area, 1);
            else if (c2->area > c1->area)
                exibirResultado("Área", c1, c2, c1->area, c2->area, 2);
            else
                exibirResultado("Área", c1, c2, c1->area, c2->area, 0);
            break;
        }

        case 3: { // PIB
            if (c1->pib > c2->pib)
                exibirResultado("PIB", c1, c2, c1->pib, c2->pib, 1);
            else if (c2->pib > c1->pib)
                exibirResultado("PIB", c1, c2, c1->pib, c2->pib, 2);
            else
                exibirResultado("PIB", c1, c2, c1->pib, c2->pib, 0);
            break;
        }

        case 4: { // Pontos turísticos
            if (c1->numPontosTuristicos > c2->numPontosTuristicos)
                exibirResultado("Pontos Turísticos", c1, c2, c1->numPontosTuristicos, c2->numPontosTuristicos, 1);
            else if (c2->numPontosTuristicos > c1->numPontosTuristicos)
                exibirResultado("Pontos Turísticos", c1, c2, c1->numPontosTuristicos, c2->numPontosTuristicos, 2);
            else
                exibirResultado("Pontos Turísticos", c1, c2, c1->numPontosTuristicos, c2->numPontosTuristicos, 0);
            break;
        }

        case 5: { // Densidade Demográfica (MENOR vence!)
            if (c1->densidadePopulacional < c2->densidadePopulacional)
                exibirResultado("Densidade Demográfica", c1, c2, c1->densidadePopulacional, c2->densidadePopulacional, 1);
            else if (c2->densidadePopulacional < c1->densidadePopulacional)
                exibirResultado("Densidade Demográfica", c1, c2, c1->densidadePopulacional, c2->densidadePopulacional, 2);
            else
                exibirResultado("Densidade Demográfica", c1, c2, c1->densidadePopulacional, c2->densidadePopulacional, 0);
            break;
        }

        default:
            printf("\nOpção inválida. Por favor, selecione uma opção de 1 a 5.\n");
    }
}

int main() {
    Carta cartas[QTD_CARTAS];

    // Leitura das cartas
    for (int i = 0; i < QTD_CARTAS; i++) {
        lerCarta(&cartas[i], i);
    }

    // Executa menu de comparação
    menuComparacao(&cartas[0], &cartas[1]);

    return 0;
}
