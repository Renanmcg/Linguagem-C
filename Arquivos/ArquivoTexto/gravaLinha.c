/* le cada linha digitada via teclado e armazena no arquivo.
O programa termina quando digita-se uma linha em branco */
#include <stdio.h>
#include <string.h>
void main() {
FILE *fptr;
char string[81];

fptr = fopen("arqtext2.txt","w");

while (strlen(gets(string)) > 0) {
    fputs(string,fptr);
    fputs("\n",fptr);
}
fclose(fptr);
}//Fim main
