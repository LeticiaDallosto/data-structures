// Escreva uma função que recebe três parâmetros  A, B e C, e devolve o menor deles em A, o maior em C, e o valor do meio em B.
// Caso sejam  passados valores repetidos, a ordem da resposta entre eles não importa. 
// Imprima no main os valores de A, B e C.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>

void ordenarVetor(int *a, int *b, int *c);

int main () {
    setlocale(LC_ALL, "Portuguese");

	int a, b, c;

	printf("Digite o valor de A: ");
	scanf("%d" ,&a);
	printf("Digite o valor de B: ");
	scanf("%d" ,&b);
	printf("Digite o valor de C: ");
	scanf("%d" ,&c);
	
	ordenarVetor(&a, &b, &c);
	printf("\nValor de A: %d", a);
	printf("\nValor de B: %d", b);
	printf("\nValor de C: %d", c);

	getch();
} 	

void ordenarVetor(int *a, int *b, int *c) {
	int troca;

	if(*a > *b) {
		troca = *a;
		*a = *b;
		*b = troca;
	}

	if(*a > *c) {
		troca = *a;
		*a = *c;
		*c = troca;
	}

	if(*b > *c) {
		troca = *b;
		*b = *c;
		*c = troca;
	}
}


