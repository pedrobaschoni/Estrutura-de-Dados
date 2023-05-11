#include <stdio.h>
#include <stdlib.h>

typedef struct sFila {
    char info;
    struct sFila *next;
}fila;

void inicializar(fila **inicio, fila **fim) {
    *inicio = NULL;
    *fim = NULL;
}

fila* getnode()  {
    return (fila*) malloc (sizeof(fila));
}

void freenode(fila *F) {
    free(F);
}

int vazia(fila *F) {
    if(F == NULL)
        return 1;
    return 0;
}

void enfileirar(fila **inicio, fila **fim, char elem) {
    fila *f;

    f = getnode();
    if(f != NULL) {
        f->info = elem;
        f->next = NULL;
        if(vazia(*inicio)) {
            *inicio = f;
            *fim = f;
        } else {
            (*fim)->next = f;
            *fim = f;
        }
    } else {
        printf("Erro na alocacao do no\n");
    }
}

char desenfileirar(fila **inicio, fila **fim) {
    char elem;
    fila *q = *inicio;

    if(vazia(*inicio)) {
        printf("Erro! - Fila vazia\n");
    } else {
        elem = (*inicio)->info;

        if(*inicio == *fim) {
            *inicio = NULL;
            *fim = NULL;
        } else {
            *inicio = (*inicio)->next;
        }
        freenode(q);
        return elem;
    }
}

void exibir_fila(fila **inicio, fila **fim) {
    if(vazia(*inicio)) {
        printf("Erro! - Fila vazia\n");
        return;
    }
    while(!vazia(*inicio)) {
        printf("[%c] ", desenfileirar(inicio, fim));
    }
}

void menu() {
        printf("\nMENU:\n");
        printf("1 - Adicionar elemento a fila\n");
        printf("2 - Remover elemento da fila\n");
        printf("3 - Exibir fila\n");
        printf("0 - Encerrar programa\n");
}

void main() {
    fila *inicio;
    fila *fim;
    int opcao;
    char elem;

    inicializar(&inicio, &fim);

    do{
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o elemento a ser adicionado: ");
                scanf(" %c", &elem);
                enfileirar(&inicio, &fim, elem);
                break;
            case 2:
                if(!vazia(inicio))
                    printf("Elemento removido: [%c]\n", desenfileirar(&inicio, &fim));
                else
                    printf("Erro! - Fila vazia\n");
                break;
            case 3:
                printf("Fila: ");
                exibir_fila(&inicio, &fim);
                printf("\n");
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        system("pause");
        system("cls");

    }while(opcao != 0);

}
