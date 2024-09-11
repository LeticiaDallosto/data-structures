#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int dado;
	nodo *esquerda;
	nodo *direita;
} nodo;

typedef nodo *arvore;

//Prototipos das funcoes
nodo *criaElemento();
nodo *insere(nodo *a, int valor);
void prefixoDesloca(nodo *a);
void prefixoNivel(nodo *a, int nivel, char texto);
void infixo(nodo *a);
void prefixo(nodo *a);
void posfixo(nodo *a);
void decrescente(nodo *a);
int alturaArvore(nodo *a);
int procura(nodo *a, int valor);
int nivelNodo(nodo *a, int valor, int nivel);
void grauNodo(nodo *a, int valor);
void elementosAscendentes(nodo *a, int valor);
void elementosDescendentes(nodo *a, int valor);
void elementosFilhos(nodo *a);
void elementosPais(nodo *a);

main() {
	nodo *minha, *buscar;
	minha = NULL;
	int i, numero, op, n;
	int dados[20] = {50,25,75,15,30,70,80,5,85,8,36,18,3,65,73,79,16,22,27,35};
	do {
		system("cls");
		printf("1- Inserir dados\n");
		printf("2- Mostrar arvore\n");
		printf("3- Percurso Infixo\n");
		printf("4- Percurso Prefixo\n");
		printf("5- Percurso Posfixo\n");
		printf("6- Ordem Decrescente\n");
		printf("7- Altura da arvore\n");
		printf("8- Procurar\n");
		printf("9- Nivel de um nodo\n");
		printf("10- Grau de um nodo\n");
		printf("11- Elementos ascendentes\n");
		printf("12- Elementos descendentes\n");
		printf("13- Elementos filhos\n");
		printf("14- Elementos pais\n");
		printf("0- Finalizar\n");
		printf("selecione: \n");
		scanf("%d",&op);
		switch(op) {
			case 1:
				for(i=0; i<20; i++) {
					numero = dados[i];
					minha=insere(minha,numero);
				}
				break;
			case 2:
				if (minha != NULL) {
					prefixoDesloca(minha);
				}
				break;
			case 3:
				if (minha != NULL) {
					infixo(minha);
				}
				break;
			case 4:
				if (minha != NULL) {
					prefixo(minha);
				}
				break;
			case 5:
				if (minha != NULL) {
					posfixo(minha);
				}
				break;
			case 6:
				if (minha != NULL) {
					decrescente(minha);
				}
				break;
			case 7:
				if (minha != NULL) {
                    printf("Altura da arvore: %d\n", alturaArvore(minha));
                }
                break;
			case 8:
				if(minha != NULL) {
					printf("Digite o valor a ser procurado: ");
					scanf("%d",&numero);
					if(procura(minha,numero) == 1) {
						printf("Valor encontrado!\n");
					} else {
						printf("Valor nao encontrado!\n");
					}
				}
				break;
			case 9:
				if (minha != NULL) {
                    printf("Digite o valor a ser procurado: ");
                    scanf("%d", &numero);
                    int nivel = nivelNodo(minha, numero, 0);
                    if (nivel != -1) {
                        printf("Nivel do valor %d: %d\n", numero, nivel);
                    } else {
                        printf("Valor nao encontrado na arvore.\n");
                    }
                }
                break;
			case 10:
				if(minha != NULL) {
					grauNodo(minha, 0);
				}
				break;
			case 11:
				if(minha != NULL) {
					printf("Digite o valor a ser procurado: ");
					scanf("%d",&numero);
					elementosAscendentes(minha,numero);
				}
				break;
			case 12:
				if(minha != NULL) {
					printf("Digite o valor a ser procurado: ");
					scanf("%d",&numero);
					elementosDescendentes(minha,numero);
				}
				break;
			case 13:
				if (minha != NULL) {
                    elementosFilhos(minha);
                }
                break;
			case 14:
				printf("Elementos pais: \n");
				if (minha != NULL) {
                    elementosPais(minha);
                }
                break;
			case 0:
				printf("Finalizando...\n\n");
				break;
			default:
				printf("Selecione opcao valida...\n\n");
				break;
		}
		system("pause");
	} while(op!=0);
}

//Implementacao das funcoes

//Cria um novo nodo, coloca o seu valor em dado, inicializa os ponteiros esquerda e direita com o valor NULL
	/* retorna o endereco da posicao de memoria alocada */
nodo *criaElemento(int valor) {
	nodo *a;
	a = (nodo*)malloc(sizeof(nodo));
	a->dado = valor;
	a->esquerda = NULL;
	a->direita = NULL;
	return(a);
}

//Inclui um novo nodo na árvore binária de pesquisa
	/* a inclusão respeita a regra de que os nodos:
	a esquerda possuem valor menor que a raiz
	a direita possuem valor maior que a raiz
	função recursiva */
nodo *insere(nodo *a, int valor) {
	if (a == NULL) {
		a = criaElemento(valor);
		printf("novo\n");
	} else if (valor <= a->dado) {
		printf("esquerda\n");
		a->esquerda = insere(a->esquerda,valor);
	} else {
		printf("direita\n");
		a->direita = insere(a->direita,valor);
	}
	printf("%d\n",a->dado);
	return(a);
}

//Varre e mostra todos os elementos da árvore
	/* implementa o percurso prefixo: Raiz - SAE - SAD
	desloca espaços na tela para indicar a diferença entre os níveis dos nodos */
