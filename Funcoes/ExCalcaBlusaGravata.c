#include <stdio.h>
#include <conio.h>

#define TAM 3

struct reg{
 int cod;
 char desc[30], tipo;
 float preco;
};

struct reg leRegistro() {
 struct reg produto;

 printf("\nDigite o código: ");
 fflush(stdin); scanf("%i", &produto.cod);
 printf("Digite a descrição: ");
 fflush(stdin); gets(produto.desc);
 printf("\nDigite o tipo[C-Calça, B-Blusa, G-Gravata]: ");
 fflush(stdin);scanf("%c", &produto.tipo);
 printf("Digite o preço: ");
 fflush(stdin); scanf("%f", &produto.preco);

 return produto;
}
void exibeRegistro(struct reg produto) {
  printf("\nCódigo: %i", produto.cod);
  printf("\nDescrição: %s", produto.desc);
  printf("\nTipo: %c", produto.tipo);
  printf("\nPreço: %f2.2f", produto.preco);

}

float preçoMedioCalcas(struct reg prods[TAM]) {
  int i, cont=0;
  float soma=0.0, media=0.0;

 for(i=0; i<TAM; i++){
        if (prods[i].tipo=='C'){
            soma+=prods[i].preco;
            cont++;
        }
  }
  if (cont!=0 ){}
    media = (float)soma/cont; /* use o cast para garantir o tipo do resultado*/
  }
  return media;
}

void exibeBlusas(struct reg prods[TAM]) {
 float precoMax;

 printf("\nDigite o preço máximo das blusas: ")
 fflush(stdin); scanf("%f", &precoMax);

  for(i=0; i<TAM; i++){
    if ((prods[i].tipo=='B') && (prods.preco < precoMax)){
        exibeRegistro(prods[i]);
        printf("\n-----------------------------------------------------");
    }

    }


}
float produtoMaisCaro(struct reg prods[TAM]) {
  float x, y, maisCaro;


}


void main(){
 struct reg prods[TAM];
 int i;

 for(i=0; i<TAM; i++){
    prods[i]=leRegistro();
 }

 //Lista todos os produtos
 printf("\n--- Relatorio de Todos os Produtos ----\n");
  for(i=0; i<TAM; i++){
    exibeRegistro(prods[i]);
    printf("\n-----------------------------------");
 }

 printf("\n\nPreço médio das calcas %5.2f\n", preçoMedioCalcas(prods));


 exibeBlusas(prods);


 exibeRegistro(produtoMaisCaro(prods));

}
