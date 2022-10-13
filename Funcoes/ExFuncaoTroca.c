#include <stdio.h>
#include <stdlib.h>

void trocaPorRef(int *x, int *y) { //Por Referência
int temp;

  temp = *x;
  *x = *y;
  *y = temp;
}

void trocaPorValor(int x, int y) { //Por valor
int temp;

  temp = x;
  x = y;
  y = temp;
}

void main ( ) {
int a=45 , b=21;

printf("Antes de trocaPorValor: a=%d b=%d \n", a, b);
trocaPorValor(a,b); //Passagem por valor
printf("Depois de trocaPorValor: a=%d b=%d \n", a, b);

system("pause");

trocaPorRef(&a, &b); //Passagem por referência
printf("\nDepois de trocaPorRef: a=%d b=%d \n", a, b);

}
