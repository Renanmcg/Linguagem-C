#include <stdio.h>

main(){
int vet[10], vetpar[10], vetimpar[10];
int i,j,k,contpar,contimpar;

//Entrada de Dados
for (i=0; i<10; i++){
    printf("\nDigite vet[%i]= ",i);
    fflush(stdin); scanf("%i",&vet[i]);
}

printf("\nvet = ");
for(i=0; i<10; i++){
    printf("%i ",vet[i]);
}

//Processamento
j=0;
k=0;
for(i=0; i<10; i++){
    if((vet[i]%2)==0){
      //É par
        vetpar[j]=vet[i];
        j++;
    }else{
      //É ímpar
        vetimpar[k]=vet[i];
        k++;
    }
}
contpar = j; //Qtde de elementos colocados no vet par
contimpar = k; //Qtde de elementos colocados no vet impar
//Saída
printf("\nvetpar: ");
for (i=0; i<contpar; i++){
    printf("%i ",vetpar[i]);
}

printf("\nvetimpar: ");
for (i=0; i<contimpar; i++){
    printf("%i ",vetimpar[i]);
}


}//Fim main
