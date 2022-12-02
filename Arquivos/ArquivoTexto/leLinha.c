/* le strings de 80 caracteres de um arquivo e imprime na tela*/
#include <stdio.h>
void main() {
FILE *fptr;
char string[81];

fptr = fopen("arqtext.txt","r");

while (fgets(string,80,fptr) != NULL){
    printf("%s", string);
    getch();
}

fclose(fptr);
}//Fim main
