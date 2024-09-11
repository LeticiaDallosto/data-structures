/*
    Utilizar como base as funcoes do programa exemplo do TAD Pilha com Encadeamento e modifica-lo, de maneira que trabalhe com uma pilha de caracteres, ou seja, 
	cada elemento da pilha tera uma letra. O programa principal (main) devera ler uma palavra e armazena-la na pilha, colocando cada letra da palavra em um elemento da pilha.
	Depois deve desempilhar os elementos da pilha formando uma nova palavra, por concatenacao dos caracteres.
	Na sequencia deve comparar a palavra original (lida) com a palavra gerada, se forem iguais informar que a palavra e um palindromo, caso contrario informar que nao e.

	Exemplo 1:
	Palavra Lida: CASA
	PILHA: topo -> A -> S -> A -> C
	Nova Palavra: ASAC
	Nao e Palindromo
	Exemplo 2:
	Palavra Lida: ASA
	PILHA: topo -> A -> S -> A
	Nova Palavra: ASA
	E Palindromo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct pilha {
    int n;
    char vet[MAX];
} Pilha;

Pilha* criarPilha(void);
Pilha* push(Pilha* p, char v);
Pilha* pop(Pilha* p);
char top(Pilha* p);
int isEmpty(Pilha* p);
void liberarPilha(Pilha* p);

int main() {
    char palavra[MAX];
    char invertida[MAX];
    int i;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    Pilha* pilha = criarPilha();

    for (i = 0; i < strlen(palavra); i++) {
        pilha = push(pilha, palavra[i]);
    }

    for (i = 0; i < strlen(palavra); i++) {
        invertida[i] = top(pilha);
        pilha = pop(pilha);
    }
    invertida[i] = '\0';

    if (strcmp(palavra, invertida) == 0) {
        printf("A palavra e um palindromo.\n");
    } else {
        printf("A palavra nao e um palindromo.\n");
    }

    liberarPilha(pilha);

    return 0;
}

Pilha* criarPilha(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0;
    return p;
}

// Insere um elemento na pilha
Pilha* push(Pilha* p, char v) {
    if (p->n == MAX) {
        printf("Capacidade da pilha estourou.\n");
        exit(1);
    }
    p->vet[p->n] = v;
    p->n++;
    return p;
}

// Retira um elemento da pilha
Pilha* pop(Pilha* p) {
    if (isEmpty(p)) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    p->vet[p->n-1] = '\0';
    p->n--;
    return p;
}

// Retorna o elemento do topo da pilha
char top(Pilha* p) {
    if (isEmpty(p)) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    return p->vet[p->n-1];
}

// Verifica se a pilha esta vazia
int isEmpty(Pilha* p) {
    return (p->n == 0);
}

// Libera a pilha
void liberarPilha(Pilha* p) {
    free(p);
}



