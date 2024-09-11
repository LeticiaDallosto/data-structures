/*
    O sistema de uma editora utiliza uma lista simplesmente encadeada para armazenar os dados dos seus livros. Está lista é automaticamente ordenada crescentemente pelos anos dos livros e cada nó da lista é representado pelo tipo estruturado NoDaLista:

    typedef struct noDaLista NoDaLista;  

    struct noDaLista  
    {
        char titulo[51]; 
        char autor[51]; 
        int ano; 
        int quantidade; 
        NoDaLista *prox; 
    };

    Com base nessa definição, implemente as seguintes funções:

    quantidade_livros – a função recebe por parâmetro o endereço do primeiro elemento da lista encadeada e deve retornar a quantidade total de livros em estoque (somatório dos campos quantidade existentes na estrutura dos nós da lista); 
    livros_ano – a função recebe por parâmetro o endereço do primeiro elemento da lista encadeada e um determinado ano. A função deve exibir na tela os dados de todos os livros existentes na lista que foram publicados no ano especificado; 
    livros_ano_rec – a função recebe por parâmetro o endereço do primeiro elemento da lista encadeada e um determinado ano. A função deve exibir na tela os dados de todos os livros existentes na lista que foram publicados no ano especificado. Obrigatoriamente a função deve ser implementada de forma recursiva; 
    separa_ano – a função recebe a lista encadeada (ou seja, o endereço do primeiro nó da lista) e um ano, e MODIFICANDO a lista original, retorna uma (sub)lista encadeada somente com os livros daquele ano. Não devem ser criados novos nós. O trecho correspondente aos livros desse ano deve ser “cortado” da lista original. A lista original deve ser “emendada”, e o endereço do primeiro nó do trecho (sublista) arrancado deve ser retornado ( sendo necessário colocar NULL no campo prox do último nó dessa (sub)lista ). A sua função deve levar em conta a ordenação da lista original. A função retorna o endereço do primeiro nó da (sub) lista resultante. Para facilitar, considere que o ano solicitado nunca é o do primeiro livro ou do último livro. Se não existir nenhum livro para o ano recebido, a função retorna NULL.
    Em seguida, continue a implementação do programa baixo para testar as suas funções. O seu programa deve exibir na tela o total de livros em estoque, todos os livros de um determinado ano fornecido pelo usuário (usando a função iterativa e a recursiva) e também as listas resultantes ao realizar a separação de um determinado ano.

    #include <stdio.h>  
    #include <stdlib.h>  
    #include <string.h>  

    typedef struct noDaLista NoDaLista;  

    struct noDaLista  
    {
        char titulo[51];  
        char autor[51];  
        int ano;  
        int quantidade;  
        NoDaLista *prox;  
    }

    NoDaLista* insere_livro(NoDaLista* lst, char *nome, char *autor, int ano,int qtd)  
    {
        NoDaLista* p = (NoDaLista*)malloc(sizeof(NoDaLista));  
        strcpy(p->titulo, nome);  
        strcpy(p->autor, autor);  
        p->ano = ano;  
        p->quantidade = qtd;  
        p->prox = lst;  
        return p;  
    }

    int main (void)  
    {
        NoDaLista *lista = NULL;  
        lista = insere_livro(lista, "Game Development: Using Unity and C#", "Millington", 2013, 43);  
        lista = insere_livro(lista, "Game Coding Complete", "McShaffry", 2012, 32);  
        lista = insere_livro(lista, "Game Development Essentials: An Introduction","Novak", 2011, 42);  
        lista = insere_livro(lista, "Prolog Programming for Artificial Intelligence", "Bratko", 2011, 31);  
        lista = insere_livro(lista, "Beginning C++ Through Game Programming", "Dawson", 2010, 54);  
        lista = insere_livro(lista, "Fundamentals of Database Systems", "Elmasri", 010, 46);  
        lista = insere_livro(lista, "Software Engineering: Theory and Practice", "Pfleeger", 2009, 28);  
        lista = insere_livro(lista, "Introduction to Algorithms", "Cormen", 2009, 31);  
        lista = insere_livro(lista, "Artificial Intelligence: A Modern Approach", "Russell and Norvig", 2009, 45);  
        lista = insere_livro(lista, "Artificial Intelligence for Games", "Millington",  009, 29);  
        lista = insere_livro(lista, "Pattern Recognition and Machine Learning",  "Bishop", 2006, 13);  
        lista = insere_livro(lista, "Algorithms", "Dasgupta", 2006, 25);  
        lista = insere_livro(lista, "Algorithm Design", "Kleinberg", 2006, 38);  
        lista = insere_livro(lista, "Introducao a Estruturas de Dados", "Waldemar Celes", 2004, 31);  
        lista = insere_livro(lista, "C - A Linguagem de Programacao", "Kernighan",  2000, 21);  
        lista = insere_livro(lista, "Machine Learning", "Mitchell", 1997, 42);  
        return 0;  
    }
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noDaLista NoDaLista;

struct noDaLista {
    char titulo[51];
    char autor[51];
    int ano;
    int quantidade;
    NoDaLista *prox;
};

// Prototipação das funções
NoDaLista *insere_livro(NoDaLista *lst, char *nome, char *autor, int ano, int qtd);
int quantidade_livros(NoDaLista* lst);
void livros_ano(NoDaLista* lst, int ano);
void livros_ano_rec(NoDaLista* lst, int ano);
NoDaLista* separa_ano(NoDaLista** lst, int ano);

int main(void) {
    NoDaLista* lista = NULL;
    lista = insere_livro(lista, "Game Development: Using Unity and C#", "Millington", 2013, 43);
    lista = insere_livro(lista, "Game Coding Complete", "McShaffry", 2012, 32);
    lista = insere_livro(lista, "Game Development Essentials: An Introduction", "Novak", 2011, 42);
    lista = insere_livro(lista, "Prolog Programming for Artificial Intelligence", "Bratko", 2011, 31);
    lista = insere_livro(lista, "Beginning C++ Through Game Programming", "Dawson", 2010, 54);
    lista = insere_livro(lista, "Fundamentals of Database Systems", "Elmasri", 2010, 46);
    lista = insere_livro(lista, "Software Engineering: Theory and Practice", "Pfleeger", 2009, 28);
    lista = insere_livro(lista, "Introduction to Algorithms", "Cormen", 2009, 31);
    lista = insere_livro(lista, "Artificial Intelligence: A Modern Approach", "Russell and Norvig", 2009, 45);
    lista = insere_livro(lista, "Artificial Intelligence for Games", "Millington", 2009, 29);
    lista = insere_livro(lista, "Pattern Recognition and Machine Learning", "Bishop", 2006, 13);
    lista = insere_livro(lista, "Algorithms", "Dasgupta", 2006, 25);
    lista = insere_livro(lista, "Algorithm Design", "Kleinberg", 2006, 38);
    lista = insere_livro(lista, "Introducao a Estruturas de Dados", "Waldemar Celes", 2004, 31);
    lista = insere_livro(lista, "C - A Linguagem de Programacao", "Kernighan", 2000, 21);
    lista = insere_livro(lista, "Machine Learning", "Mitchell", 1997, 42);

    // Teste das funções
    int totalLivros = quantidade_livros(lista);
    printf("Total de livros em estoque: %d\n", totalLivros);

    int ano;
    printf("Digite um ano: ");
    scanf("%d", &ano);

    printf("Livros do ano %d:\n", ano);
    livros_ano(lista, ano);

    printf("Livros do ano %d (recursivo):\n", ano);
    livros_ano_rec(lista, ano);

    printf("Separando livros do ano %d:\n", ano);
    NoDaLista* sublista = separa_ano(&lista, ano);
    NoDaLista* p = sublista;
    while (p != NULL) {
        printf("Título: %s\n", p->titulo);
        printf("Autor: %s\n", p->autor);
        printf("Ano: %d\n", p->ano);
        printf("Quantidade: %d\n", p->quantidade);
        printf("\n");
        p = p->prox;
    }

    return 0;
}

NoDaLista *insere_livro(NoDaLista *lst, char *nome, char *autor, int ano, int qtd) {
    NoDaLista *p = (NoDaLista *)malloc(sizeof(NoDaLista));
    strcpy(p->titulo, nome);
    strcpy(p->autor, autor);
    p->ano = ano;
    p->quantidade = qtd;
    p->prox = lst;
    return p;
}

int quantidade_livros(NoDaLista* lst) {
    int total = 0;
    NoDaLista* p = lst;
    while (p != NULL) {
        total += p->quantidade;
        p = p->prox;
    }
    return total;
}

void livros_ano(NoDaLista* lst, int ano) {
    NoDaLista* p = lst;
    while (p != NULL) {
        if (p->ano == ano) {
            printf("Título: %s\n", p->titulo);
            printf("Autor: %s\n", p->autor);
            printf("Ano: %d\n", p->ano);
            printf("Quantidade: %d\n", p->quantidade);
            printf("\n");
        }
        p = p->prox;
    }
}

void livros_ano_rec(NoDaLista* lst, int ano) {
    if (lst == NULL) {
        return;
    }
    if (lst->ano == ano) {
        printf("Titulo: %s\n", lst->titulo);
        printf("Autor: %s\n", lst->autor);
        printf("Ano: %d\n", lst->ano);
        printf("Quantidade: %d\n", lst->quantidade);
        printf("\n");
    }
    livros_ano_rec(lst->prox, ano);
}

NoDaLista* separa_ano(NoDaLista** lst, int ano) {
    NoDaLista* p = *lst;
    NoDaLista* prev = NULL;
    while (p != NULL) {
        if (p->ano == ano) {
            if (prev == NULL) {
                *lst = p->prox;
            } else {
                prev->prox = p->prox;
            }
            p->prox = NULL;
            return p;
        }
        prev = p;
        p = p->prox;
    }
    return NULL;
}

