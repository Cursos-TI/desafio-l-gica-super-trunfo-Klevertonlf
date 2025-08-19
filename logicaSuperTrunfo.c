#include <stdio.h>

// Estrutura da Carta
typedef struct {
    char estado[50];            // Ex.: "Sao Paulo", "Rio de Janeiro" (nome do estado)
    char codigo[5];             // Ex.: "SP01", "RJ01"
    char nomeCidade[50];        // Ex.: "Sao Paulo", "Rio de Janeiro"
    int   populacao;            // habitantes
    float area;                 // km²
    float pib;                  // bilhões
    int   pontosTuristicos;     // unidades
    float densidadePopulacional;// calculado: populacao/area
    float pibPerCapita;         // calculado: pib/populacao
} Carta;

/* --------- Cálculos derivados --------- */
void calcularAtributos(Carta *c) {
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
}

/* --------- Exibir carta --------- */
void exibirCarta(const Carta c) {
    printf("\n=== Carta %s ===\n", c.codigo);
    printf("Cidade: %s (%s)\n", c.nomeCidade, c.estado);
    printf("Populacao: %d\n", c.populacao);
    printf("Area: %.2f km2\n", c.area);
    printf("PIB: %.2f bilhoes\n", c.pib);
    printf("Pontos Turisticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km2\n", c.densidadePopulacional);
    printf("PIB per capita: %.6f bilhoes\n", c.pibPerCapita);
}

/* --------- Comparacao (usada no Novato e Aventureiro) --------- */
void compararAtributo(const Carta c1, const Carta c2, int atributo) {
    printf("\n=== Comparacao de Cartas ===\n");
    switch (atributo) {
        case 1: // Populacao (maior vence)
            printf("Comparando Populacao:\n");
            printf("%s: %d x %s: %d\n", c1.nomeCidade, c1.populacao, c2.nomeCidade, c2.populacao);
            if (c1.populacao > c2.populacao)      printf("Vencedora: %s\n", c1.nomeCidade);
            else if (c2.populacao > c1.populacao) printf("Vencedora: %s\n", c2.nomeCidade);
            else                                   printf("Empate!\n");
            break;

        case 2: // Area (maior vence)
            printf("Comparando Area:\n");
            printf("%s: %.2f x %s: %.2f\n", c1.nomeCidade, c1.area, c2.nomeCidade, c2.area);
            if (c1.area > c2.area)                 printf("Vencedora: %s\n", c1.nomeCidade);
            else if (c2.area > c1.area)            printf("Vencedora: %s\n", c2.nomeCidade);
            else                                   printf("Empate!\n");
            break;

        case 3: // PIB (maior vence)
            printf("Comparando PIB:\n");
            printf("%s: %.2f x %s: %.2f\n", c1.nomeCidade, c1.pib, c2.nomeCidade, c2.pib);
            if (c1.pib > c2.pib)                   printf("Vencedora: %s\n", c1.nomeCidade);
            else if (c2.pib > c1.pib)              printf("Vencedora: %s\n", c2.nomeCidade);
            else                                   printf("Empate!\n");
            break;

        case 4: // Densidade Populacional (MENOR vence)
            printf("Comparando Densidade Populacional (MENOR vence):\n");
            printf("%s: %.2f x %s: %.2f\n", c1.nomeCidade, c1.densidadePopulacional, c2.nomeCidade, c2.densidadePopulacional);
            if (c1.densidadePopulacional < c2.densidadePopulacional)      printf("Vencedora: %s\n", c1.nomeCidade);
            else if (c2.densidadePopulacional < c1.densidadePopulacional) printf("Vencedora: %s\n", c2.nomeCidade);
            else                                                           printf("Empate!\n");
            break;

        case 5: // PIB per capita (maior vence)
            printf("Comparando PIB per capita:\n");
            printf("%s: %.6f x %s: %.6f\n", c1.nomeCidade, c1.pibPerCapita, c2.nomeCidade, c2.pibPerCapita);
            if (c1.pibPerCapita > c2.pibPerCapita)      printf("Vencedora: %s\n", c1.nomeCidade);
            else if (c2.pibPerCapita > c1.pibPerCapita) printf("Vencedora: %s\n", c2.nomeCidade);
            else                                        printf("Empate!\n");
            break;

        default:
            printf("Opcao invalida!\n");
    }
}

