// Crie uma estrutura utilizando um vetor inteiro onde será realizada as operações de leitura, escrita, encontrar o maior valor, encontrar o menor valor, a média.
// Imprimir os resultados encontrados.(utilizar módulos e alocação dinâmica).
// Utilizar os seguinte módulos: alocar memória, leitura do vetor, escrita do vetor, encontrar elementos maior e menor, desalocar memória.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>

int *alocarVetor(int size);
void lerVetor(int *vet, int size);
void escreverVetor(int *vet, int size);
int maiorValor(int *vet, int size);
int menorValor(int *vet, int size);
int media(int *vet, int size);
void liberarVetor (int *vet);

int main () {
    setlocale(LC_ALL, "Portuguese");

	int size, *vetor, maior, menor;
	float med;

	system("cls");
	printf("Digite a quantidade de elementos: ");
	scanf("%d" ,&size);
	
	vetor = alocarVetor(size);
	
	lerVetor(vetor, size);
    escreverVetor(vetor, size);
	
	maior = maiorValor(vetor, size);
    menor = menorValor(vetor, size);
    med = media(vetor, size);
	
	printf("Maior valor do vetor: %d \n", maior);
    printf("Menor valor do vetor: %d \n", menor);
    printf("Media dos valores do vetor: %d \n", med);
	
	liberarVetor(vetor);
	getch();
} 	

int *alocarVetor(int size) {
	int *vetor; 	

    /* Aloca vetor com 'size' posições de números inteiros */
	vetor = (int *) calloc(size, sizeof(int) );   

    /* Tratamento se v == NULL */
	if (!vetor) {		
		printf ("** Erro: Memoria Insuficiente **");
		exit(1);
	}

    /* Retorna o ponteiro para o vetor */
	return vetor; 	
}

void lerVetor(int *vet, int size) {
	int i;

	for(i = 0; i < size; i++) {
		printf("Digite o elemento da posicao %d: ", i);
		scanf("%d", &vet[i]);
	}
}

void escreverVetor(int *vet, int size) {
    int i;

    printf("Relatorio de elementos do vetor: ");

	for(i = 0; i < size; i++) {
		printf("%d", vet[i]);
        if(size > 1 && i < size - 1) {
            printf(", ");
        }
	}
    printf("\n");
}

int maiorValor(int *vet, int size) {
	int i, maior;
	
	maior = *(vet);
	
	for(i = 0; i < size; i++) {
		if (maior < vet[i]) {
			maior = vet[i];
		}
	}
	
	return maior;
}

int menorValor(int *vet, int size) {
	int i, menor;
	
	menor = *(vet);
	
	for(i = 0; i < size; i++) {
		if (menor > vet[i]) {
			menor = vet[i];
		}
	}
	
	return menor;
}

int media(int *vet, int size) {
	int i, med;
	
	med = *(vet);
	
	for(i = 0; i < size; i++) {
		med = med + vet[i];
	}
	
	return med / size;
}

void liberarVetor (int *vet) {
	free(vet); 
}
