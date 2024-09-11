// Escreva um programa que solicita ao usuário a quantidade de elementos inteiros que deseja ordenar.
// Depois de ler os valores em uma função, ordene em ordem crescente(em outra função). 
// Desenvolva um módulo para imprimir o vetor ordenado.
// Obs: não deve ocorrer desperdício de  memória; e após ser utilizada a memória deve ser devolvida. 

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>

int *alocarVetor(int size);
void lerVetor(int *vet, int size);
void escreverVetor(int *vet, int size);
void ordenarVetor(int *vet, int size);
void liberarVetor (int *vet);

int main () {
    setlocale(LC_ALL, "Portuguese");

	int size, *vetor;

	system("cls");
	printf("Digite a quantidade de elementos para ordenar: ");
	scanf("%d" ,&size);
	
	vetor = alocarVetor(size);
	
	lerVetor(vetor, size);
	ordenarVetor(vetor, size);
	escreverVetor(vetor, size);

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

void ordenarVetor(int *vet, int size) {
	int i, j , menorValor;

	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
			if (vet[i] < vet[j]) {
				menorValor = vet[j];
				vet[j] = vet[i];
				vet[i] = menorValor;		
			}	
		}
	}
}

void liberarVetor (int *vet) {
	free(vet); 
}

