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

int main() {
    struct Carta carta1, carta2;
    int opcao;

    // Cadastro da carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Nome do pais: ");
    scanf(" %[^\n]", carta1.nome);
    printf("Populacao: ");
    scanf("%d", &carta1.populacao);
    printf("Area (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta1.pontos_turisticos);
    carta1.densidade_demografica = carta1.populacao / carta1.area;

    // Cadastro da carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Nome do pais: ");
    scanf(" %[^\n]", carta2.nome);
    printf("Populacao: ");
    scanf("%d", &carta2.populacao);
    printf("Area (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta2.pontos_turisticos);
    carta2.densidade_demografica = carta2.populacao / carta2.area;

    // Menu de atributos
    printf("\n===== MENU DE COMPARACAO =====\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de pontos turisticos\n");
    printf("5 - Densidade demografica\n");
    printf("Escolha o atributo para comparacao: ");
    scanf("%d", &opcao);

    printf("\n===== RESULTADO =====\n");

    switch (opcao) {
        case 1: // População
            printf("Atributo escolhido: Populacao\n");
            printf("%s: %d habitantes\n", carta1.nome, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nome, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("Vencedor: %s!\n", carta1.nome);
            else if (carta2.populacao > carta1.populacao)
                printf("Vencedor: %s!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        case 2: // Área
            printf("Atributo escolhido: Area\n");
            printf("%s: %.2f km²\n", carta1.nome, carta1.area);
            printf("%s: %.2f km²\n", carta2.nome, carta2.area);
            if (carta1.area > carta2.area)
                printf("Vencedor: %s!\n", carta1.nome);
            else if (carta2.area > carta1.area)
                printf("Vencedor: %s!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        case 3: // PIB
            printf("Atributo escolhido: PIB\n");
            printf("%s: %.2f bilhões\n", carta1.nome, carta1.pib);
            printf("%s: %.2f bilhões\n", carta2.nome, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("Vencedor: %s!\n", carta1.nome);
            else if (carta2.pib > carta1.pib)
                printf("Vencedor: %s!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("Atributo escolhido: Pontos Turisticos\n");
            printf("%s: %d pontos\n", carta1.nome, carta1.pontos_turisticos);
            printf("%s: %d pontos\n", carta2.nome, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos)
                printf("Vencedor: %s!\n", carta1.nome);
            else if (carta2.pontos_turisticos > carta1.pontos_turisticos)
                printf("Vencedor: %s!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        case 5: // Densidade demográfica
            printf("Atributo escolhido: Densidade Demografica\n");
            printf("%s: %.2f hab/km²\n", carta1.nome, carta1.densidade_demografica);
            printf("%s: %.2f hab/km²\n", carta2.nome, carta2.densidade_demografica);
            // Aqui a lógica é invertida: vence o MENOR valor
            if (carta1.densidade_demografica < carta2.densidade_demografica)
                printf("Vencedor: %s!\n", carta1.nome);
            else if (carta2.densidade_demografica < carta1.densidade_demografica)
                printf("Vencedor: %s!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }

    return 0;
}
