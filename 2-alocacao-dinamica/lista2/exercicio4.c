// Escreva uma função hm que converta minutos em horas-e-minutos.
// A função recebe um inteiro min e os endereços de duas variáveis inteiras, e atribui valores a essas variáveis.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>

int converterHoraMinuto(int min, int *h, int *m);

int main () {
    setlocale(LC_ALL, "Portuguese");

	int min, horas, minutos;

	system("cls");
	printf("Digite um tempo em minutos: ");
	scanf("%d" ,&min);
	
	converterHoraMinuto(min, &horas, &minutos);
	printf("%d minutos equivalem a %d horas ", min, horas);

	getch();
} 	

int converterHoraMinuto(int min, int *h, int *m) {
	*h = min / 60;
	*m = min % 60;
}



