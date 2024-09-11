/*
    Escreva um algoritmo que forneça o maior elemento, o menor, e a media aritmetica dos elementos de uma lista simplesmente encadeada.
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
void maiorElemento (List* l);
void menorElemento (List* l);
void mediaAritmetica (List* l);
void liberarLista (List* l);

int main() {
	system("cls");
	
	List* listaNumeros;
	List* tmp;
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

	//Busca o maior elemento
	maiorElemento(listaNumeros);

	//Busca o menor elemento
	menorElemento(listaNumeros);

	//Calcula a media aritmetica
	mediaAritmetica(listaNumeros);
	
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

void maiorElemento (List* l) {
	/* ponteiro para percorrer a lista */
	List* current = l;

	int maior = 0;

	for (current; current != NULL; current = current->next) {
		if (current->data > maior) {
			maior = current->data;
		}
	}
	printf("Maior elemento da lista: %d\n", maior);
}

void menorElemento (List* l) {
	/* ponteiro para percorrer a lista */
	List* current = l;

	int menor = 100;

	for (current; current != NULL; current = current->next) {
		if (current->data < menor) {
			menor = current->data;
		}
	}
	printf("Menor elemento da lista: %d\n", menor);
}

void mediaAritmetica (List* l) {
	/* ponteiro para percorrer a lista */
	List* current = l;

	int soma = 0;
	int contador = 0;
	float media;

	for (current; current != NULL; current = current->next) {
		soma += current->data;
		contador++;
	}
	media = soma / contador;
	printf("Media aritmetica dos elementos da lista: %.2f\n", media);
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




