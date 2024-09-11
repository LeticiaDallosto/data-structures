/*
    Implemente um programa que receba tres filas:
	F, F_Impares e F_Pares, e separe todos os valores guardados em F de tal forma que
	os valores pares sao movidos para a fila F_Pares e os valores impares sao movidos para F_Impares.
*/

#include <stdio.h>

typedef struct node {
	int data;
	struct node* next;
} node;

typedef struct Fila {
	node* front;
	node* rear;
} Fila;

// Funcoes
void inserirElemento(Fila* q, int v);
int deletarElemento(Fila* q);
void separateValues(Fila* F, Fila* F_Impares, Fila* F_Pares);

int main() {
	Fila F, F_Impares, F_Pares;
	F.front = NULL;
	F.rear = NULL;
	F_Impares.front = NULL;
	F_Impares.rear = NULL;
	F_Pares.front = NULL;
	F_Pares.rear = NULL;

	inserirElemento(&F, 1);
	inserirElemento(&F, 2);
	inserirElemento(&F, 3);
	inserirElemento(&F, 4);
	inserirElemento(&F, 5);

	separateValues(&F, &F_Impares, &F_Pares);

	printf("F_Impares: ");
	while (F_Impares.front != NULL) {
		printf("%d ", deletarElemento(&F_Impares));
	}
	printf("\n");

	printf("F_Pares: ");
	while (F_Pares.front != NULL) {
		printf("%d ", deletarElemento(&F_Pares));
	}
	printf("\n");

	return 0;
}

void inserirElemento(Fila* q, int v) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = v;
	newNode->next = NULL;

	if (q->rear == NULL) {
		q->front = newNode;
		q->rear = newNode;
	} else {
		q->rear->next = newNode;
		q->rear = newNode;
	}
}

int deletarElemento(Fila* q) {
	if (q->front == NULL) {
		printf("Queue is empty.\n");
		return -1;
	}

	int data = q->front->data;
	node* temp = q->front;
	q->front = q->front->next;

	if (q->front == NULL) {
		q->rear = NULL;
	}

	free(temp);
	return data;
}

void separateValues(Fila* F, Fila* F_Impares, Fila* F_Pares) {
	while (F->front != NULL) {
		int value = deletarElemento(F);
		if (value % 2 == 0) {
			inserirElemento(F_Pares, value);
		} else {
			inserirElemento(F_Impares, value);
		}
	}
}

