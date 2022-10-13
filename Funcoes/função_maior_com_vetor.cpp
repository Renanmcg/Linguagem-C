#include <stdio.h>

int maiorValor(int vet[20], int maior) {
int i=0;
for (i=1;i<20;i++)
 	if (vet[i] > vet[i-1]) {maior = vet[i];}
 	else {maior = vet[i-1];}
 	return maior;
}
void preenche(int vet[20]) {
int i, vet[20];
for (i=0;i<20;i++)
	printf("Informe o valor %d:", i+1);
	scanf("%d", &vet);
maiorValor(vet[20])
}

int main() {
int vet[20], i;
preenche(vet);
} //Fim main
