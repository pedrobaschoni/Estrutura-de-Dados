#include <stdio.h>
#include <stdlib.h>

typedef struct sLista {
    char info;
    struct sLista *next;
}lista;

lista* getnode() {
    return (lista*) malloc (sizeof(lista));
}

void inicializar(lista **L) {
    lista *aux;
    aux = getnode();
    aux->info = -1;
    aux->next = aux;
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
        (*L)->next = q;
    } else {
        printf("Erro na alocacao do no\n");
    }
}

void inserir_fim(lista **L, char elem) {
    lista *q;
    lista *aux = *L;

    q = getnode();
    if(q != NULL) {
        q->info = elem;
        q->next = *L;

        while(aux->next != *L) {
            aux = aux->next;
        }
        aux->next = q;
    } else {
        printf("Erro na alocacao do no\n");
    }
}

void remover_inicio(lista **L) {
    lista *q = (*L)->next;

    if(!vazia(*L)) {
        (*L)->next = (*L)->next->next;
        freenode(q);
    } else {
        printf("Erro! - Lista vazia\n");
    }
}

void remover_fim(lista **L) {
    lista *q;
    lista *aux = (*L)->next;

    if(!vazia(*L)) {
        while(aux->next->next != *L) {
            aux = aux->next;
        }
        q = aux->next;
        aux->next = *L;
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

    inserir_fim(&L, 'a');
    inserir_fim(&L, 'b');
    inserir_fim(&L, 'c');
    inserir_fim(&L, 'd');
    inserir_inicio(&L, 'y');
    inserir_fim(&L, 'z');

    remover_inicio(&L);
    remover_fim(&L);

    exibir_lista(&L);
}
