/*
    Duas listas com valores int, nao ordenados, simplesmente encadeados.
	Solicite para o usuario informar o numero de elementos das listas para que possa ser utilizado para saber quantos elementos devem ser lidos.
	Apresente um programa que intercale as duas listas, de forma que a lista resultante contenha todos os elementos das duas listas.
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
List* lerValores (List* l, int qtd, char* name);
List* intercalarListas (List* l1, List* l2);
void imprimirLista (List* l);
void liberarLista (List* l);

int main() {
	system("cls");

	List *lista1, *lista2;
	
	int qtdLista1, qtdLista2;
	 
	//Inicializa a lista;
	lista1 = inicializarLista();
	lista2 = inicializarLista();
	
	//Le a quantidade de elementos das listas
	printf("Informe a quantidade de elementos da lista 1: ");
	fflush(stdin);
	scanf("%d", &qtdLista1);
	printf("Informe a quantidade de elementos da lista 2: ");
	fflush(stdin);
	scanf("%d", &qtdLista2);

	//Le os valores das listas
	lista1 = lerValores(lista1, qtdLista1, "Lista 1");
	lista2 = lerValores(lista2, qtdLista2, "Lista 2");

	//Intervala as listas 
	lista1 = intercalarListas(lista1, lista2);
	
	//Imprime a lista
	printf("Lista intercalada: \n");
	imprimirLista(lista1);
	
	//Limpa a lista
	liberarLista(lista1);
	
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

List* lerValores (List* l, int qtd, char* name) {
	int i, value;
	
	printf("Lendo valores %s\n", name);
	for (i = 0; i < qtd; i++) {
		printf("Insira o elemento [%d] da lista [%s]: ", i, name);
		fflush(stdin);
		scanf("%d", &value);
		l = inserirElemento(l, value);
	}
	return l;
}

List* intercalarListas (List* l1, List* l2) {
	List* temp;
	
	temp = l1;
	
	while (temp != NULL) {
		if (temp->next == NULL) {
			temp->next = l2;
			return l1;
		}
		temp = temp->next;
	}
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

void liberarLista (List* l) {
	/* ponteiro para percorrer a lista */
	List* current = l;

	while (current != NULL) {
		List* temp = current->next;	/* guarda referencia para o proximo elemento */
		free(current);				/* libera a memoria apontada por current */
		current = temp;				/* faz current apontar para o proximo */
	}
}



