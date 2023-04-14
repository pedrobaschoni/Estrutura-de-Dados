#include <stdio.h>
#include <stdlib.h>

typedef struct sLista {
    char info;
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

void inserir_inicio(lista **L, char elem) {
    lista *q;

    q = getnode();
    if(q != NULL) {
        q->info = elem;
        q->next = *L;
        *L = q;
    } else {
        printf("\nErro! - Nao foi possivel alocar o no");
    }
}

void inserir_fim(lista **L, char elem) {
    lista *q;
    lista *aux;

    q = getnode();
    if(q != NULL) {
        q->info = elem;
        q->next = NULL;

        if(vazia(L))
            *L = q;
        else {
            aux = *L;
            while(aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = q;
        }
    } else {
        printf("\nErro! - Nao foi possivel alocar o no");
    }
}

lista* pesquisa_decrescente(lista **L, char elem) {
    lista *aux;

    if(!vazia(L)) {
        aux = *L;
        while(aux != NULL) {
            if(aux->info < elem)
                return aux;
            aux = aux->next;
        }
    } else {
        return NULL;
    }
}

void inserir_decrescente(lista **L, char elem) {
    lista *q;
    lista *aux;
    lista *aux2 = *L;

    aux = pesquisa_decrescente(L, elem);

    if(aux == NULL)
        inserir_fim(L, elem);
    else if(aux == *L)
        inserir_inicio(L, elem);
    else {
        q = getnode();
        if(q != NULL) {
            q->info = elem;
            while(aux2->next != aux) {
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
        printf("[%c] ", aux->info);
        aux = aux->next;
    }
}

void main() {
    lista *L;

    inicializar(&L);

    inserir_decrescente(&L, 'r');
    inserir_decrescente(&L, 'a');
    inserir_decrescente(&L, 'p');
    inserir_decrescente(&L, 'j');
    exibir_lista(L);
}
