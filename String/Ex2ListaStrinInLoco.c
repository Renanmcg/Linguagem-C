#include <stdio.h>
#include <string.h>

main(){
  char nome[30];
  int  i,j;
  char aux;

  //Entrada
  printf("\nDigite o nome: ");
  fflush(stdin); gets(nome);

  //Processamento
  j=0;
  for (i=strlen(nome)-1; i>=strlen(nome)/2; i--,j++){
    //Fazer a Troca
    aux = nome[j]; //Guarda o caractere do in�cio
    nome[j] = nome[i]; //Pega do fim e coloca no in�cio
    nome[i] = aux; //Coloca o aux no fim
  }

  //Sa�da
  printf("\nString invertida: %s\n",nome);
}//Fim main()
