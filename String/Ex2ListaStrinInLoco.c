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
    aux = nome[j]; //Guarda o caractere do início
    nome[j] = nome[i]; //Pega do fim e coloca no início
    nome[i] = aux; //Coloca o aux no fim
  }

  //Saída
  printf("\nString invertida: %s\n",nome);
}//Fim main()
