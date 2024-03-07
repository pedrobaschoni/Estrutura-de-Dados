#include <stdio.h>
#define TAM 10

typedef struct sDeque {
    char itens[TAM];
    int inicio, fim;
}deque;

void inicializar(deque *D) {
    D->inicio = TAM-1;
    D->fim = TAM-1;
}

int vazia(deque *D) {
    if(D->fim == D->inicio)
        return 1;
    return 0;
}

int cheia(deque *D) {
    if(D->fim == D->inicio)
        return 1;
    return 0;
}

void inserir_fim(deque *D, char elem) {
    if(D->fim == TAM-1) {
        D->fim = 0;
    } else {
        D->fim++;
    }
    if(cheia(D)) {
        printf("\nErro! - Deque cheia");
        D->fim--;
        if(D->fim == -1) {
            D->fim = TAM-1;
        }
        return;
    }
    D->itens[D->fim] = elem;
}

void inserir_inicio(deque *D, char elem) {
    if(D->inicio == 0) {
        D->inicio = TAM-1;
    } else {
        D->inicio--;
    }
    if(cheia(D)) {
        printf("\nErro! - Deque cheia");
        D->inicio = (D->inicio+1) % TAM;
        return;
    }
    D->itens[(D->inicio+1) % TAM] = elem;
}

char remover_fim(deque *D) {
    char elem;

    if(vazia(D)) {
        printf("\nErro! - Deque vazia");
        return -1;
    }
    elem = D->itens[D->fim];
    D->fim--;
    if(D->fim == -1) {
        D->fim = TAM-1;
    }
    return elem;
}

char remover_inicio(deque *D) {
    char elem;

    if(vazia(D)) {
        printf("\nErro! - Deque vazia");
        return -1;
    }
    D->inicio++;
    if(D->inicio == TAM) {
        D->inicio = 0;
    }
    elem = D->itens[D->inicio];
    return elem;
}

void exibir(deque *D) {
    if(vazia(D)) {
        printf("\nErro! - Deque vazia");
        return;
    }
    printf("\n");
    while(!vazia(D)) {
        printf("[%c] ", remover_inicio(D));
    }
}

void main() {
    deque D;

    inicializar(&D);
    inserir_fim(&D, 'a');
    inserir_fim(&D, 'b');
    inserir_fim(&D, 'c');
    inserir_fim(&D, 'd');
    inserir_inicio(&D, 'y');
    remover_fim(&D);
    remover_inicio(&D);

    exibir(&D);
}
