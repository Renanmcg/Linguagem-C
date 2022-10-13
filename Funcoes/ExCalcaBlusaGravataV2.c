#include <stdio.h>
#include <conio.h>

#define TAM 100

struct reg{
    int cod;
    char desc[30], tipo;
    float preco;
};

void cadastrarProduto(struct reg prods[TAM], int *cont) {
  struct reg produto;
  char op;

  printf("\n  **** Cadastro de Produtos->");
  printf("\nDigite o codigo: ");
  fflush(stdin); scanf("%i",&produto.cod);
  printf("Digite a Descricao: ");
  fflush(stdin); gets(produto.desc);
  printf("Tipo (C-Calca, B-Blusa, G-Gravata): ");
  fflush(stdin); scanf("%c",&produto.tipo);
  printf("Preco: ");
  fflush(stdin); scanf("%f",&produto.preco);

  printf("\nSalvar Produto?(S/N)");
  fflush(stdin); scanf("%c",&op);

  if ((op=='s')||(op=='S')){
    prods[*cont]=produto;
    *cont = *cont + 1;
    printf("\nProduto Cadastrado com Sucesso.\n\n");
  }else{
    printf("\nOperacao Cancelada!\n\n");
  }

}//Fim leRegistro()

void exibeRegistro(struct reg produto) {

  printf("\nCodigo: %i",produto.cod);
  printf("\nDescricao: %s",produto.desc);
  printf("\nTipo: %c",produto.tipo);
  printf("\nPreco: %5.2f",produto.preco);

}//Fim exibeRegistro()

void relatorioTodosProdutos(struct reg prods[TAM],int cont){
  int i;

  printf("\n  ****  Relatorio de Todos os Produtos  ****");
  printf("\nCodigo Descricao                      Tipo     Preco");
  for(i=0;i<cont;i++){
    printf("\n%-6i %-30s ",prods[i].cod,prods[i].desc);
    if (prods[i].tipo=='C')
        printf("Calca    ");
    else if (prods[i].tipo=='B')
            printf("Blusa    ");
         else if (prods[i].tipo=='G')
                printf("Gravata  ");
              else
                 printf("Invalido");
    printf("%5.2f",prods[i].preco);
  }

}//Fim relatorioTodosProdutos()

float precoMedioCalcas(struct reg produtos[TAM],int cont) {
  int i, contcalcas=0;
  float media, soma=0.0;

  for (i=0; i<cont; i++){
    if (produtos[i].tipo=='C'){
        soma = soma + produtos[i].preco;
        contcalcas++;
    }
  }

  media = (float)soma/contcalcas;

  return media;
}//Fim precoMedioCalcas()

void exibeBlusasPrecoMaximo(struct reg produtos[TAM],int cont) {
  int i;
  float precoMax;

  printf("\ndigite o Preco Maximo desejado: ");
  fflush(stdin); scanf("%f",&precoMax);

  printf("\n ----- Relatorio de Blusas com preco inferior a: %5.2f -----\n",precoMax);
  for (i=0; i<cont; i++){
    if ((produtos[i].tipo=='B')&&(produtos[i].preco<precoMax)){
        exibeRegistro(produtos[i]);
        printf("\n-------------------------------------------------------");
    }
  }

}//exibeBlusasPrecoMaximo

void produtosMaiorPreco(struct reg produtos[TAM],int cont) {
  int i;
  float maiorpreco;

  //Achar o maior preço
  maiorpreco = produtos[0].preco; //inicializando a variável com o preco do primeiro elemento;

  for(i=1; i<cont; i++){
    if (produtos[i].preco > maiorpreco){
        maiorpreco = produtos[i].preco;
    }
  }

  //Percorrer o vetor e imprimir todos os produtos com esse maiorpreco
  printf("\n*** Relatorio de Todos os produtos com o Maior preco: %5.2f\n",maiorpreco);
  for(i=0; i<cont; i++){
    if (produtos[i].preco == maiorpreco){
        exibeRegistro(produtos[i]);
        printf("\n----------------------------------------------\n");
    }
  }

}//Fim produtoMaisCaro()


main(){
  struct reg prods[TAM];
  int cont=0; //Qtde atual de elementos do vetor de produtos
  int op;

  do {

    printf("\n\n ---- Menu Loja de Roupas ----");
    printf("\n (1) Cadastrar Produto");
    printf("\n (2) Relatorio Todos os Produtos");
    printf("\n (3) Preco Medio Calcas");
    printf("\n (4) Relatorio Blusa Preco Inferior a um valor");
    printf("\n (5) Relatorio Produtos com Maior Preco");
    printf("\n (0) Sair");

    printf("\nOpcao-> ");
    fflush(stdin); scanf("%i",&op);

    switch(op){
      case 1: //Cadastrar um novo Produto
          cadastrarProduto(prods, &cont);
          break;
      case 2:  //Relatorio de todos os Produtos
          relatorioTodosProdutos(prods,cont);
          break;
      case 3: //Preco Medio das Calcas
          printf("\nPreco Medio das Calcas: %5.2f",precoMedioCalcas(prods,cont));
          break;
      case 4: //Relatorio Blusa Preco Inferior a um valor
          exibeBlusasPrecoMaximo(prods, cont);
          break;
      case 5: //Relatorio Produtos com Maior Preco
          produtosMaiorPreco(prods,cont);
          break;
      case 0:
          printf("\nObrigado por utilizar nosso sistema.");
          break;
      default:
          printf("\nOpcao Invalida!!");
    }

  }while (op!=0);

}//Fim main()
