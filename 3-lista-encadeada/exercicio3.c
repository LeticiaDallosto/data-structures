/*
    Escreva um algoritmo que inverta a ordem dos elementos de uma lista simplesmente encadeada.
	A inversao deve ser realizada de forma a nao alterar a ordem fisica dos elementos na lista.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 

struct node {
	int data;
	struct node* next;
};

typedef struct node List;

List* inicializarLista (void);
List* inserirElemento (List* l, int v);
void imprimirLista (List* l);
void inverterLista (List* l);
void liberarLista (List* l);

int main() {
	system("cls");
	
	List* listaNumeros;
	List* temp;
	int comprimentoLista;
	 
	//Inicializa a lista;
	listaNumeros = inicializarLista();
	
	//Verifica se a lista esta vazia
	if (!listaNumeros) {
		printf("A lista esta vazia\n");
    } else {
		printf("A lista nao esta vazia\n");
    }

	//Insere valores no inicio e no final da lista
	listaNumeros = inserirElemento(listaNumeros, 30);
	listaNumeros = inserirElemento(listaNumeros, 20);
	listaNumeros = inserirElemento(listaNumeros, 10);
	
	//Imprime a lista
	imprimirLista(listaNumeros);

	//Inverte a lista
	inverterLista(listaNumeros);
	
	//Limpa a lista
	liberarLista(listaNumeros);
	
	system("pause");
}

List* inicializarLista (void) {
	printf("Inicializando a lista\n");
	return NULL;
}

List* inserirElemento (List* l, int value) {
	List* new = (List*) malloc(sizeof(List));
	new->data = value;
	new->next = l;		/* aponta para o inicio da lista */
	return new;			/* retorna o novo inicio da lista */
}

void imprimirLista (List* l) {
	/* ponteiro para percorrer a lista */
	List* current = l;     

	printf("Imprimindo a lista\n");
    printf("["); 
    for (current; current != NULL; current = current->next) {
        printf("%d", current->data); 

        if (current->next != NULL) {
            printf(", "); 
        }
    }
    printf("]\n");
}

void inverterLista (List* l) {
	List* current = l;		/* ponteiro para percorrer a lista */
	List* next = NULL; 		/* ponteiro para o proximo elemento */
	List* prev = NULL;  	/* ponteiro para o elemento anterior */

	while (current != NULL) {
		next = current->next;
        current->next = prev;
        prev = current;
        current = next;
	}
	l = prev;

	printf("Lista invertida: \n");
	imprimirLista(l);
}

void liberarLista (List* l) {
	/* ponteiro para percorrer a lista */
	List* current = l;

	while (current != NULL) {
		List* temp = current->next;	/* guarda referencia para o proximo elemento */
		free(current);				/* libera a memoria apontada por current */
		current = temp;				/* faz current apontar para o proximo */
	}
}




