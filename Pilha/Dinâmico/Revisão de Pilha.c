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

void copia_pilha(pilha **topo, pilha **aux) {
    pilha *aux2;
    char elem;

    inicializar(&aux2);

    while(!vazia(*topo)) {
        elem = pop(topo);
        push(&aux2, elem);
        push(aux, elem);
    }

    while(!vazia(aux2)) {
        push(topo, pop(&aux2));
    }
}

void palindroma(pilha **topo, pilha **aux) {
    int erro = 0;

    while(!vazia(*topo) && erro == 0) {
        if(pop(topo) != pop(aux)) {
            erro++;
        }
    }

    if(erro != 0) {
        printf("A palavra nao e palindroma\n");
    } else {
        printf("A palavra e palindroma\n");
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

void inverter_base_topo(pilha **topo) {
    char base, max;
    pilha *aux;

    inicializar(&aux);

    max = pop(topo);

    while(!vazia(*topo)) {
        push(&aux, pop(topo));
    }

    base = pop(&aux);

    push(topo, max);

    while(!vazia(aux)) {
        push(topo, pop(&aux));
    }

    push(topo, base);
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
    pilha *aux;

    inicializar(&topo);
    inicializar(&aux);

    push(&topo, 'a');
    push(&topo, 'b');
    push(&topo, 'c');
    push(&topo, 'd');
    push(&topo, 'e');

//    copia_pilha(&topo, &aux);
//    palindroma(&topo, &aux);

//    inverter_pilha(&topo);

    inverter_base_topo(&topo);

    exibir_pilha(&topo);
}
