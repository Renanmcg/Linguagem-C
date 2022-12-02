//Le caracteres do teclado e escreve um caractere por vez no arquivo

#include <stdio.h>
#include <stdlib.h>
void main(){
FILE *fptr;
char ch;

  fptr = fopen("arqtext.txt","a");

  while ((ch=getche()) != '\r')
        putc(ch,fptr);

  fclose(fptr);
}//Fim main
