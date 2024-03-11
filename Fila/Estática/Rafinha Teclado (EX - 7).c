#include <stdio.h>
#define TAM 100

typedef struct sCatalogo {
    char nome[30];
    char genero[30];
}catalogo;

typedef struct sFila {
    catalogo itens[TAM];
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

void enfileirar(fila *F, catalogo elem) {
    if(F->fim == TAM-1)
        F->fim = 0;
    else
        F->fim++;
    if(cheia(F)) {
        printf("\nErro! - Fila cheia");
        F->fim--;
        if(F->fim == -1)
            F->fim = TAM-1;
        return;
    }
    F->itens[F->fim] = elem;
}

catalogo desenfileirar(fila *F) {
    catalogo elem;

    if(vazia(F)) {
        printf("\nErro! - Fila cheia");
        return;
    }
    F->inicio++;
    if(F->inicio == TAM)
        F->inicio = 0;

    elem = F->itens[F->inicio];
    return elem;
}

void armazenar_musica(catalogo *elem) {
    fflush(stdin);
    printf("\nInforme o nome da musica: ");
    scanf("%[^\n]", &elem->nome);
    fflush(stdin);
    printf("\nInforme o genero da musica: ");
    scanf("%[^\n]", &elem->genero);
}

void exibir(fila *F) {
    catalogo elem;
    int ordem = 1;

    if(vazia(F)) {
        printf("\nErro! - Fila vazia");
        return;
    }
    while(!vazia(F)) {
        elem = desenfileirar(F);
        printf("\n[%d] Nome da musica: %s", ordem, elem.nome);
        printf("\n[%d] Genero da musica: %s", ordem, elem.genero);
        ordem++;
    }
}

void main() {
    fila F;
    catalogo elem;

    inicializar(&F);
    armazenar_musica(&elem);
    enfileirar(&F, elem);
    armazenar_musica(&elem);
    enfileirar(&F, elem);
    exibir(&F);
}
