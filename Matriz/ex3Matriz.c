#include <stdio.h>

#define TAM 3

main(){
int mat[TAM][TAM];
int i,j, soma=0, cont=0;
float media;

//Entrada de Dados
for (i=0; i<TAM; i++){ //varia as linhas
    for (j=0; j<TAM; j++){ //varia as colunas
        printf("mat[%i][%i]= ",i,j);
        fflush(stdin); scanf("%i",&mat[i][j]);
    }
}

//Imprime a Matriz
printf("\n* *  Matriz  * *\n");
for (i=0; i<TAM; i++){ //varia as linhas
    for (j=0; j<TAM; j++){ //varia as colunas
        printf("%i ",mat[i][j]);
    }
    printf("\n");
}

//Processamento
for (i=0; i<TAM; i++){ //varia as linhas
    for (j=0; j<TAM; j++){ //varia as colunas
        soma = soma + mat[i][j];
    }
}

media = (float) soma / (TAM*TAM);

//Contando os menores que a media
for (i=0; i<TAM; i++){ //varia as linhas
    for (j=0; j<TAM; j++){ //varia as colunas
        if (mat[i][j]<media)
            cont++;
    }
}

//Saída
printf("\n\nMedia: %5.2f", media);
printf("\nQtde. menores que a media: %i\n",cont);

} //Fim main
