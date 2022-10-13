#include <stdio.h>
int maiorValor(int x, int y, int z, int maior) {
 if (x > y) {maior = x;}
 else {maior = y;}
 if (maior < z) {maior = z;}
 return maior;
}
int menorValor(int x, int y, int z, int menor) {
 if (x < y) {menor = x;}
 else {menor = y;}
 if (menor > z) {menor = z;}
 return menor;
}
int main()
{
 int v1, v2, v3, maior, menor;
 printf("Informe 3 valores inteiros:");
 scanf("%i %i %i", &v1, &v2, &v3);
 maior=maiorValor(v1, v2, v3, maior);
 menor=menorValor(v1, v2, v3, menor);
 printf("O maior valor informado foi %i", maior);
 printf("\nO menor valor informado foi %i", menor);
}
