// Desenvolva um programa que calcule a soma  de duas matrizes MxN de números reais (double).
// A implementação deste programa  deve considerar as dimensões fornecida pelo  usuário.
// (Dica: represente a matriz através de  variáveis do tipo double , usando alocação dinâmica de memória).
// Apos desaloque a memória utilizada.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>

double **alocarMatriz(int row, int col);
void lerMatriz(double **mat, int row, int col, char *matName);
void escreverMatriz(double **mat, int row, int col, char *matName);
void somarMatriz(double **matA, double **matB, double **matC, int row, int col);
void liberarMatriz (double **mat, int row);

int main () {
    setlocale(LC_ALL, "Portuguese");

	double **matrizA, **matrizB, **matrizC;
	int row, col;

	system("cls");
	printf("Digite a quantidade de linhas da matriz: ");	
	scanf("%d" ,&row);
	printf("Digite a quantidade de colunas da matriz: ");
	scanf("%d" ,&col);

	matrizA = alocarMatriz(row, col);
	matrizB = alocarMatriz(row, col);
	matrizC = alocarMatriz(row, col);

	lerMatriz(matrizA, row, col, "Matriz A");
	lerMatriz(matrizB, row, col, "Matriz B");

	somarMatriz(matrizA, matrizB, matrizC, row, col);

	escreverMatriz(matrizC, row, col, "Matriz Resultante");

	liberarMatriz(matrizA, row);
	liberarMatriz(matrizB, row);
	liberarMatriz(matrizC, row);
	getch();
}

double **alocarMatriz(int row, int col) {
	double **mat;
	int i, k;
	
	/* Aloca vetor de linha de posições para double */
	mat = (double **) calloc(row, sizeof(double *));
	
	/* Tratamento se mat == NULL */
	if (!mat) {		
		printf ("** Erro: Memoria Insuficiente **");
		exit(-1);
	}

	for(i = 0; i < row; i++) {

		/* Coluna posições para double,
		o endereço é atribuído a cada linha da matriz */
		mat[i] = (double *) calloc(col, sizeof(double));

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

void lerMatriz(double **mat, int row, int col, char *matName) {
	int i, j;

	printf("Digite os elementos da %s: \n", matName);

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			printf("Posicao [%lf][%lf]: ", i, j);
			scanf("%lf", &mat[i][j]);
		}
	}
	printf("\n");
}

void escreverMatriz(double **mat, int row, int col, char *matName) {
	int i, j;

	printf("Relatorio de elementos da  %s: \n", matName);

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			printf("%lf", mat[i][j]);
			if(col > 1 && j < col - 1) {
				printf(", ");
			}
		}
		printf("\n");
	}
}

void somarMatriz(double **matA, double **matB, double **matC, int row, int col) {
	int i, j;

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			matC[i][j] = matA[i][j] + matB[i][j];
		}
	}
}

void liberarMatriz (double **mat, int row) {
	int i;

	/* Libera o vetor de inteiros com coluna posições para cada linha */
	for(i = 0; i < row; i++) {
		free(mat[i]);
	}

	/* Libera o vetor de ponteiros com linha posições */
	free(mat);
}

