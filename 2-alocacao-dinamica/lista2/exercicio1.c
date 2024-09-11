// Faça um programa que chame uma função que envia como parâmetros três valores inteiros (utilizar passagem por valor).
// Retorna a posição do maior(utilizar passagem por referência para os retornos das 2 posições) e a posição do menor valor.
// Exemplo: Se a = 7, b = 1 e c = 5, o procedimento deve retornar 2 como a posição do menor e 1 como a posição do maior.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>

void posicaoMaiorMenor(int a, int b, int c, int *maior, int *menor);
void liberarVetor (int *vet);

int main () {
    setlocale(LC_ALL, "Portuguese");

	int a, b, c, *vetor, maior, menor;

	printf("Digite o primeiro valor: ");
	scanf("%d" ,&a);
	printf("Digite o segundo valor: ");
	scanf("%d" ,&b);
	printf("Digite o terceiro valor: ");
	scanf("%d" ,&c);
	
	posicaoMaiorMenor(a, b, c, &maior, &menor);
	printf("\nPosicao do maior valor: %d", maior);
	printf("\nPosicao do menor valor: %d", menor);
	
	liberarVetor(vetor);
	getch();
} 	

void posicaoMaiorMenor(int a, int b, int c, int *maior, int *menor) {
	if(a > b && a > c) {
		*maior = 1;
	} else if(b > a && b > c) {
		*maior = 2;
	} else {
		*maior = 3;
	}
	
	if(a < b && a < c) {
		*menor = 1;
	} else if(b < a && b < c) {
		*menor = 2;
	} else {
		*menor = 3;
	}
}

void liberarVetor (int *vet) {
	free(vet); 
}
