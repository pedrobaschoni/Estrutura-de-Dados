#include <stdio.h>
#define TAM 10

typedef struct sPilha {
    char itens[TAM];
    int topo;
}pilha;

void inicializar(pilha *P) {
    P->topo = -1;
}

int vazia(pilha *P) {
    if(P->topo == -1)
        return 1;
    return 0;
}

int cheia(pilha *P) {
    if(P->topo == TAM-1)
        return 1;
    return 0;
}

void push(pilha *P, char elem) {
    if(cheia(P)) {
        printf("\nErro! - Pilha cheia");
        return;
    }
    P->itens[P->topo+1] = elem;
    P->topo++;
}

char pop(pilha *P) {
    int elem;

    if(vazia(P)) {
        printf("\nErro! - Pilha vazia");
        return -1;
    }
    elem = P->itens[P->topo];
    P->topo--;
    return elem;
}

void copia_pilha(pilha P, pilha *auxP) {
    while(!vazia(&P)) {
        push(auxP, pop(&P));
    }
}

void palindroma(pilha *P, pilha *auxP) {
    int erro = 0;

    while(!vazia(P) && erro == 0) {
        if(pop(P) != pop(auxP)) {
            erro++;
        }
    }

    if(erro != 0) {
        printf("\nA palavra nao e palindroma");
    } else {
        printf("\nA palavra e palindroma");
    }
}

void exibir(pilha *P) {
    if(vazia(P)) {
        printf("\nErro! - Pilha vazia");
        return;
    }
    while(!vazia(P)) {
        printf("\n[%c]", pop(P));
    }
}

void main() {
    pilha P, auxP;

    inicializar(&P);
    inicializar(&auxP);

    push(&P, 'a');
    push(&P, 'r');
    push(&P, 'a');
    push(&P, 'r');
    push(&P, 'a');
    copia_pilha(P, &auxP);
    palindroma(&P, &auxP);
}
