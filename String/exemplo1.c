#include <stdio.h>
#include <string.h>

void myfgets(char str[],int max){
  char ch;
  int cont=0;

  while ((cont<max-2)&&((ch=getch())!='\r')){
         printf("%c",ch);
         if (ch!='\b'){ //Backspace
            str[cont]=ch;
            cont++;
         }else{
            cont--;
         }
  }
  str[cont]='\0';

}//Fim myfgets()


main(){
 char endereco[30];
 char nome[30];
 char juntar[65];
 int i;

 printf("\ndigite o Nome: ");
 //fflush(stdin); scanf("%s",&nome);
 //fflush(stdin); gets(nome);
 //fflush(stdin); fgets(nome,30,stdin);
 fflush(stdin); myfgets(nome,30);

 printf("\nDigite o endereco: ");
 fflush(stdin); gets(endereco);



 printf("\nNome: %s",nome);
 printf("\nendereco: %s",endereco);

 printf("\nTamanho da string digitada: %i\n", strlen(nome));


 for (i=0; i<strlen(nome); i++)
    printf("\nnome[%i] = %c",i,nome[i]);

 strcat(juntar,nome);
 printf("\nJuntar: %s",juntar);

 strcat(juntar,"->");
 strcat(juntar,endereco);

 printf("\nJuntar: %s\n",juntar);

}//Fim main
