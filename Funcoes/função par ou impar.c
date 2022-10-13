#include <stdio.h>
int verificaValor(int v) {
    if(v % 2 == 0)
        return 0;
    else
        return 1;
}

void main(){
 int valor, teste;
 printf("Digite um valor inteiro: ");
 scanf("%i", &valor);
 teste=verificaValor(valor);
    if(teste==0){
        printf("O valor digitado e par!");
        else printf("O valor digitado e par!");
        }
 }
