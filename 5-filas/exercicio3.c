/*
    Implemente no exemplo de fila com lista encadeada do moodle para que utilize o Descritor/cabecalho para
	armanzenar a soma, media e maior e menor elemento da lista, total de elementos na fila.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct Fila {
	struct node* front;
	struct node* rear;
	int size;
	int sum;
	int max;
	int min;
};

// Funcoes
void inicializarFila(struct Fila* q);
void inserirElemento(struct Fila* q, int v);
int deletarElemento(struct Fila* q);

int main() {
	struct Fila q;
	inicializarFila(&q);

	inserirElemento(&q, 10);
	inserirElemento(&q, 20);
	inserirElemento(&q, 30);

	printf("Tamanho da fila: %d\n", q.size);
	printf("Soma dos elementos: %d\n", q.sum);
	printf("Elemento maximo: %d\n", q.max);
	printf("Elemento minimo: %d\n", q.min);

	deletarElemento(&q);

	printf("Tamanho da fila: %d\n", q.size);
	printf("Soma dos elementos: %d\n", q.sum);
	printf("Elemento maximo: %d\n", q.max);
	printf("Elemento minimo: %d\n", q.min);

	return 0;
}

void inicializarFila(struct Fila* q) {
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
	q->sum = 0;
	q->max = INT_MIN;
	q->min = INT_MAX;
}

void inserirElemento(struct Fila* q, int v) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = v;
	newNode->next = NULL;

	if (q->rear == NULL) {
		q->front = newNode;
		q->rear = newNode;
	} else {
		q->rear->next = newNode;
		q->rear = newNode;
	}

	q->size++;
	q->sum += v;
	q->max = (v > q->max) ? v : q->max;
	q->min = (v < q->min) ? v : q->min;
}

int deletarElemento(struct Fila* q) {
	if (q->front == NULL) {
		printf("A lista esta vazia.\n");
		return -1;
	}

	struct node* temp = q->front;
	int data = temp->data;

	q->front = q->front->next;
	if (q->front == NULL) {
		q->rear = NULL;
	}

	free(temp);
	q->size--;
	q->sum -= data;

	return data;
}

