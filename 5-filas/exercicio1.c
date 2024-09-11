/*
    Considere a existencia de duas filas A e B onde os elementos estao ordenados da seguinte forma:
	o maior deles esta no comeco da fila e o menor no final.
	Escreva um programa que crie uma fila com os elementos das duas filas A e B tambem ordenados.
*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura para no
typedef struct Node {
	int data;
	struct Node* next;
} Node;

// Estrutura para fila
typedef struct Fila {
	Node *front, *rear;
} Fila;

// Funcoes
Node* newNode(int data);
Fila* ciarFila();
void inserirElemento(Fila* q, int v);
void deletarElemento(Fila* q);
void imprimirFila(Fila* q);
Fila* mesclarFilas(Fila* q1, Fila* q2);

int main() {
	Fila* q1 = ciarFila();
	Fila* q2 = ciarFila();

	inserirElemento(q1, 10);
	inserirElemento(q1, 8);
	inserirElemento(q1, 6);
	inserirElemento(q1, 4);

	inserirElemento(q2, 9);
	inserirElemento(q2, 7);
	inserirElemento(q2, 5);
	inserirElemento(q2, 3);

	Fila* filaMesclada = mesclarFilas(q1, q2);

	imprimirFila(filaMesclada);

	return 0;
}

Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

// Criar uma fila vazia
Fila* ciarFila() {
	Fila* q = (Fila*)malloc(sizeof(Fila));
	q->front = q->rear = NULL;
	return q;
}

void inserirElemento(Fila* q, int v) {
	Node* node = newNode(v);

	if (q->rear == NULL) {
		q->front = q->rear = node;
		return;
	}

	q->rear->next = node;
	q->rear = node;
}

void deletarElemento(Fila* q) {
	if (q->front == NULL)
		return;

	Node* temp = q->front;
	q->front = q->front->next;

	if (q->front == NULL)
		q->rear = NULL;

	free(temp);
}

void imprimirFila(Fila* q) {
	Node* temp = q->front;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

Fila* mesclarFilas(Fila* q1, Fila* q2) {
	Fila* filaMesclada = ciarFila();

	while (q1->front && q2->front) {
		if (q1->front->data > q2->front->data) {
			inserirElemento(filaMesclada, q1->front->data);
			deletarElemento(q1);
		} else {
			inserirElemento(filaMesclada, q2->front->data);
			deletarElemento(q2);
		}
	}

	while (q1->front) {
		inserirElemento(filaMesclada, q1->front->data);
		deletarElemento(q1);
	}

	while (q2->front) {
		inserirElemento(filaMesclada, q2->front->data);
		deletarElemento(q2);
	}

	return filaMesclada;
}



