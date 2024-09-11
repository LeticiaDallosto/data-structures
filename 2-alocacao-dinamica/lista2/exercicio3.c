// Faça um programa que tenha  uma função que receba um valor inteiro do main como referência e retorne o resto da divisão deste número por 10.
// Imprima o resultado no main.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>

int restoDivisao(int a);

int main () {
    setlocale(LC_ALL, "Portuguese");

	int a, resto;

	printf("Digite um numero inteiro: ");
	scanf("%d" ,&a);
	
	resto = restoDivisao(a);
	printf("\nResto da divisao de %d por 10: %d", a, resto);

	getch();
} 	

int restoDivisao(int a) {
	return a % 10;
}

