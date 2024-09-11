/*
    A Roda da Fortuna E um jogo composto por uma roda, dividida em fatias.
	Quando a roda E girada, na fatia onde a roda parar determina o que voce ganha ou perde. 
	REGRAS:
	A roda a ser criada devera ser composta por 15 fatias;
	Cada fatia da roda devera conter um valor aleatorio a ser ganho, caso a roda pare de girar na fatia em questao. 
	Para executar o jogo, o programa devera pedir se o jogador deseja jogar ou deseja sair do jogo;
	Se ele desejar sair, o programa e terminado;
	Se ele desejar jogar, o sistema devera girar a roda;
	A forca da girada sera gerada a partir de um numero aleatorio que pode variar de 1 a 15 (tamanho da roda);
	Apos girar a roda, o programa devera exibir o valor da fatia onde a roda parar;
	Deve-se considerar que o inicio do girar da roda sempre sera a ultima posicao onde a roda parou na execucao anterior,
	salvo na primeira vez, onde a roda inicia a girar a partir do primeiro elemento;
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
No* exibirDequeInicio(Deque* d, int posicoes);
No* exibirDequeApartirPosicao(No* d, int posicoes);
bool inserirDequeFim(Deque* d, int v);
void reinicializarDeque(Deque* d);

int main() {
	// Criar a roda da fortuna com 15 fatias
	Deque* roda = cria();

	// Ponteiro para o elemento onde a roda parou
	No* end = NULL;

	int valorRemovido; // Valor da fatia removida
	int movimentoRoda; // Movimento da roda

	// Inicializar a roda com valores aleatorios
	for (int i = 0; i < 15; i++) {
		int valor = rand() % 100; // Valor aleatorio a ser ganho na fatia
		inserirDequeFim(roda, valor);
	}

	// Loop principal do jogo
	while (true) {
		printf("Deseja girar a roda da fortuna? (s/n): ");
		char opcao;
		scanf(" %c", &opcao);

		if (opcao == 'n') {
			break; // Sair do jogo
		} else if (opcao == 's') {
			//Gira a roda
			movimentoRoda = rand() % 15;

			//Movimenta a roda
			//Armazena a referencia do movimento
			if (end == NULL){
				end = exibirDequeInicio(roda, movimentoRoda);
			}
			else{
				end = exibirDequeApartirPosicao(end, movimentoRoda);
			}

			// Exibir o valor da fatia onde a roda parou
			printf("Voce ganhou o valor: %d\n", end->value);

		} else {
			printf("Opcao invalida. Tente novamente.\n");
		}
	}

	// Liberar a memoria alocada pelo deque
	reinicializarDeque(roda);

	return 0;
}

Deque* cria(void) {
	Deque* d = (Deque*) malloc(sizeof(Deque));
	d->head = (No*) malloc(sizeof(No));
	d->head->next = d->head;
	d->head->prev = d->head;
	return d;
}

No* exibirDequeInicio(Deque* d, int posicoes) {
	int contador = 0;
	
	No* end = d->head->next;
	printf("Deque partindo do fim: \" ");
	while (contador < posicoes) {
		end = end->next;
		contador++;
	}
	return end;
}

No* exibirDequeApartirPosicao(No* d, int posicoes) {
	int contador = 0;
	No* end = d;
	printf("Deque partindo do fim: \" ");
	while (contador < posicoes) {
		end = end->next;
		contador++;
	}
	return end;
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


