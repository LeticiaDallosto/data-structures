// Aloque uma matriz dinamicamente e encontre o elemento minimax. Imprima no main.
// Utilizar os seguinte módulos: alocar memória, leitura da matriz, escrita da matriz, encontrar minimax e desalocar memória.
// Minimax de uma matriz é o menor elemento da linha onde se encontra o maior elemento da matriz.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>

int **alocarMatriz(int row, int col);
void lerMatriz(int **mat, int row, int col, char *matName);
void escreverMatriz(int **mat, int row, int col, char *matName);
int minimax(int **mat, int row, int col);
void liberarMatriz (int **mat, int row);

int main () {
    setlocale(LC_ALL, "Portuguese");

	int **matriz, row, col, minimaximo;

	system("cls");
	printf("Digite a quantidade de linhas da Matriz: ");	
	scanf("%d" ,&row);
	printf("Digite a quantidade de colunas da Matriz: ");
	scanf("%d" ,&col);

	matriz = alocarMatriz(row, col);

	lerMatriz(matriz, row, col, "Matriz");
	escreverMatriz(matriz, row, col, "Matriz");

	minimaximo = minimax(matriz, row, col);
	printf("Minimax da matriz: %d \n", minimaximo);

	liberarMatriz(matriz, row);
	getch();
}

int **alocarMatriz(int row, int col) {
	int **mat, i, k;
	
	/* Aloca vetor de linha de posições para inteiros */
	mat = (int **) calloc(row, sizeof(int *));
	
	/* Tratamento se mat == NULL */
	if (!mat) {		
		printf ("** Erro: Memoria Insuficiente **");
		exit(-1);
	}

	for(i = 0; i < row; i++) {

		/* Coluna posições para inteiros, o endereço é atribuído a cada linha da matriz */
		mat[i] = (int *) calloc(col, sizeof(int));

		if (!mat[i]) {		
			printf ("** Erro: Memoria Insuficiente **");
			/* Libera as linhas alocadas */
			for (k = i - 1; k >= 0; k--) {
				free(mat[k]);
			}
			/* Libera o vetor de ponteiros */
			free(mat);
			/* Abandona a tarefa */
			exit(-1);
		}
	}
	
	/* Retorna o ponteiro para a matriz */
	return mat;
}

void lerMatriz(int **mat, int row, int col, char *matName) {
	int i, j;

	printf("Digite os elementos da %s: \n", matName);

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			printf("Posicao [%d][%d]: ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
	printf("\n");
}

void escreverMatriz(int **mat, int row, int col, char *matName) {
	int i, j;

	printf("Relatorio de elementos da  %s: \n", matName);

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			printf("%d", mat[i][j]);
			if(col > 1 && j < col - 1) {
				printf(", ");
			}
		}
		printf("\n");
	}
}

int minimax(int **mat, int row, int col) {
	int i, j, maior, menor, linhaMaior;

	maior = mat[0][0];
	menor = mat[0][0];

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			if (maior < mat[i][j]) {
				maior = mat[i][j];
				linhaMaior = i;
			}
		}
	}

	menor = mat[linhaMaior][0];

	for(j = 0; j < col; j++) {
		if (mat[linhaMaior][j] < menor) {
			menor = mat[linhaMaior][j];
		}
	}

	return menor;
}

void liberarMatriz (int **mat, int row) {
	int i;

	/* Libera o vetor de inteiros com coluna posições para cada linha */
	for(i = 0; i < row; i++) {
		free(mat[i]);
	}

	/* Libera o vetor de ponteiros com linha posições */
	free(mat);
}

