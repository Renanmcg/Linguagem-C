#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
FILE *fptr;
char ch,chanterior;
int contcar=0, contlin=0, contpalavra=0;

if (argc!=2){
    printf("\nDigite: contarV2 nome_arquivo\n");
    exit(0);
}

if ((fptr = fopen(argv[1],"r"))==NULL) {
    printf("Erro na abertura do arquivo: %s",argv[1]);
    exit(0);
}
chanterior=' ';
while ((ch=getc(fptr)) != EOF){
    printf("%c",ch);
    //getch();
    if (ch!='\n')
        contcar++;
    if (ch=='\n')
        contlin++;

    if (((ch==' ')&&(chanterior!=' ')&&(chanterior!='\n'))||((ch=='\n')&&(chanterior!='\n')&&(chanterior!=' ')))
        contpalavra++;

    chanterior = ch;
}

if (chanterior!='\n') { //Última linha terminou sem \n
    contlin++;
}

if ((chanterior!='\n')&&(chanterior!=' ')) //Última linha terminou sem \n e com espaço
    contpalavra++;

printf("\nQtde. de Caracteres: %i",contcar);
printf("\nQtde. de Linhas: %i",contlin);
printf("\nQtde. de Palavras: %i", contpalavra);

fclose(fptr);
}//Fim main
