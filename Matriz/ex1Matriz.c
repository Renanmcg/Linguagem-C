#include <stdio.h>

main(){
int  mat[3][5];
int i,j, contpar=0, contimpar=0;

//Entrada
for(i=0; i<3; i++){ //varia a linha
    for(j=0; j<5; j++){ //Varia a coluna
        printf("mat[%i][%i]= ",i,j);
        fflush(stdin); scanf("%i",&mat[i][j]);
    }
}

//Imprime a Matriz
for(i=0; i<3; i++){ //varia a linha
    for(j=0; j<5; j++){ //Varia a coluna
        printf("%3i ",mat[i][j]);
    }
    printf("\n");
}

//Processamento
for(i=0; i<3; i++){ //varia a linha
    for(j=0; j<5; j++){ //Varia a coluna
        if (mat[i][j]%2==0) //eh par
            contpar++;
        else
            contimpar++;
    }
}

//saída
printf("\nQtde. de Par: %i",contpar);
printf("\nQtde. de Impar: %i",contimpar);



}//Fim main()
