#include <stdio.h>
#define TAM 6

typedef struct sFila {
    int itens[TAM];
    int inicio, fim;
}fila;

void inicializar(fila *F) {
    F->inicio = TAM-1;
    F->fim = TAM-1;
}

int vazia(fila *F) {
    if(F->fim == F->inicio) {
        return 1;
    }
    return 0;
}

int cheia(fila *F) {
    if(F->fim == F->inicio) {
        return 1;
    }
    return 0;
}

void enfileirar(fila *F, int elem) {
    if(F->fim == TAM-1) {
        F->fim = 0;
    } else {
        F->fim++;
    }
    if(cheia(F)) {
        printf("\nErro! - Fila cheia");
        F->fim--;

        if(F->fim == -1) {
            F->fim = TAM-1;
        }
        return;
    }
    F->itens[F->fim] = elem;
}

int desenfileirar(fila *F) {
    int elem;

    if(!vazia(F)) {
        if(F->inicio == TAM-1) {
            F->inicio = 0;
        } else {
            F->inicio++;
        }
        elem = F->itens[F->inicio];
    } else {
        printf("\nErro! - Fila vazia");
    }
    return elem;
}

void exibir(fila *F) {
    if(vazia(F)) {
        printf("\nErro! - Fila vazia");
    }

    while(!vazia(F)) {
        printf("[%d] ", desenfileirar(F));
    }
}

void main() {
    fila F;

    inicializar(&F);

    enfileirar(&F, 1);
    enfileirar(&F, 2);
    enfileirar(&F, 3);
    enfileirar(&F, 4);
    enfileirar(&F, 5);
    desenfileirar(&F);
    desenfileirar(&F);
    exibir(&F);
}
