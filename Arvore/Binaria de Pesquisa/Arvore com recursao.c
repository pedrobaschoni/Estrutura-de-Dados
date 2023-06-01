#include <stdio.h>
#include <stdlib.h>

typedef struct sNo {
    int info;
    struct sNo *esq;
    struct sNo *dir;
}no;

void inicializar(no **raiz) {
    *raiz = NULL;
}

no* getnode() {
    return (no*) malloc (sizeof(no));
}

int vazia(no *raiz) {
    if(raiz == NULL)
        return 1;
    return 0;
}

void inserir(no **raiz, int elem) {
    no *aux = *raiz;
    no *aux2 = NULL;
    no *novo;

    novo = getnode();

    if(novo == NULL) {
        printf("Erro ao alocar o no");
        return;
    }

    novo->info = elem;
    novo->esq = NULL;
    novo->dir = NULL;

    while(aux != NULL) {
        aux2 = aux;
        if(elem < aux->info)
            aux = aux->esq;
        else
            aux = aux->dir;
    }

    if(aux2 == NULL)
        *raiz = novo;
    else {
        if(elem < aux2->info)
            (aux2)->esq = novo;
        else
            (aux2)->dir = novo;
    }
}

void visita(no *raiz) {
    printf("[%d] ", raiz->info);
}

void pre_ordem(no *raiz) {
    if(raiz != NULL) {
        visita(raiz);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void em_ordem(no *raiz) {
    if(raiz != NULL) {
        em_ordem(raiz->esq);
        visita(raiz);
        em_ordem(raiz->dir);
    }
}

void pos_ordem(no *raiz) {
    if(raiz != NULL) {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        visita(raiz);
    }
}

int quantidade_no_arv(no *raiz) {
    if(raiz == NULL)
        return 0;
    else
        return 1 + quantidade_no_arv(raiz->esq) + quantidade_no_arv(raiz->dir);
}

int altura_arv(no *raiz) {
    int esq;
    int dir;

    if(raiz == NULL)
        return 0;
    else {
        esq = altura_arv(raiz->esq);
        dir = altura_arv(raiz->dir);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

int menu() {
    printf("\n\n----PROGRAMA DESENVOLVIDO UTILIZANDO UMA ARVORE BINARIA DE PESQUISA----\n\n\n");
    printf("---------------MENU----------------\n");
    printf("1 - Inserir elemento na arvore\n");
    printf("2 - Exibir quantidade de nos da arvore\n");
    printf("3 - Exibir altura da arvore\n");
    printf("4 - Exibir elementos da arvore PRE-ORDER\n");
    printf("5 - Exibir elementos da arvore IN-ORDER\n");
    printf("6 - Exibir elementos da arvore POS-ORDER\n");
    printf("0 - Sair\n");
    printf("----------------------------------");
}

void main() {
    no *raiz;
    int elem, opcao;

    inicializar(&raiz);

    do {
        menu();
        printf("\n\nInforme a opcao desejada: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nInforme o valor que deseja inserir na arvore: ");
                scanf("%d", &elem);
                printf("\n\n");
                inserir(&raiz, elem);
                break;

            case 2:
                printf("\nQuantidade de nos da Arvore: %d\n\n", quantidade_no_arv(raiz));
                break;

            case 3:
                printf("\nAltura da Arvore: %d\n\n", altura_arv(raiz));
                break;

            case 4:
                printf("\n");
                pre_ordem(raiz);
                printf("\n\n");
                break;

            case 5:
                printf("\n");
                em_ordem(raiz);
                printf("\n\n");
                break;

            case 6:
                printf("\n");
                pos_ordem(raiz);
                printf("\n\n");
                break;

            case 0:
                printf("\nSaindo...\n\n");
                break;

            default:
                printf("\nOpcao invalida");
                break;
        }
        system("pause");
        system("cls");

    }while(opcao != 0);
}
