#include <stdio.h>

struct Carta {
    char estado[3];
    char codigo[5];
    char nome[30];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
};

int main() {
    struct Carta carta1, carta2;

    // Cadastro da carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Estado: ");
    scanf("%s", carta1.estado);
    printf("Codigo: ");
    scanf("%s", carta1.codigo);
    printf("Cidade: ");
    scanf(" %[^\n]", carta1.nome);
    printf("Populacao: ");
    scanf("%d", &carta1.populacao);
    printf("Area: ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    printf("Pontos Turisticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // Cadastro da carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: ");
    scanf("%s", carta2.estado);
    printf("Codigo: ");
    scanf("%s", carta2.codigo);
    printf("Cidade: ");
    scanf(" %[^\n]", carta2.nome);
    printf("Populacao: ");
    scanf("%d", &carta2.populacao);
    printf("Area: ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    printf("Pontos Turisticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Cálculos
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    carta2.densidade_populacional = carta2.populacao / carta2.area;

    carta1.pib_per_capita = carta1.pib / carta1.populacao;
    carta2.pib_per_capita = carta2.pib / carta2.populacao;

    // Escolha do atributo para comparar
    // Altere esta variável para mudar o critério da comparação
    char atributo[] = "populacao";  // pode ser: populacao, area, pib, densidade, pib_per_capita, pontos

    printf("\nComparacao de cartas (Atributo: %s)\n", atributo);

    if (strcmp(atributo, "densidade") == 0) {
        if (carta1.densidade_populacional < carta2.densidade_populacional)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else if (strcmp(atributo, "populacao") == 0) {
        if (carta1.populacao > carta2.populacao)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else if (strcmp(atributo, "area") == 0) {
        if (carta1.area > carta2.area)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else if (strcmp(atributo, "pib") == 0) {
        if (carta1.pib > carta2.pib)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else if (strcmp(atributo, "pib_per_capita") == 0) {
        if (carta1.pib_per_capita > carta2.pib_per_capita)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else if (strcmp(atributo, "pontos") == 0) {
        if (carta1.pontos_turisticos > carta2.pontos_turisticos)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("Atributo invalido!\n");
    }

    return 0;
}
