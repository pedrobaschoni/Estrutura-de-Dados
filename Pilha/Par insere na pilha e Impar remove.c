#include <stdio.h>
#define TAM 5

typedef struct sPilha {
    int itens[TAM];
    int topo;
} pilha;

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
        return;
    }
    P->itens[P->topo+1] = elem;
    P->topo++;
}

int pop(pilha *P) {
    int elem;

    if(vazia(P)) {
        printf("\nErro! - Pilha vazia");
        return -1;
    }
    elem = P->itens[P->topo];
    P->topo--;
    return elem;
}

void par_impar(pilha *P) {
    int i, numero;

    for(i = 0; i < TAM; i++) {
        printf("\nInforme um numero: ");
        scanf("%d", &numero);

        if(numero %2 == 0) {
            push(P, numero);
        } else {
            pop(P);
        }
    }
}

void exibir(pilha *P) {
    int i;

    if(vazia(P)) {
        printf("\nErro! - Pilha vazia");
        return;
    }

    while(!vazia(P)) {
        printf("\n[%d]", pop(P));
    }
}

void main() {
    pilha P;

    inicializar(&P);
    par_impar(&P);
    exibir(&P);
}
