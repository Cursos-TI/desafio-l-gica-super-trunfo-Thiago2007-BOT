#include <stdio.h>
#include <string.h>

struct Carta {
    char nome[30];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_demografica;
};

// Função que compara um atributo e retorna uma pontuação
float compararAtributo(int atributo, struct Carta c1, struct Carta c2) {
    float valor1, valor2;
    float resultado = 0;

    switch (atributo) {
        case 1: // População
            valor1 = c1.populacao;
            valor2 = c2.populacao;
            resultado = (valor1 > valor2) ? 1 : (valor1 < valor2 ? -1 : 0);
            break;
        case 2: // Área
            valor1 = c1.area;
            valor2 = c2.area;
            resultado = (valor1 > valor2) ? 1 : (valor1 < valor2 ? -1 : 0);
            break;
        case 3: // PIB
            valor1 = c1.pib;
            valor2 = c2.pib;
            resultado = (valor1 > valor2) ? 1 : (valor1 < valor2 ? -1 : 0);
            break;
        case 4: // Pontos turísticos
            valor1 = c1.pontos_turisticos;
            valor2 = c2.pontos_turisticos;
            resultado = (valor1 > valor2) ? 1 : (valor1 < valor2 ? -1 : 0);
            break;
        case 5: // Densidade demográfica (vence menor)
            valor1 = c1.densidade_demografica;
            valor2 = c2.densidade_demografica;
            resultado = (valor1 < valor2) ? 1 : (valor1 > valor2 ? -1 : 0);
            break;
        default:
            resultado = 0;
    }

    return resultado;
}

int main() {
    struct Carta carta1, carta2;
    int atributo1, atributo2;

    // Cadastro das cartas
    printf("Digite os dados da Carta 1:\n");
    printf("Nome do pais: ");
    scanf(" %[^\n]", carta1.nome);
    printf("Populacao: ");
    scanf("%d", &carta1.populacao);
    printf("Area (km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (bilhoes): ");
    scanf("%f", &carta1.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta1.pontos_turisticos);
    carta1.densidade_demografica = carta1.populacao / carta1.area;

    printf("\nDigite os dados da Carta 2:\n");
    printf("Nome do pais: ");
    scanf(" %[^\n]", carta2.nome);
    printf("Populacao: ");
    scanf("%d", &carta2.populacao);
    printf("Area (km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (bilhoes): ");
    scanf("%f", &carta2.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta2.pontos_turisticos);
    carta2.densidade_demografica = carta2.populacao / carta2.area;

    // MENU DINÂMICO — ESCOLHA DOS ATRIBUTOS
    printf("\n===== MENU DE ATRIBUTOS =====\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("=============================\n");

    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);

    do {
        printf("Escolha o segundo atributo (diferente do primeiro): ");
        scanf("%d", &atributo2);
        if (atributo2 == atributo1)
            printf("❌ O segundo atributo deve ser diferente do primeiro!\n");
    } while (atributo2 == atributo1);

    // Comparação dos dois atributos
    float resultado1 = compararAtributo(atributo1, carta1, carta2);
    float resultado2 = compararAtributo(atributo2, carta1, carta2);

    // Soma dos resultados (1 = carta1 vence, -1 = carta2 vence, 0 = empate)
    float soma1 = (resultado1 > 0) + (resultado2 > 0);
    float soma2 = (resultado1 < 0) + (resultado2 < 0);

    // Exibição dos resultados
    printf("\n===== RESULTADO FINAL =====\n");
    printf("Cartas: %s x %s\n", carta1.nome, carta2.nome);
    printf("Atributos usados: %d e %d\n", atributo1, atributo2);
    printf("----------------------------\n");

    // Exibe detalhes dos atributos
    if (atributo1 == 1) printf("Populacao -> %s: %d | %s: %d\n", carta1.nome, carta1.populacao, carta2.nome, carta2.populacao);
    if (atributo1 == 2) printf("Area -> %s: %.2f | %s: %.2f\n", carta1.nome, carta1.area, carta2.nome, carta2.area);
    if (atributo1 == 3) printf("PIB -> %s: %.2f | %s: %.2f\n", carta1.nome, carta1.pib, carta2.nome, carta2.pib);
    if (atributo1 == 4) printf("Pontos -> %s: %d | %s: %d\n", carta1.nome, carta1.pontos_turisticos, carta2.nome, carta2.pontos_turisticos);
    if (atributo1 == 5) printf("Densidade -> %s: %.2f | %s: %.2f\n", carta1.nome, carta1.densidade_demografica, carta2.nome, carta2.densidade_demografica);

    if (atributo2 == 1) printf("Populacao -> %s: %d | %s: %d\n", carta1.nome, carta1.populacao, carta2.nome, carta2.populacao);
    if (atributo2 == 2) printf("Area -> %s: %.2f | %s: %.2f\n", carta1.nome, carta1.area, carta2.nome, carta2.area);
    if (atributo2 == 3) printf("PIB -> %s: %.2f | %s: %.2f\n", carta1.nome, carta1.pib, carta2.nome, carta2.pib);
    if (atributo2 == 4) printf("Pontos -> %s: %d | %s: %d\n", carta1.nome, carta1.pontos_turisticos, carta2.nome, carta2.pontos_turisticos);
    if (atributo2 == 5) printf("Densidade -> %s: %.2f | %s: %.2f\n", carta1.nome, carta1.densidade_demografica, carta2.nome, carta2.densidade_demografica);

    printf("----------------------------\n");
    printf("Soma dos pontos: %s = %.0f | %s = %.0f\n", carta1.nome, soma1, carta2.nome, soma2);

    if (soma1 > soma2)
        printf("🏆 %s venceu a rodada!\n", carta1.nome);
    else if (soma2 > soma1)
        printf("🏆 %s venceu a rodada!\n", carta2.nome);
    else
        printf("⚖️ Empate!\n");

    return 0;
}
