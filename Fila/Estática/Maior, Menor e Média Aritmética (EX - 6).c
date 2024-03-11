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
    if(F->fim == F->inicio)
        return 1;
    return 0;
}

int cheia(fila *F) {
    if(F->fim == F->inicio)
        return 1;
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
        printf("\nErro! - Fila vazia");
        return -1;
    }
    F->inicio++;
    if(F->inicio == TAM) {
        F->inicio = 0;
    }
    elem = F->itens[F->inicio];
    return elem;
}

void maior_elemento(fila *F) {
    fila auxF;
    int elem, maior = 0;

    inicializar(&auxF);

    while(!vazia(F)) {
        elem = desenfileirar(F);

        if(elem > maior) {
            maior = elem;
        }
        enfileirar(&auxF, elem);
    }

    while(!vazia(&auxF)) {
        elem = desenfileirar(&auxF);
        enfileirar(F, elem);
    }

    printf("\nMaior elemento da fila: %d", maior);
}

void menor_elemento(fila *F) {
    fila auxF;
    int elem, menor;

    inicializar(&auxF);

    while(!vazia(F)) {
        elem = desenfileirar(F);

        if(elem < menor) {
            menor = elem;
        }
        enfileirar(&auxF, elem);
    }

    while(!vazia(&auxF)) {
        elem = desenfileirar(&auxF);
        enfileirar(F, elem);
    }

    printf("\nMenor elemento da fila: %d", menor);
}

void media(fila *F) {
    fila auxF;
    int elem, tam = 0;
    float media = 0;

    inicializar(&auxF);

    while(!vazia(F)) {
        elem = desenfileirar(F);

        media = media + elem;
        tam++;

        enfileirar(&auxF, elem);
    }

    media = media / tam;

    while(!vazia(&auxF)) {
        elem = desenfileirar(&auxF);
        enfileirar(F, elem);
    }

    printf("\nMedia aritmetica dos elementos da fila: %0.2f", media);
}

void exibir(fila *F) {
    if(vazia(F)) {
        printf("\nErro! - Fila vazia");
    }
    printf("\n\n");
    while(!vazia(F)) {
        printf("[%d] ", desenfileirar(F));
    }
}

void main() {
    fila F;

    inicializar(&F);
    enfileirar(&F, 3);
    enfileirar(&F, 2);
    enfileirar(&F, 10);
    enfileirar(&F, 7);
    enfileirar(&F, 5);

    maior_elemento(&F);
    menor_elemento(&F);
    media(&F);
    exibir(&F);
}
