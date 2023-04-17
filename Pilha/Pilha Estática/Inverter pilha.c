#include <stdio.h>
#define TAM 5

typedef struct sPilha {
    int itens[TAM];
    int topo;
}pilha;

typedef struct sLista {
    int itens[TAM];
    int n;
}lista;

void inicializar_pilha(pilha *P) {
    P->topo = -1;
}

void inicializar_lista(lista *L) {
    L->n = -1;
}

int pilha_vazia(pilha *P) {
    if(P->topo == -1) {
        return 1;
    }
    return 0;
}

int pilha_cheia(pilha *P) {
    if(P->topo == TAM-1) {
        return 1;
    }
    return 0;
}

int lista_vazia(lista *L) {
    if(L->n == -1) {
        return 1;
    }
    return 0;
}

int lista_cheia(lista *L) {
    if(L->n == TAM-1) {
        return 1;
    }
    return 0;
}

void push(pilha *P, int elem) {
    if(pilha_cheia(P)) {
        printf("\nErro! - Pilha cheia");
        return;
    }
    P->itens[P->topo+1] = elem;
    P->topo++;
}

void inserir_fim(lista *L, int elem) {
    if(lista_cheia(L)) {
        printf("\nErro! - Lista cheia");
        return;
    }
    L->itens[L->n+1] = elem;
    L->n++;
}

int pop(pilha *P) {
    int elem;

    if(pilha_vazia(P)) {
        printf("\nErro! - Pilha vaiza");
        return -1;
    }
    elem = P->itens[P->topo];
    P->topo--;
    return elem;
}

int remover_inicio(lista *L) {
    int elem, i;

    if(lista_vazia(L)) {
        printf("\nErro! - Lista vazia");
        return -1;
    }

    elem = L->itens[0];
    for(i = 0; i < L->n+1; i++) {
        L->itens[i] = L->itens[i+1];
    }
    L->n = L->n-1;
    return elem;
}

void inverter_lista(pilha *P) {
    lista L;
    int elem;

    inicializar_lista(&L);

    while(!pilha_vazia(P))
        inserir_fim(&L,pop(P));
    while(!lista_vazia(&L))
        push(P,remover_inicio(&L));

}

pilha inverter_pilha(pilha *P) {
    pilha auxP;

    inicializar_pilha(&auxP);

    if(pilha_vazia(P)) {
        printf("\nErro! - Pilha vazia");
        return;
    }

    while(!pilha_vazia(P)) {
        push(&auxP, pop(P));
    }
    return auxP;
}

void exibir(pilha *P) {
    int i;

    if(pilha_vazia(P)) {
        printf("\nErro! - Pilha vazia");
        return;
    }

    while(!pilha_vazia(P)) {
        printf("\n[%d]", pop(P));
    }
}

void exibir_lista(lista *L) {
    int i;

    for(i = 0; i <= L->n; i++) {
        printf("[%d] ", L->itens[i]);
    }
}

void main() {
    pilha P;
    inicializar_pilha(&P);

    push(&P, 1);
    push(&P, 2);
    push(&P, 3);
    push(&P, 4);

//    inverter_lista(&P);

    P = inverter_pilha(&P);

   exibir(&P);


}
