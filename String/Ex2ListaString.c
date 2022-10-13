#include <stdio.h>
#include <string.h>

main(){
  char nome[30];
  char invertida[30];
  int  i,j;

  //Entrada
  printf("\nDigite o nome: ");
  fflush(stdin); gets(nome);

  //Processamento
  j=0;
  for (i=strlen(nome)-1; i>=0; i--,j++){
    invertida[j] = nome[i];
    //j++;
  }
  invertida[j] = '\0';
  //Saída
  printf("\nString invertida: %s\n",invertida);
}//Fim main()
