#include <stdio.h>
//Funcao que retorna o maior e o menor valor
//PROBLEMA: Função só pode retornar 1 valor!!!!

struct retorno{
  int maior;
  int menor;
};

struct retorno maiorMenorValor(int v1,int v2,int v3) {
  struct retorno mm;
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

  mm.maior = maior;
  mm.menor = menor;

  return mm;

}//Fim maiorMenorValor()

void main(){
 int v1, v2, v3;
 struct retorno ret;

 printf("Informe 3 valores inteiros:");
 scanf("%i %i %i", &v1, &v2, &v3);

 ret = maiorMenorValor(v1, v2, v3);

 printf("\nO maior valor informado foi %i", ret.maior);
 printf("\nO menor valor informado foi %i", ret.menor);
}
