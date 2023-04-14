#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    char info;
    struct cell *next;
}lista;

lista* inicializar(lista *L) {
    L = NULL;
    return L;
}

lista* getnode() {
    return (lista*) malloc(sizeof(lista));
}

void freenode(lista *L) {
    free(L);
}

int vazia(lista *L) {
    if(L == NULL)
        return 1;
    return 0;
}

lista* inserir_inicio(lista *L, char elem) {
    lista *q;

    q = getnode();
    if(q == NULL) {
        printf("Erro! - Nao alocxado");
        return L;
    }
    q->info = elem;
    q->next = L;
    L = q;
    return L;
}

lista* inserir_fim(lista *L, char elem) {
    lista *q, *aux;
    q = getnode();
    if(q == NULL) {
        printf("Erro! - Nao alocxado");
        return L;
    }
    q->info = elem;
    q->next = NULL;

    aux = L;

    if(vazia(L))
        L = q;
    else {
        while(aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = q;
    }
    return L;
}

lista* pesquisa_ordenada(lista *L, char elem) {
    lista *aux;

    aux = L;
    if(!vazia(L)) {
        while(aux != NULL) {
            if(aux->info > elem)
                return aux;
            aux = aux->next;
        }
    }
    return NULL;
}

lista* inserir_ordenado(lista *L, char elem) {
    lista *q;
    lista *aux;
    lista *aux2;

    aux = pesquisa_ordenada(L, elem);

    if(aux == NULL)
        inserir_fim(L, elem);
    else if(aux == L)
        inserir_inicio(L, elem);
    else {
        q = getnode();
        if(q != NULL) {
            aux2 = L;
            while(aux2->next->info != aux->info) {
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

lista* remover_inicio(lista *L) {
    lista *aux;
    aux = L;

    if(vazia(L)) {
        printf("Erro! - Lista vazia");
        return NULL;
    }

    L = L->next;
    freenode(aux);
    return L;
}

lista* remover_fim(lista *L) {
    lista *aux;
    aux = L;

    if(vazia(L)) {
        printf("Erro! - Lista vazia");
        return NULL;
    }

    if(vazia(aux->next)) {
        freenode(aux);
        L = NULL;
    } else {
        while(!vazia(aux->next->next)) {
            aux = aux->next;
        }
        freenode(aux->next);
        aux->next = NULL;
    }
    return L;
}

lista* pesquisa(lista *L, char elem) {
    lista *q;

    if(vazia(L)) {
        printf("\nErro! - Lista vazia");
    } else {
        q = L;
        while(!vazia(q)) {
        if(q->info == elem)
            return q;
        q = q->next;
        }
    }
    return NULL;
}

lista* remover_valor(lista *L, char elem) {
    lista *aux;
    lista *q;

    if((q = pesquisa(L, elem)) != NULL) {
        aux = L;
        if(aux == q)
            remover_inicio(L);
        else {
            while(aux->next != q) {
                aux = aux->next;
            }
            aux->next = q->next;
            freenode(q);
        }
    }
    return L;
}

void exibir_lista(lista *L) {
    lista *aux;
    aux = L;

    if(vazia(L)) {
        printf("Erro! - Lista vazia");
        return;
    }

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

    L = inicializar(L);

    do {
        opcao = menu();

        switch(opcao) {
            case 1:
                printf("Opção selecionada: Inserir no fim\n");
                __fpurge(stdin);
                printf("Informe a letra que deseja inserir: \n");
                scanf("%c", &elem);
                L = inserir_fim(L, elem);
                break;
            case 2:
                printf("Opção selecionada: Inserir no início\n");
                __fpurge(stdin);
                printf("Informe a letra que deseja inserir: \n");
                scanf("%c", &elem);
                L = inserir_inicio(L, elem);
                break;
            case 3:
                printf("Opção selecionada: Inserir ordenado\n");
                __fpurge(stdin);
                printf("Informe a letra que deseja inserir: \n");
                scanf("%c", &elem);
                L = inserir_ordenado(L, elem);
                break;
            case 4:
                printf("Opção selecionada: Remover no início\n");
                L = remover_inicio(L);
                break;
            case 5:
                printf("Opção selecionada: Remover no fim\n");
                L = remover_fim(L);
                break;
            case 6:
                printf("Opção selecionada: Remover por valor\n");
                __fpurge(stdin);
                printf("Informe a letra que deseja remover: \n");
                scanf("%c", &elem);
                L = remover_valor(L, elem);
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
