#include <stdio.h>
#include <string.h>

main(){
  char nome[30];
  int  i;

  //Entrada
  printf("\nDigite o nome: ");
  fflush(stdin); gets(nome);

  //Processamento
  nome[0] = toupper(nome[0]);
  for(i=1; i<strlen(nome); i++){
    if(nome[i-1] == ' '){
        nome[i] = toupper(nome[i]);
    }
  }

  //Saída
  printf("\nNome com iniciais em Maiusculo: %s\n",nome);
}//Fim main
