#include <stdio.h>
#include <stdlib.h>

typedef struct sLista {
    int info;
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

int vazia(lista *L) {
    if(L == NULL)
        return 1;
    return 0;
}

void inserir_inicio(lista **L, int elem) {
    lista *q;
    lista *aux = *L;

    q = getnode();
    if(q != NULL) {
        q->info = elem;

        if(vazia(*L)) {
            q->next = q;
            *L = q;
        } else {
            while(aux->next != *L) {
                aux = aux->next;
            }
            q->next = *L;
            aux->next = q;
            *L = q;
        }
    } else {
        printf("\nErro ao alocar o no");
    }
}

void inserir_fim(lista **L, int elem) {
    lista *q;
    lista *aux = *L;

    q = getnode();
    if(q != NULL) {
        q->info = elem;

        if(vazia(*L)) {
            q->next = q;
            *L = q;
        } else {
            while(aux->next != *L) {
                aux = aux->next;
            }
            aux->next = q;
            q->next = *L;
        }
    } else {
        printf("\nErro ao alocar o no");
    }
}

void remover_inicio(lista **L) {
    lista *q = *L;
    lista *aux = *L;

    if(vazia(*L))
        printf("\nErro! - Lista vazia");
    else {
        if((*L)->next == *L) {
            freenode(q);
            *L = NULL;
        } else {
            while(aux->next != *L) {
                aux = aux->next;
            }
            *L = (*L)->next;
            aux->next = *L;
            freenode(q);
        }
    }
}

void remover_fim(lista **L) {
    lista *q;
    lista *aux = *L;

    if(vazia(*L))
        printf("\nErro! - Lista vazia");
    else {
        if((*L)->next == *L) {
            freenode(*L);
            *L = NULL;
        } else {
            while(aux->next->next != *L) {
                aux = aux->next;
            }
            q = aux->next;
            aux->next = *L;
            freenode(q);
        }
    }
}

void exibir_lista(lista *L) {
    lista *aux = L;

    if(vazia(L)) {
        printf("\nErro! - Lista vazia");
        return;
    }
    do {
        printf("[%d] ", aux->info);
        aux = aux->next;
    }while(aux != L);
}

void main() {
    lista *L;

    inicializar(&L);

    inserir_inicio(&L, 1);
    inserir_inicio(&L, 2);
    inserir_inicio(&L, 3);
    inserir_inicio(&L, 4);
    inserir_fim(&L, 8);
    remover_inicio(&L);
    remover_fim(&L);

    exibir_lista(L);
}