void prefixoDesloca(nodo *a) {
	prefixoNivel(a, 0, 'R');
}
void prefixoNivel(nodo *a, int nivel, char texto) {
	if (a != NULL) {
		for(int i=0; i<=nivel; i++) printf(" ");
		printf("%c %d\n", texto, a->dado);
		if (a->esquerda != NULL) {
			prefixoNivel(a->esquerda, nivel + 2, 'E');
		}
		if (a->direita != NULL) {
			prefixoNivel(a->direita, nivel + 2, 'D');
		}
	}
}

//Varre e mostra todos os elementos da árvore
	/* implementa o percurso infixo: SAE - Raiz - SAD */
void infixo(nodo *a) {
	if (a != NULL) {
		if (a->esquerda != NULL) {
			infixo(a->esquerda);
		}
		printf("%d - ",a->dado);
		if (a->direita != NULL) {
			infixo(a->direita);
		}
	}
}

//Varre e mostra todos os elementos da árvore
	/* implementa o percurso prefixo: Raiz - SAE - SAD */
void prefixo(nodo *a) {
	if(a != NULL) {
		printf("%d - ", a->dado);
		if(a->esquerda != NULL) {
			prefixo(a->esquerda);
		}
		if(a->direita != NULL) {
			prefixo(a->direita);
		}
	}
}

//Varre e mostra todos os elementos da árvore
	/* implementa o percurso posfixo: SAE - SAD - Raiz */
void posfixo(nodo *a) {
	if(a != NULL) {
		if(a->esquerda != NULL) {
			posfixo(a->esquerda);
		}
		if(a->direita != NULL) {
			posfixo(a->direita);
		}
		printf("%d - ", a->dado);
	}
}

//Varre e mostra todos os elementos da árvore
	/* implementa o percurso infixo modificado: SAD - Raiz - SAE */
void decrescente(nodo *a) {
	if(a != NULL) {
		if(a->direita != NULL) {
			decrescente(a->direita);
		}
		printf("%d - ", a->dado);
		if(a->esquerda != NULL) {
			decrescente(a->esquerda);
		}
	}
}

//Calcula a altura da árvore
	/* Árvore vazia tem altura -1 */
int alturaArvore(nodo *a) {
	int alturaEsquerda, alturaDireita;

    if (a == NULL) {
        return -1; 
    }
    alturaEsquerda = alturaArvore(a->esquerda);
    alturaDireita = alturaArvore(a->direita);

    if (alturaEsquerda > alturaDireita) {
		return alturaEsquerda + 1;
	} else {
		return alturaDireita + 1;
	}
}

//Procura um valor na árvore
	/* retorna 1 se encontrar o valor e 0 se não encontrar */
int procura(nodo *a, int valor) {
	if(a != NULL) {
		if(valor == a->dado) {
			return(1);
		} else if(valor < a->dado) {
			return(procura(a->esquerda, valor));
		} else {
			return(procura(a->direita, valor));
		}
	} else {
		return(0);
	}
}

//Calcula o nível de um nodo na árvore
	/* retorna -1 se o valor não for encontrado */
int nivelNodo(nodo *a, int valor, int nivel) {
	if(a != NULL) {
		if(valor == a->dado) {
			return(nivel);
		} else if(valor < a->dado) {
			return(nivelNodo(a->esquerda, valor, nivel + 1));
		} else {
			return(nivelNodo(a->direita, valor, nivel + 1));
		}
	} else {
		return(-1);
	}
}

//Calcula o grau da árvore
void grauNodo(nodo *a, int valor) {
	int grau = 0;
	if(valor == a->dado) {
		if(a->esquerda != NULL) {
			grau++;
		}
		if(a->direita != NULL) {
			grau++;
		}
	} else if(valor < a->dado) {
		if(a->esquerda != NULL) {
			grauNodo(a->esquerda, valor);
		} else {
			grau = -1;
		}
	} else {
		if(a->direita != NULL) {
			grauNodo(a->direita, valor);
		} else {
			grau = -1;
		}
	}
	printf("Grau do elemento: %d\n", grau);
}

//Mostra os elementos ascendentes de um nodo
void elementosAscendentes(nodo *a, int valor) {
	if(a != NULL) {
		if(a->dado == valor) {
			printf("Ascendentes do valor %d: %d\n", valor, a->dado);
		} else if(valor < a->dado) {
			elementosAscendentes(a->esquerda, valor);
			printf("%d\n", a->dado);
		} else {
			elementosAscendentes(a->direita, valor);
			printf("%d\n", a->dado);
		}
	}
}

//Mostra os elementos descendentes de um nodo
void elementosDescendentes(nodo *a, int valor) {
	if(a != NULL) {
		if(a->dado == valor) {
			// prefixoDesloca(a);
			printf("Descendentes do valor %d: %d\n", valor, a->dado);
		} else if(valor < a->dado) {
			elementosDescendentes(a->esquerda, valor);
			printf("%d\n", a->dado);
		} else {
			elementosDescendentes(a->direita, valor);
			printf("%d\n", a->dado);
		}
	}
}

//Mostra todos os elementos filhos
void elementosFilhos(nodo *a) {
    if (a != NULL) {
        if (a->esquerda != NULL || a->direita != NULL) {
            printf("Elemento pai: %d\n", a->dado);
            if (a->esquerda != NULL) {
                printf("Filho esquerdo: %d\n", a->esquerda->dado);
            }
            if (a->direita != NULL) {
                printf("Filho direito: %d\n", a->direita->dado);
            }
            elementosFilhos(a->esquerda);
            elementosFilhos(a->direita);
        }
    }
}

//Mostra todos os elementos pais 
void elementosPais(nodo *a) {
    if (a != NULL) {
        if (a->esquerda != NULL || a->direita != NULL) {
            printf("%d\n", a->dado);
            elementosPais(a->esquerda);
            elementosPais(a->direita);
        }
    }
}



