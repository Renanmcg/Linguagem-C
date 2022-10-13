#include <stdio.h>
#include <conio.h>

#define TAM 100

struct reg{
    int cod;
    char desc[30], tipo;
    float preco;
    int estoque;
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
	fflush(stdin); scanf(" %c",&produto.tipo);
	printf("Preco: ");
	fflush(stdin); scanf("%f",&produto.preco);
	printf("Produtos no estoque: ");
	fflush(stdin); scanf("%d",&produto.estoque);
	printf("\nSalvar Produto?(S/N)");
	fflush(stdin); scanf(" %c",&op);

	if ((op=='s')||(op=='S')){
		prods[*cont]=produto;
		*cont = *cont + 1;
		printf("\nProduto Cadastrado com Sucesso.\n\n");
	}else{
		printf("\nOperacao Cancelada!\n\n");
	}
}//Fim cadastrarProduto()

void cadastrar_produto_lugar_apagado(struct reg prods[TAM],int cont){
	/*Essa função faz parte da implementação da excljusão de produtos. Como ao apagar o produto um espaço no vetor continuava a ser ocupado,
	 criei essa função para aproveitar esses espaços ao cadastrar novos produtos.*/
	int i, op;

	for (i=0; i<cont; i++){
		if(prods[i].cod == 0){
			printf("\n  **** Cadastro de Produtos->");
			printf("\nDigite o codigo: ");
			fflush(stdin); scanf("%i",&prods[i].cod);
			printf("Digite a Descricao: ");
			fflush(stdin); gets(prods[i].desc);
			printf("Tipo (C-Calca, B-Blusa, G-Gravata): ");
			fflush(stdin); scanf(" %c",&prods[i].tipo);
			printf("Preco: ");
			fflush(stdin); scanf("%f",&prods[i].preco);
			printf("Produtos no estoque: ");
			fflush(stdin); scanf("%d",&prods[i].estoque);
			printf("\nSalvar Produto?(S/N)");
			fflush(stdin); scanf(" %c",&op);

		break;
		}
	}
}//Fim cadastrar_produto_lugar_apagado()

void exibeRegistro(struct reg produto) {

  printf("\nCodigo: %i",produto.cod);
  printf("\nDescricao: %s",produto.desc);
  printf("\nTipo: %c",produto.tipo);
  printf("\nPreco: %5.2f",produto.preco);
  printf("\nEstoque: %d",produto.estoque);

}//Fim exibeRegistro()

