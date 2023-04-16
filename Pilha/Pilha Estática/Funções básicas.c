#include <stdio.h>
#define TAM 5

typedef struct spilha {
    int itens[TAM];
    int topo;
}pilha;

void inicializar(pilha *P) {
    P->topo = -1;
}

int vazia(pilha *P) {
    if(P->topo == -1) {
        return 1;
    }
    return 0;
}

int cheia(pilha *P) {
    if(P->topo == TAM-1) {
        return 1;
    }
    return 0;
}

void push(pilha *P, int elem) {
    if(cheia(P)) {
        printf("\nErro! - Pilha cheia");
    } else {
        P->itens[P->topo+1] = elem;
        P->topo++;
    }

}

int pop(pilha *P) {
    int aux;

    if(vazia(P)) {
        printf("\nErro! - Pilha vazia");
        return -1;
    } else {
        aux = P->itens[P->topo];
        P->topo--;
        return aux;
    }
}

void exibir(pilha *P) {
    if(vazia(P)) {
        printf("\nErro! - Pilha vazia");
    }

    while(vazia(P) != 1) {
        printf("\n[%d]", pop(P));
    }
}

void main() {
    pilha P;

    inicializar(&P);
    push(&P, 1);
    push(&P, 2);
    push(&P, 3);
    push(&P, 4);
    pop(&P);

    exibir(&P);

}
