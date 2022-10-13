#include <stdio.h>

main(){
int  mat[3][3];
int i,j, soma=0;

//Entrada
for(i=0; i<3; i++){ //varia a linha
    for(j=0; j<3; j++){ //Varia a coluna
        printf("mat[%i][%i]= ",i,j);
        fflush(stdin); scanf("%i",&mat[i][j]);
    }
}

//Imprime a Matriz
for(i=0; i<3; i++){ //varia a linha
    for(j=0; j<3; j++){ //Varia a coluna
        printf("%3i ",mat[i][j]);
    }
    printf("\n");
}

//Processamento
printf("\n\nDiag. Principal: ");
for(i=0; i<3; i++){ //varia a linha
    for(j=0; j<3; j++){ //Varia a coluna
        if (i==j){ //Elemento da Diagonal Principal
            printf("%3i ",mat[i][j]);
            soma = soma + mat[i][j];
        }
    }
}

//Saída
printf("\nSoma da Diagonal Principal: %i",soma);

}//Fim main
