#include <stdio.h>
int calculaArea(int l1, int l2){
 int area;
 area =  l1 * l2;
 return area;
 /*ou simplesmente return l1 * l2; */
}
int calculaPerimetro(int l1, int l2){
 int perimetro;
 perimetro = 2*l1 + 2*l2;
 return perimetro;
 /*ou simplesmente return 2*l1 + 2*l2; */
}

int main()
{
 int lado1, lado2, area;
 printf("Digite as medidas dos lados de um retângulo: ");
 scanf("%i, %i", &lado1, &lado2);
 area = calculaArea(lado1, lado2);
 printf("A área do retângulo e %i", area);
 printf("O perímetro do retângulo e %i", calculaPerimetro(lado1, lado2));
}
