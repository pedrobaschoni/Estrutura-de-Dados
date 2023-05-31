#include <stdio.h>
#include <stdlib.h>

typedef struct sLista {
    char info;
    struct sLista *next;
    struct sLista *back;
}lista;

lista* getnode() {
    return (lista*) malloc (sizeof(lista));
}

void inicializar(lista **L) {
    lista *aux;
    aux = getnode();
    aux->info = -1;
    aux->next = aux;
    aux->back = aux;
    *L = aux;
}

void freenode(lista *L) {
    free(L);
}

int vazia(lista *L) {
    if(L->next == L)
        return 1;
    return 0;
}

void inserir_inicio(lista **L, char elem) {
    lista *q;

    q = getnode();
    if(q != NULL) {
        q->info = elem;
        q->next = (*L)->next;
        q->back = *L;
        (*L)->next->back = q;
        (*L)->next = q;
    } else {
        printf("Erro ao alocar o no\n");
    }
}

void inserir_fim(lista **L, char elem) {
    lista *q;

    q = getnode();
    if(q != NULL) {
        q->info = elem;
        q->next = *L;
        q->back = (*L)->back;
        (*L)->back->next = q;
        (*L)->back = q;
    } else {
        printf("Erro ao alocar o no\n");
    }
}

void remover_inicio(lista **L) {
    lista *q = (*L)->next;

    if(!vazia(*L)) {
        (*L)->next->next->back = *L;
        (*L)->next = (*L)->next->next;
        freenode(q);
    } else {
        printf("Erro! - Lista vazia\n");
    }
}

void remover_fim(lista **L) {
    lista *q = (*L)->back;

    if(!vazia(*L)) {
        (*L)->back->back->next = *L;
        (*L)->back = (*L)->back->back;
        freenode(q);
    } else {
        printf("Erro! - Lista vazia\n");
    }
}

void exibir_lista(lista **L) {
    lista *aux = (*L)->next;

    if(vazia(*L)) {
        printf("Erro! - Lista vazia\n");
        return;
    }
    while(aux != *L) {
        printf("[%c] ", aux->info);
        aux = aux->next;
    }
}


void main() {
    lista *L;

    inicializar(&L);

    inserir_inicio(&L, 'a');
    inserir_inicio(&L, 'b');
    inserir_inicio(&L, 'c');
    inserir_inicio(&L, 'd');
    inserir_fim(&L, 'w');
    inserir_fim(&L, 'x');
    inserir_fim(&L, 'y');
    inserir_fim(&L, 'z');

    remover_inicio(&L);
    remover_fim(&L);

    exibir_lista(&L);
}