void relatorioTodosProdutos(struct reg prods[TAM],int cont){
  int i;

  printf("\n  ****  Relatorio de Todos os Produtos  ****");
  printf("\nCodigo Descricao            estoque       Tipo     Preco");
  for(i=0;i<cont;i++){
    printf("\n%-6i %-20s  %d           ",prods[i].cod,prods[i].desc, prods[i].estoque);
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

}// Fim exibeBlusasPrecoMaximo()

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

void consulta_produto_codigo(struct reg produtos[TAM],int cont){
	int i;
	int opcao;
	printf("Digite o numero do codigo do produto que deseja consultar.");
	fflush(stdin); scanf("%d", &opcao);
	for(i=0; i<cont; i++){
		if(produtos[i].cod == opcao){
			exibeRegistro(produtos[i]);
		}

	}
}//Fim consulta_produto_codigo()

float altera_preco(struct reg produtos[TAM],int cont){
	int i;
	float preco_novo;
	int opcao;
	printf("Digite o numero do codigo do produto que voce deseja alterar o preco.");
	fflush(stdin); scanf("%d", &opcao);
	for(i=0; i<cont; i++){
		if(produtos[i].cod == opcao){
			exibeRegistro(produtos[i]);
            printf("\nDigite o novo preco: ");
            fflush(stdin); scanf("%f", &preco_novo);
            produtos[i].preco = preco_novo;
		}
	}
}//Fim altera_preco()


void aumenta_preco(struct reg produtos[TAM], int cont){
	int i;
	float aumento, perc;
	char opcao;
	printf("Digite o tipo de produto que voce deseja aumentar o preco.");
	fflush(stdin); scanf(" %c", &opcao);
	printf("\nDigite a percentual do aumento: ");
	fflush(stdin); scanf("%f", &perc);
	for(i=0; i<cont; i++){
		if(produtos[i].tipo == opcao){
			aumento = produtos[i].preco * (perc/100);
			produtos[i].preco += aumento;
		}
	}
}// Fim aumenta_preco()

void verifica_estoque(struct reg produtos[TAM],int cont){
	int i;
	int qtd;
	printf("Digite o o valor base de produtos.");
	fflush(stdin); scanf("%d", &qtd);
	for(i=0; i<cont; i++){
		if(produtos[i].estoque <= qtd){
			exibeRegistro(produtos[i]);
		}
	}

}//Fim verifica_estoque()


void exclui_produto_codigo(struct reg produtos[TAM],int cont){
	int i, j;
	int opcao;
	printf("Digite o codigo do produto a ser excluido.");
	fflush(stdin); scanf("%d", &opcao);
	for(i=0; i<cont; i++){
		if(produtos[i].cod == opcao){
			produtos[i] = {NULL};
		}
	}
}//Fim exclui_produto_codigo()

void exclui_produto_tipo(struct reg produtos[TAM],int cont){
	int i, j;
	char opcao;
	printf("Digite o tipo de produto a ser excluido.");
	fflush(stdin); scanf("%c", &opcao);
	for(i=0; i<cont; i++){
		if(produtos[i].tipo == opcao){
			produtos[i] = {NULL};
		}
	}
}//Fim exclui_produto_tipo()


main(){
  struct reg prods[TAM] = {NULL};
  int cont=0; //Qtde atual de elementos do vetor de produtos
  int op, opcao;


  do {

    printf("\n\n ---- Menu Loja de Roupas ----");
    printf("\n (1) Cadastrar Produto");
    printf("\n (2) Relatorio Todos os Produtos");
    printf("\n (3) Preco Medio Calcas");
    printf("\n (4) Relatorio Blusa Preco Inferior a um valor");
    printf("\n (5) Relatorio Produtos com Maior Preco");
    printf("\n (6) Consulta de Produtos por Codigo");
    printf("\n (7) Alterar preco de Produtos por Codigo");
    printf("\n (8) Aumentar preco de Produtos por tipo");
    printf("\n (9) Verifica o Estoque dos Produtos");
    printf("\n (10) Exclui produto por codigo");
    printf("\n (11) Exclui produto por tipo");
    printf("\n (0) Sair");

    printf("\nOpcao-> ");
    fflush(stdin); scanf("%i",&op);

    switch(op){
      case 1: //Cadastrar um novo Produto
          do{
	  		printf("\n\n ---- Menu de cadastro ----");
			printf("\n (1) Cadastrar Produto");
	    	printf("\n (2) Cadastrar Novo Produto no Lugar de um Produto Apagado");
	    	printf("\n (0) Voltar");

  			printf("\nOpcao-> ");
    		fflush(stdin); scanf("%i",&opcao);

			  switch(opcao){

			      case 1: //Cadastrar um novo Produto
			      	  cadastrarProduto(prods, &cont);
			          break;

			      case 2:  //Cadastrar novo produto no lugar de um produto apagado
			      	  cadastrar_produto_lugar_apagado(prods, cont);
			      	  break;

			      case 0:
			          printf("\nObrigado por utilizar nosso sistema.");
			          break;
			      default:
			          printf("\nOpcao Invalida!!");
			      }
			}while (opcao!=0);



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
      case 6: //Consulta de Produtos por Codigo
          consulta_produto_codigo(prods, cont);
          break;
      case 7: //Altera preco de Produtos por Codigo
          altera_preco(prods, cont);
          break;
      case 8: //Aumenta preco de Produtos por tipo
          aumenta_preco(prods, cont);
          break;
      case 9: //Verifica o estoque dos produtos
          verifica_estoque(prods, cont);
      	  break;
      case 10: //Exclui produto por codigo
      	  exclui_produto_codigo(prods, cont);
      	  break;
      case 11: //Exclui produto por tipo
      	  exclui_produto_tipo(prods, cont);
          break;
      case 0:
          printf("\nObrigado por utilizar nosso sistema.");
          break;
      default:
          printf("\nOpcao Invalida!!");

   }
  }while (op!=0);

}//Fim main()
