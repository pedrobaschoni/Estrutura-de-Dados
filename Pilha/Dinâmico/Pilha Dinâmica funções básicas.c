#include <stdio.h>
#include <stdlib.h>

typedef struct sPilha {
    char info;
    struct sPilha *next;
}pilha;

void inicializar(pilha **topo) {
    *topo = NULL;
}

pilha* getnode()  {
    return (pilha*) malloc (sizeof(pilha));
}

void freenode(pilha *topo) {
    free(topo);
}

int vazia(pilha *topo) {
    if(topo == NULL)
        return 1;
    return 0;
}

void push(pilha **topo, char elem) {
    pilha *p;

    p = getnode();
    if(p != NULL) {
        p->info = elem;
        p->next = *topo;
        *topo = p;
    } else {
        printf("Erro ao alocar o no\n");
    }
}

char pop(pilha **topo) {
    char elem;
    pilha *p = *topo;

    if(vazia(*topo)) {
        printf("Erro! - Pilha vazia\n");
    } else {
        *topo = (*topo)->next;
        elem = p->info;
        freenode(p);
        return elem;
    }
}

void exibir_pilha(pilha **topo) {
    if(vazia(*topo)) {
        printf("Erro - Pilha vazia\n");
        return;
    }
    while(!vazia(*topo)) {
        printf("[%c]\n", pop(topo));
    }
}

void menu() {
        printf("\nMENU:\n");
        printf("1 - Adicionar elemento a pilha\n");
        printf("2 - Remover elemento da pilha\n");
        printf("3 - Exibir pilha\n");
        printf("0 - Encerrar programa\n");
}

void main() {
    pilha *topo;
    int opcao;
    char elem;

    inicializar(&topo);

    do{
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o elemento a ser adicionado: ");
                scanf(" %c", &elem);
                push(&topo, elem);
                break;
            case 2:
                if(!vazia(topo))
                    printf("Elemento removido: [%c]\n", pop(&topo));
                else
                    printf("Erro! - Pilha vazia\n");
                break;
            case 3:
                printf("Pilha: \n");
                exibir_pilha(&topo);
                printf("\n");
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
//        system("pause");
//        system("cls");

    }while(opcao != 0);
}
