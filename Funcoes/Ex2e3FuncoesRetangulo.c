#include <stdio.h>

int calculaArea(int base, int altura) {

    return (base * altura);

}//Fim calculaArea()

int  calculaPerimetro(int base, int altura) {

   return (2*base + 2*altura);

}//Fim calculaPerimetro()

void main(){
 int lado1, lado2, area;

 printf("Digite as medidas dos lados de um retângulo: ");
 scanf("%i %i", &lado1, &lado2);

 area=calculaArea(lado1, lado2);

 printf("A area do retangulo e %i", area);
 printf("\nO perimetro do retangulo e %i", calculaPerimetro(lado1, lado2));
}//Fim main()
