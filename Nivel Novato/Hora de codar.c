#include <stdio.h>

int main(){
    float temperatura, umidade;
    unsigned int estoque, estoqueMinimo = 1500;

 printf("Entre com a temperatura:");
 scanf("%f", &temperatura);
 printf("Entre com a umidade:");
 scanf("%f", &umidade);
 printf("Entre com o estoque:");
 scanf("%u", &estoque);

    if( temperatura > 30){

        printf("A temperatura está alta\n");

    } else {

        printf("A temperatura está normal\n");
    }

 if( umidade > 50){

        printf("A umidade está alta\n");

    } else {

        printf("Umidade está normal\n");

    }

if( estoque >= estoqueMinimo){

        printf("O estoque está acima do mínimo\n");

    } else {

        printf("O estoque está abaixo do mínimo\n");
    }

}