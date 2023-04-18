#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct sReceita {
    char titutlo[50];
    char descricao[50];
    char tipo[15];
    char nome[50];
}receita;

typedef struct sLista {
    receita info;
    struct sLista *next;
}lista;

void inicializar(lista **L) {
    *L = NULL;
}

lista* getnode() {
    return (lista*) malloc (sizeof(lista));
}

void freenode(lista *L) {
    free(L);
}

int vazia(lista **L) {
    if(*L == NULL)
        return 1;
    return 0;
}

void inserir_inicio(lista **L, receita elem) {
    lista *q;

    q = getnode();
    if(q != NULL) {
        strcpy(q->info.titutlo, elem.titutlo);
        strcpy(q->info.descricao, elem.descricao);
        strcpy(q->info.tipo, elem.tipo);
        strcpy(q->info.nome, elem.nome);

        q->next = *L;
        *L = q;
    } else {
        printf("\nErro! - Nao foi possivel alocar o no");
    }
}

void inserir_fim(lista **L, receita elem) {
    lista *q;
    lista *aux = *L;

    q = getnode();
    if(q != NULL) {
        strcpy(q->info.titutlo, elem.titutlo);
        strcpy(q->info.descricao, elem.descricao);
        strcpy(q->info.tipo, elem.tipo);
        strcpy(q->info.nome, elem.nome);
        q->next = NULL;

        if(vazia(L))
            *L = q;
        else {
            while(aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = q;
        }
    } else {
        printf("\nErro! - Nao foi possivel alocar o no");
    }
}

lista* pesquisar_receita(lista **L, receita elem) {
    lista *aux = *L;

    if(!vazia(L)) {
        while(aux != NULL) {
            if(strcmp(elem.titutlo, aux->info.titutlo) < 0) {
                return aux;
            }
            aux = aux->next;
        }
    }
    return NULL;
}

void inserir_ordenado(lista **L, receita elem) {
     lista *q;
     lista *aux;
     lista *aux2 = *L;

     aux = pesquisar_receita(L, elem);

     if(aux == NULL)
        inserir_fim(L, elem);
     else if(aux == *L)
        inserir_inicio(L, elem);
     else {
        q = getnode();
        if(q != NULL) {
            strcpy(q->info.titutlo, elem.titutlo);
            strcpy(q->info.descricao, elem.descricao);
            strcpy(q->info.tipo, elem.tipo);
            strcpy(q->info.nome, elem.nome);
            while(strcmp(aux2->next->info.titutlo, aux->info.titutlo) != 0) {
                aux2 = aux2->next;
            }
            q->next = aux;
            aux2->next = q;
        } else {
            printf("\nErro! - Nao foi possivel alocar o no");
        }
     }
}

void exibir_lista(lista *L) {
    lista *aux = L;

    if(vazia(&L)) {
        printf("\nErro! - Lista vazia");
        return;
    }
    while(aux != NULL) {
        printf("\n-------RECEITAS CADASTRADAS-------");
        printf("\nTitulo da receita: %s", aux->info.titutlo);
        printf("\nDescricao da receita: %s", aux->info.descricao);
        printf("\nTipo da receita: %s", aux->info.tipo);
        printf("\nNome da pessoa que fez a receita: %s", aux->info.nome);
        printf("\n----------------------------------\n");
        aux = aux->next;
    }
    printf("\n");
}

int menu() {
    int op;

    printf("\n");
    printf("-------MENU-------");
    printf("\nEscolha uma das opcoes");
    printf("\n[1] - Cadastrar receita");
    printf("\n[2] - Exibir receitas cadastradas");
    printf("\n[0] - Sair");
    printf("\nInforme a opcao desejada: ");
    scanf("%d", &op);

    return op;
}

receita ler_receita(receita elem) {
    fflush(stdin);
    printf("\nInforme o nome da receita: ");
    scanf("%[^\n]", elem.titutlo);
    elem.titutlo[0] = toupper(elem.titutlo[0]);
    fflush(stdin);
    printf("Informe a descricao da receita: ");
    scanf("%[^\n]", elem.descricao);
    fflush(stdin);
    printf("Informe o tipo da receita: ");
    scanf("%[^\n]", elem.tipo);
    fflush(stdin);
    printf("Informe o seu nome: ");
    scanf("%[^\n]", elem.nome);
    fflush(stdin);

    return elem;
}

void main() {
    lista *L;
    receita elem;
    int op;

    inicializar(&L);

    do {
        op = menu();
        switch(op) {
            case 1:
                elem = ler_receita(elem);
                inserir_ordenado(&L, elem);
                break;

            case 2:
                exibir_lista(L);
                break;

            case 0:
                printf("\nSaindo...");
                break;

            default:
                printf("\nErro!");
        }

    }while(op != 0);
}
