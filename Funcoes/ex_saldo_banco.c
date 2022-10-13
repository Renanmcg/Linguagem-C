#include <stdio.h>

#define TAM 3

  struct reg_conta{
    int codigo;
    char nome[30];
    float saldomedio;
    float limite_credito;
    char avaliacao[2];
  };


main(){
  struct reg_conta vetcli[TAM];
  int i,cont=0;;
  float maiorsaldo;

  //Entrada
  for(i=0; i<TAM; i++){
    printf("\nCodigo: ");
    fflush(stdin); scanf("%i",&vetcli[i].codigo);
    printf("Nome: ");
    fflush(stdin); gets(vetcli[i].nome);
    printf("Saldo Medio: ");
    fflush(stdin); scanf("%f",&vetcli[i].saldomedio);
    printf("Avaliação[O – otimo, B – bom e R – regular]: ");
    fflush(stdin); gets(vetcli[i].avaliacao);
  }

  //Processamento
  //Inicializar a variavel maiorsaldo com o
  // saldo do primeiro cliente
  maiorsaldo = vetcli[0].saldomedio;
  for(i=1; i<TAM; i++) {
    if (vetcli[i].saldomedio>maiorsaldo){
        maiorsaldo = vetcli[i].saldomedio; //Troca
    }
  }

  //Imprimir todos com o maior saldo medio
  // e contar quantos clientes tem saldo medio superior a 2.000
  printf("\nMaior saldo medio: %5.2f",maiorsaldo);
  printf("\nClientes com maior Saldo Medio: ");
  for(i=0; i<TAM; i++) {
    if (vetcli[i].saldomedio==maiorsaldo){
        printf("\n%i %s %5.2f",vetcli[i].codigo,vetcli[i].nome,vetcli[i].saldomedio);
    }
    if (vetcli[i].saldomedio>2000.0){
        cont++;
    }
    if (vetcli[i].saldomedio>=5000.0 && vetcli[i].avaliacao == "O" || "B" ){
        vetcli[i].limite_credito * 2;
    }
  }

    printf("\nQtde. Cliente com saldo medio superior a 2.000: %i",cont);
    for(i=0; i<TAM; i++) {
        printf("limite de credito: %f", vetcli[i].limite_credito);

        }
}//Fim main()
