#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caixaAlta(char str[]){
  int i;

  for(i=0;i<strlen(str);i++)
    str[i] = toupper(str[i]);
}//Fim caixaAlta


main () {
char cidade[] = "PARIS";
char cap[10];
int i;

for (i = 0 ; i < 10 ; i ++) {
    printf("\nDigite o nome da capital da Franca: ");
    fflush(stdin); gets(cap);

    caixaAlta(cap);
    if (strcmp(cap,cidade) != 0)
        puts ("\nVoce errou. Tente outra vez !\n");
    else {
        puts("\nVoce acertou\n");
        break;
    }
}

   //system("pause");

}//Fim main
