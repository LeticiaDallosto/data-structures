/*
    Com base no codigo fonte de exemplo para gerenciar a estrutura de dados Deque, complemente o exemplo com as seguintes rotinas:
	Inserir no Inicio;
	Excluir no Fim;
	Listar itens do Deque pelo inicio;
	Acrescentando no "main" exemplos de funcionamento dos metodos criados.
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct no {
	int value;
	struct no* prev;
	struct no* next;
};
typedef struct no No;

typedef struct {
	No* head;
} Deque;

// Funcoes
Deque* cria(void);
int tamanho(Deque* d);
int tamanho2(Deque* d);
void exibirDequeFim(Deque* d);
void exibirDequeInicio(Deque* d);
bool inserirDequeFim(Deque* d, int v);
bool inserirDequeInicio(Deque* d, int v);
int excluirElemDequeInicio(Deque* d);
int excluirElemDequeFim(Deque* d);
void reinicializarDeque(Deque* d);

// Implementacao
int main (void) {
	int valorRemovidoInicio;
	int valorRemovidoFim;
	
	Deque* deq;
	
	deq = cria();
	
	inserirDequeFim(deq, 23);
	inserirDequeFim(deq, 15);
	inserirDequeInicio(deq, 7);
	inserirDequeInicio(deq, 10);
	
	printf("Tamanho do deque: %d\n",tamanho(deq));
	
	exibirDequeInicio(deq);
	
	valorRemovidoInicio = excluirElemDequeInicio(deq);
	printf("Valor removido do inicio: %d\n", valorRemovidoInicio);

	valorRemovidoFim = excluirElemDequeFim(deq);
	printf("Valor removido do fim: %d\n", valorRemovidoFim);
	
	printf("Tamanho do deque depois da remocao: %d\n",tamanho(deq));
	
	exibirDequeInicio(deq);
	
	reinicializarDeque(deq);
}

Deque* cria(void) {
	Deque* d = (Deque*) malloc(sizeof(Deque));
	d->head = (No*) malloc(sizeof(No));
	d->head->next = d->head;
	d->head->prev = d->head;
	return d;
}

int tamanho(Deque* d) {
	// Avanca pelo primeiro nodo
	No* end = d->head->next;
	int size = 0;
	while (end != d->head) {
		size++;
		end = end->next;
	}
	return size;
}

int tamanho2(Deque* d) {
	// Avanca pelo ultimo nodo
	No* end = d->head->prev;
	int size = 0;
	while (end != d->head) {
		size++;
		end = end->prev;
	}
	return size;
}

void exibirDequeFim(Deque* d) {
	No* end = d->head->prev;
	printf("Deque partindo do fim: \" ");
	while (end != d->head) {
		printf("%i ", end->value);
		end = end->prev;
	}
	printf("\"\n");
}

void exibirDequeInicio(Deque* d) {
	No* end = d->head->next;
	printf("Deque partindo do inicio: \" ");
	while (end != d->head) {
		printf("%i ", end->value);
		end = end->next;
	}
	printf("\"\n");
}

bool inserirDequeFim(Deque* d, int v) {
	No* new = (No*) malloc(sizeof(No));
	new->value = v;
	new->next = d->head;
	new->prev = d->head->prev;
	d->head->prev = new;
	new->prev->next = new;
	return true;
}

bool inserirDequeInicio(Deque* d, int v) {
	No* new = (No*) malloc(sizeof(No));
	new->value = v;
	new->next = d->head->next;
	new->prev = d->head;
	d->head->next = new;
	new->next->prev = new;
	return true;
}

int excluirElemDequeInicio(Deque* d) {
	int returnValue;
	
	if (d->head->next == d->head) return false;
	No* delete = d->head->next;
	returnValue = delete->value;
	d->head->next = delete->next;
	delete->next->prev = d->head;
	free(delete);
	return returnValue;
}

int excluirElemDequeFim(Deque* d) {
	int returnValue;
	
	if (d->head->prev == d->head) return false;
	No* delete = d->head->prev;
	returnValue = delete->value;
	d->head->prev = delete->prev;
	delete->prev->next = d->head;
	free(delete);
	return returnValue;
}

void reinicializarDeque(Deque* d) {
	No* end = d->head->next;
	while (end != d->head) {
		No* delete = end;
		end = end->next;
		free(delete);
	}
	d->head->next = d->head;
	d->head->prev = d->head;
}


