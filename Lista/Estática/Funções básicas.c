#include <stdio.h>
#define TAM 5

typedef struct sLista {
    char itens[TAM];
    int n;
}lista;

void inicializar(lista *L) {
    L->n = -1;
}

int vazia(lista *L) {
    if(L->n == -1)
        return 1;
    return 0;
}

int cheia(lista *L) {
    if(L->n == TAM-1)
        return 1;
    return 0;
}

void inserir_fim(lista *L, char elem) {
    if(cheia(L)) {
        printf("\nErro! - Lista cheia");
        return;
    }
    L->itens[L->n+1] = elem;
    L->n++;
}

void inserir_inicio(lista *L, char elem) {
    int i;

    if(cheia(L)) {
        printf("\nErro! - Lista cheia");
        return;
    }
    for(i = L->n; i >= 0; i--) {
        L->itens[i+1] = L->itens[i];
    }
    L->itens[0] = elem;
    L->n++;
}

void inserir_posicao(lista *L, int posicao, char elem) {
    int i;

    if(cheia(L)) {
        printf("\nErro! - Lista cheia");
        return;
    }
    if(posicao < 0 || posicao > L->n+1) {
        printf("\nErro! - Elemento fora dos limites");
        return;
    }
    for(i = L->n; i >= posicao; i--) {
        L->itens[i+1] = L->itens[i];
    }
    L->itens[posicao] = elem;
    L->n++;
}

void modificar(lista *L, int posicao, char elem) {
    if(posicao < 0 || posicao > L->n+1) {
        printf("\nErro! - Elemento fora dos limites");
        return;
    }
    L->itens[posicao] = elem;
}

int remover_inicio(lista *L) {
    char elem;
    int i;

    if(vazia(L)) {
        printf("\nErro! - Lista vazia");
        return -1;
    }
    elem = L->itens[0];

    for(i = 0; i <= L->n; i++) {
        L->itens[i] = L->itens[i+1];
    }
    L->n--;
    return elem;
}

int remover_fim(lista *L) {
    char elem;
    int i;

    if(vazia(L)) {
        printf("\nErro! - Lista vazia");
        return -1;
    }
    elem = L->itens[L->n];

    for(i = L->n; i <= 0; i--) {
        L->itens[i] = L->itens[i-1];
    }
    L->n--;
    return elem;
}

int remover_posicao(lista *L, int posicao) {
    char elem;
    int i;

    if(vazia(L)) {
        printf("\nErro! - Lista vazia");
        return -1;
    }

    if(posicao < 0 || posicao > L->n+1) {
        printf("\nErro! - Elemento fora dos limites");
    } else {
        elem = L->itens[posicao];

        for(i = posicao; i <= L->n; i++) {
            L->itens[i] = L->itens[i+1];
        }
        L->n--;
    }
    return elem;
}

int acessar(lista *L, int posicao) {
    if(posicao < 0 || posicao > L->n) {
        printf("\nErro! - Elemento fora dos limites");
    } else {
        return L->itens[posicao];
    }
    return -1;
}

void exibir_lista(lista *L) {
    int i;

    if(vazia(L)) {
        printf("\nErro! - Lista vazia");
        return;
    }
    printf("\n");
    for(i = 0; i <= L->n; i++) {
        printf("[%c] ", L->itens[i]);
    }
    printf("\n");

}

int menu() {
    int opcao;

    printf("\nMENU\n");
    printf("1 - Inserir no fim\n");
    printf("2 - Inserir no início\n");
    printf("3 - Inserir em uma posição específica\n");
    printf("4 - Remover no início\n");
    printf("5 - Remover no fim\n");
    printf("6 - Remover em uma posição específica\n");
    printf("7 - Modificar um elemento\n");
    printf("8 - Acessar um elemento\n");
    printf("9 - Exibir a lista\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    return opcao;
}

void main() {
    lista L;
    char elem, elemRemovido;
    int posicao, opcao;

    inicializar(&L);

    do {
        opcao = menu();
        switch(opcao) {
            case 0:
                printf("Encerrando o programa...\n");
                break;
            case 1:
                printf("\nInforme o valor que deseja inserir: ");
                __fpurge(stdin);
                scanf("%c", &elem);
                inserir_fim(&L, elem);
                break;
            case 2:
                printf("\nInforme o valor que deseja inserir: ");
                __fpurge(stdin);
                scanf("%c", &elem);
                inserir_inicio(&L, elem);
                break;
            case 3:
                printf("\nInforme o valor que deseja inserir: ");
                __fpurge(stdin);
                scanf("%c", &elem);
                printf("\nInforme a posicao que deseja inserir: ");
                scanf("%d", &posicao);
                inserir_posicao(&L, posicao, elem);
                break;
            case 4:
                elemRemovido = remover_inicio(&L);
                printf("\nElemento removido: [%c]", elemRemovido);
                break;
            case 5:
                elemRemovido = remover_fim(&L);
                printf("\nElemento removido: [%c]", elemRemovido);
                break;
            case 6:
                printf("\nInforme a posicao que deseja inserir: ");
                scanf("%d", &posicao);
                elemRemovido = remover_posicao(&L, posicao);
                printf("\nElemento removido: [%c]", elemRemovido);
                break;
            case 7:
                printf("\nInforme o elemento que deseja inserir: ");
                __fpurge(stdin);
                scanf("%c", &elem);
                printf("\nInforme a posicao que deseja modificar: ");
                scanf("%d", &posicao);
                modificar(&L, posicao, elem);
                break;
            case 8:
                printf("\nInforme a posicao que deseja acessar: ");
                scanf("%d", &posicao);
                elem = acessar(&L, posicao);
                printf("\nElemento na posicao acessada: [%c]", elem);
                break;
            case 9:
                exibir_lista(&L);
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while(opcao != 0);
}
