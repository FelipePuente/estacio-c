#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANHO_STRING 50
#define TAMANHO_CODIGO 6

#define ATRIBUTO_ESTADO 0
#define ATRIBUTO_CODIGO 1
#define ATRIBUTO_NOME_CIDADE 2
#define ATRIBUTO_POPULACAO 3
#define ATRIBUTO_AREA 4
#define ATRIBUTO_PIB 5
#define ATRIBUTO_PONTOS_TURISTICOS 6
#define ATRIBUTO_SUPER_PODER 7
#define NUMERO_DE_ATRIBUTOS 8

struct Carta {
    char estado[TAMANHO_STRING];
    char codigo[TAMANHO_CODIGO];
    char nomeCidade[TAMANHO_STRING];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float superPoder;
};

void cadastrarCarta(struct Carta *carta, int numero);
void exibirMenuAtributos(int atributoIgnorado);
int escolherAtributo(int atributoIgnorado);
float getValorAtributo(struct Carta carta, int atributo);
void compararCartas(struct Carta carta1, struct Carta carta2, int atributo1, int atributo2, float *somaCarta1, float *somaCarta2);
const char* getNomeAtributo(int atributo);

int main() {
    struct Carta carta1, carta2;
    int atributo1, atributo2;
    float somaCarta1 = 0, somaCarta2 = 0;

    // Cadastra os dados das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    // Escolhe o primeiro atributo
    atributo1 = escolherAtributo(-1);
    while (atributo1 == -1) {
        atributo1 = escolherAtributo(-1);
    }

    // Escolhe o segundo atributo
    atributo2 = escolherAtributo(atributo1);
    while (atributo2 == -1) {
        atributo2 = escolherAtributo(atributo1);
    }

    printf("\n--- ComparaÃ§Ã£o das Cartas ---\n");
    printf("Atributo 1 escolhido: %s\n", getNomeAtributo(atributo1));
    printf("Atributo 2 escolhido: %s\n", getNomeAtributo(atributo2));
    printf("\n");

    // ObtÃ©m os valores dos atributos para exibiÃ§Ã£o
    float valor1_atributo1 = getValorAtributo(carta1, atributo1);
    float valor2_atributo1 = getValorAtributo(carta2, atributo1);
    float valor1_atributo2 = getValorAtributo(carta1, atributo2);
    float valor2_atributo2 = getValorAtributo(carta2, atributo2);

    // Exibe os valores dos atributos para cada carta
    printf("Carta 1 (%s):\n", carta1.nomeCidade);
    if (valor1_atributo1 >= -1.0f) { // Verifica se nÃ£o Ã© um atributo de string
        printf("  %s: %.2f\n", getNomeAtributo(atributo1), valor1_atributo1);
    } else {
        printf("  %s: %s\n", getNomeAtributo(atributo1), (atributo1 == ATRIBUTO_ESTADO) ? carta1.estado : (atributo1 == ATRIBUTO_CODIGO) ? carta1.codigo : carta1.nomeCidade);
    }
    if (valor1_atributo2 >= -1.0f) {
        printf("  %s: %.2f\n", getNomeAtributo(atributo2), valor1_atributo2);
    } else {
        printf("  %s: %s\n", getNomeAtributo(atributo2), (atributo2 == ATRIBUTO_ESTADO) ? carta1.estado : (atributo2 == ATRIBUTO_CODIGO) ? carta1.codigo : carta1.nomeCidade);
    }
    printf("Soma dos atributos: %.2f\n\n", somaCarta1);

    printf("Carta 2 (%s):\n", carta2.nomeCidade);
    if (valor2_atributo1 >= -1.0f) {
        printf("  %s: %.2f\n", getNomeAtributo(atributo1), valor2_atributo1);
    } else {
        printf("  %s: %s\n", getNomeAtributo(atributo1), (atributo1 == ATRIBUTO_ESTADO) ? carta2.estado : (atributo1 == ATRIBUTO_CODIGO) ? carta2.codigo : carta2.nomeCidade);
    }
    if (valor2_atributo2 >= -1.0f) {
        printf("  %s: %.2f\n", getNomeAtributo(atributo2), valor2_atributo2);
    } else {
        printf("  %s: %s\n", getNomeAtributo(atributo2), (atributo2 == ATRIBUTO_ESTADO) ? carta2.estado : (atributo2 == ATRIBUTO_CODIGO) ? carta2.codigo : carta2.nomeCidade);
    }
    printf("Soma dos atributos: %.2f\n\n", somaCarta2);

    // Compara as cartas e calcula a soma dos atributos
    compararCartas(carta1, carta2, atributo1, atributo2, &somaCarta1, &somaCarta2);

    // Determina a carta vencedora
    printf("--- Resultado da ComparaÃ§Ã£o ---\n");
    if (somaCarta1 > somaCarta2) {
        printf("Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (somaCarta2 > somaCarta1) {
        printf("Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Empate!\n");
    }

    return 0;
}

// (As funÃ§Ãµes cadastrarCarta, exibirMenuAtributos, escolherAtributo, getValorAtributo e compararCartas permanecem as mesmas do cÃ³digo anterior)

void cadastrarCarta(struct Carta *carta, int numero) {
    printf("Insira os dados da Carta %d:\n", numero);
    printf("Estado: ");
    scanf(" %49[^\n]", carta->estado);
    printf("Código da Carta: ");
    scanf(" %5s", carta->codigo);
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", carta->nomeCidade);
    printf("População: ");
    scanf("%d", &carta->populacao);
    printf("Ãrea (em kmÂ²): ");
    scanf("%f", &carta->area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);
    printf("Número de Pontos Turí­sticos: ");
    scanf("%d", &carta->pontosTuristicos);
    printf("Super Poder: ");
    scanf("%f", &carta->superPoder);
    printf("\n");
}

void exibirMenuAtributos(int atributoIgnorado) {
    printf("Escolha um atributo para comparar:\n");
    printf("0 - Estado\n");
    printf("1 - Código da Carta\n");
    printf("2 - Nome da Cidade\n");
    printf("3 - População\n");
    printf("4 - Ãrea\n");
    printf("5 - PIB\n");
    printf("6 - Número de Pontos Turísticos\n");
    printf("7 - Super Poder\n");
    printf("Escolha o número do atributo: ");
}

int escolherAtributo(int atributoIgnorado) {
    int escolha;
    exibirMenuAtributos(atributoIgnorado);
    scanf("%d", &escolha);
    if (escolha < 0 || escolha >= NUMERO_DE_ATRIBUTOS || escolha == atributoIgnorado) {
        printf("Escolha invÃ¡lida. Por favor, tente novamente.\n");
        return -1;
    }
    return escolha;
}

float getValorAtributo(struct Carta carta, int atributo) {
    switch (atributo) {
        case ATRIBUTO_ESTADO:
            return -2.0f;
        case ATRIBUTO_CODIGO:
            return -2.0f;
        case ATRIBUTO_NOME_CIDADE:
            return -2.0f;
        case ATRIBUTO_POPULACAO:
            return (float)carta.populacao;
        case ATRIBUTO_AREA:
            return carta.area;
        case ATRIBUTO_PIB:
            return carta.pib;
        case ATRIBUTO_PONTOS_TURISTICOS:
            return (float)carta.pontosTuristicos;
        case ATRIBUTO_SUPER_PODER:
            return carta.superPoder;
        default:
            printf("Erro: Atributo invÃ¡lido.\n");
            exit(1);
    }
}

void compararCartas(struct Carta carta1, struct Carta carta2, int atributo1, int atributo2, float *somaCarta1, float *somaCarta2) {
    float valor1_atributo1 = getValorAtributo(carta1, atributo1);
    float valor2_atributo1 = getValorAtributo(carta2, atributo1);
    float valor1_atributo2 = getValorAtributo(carta1, atributo2);
    float valor2_atributo2 = getValorAtributo(carta2, atributo2);

    *somaCarta1 = 0;
    *somaCarta2 = 0;

    // ComparaÃ§Ã£o do primeiro atributo
    if (atributo1 == ATRIBUTO_AREA) { // Densidade DemogrÃ¡fica (menor valor vence)
        if (valor1_atributo1 < valor2_atributo1) {
            *somaCarta1 += 1;
        } else if (valor2_atributo1 < valor1_atributo1) {
            *somaCarta2 += 1;
        }
    } else if (valor1_atributo1 > valor2_atributo1) {
        *somaCarta1 += 1;
    } else if (valor2_atributo1 > valor1_atributo1) {
        *somaCarta2 += 1;
    }

    // ComparaÃ§Ã£o do segundo atributo
    if (atributo2 == ATRIBUTO_AREA) { // Densidade DemogrÃ¡fica (menor valor vence)
        if (valor1_atributo2 < valor2_atributo2) {
            *somaCarta1 += 1;
        } else if (valor2_atributo2 < valor1_atributo2) {
            *somaCarta2 += 1;
        }
    } else if (valor1_atributo2 > valor2_atributo2) {
        *somaCarta1 += 1;
    } else if (valor2_atributo2 > valor1_atributo2) {
        *somaCarta2 += 1;
    }

    // Adiciona os valores dos atributos Ã  soma (para desempate)
    if (valor1_atributo1 >= 0) {
        *somaCarta1 += valor1_atributo1;
    }
    if (valor2_atributo1 >= 0) {
        *somaCarta2 += valor2_atributo1;
    }
    if (valor1_atributo2 >= 0) {
        *somaCarta1 += valor1_atributo2;
    }
    if (valor2_atributo2 >= 0) {
        *somaCarta2 += valor2_atributo2;
    }
}

const char* getNomeAtributo(int atributo) {
    switch (atributo) {
        case ATRIBUTO_ESTADO:
            return "Estado";
        case ATRIBUTO_CODIGO:
            return "CÃ³digo da Carta";
        case ATRIBUTO_NOME_CIDADE:
            return "Nome da Cidade";
        case ATRIBUTO_POPULACAO:
            return "PopulaÃ§Ã£o";
        case ATRIBUTO_AREA:
            return "Ãrea";
        case ATRIBUTO_PIB:
            return "PIB";
        case ATRIBUTO_PONTOS_TURISTICOS:
            return "NÃºmero de Pontos TurÃ­sticos";
        case ATRIBUTO_SUPER_PODER:
            return "Super Poder";
        default:
            return "Atributo Desconhecido";
    }
}
