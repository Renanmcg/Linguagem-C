/*Calcula a media das notas de alunos*/
#include <stdio.h>
#define ALUNOS 3 //Constante que define o nro de alunos
#define NOTAS 4 //Constante que define o nro de notas por aluno

void main( ) {
 char aluno[ALUNOS][30]; //Armazena os nomes dos alunos
 float notas[ALUNOS][NOTAS]; //Armazena as notas dos alunos
 float medias[ALUNOS]; //Armazena as medias dos alunos*/
 int i,j;
 //Entrada dos dados
 for (i=0;i<ALUNOS;i++) {
    printf("\n Nome do ALUNO[%d]=",i);
    fflush(stdin); gets(aluno[i]);
    for (j=0;j<NOTAS;j++) {
        printf(" -->NOTA[%d]=",j);
        fflush(stdin); scanf("%f",&notas[i][j]);
    }
 }

 //Calculo das medias
 for (i=0; i<ALUNOS ; i++){
    medias[i]=0;
    for (j=0; j<NOTAS; j++)
        medias[i]=medias[i] + notas[i][j];
    medias[i]=medias[i]/NOTAS;
    }

 //Impressao dos resultados
 for (i=0; i<ALUNOS; i++) {
    printf("\n Aluno:%s",aluno[i]);
    printf("\n Notas: ");
    for (j=0; j<NOTAS; j++)
        printf("%2.2f ", notas[i][j]);
    printf("\n Media= %2.2f", medias[i]);
 }
}//Fim main
