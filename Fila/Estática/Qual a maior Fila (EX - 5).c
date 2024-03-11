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

    if(vazia(F)) {
        printf("\nErro! - Fila cheia");
        return -1;
    }
    F->inicio++;
    if(F->inicio == TAM) {
        F->inicio = 0;
    }
    elem = F->itens[F->inicio];
    return elem;

}

void comparar_tamanho(fila *F1, fila *F2) {
    int elem, tam1 = 0, tam2 = 0;
    fila F3;

    inicializar(&F3);

    while(!vazia(F1)) {
        elem = desenfileirar(F1);
        tam1++;
        enfileirar(&F3, elem);
    }

    while(!vazia(&F3)) {
        elem = desenfileirar(&F3);
        enfileirar(F1, elem);
    }

    while(!vazia(F2)) {
        elem = desenfileirar(F2);
        tam2++;
        enfileirar(&F3, elem);
    }

    while(!vazia(&F3)) {
        elem = desenfileirar(&F3);
        enfileirar(F2, elem);
    }

    printf("\nTamanho da fila [1]: %d", tam1);
    printf("\nTamanho da fila [2]: %d", tam2);

    if(tam1 > tam2) {
        printf("\nFila [1] e maior que a fila [2]");
    } else if(tam2 > tam1) {
        printf("\nFila [2] e maior que a fila [1]");
    } else {
        printf("\nFila [1] e fila [2] possuem o mesmo tamanho");
    }

}

void exibir(fila *F) {
    if(vazia(F)) {
        printf("\nErro! - Fila vazia");
        return;
    }

    printf("\n");
    while(!vazia(F)) {
        printf("[%d] ", desenfileirar(F));
    }
}

void main() {
    fila F1, F2;

    inicializar(&F1);
    inicializar(&F2);

    enfileirar(&F1, 1);
    enfileirar(&F1, 2);
    enfileirar(&F1, 3);
    enfileirar(&F1, 4);
    enfileirar(&F1, 5);

    enfileirar(&F2, 3);
    enfileirar(&F2, 2);
    enfileirar(&F2, 1);

    comparar_tamanho(&F1, &F2);
    exibir(&F1);
    exibir(&F2);
}
