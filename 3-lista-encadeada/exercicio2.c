/*
    Implemente uma funcao que tenha como valor de retorno o comprimento de uma lista encadeada.
	Ou seja, calcule o número de nos da lista. Esta funcao deve obedecer ao prototipo:
	int comprimento (lista* l);
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
int comprimento (List* l);
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

	//Calcula o comprimento da lista
	comprimentoLista = comprimento(listaNumeros);
	
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

int comprimento (List* l) {
	/* ponteiro para percorrer a lista */
	List* current = l;
	int count = 0;
	
	for (current; current != NULL; current = current->next) {
		count++;
	}
	printf("Comprimento da lista: %d\n", count);
	return count;
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



