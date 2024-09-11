/*
    Crie um programa contendo as seguintes funcoes:
        a)	Insercao no inicio;
        b)	Insercao no final;
        c)	Remocao de um elemento v passado como parametro;
        d)	Busca de um elemento v;
        e)	Listagem dos elementos contidos na lista;
        f)	Liberar a memoria alocada.
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
List* inserirNoFinal (List* l, int v);
List* deletarElemento (List* l, int v);
List* buscarElemento (List* l, int v);
void imprimirLista (List* l);
void liberarLista (List* l);

int main() {
	system("cls");
	
	List* listaNumeros;
	List* temp;
	 
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
    listaNumeros = inserirNoFinal(listaNumeros, 40);
    listaNumeros = inserirNoFinal(listaNumeros, 50);
    listaNumeros = inserirNoFinal(listaNumeros, 60);
	
	//Imprime a lista
	imprimirLista(listaNumeros);

    //Deleta o valor 60 da lista
	listaNumeros = deletarElemento(listaNumeros, 60);
    imprimirLista(listaNumeros);
	
	//Busca o valor 20 na lista
	temp = buscarElemento(listaNumeros, 20);
	if (temp != NULL) {
		printf("O valor %d foi encontrado! \n", temp->data);
    } else {
		printf("O valor %d nao foi encontrado! \n", temp->data);
    }	
	
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

List* inserirNoFinal (List* l, int value) {
	List* new = (List*) malloc(sizeof(List));
    List* current;
    new->data = value;	/* armazena informacao */
    new->next = NULL;	/* new elemento passa a ser o ultimo */
    
    if (l == NULL) { 
        return new; 
    }
    current = l;	
    
    while (current->next != NULL) { 
        current = current->next;	
    }
    current->next = new; 	
    return l;			
}
 
List* deletarElemento (List* l, int v) {
	List* current = l;		/* ponteiro para percorrer a lista */
	List* prev = NULL;		/* ponteiro para elemento anterior */

	/* procura elemento na lista, guardando anterior */
	while (current != NULL && current->data != v) {
		prev = current;
		current = current->next;
	}

	/* verifica se achou elemento, se nao achou: retorna lista original */
	if (current == NULL)
		return l; 				

	/* deletar elemento */
	if (prev == NULL) {
		l = current->next;			/* deletar elemento do inicio */
	} else {
		prev->next = current->next;	/* deletar elemento do meio da lista */
	}
	printf("O valor %d foi deletado! \n", current->data);

	free(current);
	return l;
}

List* buscarElemento (List* l, int v) {
	/* ponteiro para percorrer a lista */
	List* current = l;

    /* percorre a lista do inicio ao fim */
	for (current; current!=NULL; current=current->next) {
		if (current->data == v) {
			return current;
        }
    }
	return NULL; /* nao achou o elemento */
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



