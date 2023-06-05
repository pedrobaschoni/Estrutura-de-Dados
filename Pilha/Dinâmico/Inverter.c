#include <stdio.h>
#include <stdlib.h>

typedef struct sPilha {
    char info;
    struct sPilha *next;
}pilha;

void inicializar(pilha **topo) {
    *topo = NULL;
}

pilha* getnode() {
    return (pilha*) malloc (sizeof(pilha));
}

void freenode(pilha *P) {
    free(P);
}

int vazia(pilha *P) {
    if(P == NULL)
        return 1;
    return 0;
}

void push(pilha **topo, char elem) {
    pilha *q;

    q = getnode();
    if(q != NULL) {
        q->info = elem;

        if(vazia(*topo))
            q->next = NULL;
        else
            q->next = *topo;
        *topo = q;
    } else {
        printf("Erro ao alocar o no\n");
    }
}

char pop(pilha **topo) {
    char elem;
    pilha *q = *topo;

    if(!vazia(*topo)) {
        elem = (*topo)->info;
        *topo = (*topo)->next;
        freenode(q);
        return elem;
    } else {
        printf("Erro! - Pilha vazia");
    }
}

void inverter_pilha(pilha **topo) {
    pilha *aux;

    inicializar(&aux);

    while(!vazia(*topo)) {
        push(&aux, pop(topo));
    }

    *topo = aux;
}

void exibir_pilha(pilha **topo) {
    if(vazia(*topo)) {
        printf("Erro! - Pilha vazia");
        return;
    }
    while(!vazia(*topo)) {
        printf("[%c]\n", pop(topo));
    }
}

void main() {
    pilha *topo;

    inicializar(&topo);

    push(&topo, 'a');
    push(&topo, 'b');
    push(&topo, 'c');
    push(&topo, 'd');
    push(&topo, 'e');

    inverter_pilha(&topo);

    exibir_pilha(&topo);
}
