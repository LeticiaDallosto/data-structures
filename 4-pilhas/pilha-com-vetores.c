/*
    Voce deve utilizar o programa exemplo do TAD Pilha com Vetores e complementa-lo para ter as funcoes Transfere e TransfereIgual,
	chamando-as adequadamente a partir de opcao especifica do menu.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 

#define MAX 50

// Estrutura para pilha
typedef struct pilha {
	int n;
	float vet[MAX];
} Pilha;

Pilha* criarPilha(void);
Pilha* push(Pilha* p, float v);
Pilha* pop(Pilha* p);
Pilha* transfere(Pilha* p);
Pilha* transfereIgual(Pilha* p);
float top(Pilha* p);
int isEmpty(Pilha* p);
void imprimirPilha(Pilha* p);
void liberarPilha(Pilha* p);

int main() {
	int menu;
	float value;
	Pilha* pilha;
	Pilha* pilha2 = NULL;

	pilha = criarPilha();
	pilha2 = criarPilha();

	do{
		system("cls");
		printf("Menu - PILHA COM VETOR\n");
		printf("1- Adiciona elemento\n");
		printf("2- Mostra pilha\n");
		printf("3- Desempilha\n");
		printf("4- Transfere\n");
    	printf("5- TransfereIgual\n");
		printf("0- Finaliza\n");
		printf("Digite: ");
		scanf("%d",&menu);
		
		switch (menu){
			case 1:
				printf("Empilhar!\n"); 
				printf("\n digite elemento para inserir na pilha: ");
				scanf("%f", &value);     
				pilha = push(pilha,value); 			       		
				break;
			case 2:
				printf("Mostrar!\n");  
				imprimirPilha(pilha);     		
				break;
			case 3:
				printf("Desempilhar!\n");
				printf("Topo: %f\n", top(pilha));
				pilha = pop(pilha);
				imprimirPilha(pilha);			        		
				break;
			case 4:
				printf("Transferir!\n");
				pilha2 = transfere(pilha);
				break;
			case 5:
				printf("TransferirIgual!\n");
				pilha2 = transfereIgual(pilha);
				break;
			case 0:
				printf("Terminar programa!\n"); 
				liberarPilha(pilha);			       		
				break;
			default:
				printf("Escolha incorreta!\n");
		} 
		printf("\n\n");
		system("pause"); 	 

	} while(menu!=0);   
}

// Cria uma pilha vazia
Pilha* criarPilha(void) {
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->n = 0; 		/* inicializa com zero elementos */
	return p;
}

// Insere um elemento na pilha
Pilha* push(Pilha* p, float value) {
	if (p->n == MAX) {
		printf("Capacidade da pilha estourou.\n");		/* capacidade esgotada */
		exit(1); 										/* aborta programa */
	} else {
		/* insere elemento na proxima posicao livre */
		p->vet[p->n] = value;
		p->n++;
		return p;
	}
}

// Retira um elemento da pilha
Pilha* pop(Pilha* p) {
	if (isEmpty(p)) {
		printf("Pilha vazia.\n");
		exit(1); 					
	} else {
		/* retira elemento do topo */
		p->vet[p->n-1] = 0.0;
		p->n--;
		return p;			
	}
}

Pilha* transfere(Pilha* p) {
	Pilha* p2 = criarPilha();
	int i;
	
	while(!isEmpty(p)) {
		push(p2, top(p));
		pop(p);
	}
	
	imprimirPilha(p2);

	return p2;
}

Pilha* transfereIgual(Pilha* p) {
	Pilha* p2 = criarPilha();
	int i;
	
	while(!isEmpty(p)) {
		push(p2, top(p));
		pop(p);
	}

	while(!isEmpty(p2)) {
		push(p, top(p2));
		pop(p2);
	}

	imprimirPilha(p2);
	
	return p2;
}

// Retorna o elemento do topo da pilha
float top(Pilha* p) {
	if (isEmpty(p)) {
		printf("Pilha vazia.\n");
		exit(0); 					
	}
	
	return p->vet[p->n-1];
}

// Retorna 1 se a pilha estiver vazia e 0 caso contrario
int isEmpty(Pilha* p) {
	return (p->n == 0);
}
 
void imprimirPilha (Pilha* p) {
	int i;

	printf("TOPO >>\n");
	for (i = p->n-1; i >= 0; i--)
		printf("%6.2f\n",p->vet[i]);
	printf("<< BASE ");
	printf("\n");
}

void liberarPilha(Pilha* p) {
	free(p);
}



