/*
    Implemente uma funcao que receba como parametro uma lista encadeada e um valor inteiro n,
	retire da lista todas as ocorrencias de n, e retorne a lista resultante. Imprima a lista atualizada. Essa funcao deve obedecer ao prototipo:
	Lista* retira_n (Lista* l, int n);
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
List* inserirElemento (List* l, int n);
List* retira_n (List* l, int n);
void imprimirLista (List* l);
void troca (List* l, int original, int new);
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
	listaNumeros = inserirElemento(listaNumeros, 20);
	
	//Imprime a lista
	imprimirLista(listaNumeros);

	//Retira o valor 20 da lista
	listaNumeros = retira_n(listaNumeros, 20);
	imprimirLista(listaNumeros);
	
	//Limpa a lista
	liberarLista(listaNumeros);
	
	system("pause");
}

List* inicializarLista (void) {
	printf("Inicializando a lista\n");
	return NULL;
}

List* inserirElemento (List* l, int valor) {
	List* new = (List*) malloc(sizeof(List));
	new->data = valor;
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

List* retira_n (List* l, int n) {
	List* current = l; 		/* ponteiro para percorrer a lista */
	List* prev = NULL;		/* ponteiro para o elemento anterior */
	List* temp;				/* ponteiro temporario */

	printf("Retirando o valor %d da lista\n", n);

	while (current != NULL) {
        if (current->data == n) {
            if (prev == NULL) {
                l = current->next; 			/* retira elemento do inicio */
            } else {
                prev->next = current->next; /* retira elemento do meio da lista */
            }
            temp = current->next;			/* salva o próximo nó em temp */
            free(current);					/* libera a memória apontada por current */
            current = temp;					/* faz current apontar para o próximo */
        } else {
            prev = current;					/* faz prev apontar para o próximo */
            current = current->next;
        }
    }
    printf("Valor %d retirado da lista\n", n);
    return l;
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




