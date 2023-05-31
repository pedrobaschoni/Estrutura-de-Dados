#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sTv {
    char canais[10];
    int numero_canal;
}tv;

typedef struct sLista {
    tv info;
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

void inserir_fim(lista **L, tv elem) {
    lista *q;
    lista *aux = *L;

    q = getnode();
    if(q != NULL) {
        q->info.numero_canal = elem.numero_canal;
        strcpy(q->info.canais, elem.canais);

        if(vazia(*L)) {
            q->next = q;
            *L = q;
        } else {
            while(aux->next != *L) {
                aux = aux->next;
            }
            aux->next = q;
            q->next = *L;
        }
    } else {
        printf("\nErro ao alocar o no");
    }
}

tv ler_canais(tv elem) {
    printf("\nInforme o numero do canal: ");
    scanf("%d", &elem.numero_canal);
    __fpurge(stdin);
    printf("\nInforme o nome do canal: ");
    scanf("%[^\n]", elem.canais);

    return elem;
}

void passar_canal(lista **L) {
    printf("\nCanal atual: [%d - %s]", (*L)->info.numero_canal, (*L)->info.canais);
    printf("\n");
    *L = (*L)->next;
}

void exibir_lista(lista *L) {
    lista *aux = L;

    if(vazia(L)) {
        printf("\nErro! - Lista vazia");
        return;
    }
    printf("\n");
    do {
        printf("[%d - ", aux->info.numero_canal);
        printf("%s] ", aux->info.canais);
        aux = aux->next;
    }while(aux != L);
    printf("\n");
}

int menu() {
    int opcao;

    printf("\nMENU\n");
    printf("1 - Cadastrar canal\n");
    printf("2 - Exibir canais\n");
    printf("3 - Passar canal\n");
    printf("0 - Deligar Tv\n");
    printf("\nInforme a opcao desejada: ");
    scanf("%d", &opcao);

    return opcao;
}

void main() {
    lista *L;
    lista *aux = L;
    tv elem;
    int opcao;

    inicializar(&L);

    do {
        opcao = menu();
        switch(opcao) {
            case 0:
                printf("\nDesligando Tv...");
                printf("\n");
                break;
            case 1:
                elem = ler_canais(elem);
                inserir_fim(&L, elem);
                aux = L;
                break;
            case 2:
                exibir_lista(L);
                break;
            case 3:
                passar_canal(&aux);
                break;
            default:
                printf("\nOpcao invalida");
        }
    }while(opcao != 0);

}
