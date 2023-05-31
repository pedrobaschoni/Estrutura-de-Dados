#include <stdio.h>
#include <stdlib.h>

typedef struct sLista {
    char info;
    struct sLista *next;
}lista;

void inicializar(lista **L) {
    *L = getnode();
    (*L)->info = -1;
    (*L)->next = NULL;
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

void inserir_inicio(lista **L, char elem) {
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
        printf("\nErro na alocacao do no");
    }
}

void exibir_lista(lista *L) {
    lista *aux = L;

    if(vazia(L)) {
        printf("\nErro! - Lista vazia");
        return;
    }
    do {
        printf("[%c] ", aux->info);
        aux = aux->next;
    }while(aux != L);
}

void main() {
    lista *L,*no;
    L->next = no;
    inicializar(&L);

    inserir_inicio(&L, 'a');
    inserir_inicio(&L, 'b');
    inserir_inicio(&L, 'c');
    inserir_inicio(&L, 'd');

    exibir_lista(L);
}
