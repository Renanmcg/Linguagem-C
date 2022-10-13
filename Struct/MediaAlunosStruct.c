#include <stdio.h>

#define QTD_ALUNOS 3

struct reg_aluno {
    char nome[30]; //Nome do aluno
    float n1,n2,n3,n4; //Notas do aluno
    float media; //Media das notas do aluno
};

main(){
 struct reg_aluno vet_alunos[QTD_ALUNOS];
 struct reg_aluno aluno;
 int i;

 //Entrada de Dados
 for (i=0; i<QTD_ALUNOS; i++){
    printf("\n Nome do ALUNO[%d]= ",i);
    fflush(stdin); gets(aluno.nome);
    printf("Nota 1= ");fflush(stdin);scanf("%f",&aluno.n1);
    printf("Nota 2= ");fflush(stdin);scanf("%f",&aluno.n2);
    printf("Nota 3= ");fflush(stdin);scanf("%f",&aluno.n3);
    printf("Nota 4= ");fflush(stdin);scanf("%f",&aluno.n4);
    aluno.media = (aluno.n1+aluno.n2+aluno.n3+aluno.n4)/4;
    vet_alunos[i] = aluno;
 }

 //Saía - Impressao dos dados
 for (i=0; i<QTD_ALUNOS; i++){
    printf("\n Aluno: %s",vet_alunos[i].nome);
    printf("\n Notas: ");
    printf("%2.2f %2.2f %2.2f %2.2f ", vet_alunos[i].n1,vet_alunos[i].n2,vet_alunos[i].n3,vet_alunos[i].n4);
    printf("\n Media= %2.2f", vet_alunos[i].media);
 }


}//Fim main()