int main(void) {
    /* Cartas preenchidas (todos os campos inicializados).
       Os dois ultimos (densidade/pib per capita) entram como 0.0f para evitar warnings;
       em seguida sao calculados por calcularAtributos(). */
    Carta carta1 = { "Sao Paulo", "SP01", "Sao Paulo", 12300000,
                     1521.11f, 750.50f, 15, 0.0f, 0.0f };
    Carta carta2 = { "Rio de Janeiro", "RJ01", "Rio de Janeiro", 6748000,
                     1182.30f, 400.75f, 12, 0.0f, 0.0f };

    // Calcula atributos derivados
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    /* ===== Nível Novato (comparacao fixa: Populacao) ===== */
    printf("\n==============================\n");
    printf("SUPER TRUNFO - NIVEL NOVATO\n");
    printf("==============================\n");
    exibirCarta(carta1);
    exibirCarta(carta2);
    compararAtributo(carta1, carta2, 1); // 1 = Populacao

    /* ===== Nível Aventureiro (menu com switch) ===== */
    printf("\n==============================\n");
    printf("SUPER TRUNFO - NIVEL AVENTUREIRO\n");
    printf("==============================\n");
    int opcao = 3; // <- escolha interna para ficar 100% automatico (ex.: 3 = PIB)
    printf("Escolha (automatico para demonstracao): %d\n", opcao);
    compararAtributo(carta1, carta2, opcao);

    /* ===== Nível Mestre (comparar DOIS atributos, com logica de pontos) ===== */
    printf("\n==============================\n");
    printf("SUPER TRUNFO - NIVEL MESTRE\n");
    printf("==============================\n");
    int op1 = 1; // primeiro atributo (ex.: 1 Populacao)
    int op2 = 4; // segundo atributo (ex.: 4 Densidade - menor vence)
    printf("Atributos escolhidos (automatico): %d e %d\n", op1, op2);

    int pontos1 = 0, pontos2 = 0;

    // Atributo 1
    if (op1 == 4) (carta1.densidadePopulacional < carta2.densidadePopulacional) ? pontos1++ : (carta2.densidadePopulacional < carta1.densidadePopulacional ? pontos2++ : 0);
    else if (op1 == 1) (carta1.populacao > carta2.populacao) ? pontos1++ : (carta2.populacao > carta1.populacao ? pontos2++ : 0);
    else if (op1 == 2) (carta1.area > carta2.area) ? pontos1++ : (carta2.area > carta1.area ? pontos2++ : 0);
    else if (op1 == 3) (carta1.pib > carta2.pib) ? pontos1++ : (carta2.pib > carta1.pib ? pontos2++ : 0);
    else if (op1 == 5) (carta1.pibPerCapita > carta2.pibPerCapita) ? pontos1++ : (carta2.pibPerCapita > carta1.pibPerCapita ? pontos2++ : 0);

    // Atributo 2
    if (op2 == 4) (carta1.densidadePopulacional < carta2.densidadePopulacional) ? pontos1++ : (carta2.densidadePopulacional < carta1.densidadePopulacional ? pontos2++ : 0);
    else if (op2 == 1) (carta1.populacao > carta2.populacao) ? pontos1++ : (carta2.populacao > carta1.populacao ? pontos2++ : 0);
    else if (op2 == 2) (carta1.area > carta2.area) ? pontos1++ : (carta2.area > carta1.area ? pontos2++ : 0);
    else if (op2 == 3) (carta1.pib > carta2.pib) ? pontos1++ : (carta2.pib > carta1.pib ? pontos2++ : 0);
    else if (op2 == 5) (carta1.pibPerCapita > carta2.pibPerCapita) ? pontos1++ : (carta2.pibPerCapita > carta1.pibPerCapita ? pontos2++ : 0);

    printf("\nResultado Mestre:\n");
    if (pontos1 > pontos2)      printf("Vencedora: %s\n", carta1.nomeCidade);
    else if (pontos2 > pontos1) printf("Vencedora: %s\n", carta2.nomeCidade);
    else                        printf("Empate!\n");

    return 0;
}
