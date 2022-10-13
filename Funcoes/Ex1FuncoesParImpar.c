#include <stdio.h>

int verificaValor(int v) {

 if (v%2==0)
    return 0;  //Nro Par
 else
    return 1; //Nro Impar

}//Fim verificaValor()

main() {
 int valor, teste;

 printf("Digite um valor inteiro: ");
 scanf("%i", &valor);

 teste=verificaValor(valor);

 if(teste==0)
    printf("O valor digitado e par!");
 else
    printf("O valor digitado e impar!");
}//Fim main()
