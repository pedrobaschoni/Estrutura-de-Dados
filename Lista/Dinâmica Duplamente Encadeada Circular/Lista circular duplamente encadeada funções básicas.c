#include <stdio.h>
#include <stdlib.h>

typedef struct sLista {
    char info;
    struct sLista *next;
    struct sLista *back;
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

void inserir_inicio(lista **L, char elem) {
    lista *q;

    q = getnode();
    if(q != NULL) {
        q->info = elem;

        if(vazia(*L)) {
            q->next = q;
            q->back = q;
            *L = q;
        } else {
            q->next = *L;
            q->back = (*L)->back;
            (*L)->back->next = q;
            (*L)->back = q;
            *L = q;
        }
    } else
        printf("\nErro ao alocar o no");
}

void inserir_fim(lista **L, char elem) {
    lista* q;

    q = getnode();
    if(q != NULL) {
        q->info = elem;

        if(vazia(*L)) {
            q->next = q;
            q->back = q;
            *L = q;
        } else {
            q->next = *L;
            q->back = (*L)->back;
            (*L)->back->next = q;
            (*L)->back = q;
        }
    } else
        printf("\nErro ao alocar o no");
}

void remover_inicio(lista **L) {
    lista *q = *L;

    if(vazia(*L))
        printf("\nErro! - Lista vazia");
    else {
        if((*L)->next == *L) {
            freenode(q);
            *L = NULL;
        } else {
            (*L)->next->back = (*L)->back;0
            (*L)->back->next = (*L)->next;
            *L = (*L)->next;
            freenode(q);
        }
    }
}

void remover_fim(lista **L) {
    lista *q;

    if(vazia(*L))
        printf("\nErro - Lista vazia");
    else {
        if((*L)->next == *L) {
            freenode(q);
            *L = NULL;
        } else {
            (*L)->back->back->next = *L;
            (*L)->back = (*L)->back->back;
            freenode(q->back);
        }
    }
}

lista* pesquisa(lista *L, char elem) {
    lista *aux = L;

    if(!vazia(L)) {
        do {
            if(aux->info == elem)
                return aux;
            aux = aux->next;
        }while(aux != L);
    }
    printf("a");
    return NULL;
}

void remover_valor(lista **L, char elem) {
    lista *aux;
    lista *aux2 = *L;

    aux = pesquisa(*L, elem);

    if(aux != NULL) {
        if(aux == *L){
            remover_inicio(L);
        } else {
            while(aux2 != aux) {
                aux2 = aux2->next;
            }
            aux2->back->next = aux2->next;
            aux2->next->back = aux2->back;
            freenode(aux);
        }
    }
}

void exibir_lista(lista *L) {
    lista *aux = L;

    if(vazia(L)) {
        printf("\nErro! - Lista vazia");
        return;
    }
    printf("\n");
    do {
        printf("[%c] ", aux->info);
        aux = aux->next;
    }while(aux != L);
    printf("\n");
}

void main() {
    lista *L;

    inicializar(&L);

    inserir_fim(&L, 'a');
    inserir_fim(&L, 'b');
    inserir_fim(&L, 'c');
    inserir_fim(&L, 'd');
    inserir_inicio(&L, 'y');
    inserir_inicio(&L, 'z');
//    remover_inicio(&L);
//    remover_fim(&L);
    remover_valor(&L, 'z');

    exibir_lista(L);
}
