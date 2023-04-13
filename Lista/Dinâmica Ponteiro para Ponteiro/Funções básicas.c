#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sLista {
    char info;
    struct sLista *next;
}lista;

void inicializar(lista **L) {
    *L = NULL;
}

lista* getnode() {
    return (lista*) malloc (sizeof(lista));
}

void freenode(lista *L) {
    free(L);
}

int vazia(lista *L) {
    if(L == NULL)
        return 1;
    return 0;
}

void inserir_inicio(lista **L, char elem) {
    lista *q;

    q = getnode();
    if(q != NULL) {
        q->info = elem;
        q->next = *L;
        *L = q;
    } else {
        printf("\nErro! - Nao foi possivel alocar o no");
    }
}

void inserir_fim(lista **L, char elem) {
    lista *q;
    lista *aux;

    q = getnode();
    if(q != NULL) {
        q->info = elem;
        q->next = NULL;
    }
    if(vazia(*L)) {
        *L = q;
    } else {
        aux = *L;

        while(aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = q;
    }
}

lista* pesquisa_ordenada(lista **L, char elem) {
    lista *aux;

    aux = *L;
    if(!vazia(*L)) {
        while(aux != NULL) {
            if(aux->info > elem)
                return aux;
            aux = aux->next;
        }
    }
    return NULL;
}

void inserir_ordenado(lista **L, char elem) {
    lista *q;
    lista *aux;
    lista *aux2;

    aux = pesquisa_ordenada(L, elem);

    if(aux == NULL)
        inserir_fim(L, elem);
    else if(aux == *L)
        inserir_inicio(L, elem);
    else {
        q = getnode();
        if(q != NULL) {
            aux2 = *L;
            while(aux2->next != aux) {
                aux2 = aux2->next;
            }
            q->info = elem;
            q->next = aux;
            aux2->next = q;
        } else {
            printf("\nErro! - Nao foi possivel alocar o no");
        }
    }
}

void remover_inicio(lista **L) {
    lista *q = *L;

    if(vazia(*L)) {
        printf("\nErro! - Lista vazia");
        return;
    }
    *L = (*L)->next;
    free(q);
}

void remover_fim(lista **L) {
    lista *aux = *L;
    lista *q;

    if(vazia(*L)) {
        printf("\nErro! - Lista vazia");
        return;
    }

    if(aux->next == NULL) {
        remover_inicio;
    } else {
        while(aux->next->next != NULL) {
            aux = aux->next;
        }
        q = aux->next;
        aux->next = NULL;
        freenode(q);
    }
}

lista* pesquisa_remover(lista **L, char elem) {
    lista *aux = *L;

    if(!vazia(*L)) {
        while(aux != NULL) {
            if(aux->info == elem)
                return aux;
            aux = aux->next;
        }
    } else {
        printf("\nErro! - Lista vazia");
        return NULL;
    }
}

void remover_valor(lista **L, char elem) {
    lista *q;
    lista *aux = *L;

    q = pesquisa_remover(L, elem);
    if(q != NULL) {
        if(q->info == (*L)->info)
            remover_inicio(L);
        else {
            while(aux->next->info != q->info) {
                aux = aux->next;
            }
            aux->next = aux->next->next;
            freenode(q);
        }
    } else {
        printf("\nErro! - Elemento não encontrado");
    }
}

void exibir_lista(lista *L) {
    lista *aux;

    if(vazia(L)) {
        printf("\nErro! - Lista cheia");
        return;
    }
    aux = L;
    while(!vazia(aux)) {
        printf("[%c] ", aux->info);
        aux = aux->next;
    }
    printf("\n");
}

int menu() {
    int opcao;

    printf("\nMENU\n");
    printf("1 - Inserir no fim\n");
    printf("2 - Inserir no início\n");
    printf("3 - Inserir ordenado\n");
    printf("4 - Remover no início\n");
    printf("5 - Remover no fim\n");
    printf("6 - Remover por valor\n");
    printf("7 - Exibir lista\n");
    printf("0 - Sair\n");
    printf("Digite sua opção: ");

    scanf("%d", &opcao);

    return opcao;
}

void main() {
    lista *L;
    int opcao;
    char elem;

    inicializar(&L);

    do {
        opcao = menu();

        switch(opcao) {
            case 1:
                printf("Opção selecionada: Inserir no fim\n");
                __fpurge(stdin);
                printf("Informe a letra que deseja inserir: \n");
                scanf("%c", &elem);
                inserir_fim(&L, elem);
                break;
            case 2:
                printf("Opção selecionada: Inserir no início\n");
                __fpurge(stdin);
                printf("Informe a letra que deseja inserir: \n");
                scanf("%c", &elem);
                inserir_inicio(&L, elem);
                break;
            case 3:
                printf("Opção selecionada: Inserir ordenado\n");
                __fpurge(stdin);
                printf("Informe a letra que deseja inserir: \n");
                scanf("%c", &elem);
                inserir_ordenado(&L, elem);
                break;
            case 4:
                printf("Opção selecionada: Remover no início\n");
                remover_inicio(&L);
                break;
            case 5:
                printf("Opção selecionada: Remover no fim\n");
                remover_fim(&L);
                break;
            case 6:
                printf("Opção selecionada: Remover por valor\n");
                __fpurge(stdin);
                printf("Informe a letra que deseja remover: \n");
                scanf("%c", &elem);
                remover_valor(&L, elem);
                break;
            case 7:
                printf("Opção selecionada: Exibir lista\n");
                exibir_lista(L);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Digite novamente.\n");
                break;
        }

    }while(opcao != 0);
}
