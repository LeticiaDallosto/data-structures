/*
    Em uma agenda telefônica os contatos são cadastrados com os seguintes dados:  

    Nome – nome do contato (máximo 40 caracteres); 
    Telefone – cadeia de caracteres com o número do telefone do contato (máximo 15 caracteres); 
    Celular – cadeia de caracteres com o número do celular do contato (máximo 15 caracteres); 
    Email – cadeia de caracteres com o email do contato (máximo 40 caracteres); 
    DataAniversario – data de aniversario do contato (contendo dia e mês);
    Essas informações podem ser representadas em dois tipos estruturados: Data e Contato.

    Utilizando listas encadeadas, escreva um programa que permita o cadastro, edição, remoção, busca e impressão de contatos desta agenda telefônica.  
    Os elementos da lista encadeada para armazenar contatos são representados pela seguinte estrutura:  

    struct elemento {  
        Contato info; 
        struct elemento* prox; 
    };  
    typedef struct elemento Elemento;

    O seu programa deve implementar as seguintes funções:

    cria_agenda – cria uma nova lista encadeada retornando um ponteiro para NULL; 
    insere_contato – insere um novo contato na lista encadeada respeitando a ordem alfabética dos nomes dos contatos já existentes na agenda;
    lista_contatos – exibe na tela todos os dados dos contatos existentes na agenda; 
    busca_contato– busca um contato na agenda com base em um determinado nome informado pelo usuário. A função retorna o endereço de memória do elemento encontrado ou NULL caso o contato não seja encontrado; 
    remove_contato – deleta um determinado contato existente na agenda. A função deve permitir ao usuário buscar por um contato na agenda (utilizando a função busca_contato previamente criada) e em seguida remover da lista o contato. Se o contato buscado não for encontrado, o programa deve exibir uma mensagem informando o usuário sobre esse fato;
    atualiza_contato – modifica os dados de um contato já existente na agenda. A função deve permitir ao usuário buscar por um contato na agenda (utilizando a função busca_contato previamente criada) e em seguida alterar os dados do contato encontrado com base nas novas informações fornecidas pelo usuário. Se o contato buscado não for encontrado, o programa deve exibir uma mensagem informando o usuário sobre esse fato; 
    remove_duplicados – remove todos os contatos duplicados existentes na lista. Um contato é considerado duplicado se existir outro contato na agenda com o mesmo nome; 
    libera_agenda – libera a memória alocada dinamicamente para armazenar os contatos da agenda; 
    Em seguida, você deve implementar a função principal do programa que permita ao usuário realizar todas as operações da agenda: cadastro, impressão, edição, remoção, busca e remover duplicados. O programa deve exibir um menu para o usuário escolher as operações desejadas. Exemplo:

    Inserir Contato
    Listar Contatos
    Buscar Contato 
    Editar Contato 
    Remover Contato 
    Remover Contatos Duplicados 
    Sair 
    O programa deve permitir que o usuário realize operações na agenda de contatos até o momento que ele desejar sair do programa escolhendo a opções 7.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define o tamanho máximo para os campos de dados dos contatos
#define MAX_NAME_LENGTH 40
#define MAX_PHONE_LENGTH 15
#define MAX_CELL_LENGTH 15
#define MAX_EMAIL_LENGTH 40

// Estrutura para representar uma data
typedef struct {
    int day;
    int month;
} Date;

// Estrutura para representar um contato
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char cell[MAX_CELL_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    Date birthday;
} Contact;

// Estrutura para representar um elemento da lista encadeada
typedef struct element {
    Contact info;
    struct element* next;
} Element;

// Prototipação das funções
Element* cria_agenda();
Element* insere_contato(Element* agenda, Contact newContact);
void lista_contatos(Element* agenda);
Element* busca_contato(Element* agenda, char* name);
Element* remove_contato(Element* agenda, char* name);
void atualiza_contato(Element* agenda, char* name);
Element* remove_duplicados(Element* agenda);
void libera_agenda(Element* agenda);

int main() {
    Element* agenda = cria_agenda();
    int option;

    do {
        printf("Menu:\n");
        printf("1. Inserir Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Buscar Contato\n");
        printf("4. Editar Contato\n");
        printf("5. Remover Contato\n");
        printf("6. Remover Contatos Duplicados\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);
        getchar(); // Clear the newline character from the input buffer

        switch (option) {
            case 1: {
                Contact newContact;
                printf("Digite o nome: ");
                fgets(newContact.name, MAX_NAME_LENGTH, stdin);
                newContact.name[strcspn(newContact.name, "\n")] = '\0';

                printf("Digite o telefone: ");
                fgets(newContact.phone, MAX_PHONE_LENGTH, stdin);
                newContact.phone[strcspn(newContact.phone, "\n")] = '\0';

                printf("Digite o celular: ");
                fgets(newContact.cell, MAX_CELL_LENGTH, stdin);
                newContact.cell[strcspn(newContact.cell, "\n")] = '\0';

                printf("Digite o email: ");
                fgets(newContact.email, MAX_EMAIL_LENGTH, stdin);
                newContact.email[strcspn(newContact.email, "\n")] = '\0';

                printf("Digite o dia de aniversario: ");
                scanf("%d", &newContact.birthday.day);

                printf("Digite o mes de aniversario: ");
                scanf("%d", &newContact.birthday.month);

                agenda = insere_contato(agenda, newContact);
                printf("Contato inserido com sucesso.\n");
                break;
            }
            case 2:
                lista_contatos(agenda);
                break;
            case 3: {
                char name[MAX_NAME_LENGTH];
                printf("Digite o nome do contato: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';

                Element* contact = busca_contato(agenda, name);
                if (contact != NULL) {
                    printf("Contato encontrado:\n");
                    printf("Nome: %s\n", contact->info.name);
                    printf("Telefone: %s\n", contact->info.phone);
                    printf("Celular: %s\n", contact->info.cell);
                    printf("Email: %s\n", contact->info.email);
                    printf("Data de Aniversario: %d/%d\n", contact->info.birthday.day, contact->info.birthday.month);
                } else {
                    printf("Contato nao encontrado.\n");
                }
                break;
            }
            case 4: {
                char name[MAX_NAME_LENGTH];
                printf("Digite o nome do contato: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';

                atualiza_contato(agenda, name);
                break;
            }
            case 5: {
                char name[MAX_NAME_LENGTH];
                printf("Digite o nome do contato: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';

                agenda = remove_contato(agenda, name);
                break;
            }
            case 6:
                agenda = remove_duplicados(agenda);
                break;
            case 7:
                libera_agenda(agenda);
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }

        printf("\n");
    } while (option != 7);

    return 0;
}

// Criar uma nova lista encadeada para armazenar os contatos da agenda
Element* cria_agenda() {
    return NULL;
}

// Inserir um novo contato na lista encadeada respeitando a ordem alfabética dos nomes dos contatos já existentes na agenda
Element* insere_contato(Element* agenda, Contact newContact) {
    Element* newElement = (Element*) malloc(sizeof(Element));
    newElement->info = newContact;
    newElement->next = NULL;

    if (agenda == NULL) {
        return newElement;
    }

    Element* current = agenda;
    Element* previous = NULL;

    while (current != NULL && strcmp(newContact.name, current->info.name) > 0) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        newElement->next = agenda;
        return newElement;
    } else {
        previous->next = newElement;
        newElement->next = current;
        return agenda;
    }
}

// Imprime na tela todos os dados dos contatos existentes na agenda
void lista_contatos(Element* agenda) {
    if (agenda == NULL) {
        printf("Agenda vazia.\n");
        return;
    }

    Element* current = agenda;

    while (current != NULL) {
        printf("Nome: %s\n", current->info.name);
        printf("Telefone: %s\n", current->info.phone);
        printf("Celular: %s\n", current->info.cell);
        printf("Email: %s\n", current->info.email);
        printf("Data de Aniversario: %d/%d\n", current->info.birthday.day, current->info.birthday.month);
        printf("\n");

        current = current->next;
    }
}

// Busca um contato na agenda com base em um determinado nome informado pelo usuário
Element* busca_contato(Element* agenda, char* name) {
    Element* current = agenda;

    while (current != NULL) {
        if (strcmp(name, current->info.name) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Remove um determinado contato existente na agenda
Element* remove_contato(Element* agenda, char* name) {
    if (agenda == NULL) {
        printf("Agenda vazia.\n");
        return NULL;
    }

    Element* current = agenda;
    Element* previous = NULL;

    while (current != NULL && strcmp(name, current->info.name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Contato nao encontrado.\n");
        return agenda;
    }

    if (previous == NULL) {
        agenda = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Contato removido com sucesso.\n");
    return agenda;
}

// Atualiza os dados de um contato já existente na agenda
void atualiza_contato(Element* agenda, char* name) {
    Element* contact = busca_contato(agenda, name);

    if (contact == NULL) {
        printf("Contato nao encontrado.\n");
        return;
    }

    printf("Digite o novo nome: ");
    fgets(contact->info.name, MAX_NAME_LENGTH, stdin);
    contact->info.name[strcspn(contact->info.name, "\n")] = '\0';

    printf("Digite o novo telefone: ");
    fgets(contact->info.phone, MAX_PHONE_LENGTH, stdin);
    contact->info.phone[strcspn(contact->info.phone, "\n")] = '\0';

    printf("Digite o novo celular: ");
    fgets(contact->info.cell, MAX_CELL_LENGTH, stdin);
    contact->info.cell[strcspn(contact->info.cell, "\n")] = '\0';

    printf("Digite o novo email: ");
    fgets(contact->info.email, MAX_EMAIL_LENGTH, stdin);
    contact->info.email[strcspn(contact->info.email, "\n")] = '\0';

    printf("Digite o novo dia de aniversario: ");
    scanf("%d", &contact->info.birthday.day);

    printf("Digite o novo mes de aniversario: ");
    scanf("%d", &contact->info.birthday.month);

    printf("Contato atualizado com sucesso.\n");
}

// Remove todos os contatos duplicados existentes na lista
Element* remove_duplicados(Element* agenda) {
    if (agenda == NULL) {
        printf("Agenda vazia.\n");
        return NULL;
    }

    Element* current = agenda;

    while (current != NULL) {
        Element* runner = current;

        while (runner->next != NULL) {
            if (strcmp(current->info.name, runner->next->info.name) == 0) {
                Element* duplicate = runner->next;
                runner->next = runner->next->next;
                free(duplicate);
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }

    printf("Contatos duplicados removidos com sucesso.\n");
    return agenda;
}

// Libera a memória alocada dinamicamente para armazenar os contatos da agenda
void libera_agenda(Element* agenda) {
    Element* current = agenda;

    while (current != NULL) {
        Element* next = current->next;
        free(current);
        current = next;
    }
}

