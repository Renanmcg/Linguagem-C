#include <stdio.h>
//Funcao que retorna o maior e o menor valor
//PROBLEMA: Função só pode retornar 1 valor!!!!

void maiorMenorValorPorRef(int v1,int v2,int v3,int *mai, int *men) {
  int maior, menor;

  if ((v1>=v2)&&(v1>=v3)){
    maior = v1;
  }
  if ((v2>=v1)&&(v2>=v3)){
    maior = v2;
  }
  if ((v3>=v1)&&(v3>=v2)){
    maior = v3;
  }
  if ((v1<=v2)&&(v1<=v3)){
    menor = v1;
  }
  if ((v2<=v1)&&(v2<=v3)){
    menor = v2;
  }
  if ((v3<=v1)&&(v3<=v2)){
    menor = v3;
  }

  *mai = maior;
  *men = menor;

}//Fim maiorMenorValor()

void main(){
 int v1, v2, v3;
 int maior,menor;

 printf("Informe 3 valores inteiros:");
 scanf("%i %i %i", &v1, &v2, &v3);

 maiorMenorValorPorRef(v1, v2, v3,&maior,&menor);

 printf("\nO maior valor informado foi %i", maior);
 printf("\nO menor valor informado foi %i", menor);
}
