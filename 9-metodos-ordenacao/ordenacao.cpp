#include <stdio.h>
#include <stdlib.h>

// ordem crescente
void insertionSort(int *v, int n) {
	int i = 0;
	int j = 1;
	int aux = 0;
	while (j < n) {
		aux = v[j];
		i = j - 1;
		while ((i >= 0) && (v[i] > aux)) {
			v[i + 1] = v[i];
			i--;
		}
		v[i + 1] = aux;
		j = j + 1;
	}
}

// ordem decrescente
void insertionSortDecrescente(int *v, int n) {
	int i = 0;
	int j = 1;
	int aux = 0;
	while (j < n) {
		aux = v[j];
		i = j - 1;
		while ((i >= 0) && (v[i] < aux)) {
			v[i + 1] = v[i];
			i--;
		}
		v[i + 1] = aux;
		j = j + 1;
	}
}

void selectionSort(int *v, int n) {
	int i, j, min, aux;
	for (i = 0; i < (n - 1); i++) {
		min = i;
		for (j = (i + 1); j < n; j++) {
			if (v[j] < v[min]) {
				min = j;
			}
		}
		if (v[i] != v[min]) {
			aux = v[i];
			v[i] = v[min];
			v[min] = aux;
		}
	}
}

void bubbleSort(int *v, int n) {
	int i, fim, aux;
	for (fim = n - 1; fim > 0; --fim) {
		for (i = 0; i < fim; i++) {
			if (v[i] > v[i + 1]) {
				aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
			}
		}
	}
}

void bubbleSort(int *v, int n) {
    int i, fim, aux;
    int swapped; // Variável para detectar trocas
    for (fim = n - 1; fim > 0; --fim) {
        swapped = 0; // Inicializa como 0 no início de cada iteração externa
        for (i = 0; i < fim; i++) {
            if (v[i] > v[i + 1]) {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                swapped = 1; // Marca que houve uma troca
            }
        }
        if (!swapped) break; // Se não houve trocas, termina o loop
    }
}

void mergeSort(int *vetor, int inicio, int fim) {
	if (inicio < fim) {
		int meio = (inicio + fim) / 2;
		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio + 1, fim);
	}
}

main () {
	int v[5] = {9, 8, 7, 6, 5};
	insertionSort(v, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");

	int v2[5] = {9, 6, 7, 8, 5};
	insertionSortDecrescente(v2, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d ", v2[i]);
	}
	printf("\n");
}