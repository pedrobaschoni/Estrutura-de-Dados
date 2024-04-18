#include <stdio.h>
#include <stdlib.h>

typedef struct sDeque {
    char info;
    struct sDeque *next;
    struct sDeque *back;
}deque;

void inicializar(deque **inicio, deque **fim) {
    *inicio = NULL;
    *fim = NULL;
}

deque* getnode() {
    return (deque*) malloc (sizeof(deque));
}

void freenode(deque *D) {
    free(D);
}

int vazia(deque *D) {
    if(D == NULL)
        return 1;
    return 0;
}

void inserir_inicio(deque **inicio, deque **fim, char elem) {
    deque *q;

    q = getnode();
    if(q != NULL) {
        q->info = elem;
        q->back = NULL;
        if(vazia(*inicio)) {
            q->next = NULL;
            *fim = q;
        } else {
            (*inicio)->back = q;
            q->next = *inicio;
        }
        *inicio = q;
    } else {
        printf("Erro na alocacao de no\n");
    }
}

void inserir_fim(deque **inicio, deque **fim, char elem) {
    deque *q;
    deque *aux = *inicio;

    q = getnode();
    if(q != NULL) {
        q->info = elem;
        q->next = NULL;

        if(vazia(*inicio)) {
            q->back = NULL;
            *inicio = q;
            *fim = q;
        } else {
            (*fim)->next = q;
            q->back = *fim;
            *fim = q;
        }
    } else {
        printf("Erro na alocao do no");
    }
}

char remover_inicio(deque **inicio, deque **fim) {
    char elem;
    deque *q;

    if(vazia(*inicio)) {
        printf("Erro! - Deque vazio");
    } else {
        elem = (*inicio)->info;
        q = *inicio;

        if(*inicio == *fim) {
            *inicio = NULL;
            *fim = NULL;
        } else {
            *inicio = (*inicio)->next;
            (*inicio)->back = NULL;
        }
        free(q);
        return elem;
    }
}

char remover_fim(deque **inicio, deque **fim) {
    char elem;
    deque *q;

    if(vazia(*inicio)) {
        printf("Erro! - Deque vazio");
    } else {
        elem = (*fim)->info;
        q = *fim;

        if(*inicio == *fim) {
            *inicio = NULL;
            *fim = NULL;
        } else {
            *fim = (*fim)->back;
            (*fim)->next = NULL;
        }
        free(q);
        return elem;
    }
}

void exibir_deque(deque **inicio, deque **fim) {
    if(vazia(*inicio)) {
        printf("Erro! - Deque vazio");
        return;
    }

    do{
        printf("[%c] ", remover_inicio(inicio, fim));
    }while(!vazia(*inicio));
}

void main() {
    deque *inicio;
    deque *fim;

    inicializar(&inicio, &fim);

    inserir_inicio(&inicio, &fim, 'a');
    inserir_inicio(&inicio, &fim, 'b');
    inserir_inicio(&inicio, &fim, 'c');
    inserir_inicio(&inicio, &fim, 'd');
    inserir_fim(&inicio, &fim, 'y');
    inserir_fim(&inicio, &fim, 'z');
    inserir_fim(&inicio, &fim, 'w');

    remover_inicio(&inicio, &fim);
    remover_fim(&inicio, &fim);

    exibir_deque(&inicio, &fim);
}
