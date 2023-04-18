#include <stdio.h>
#include <string.h>
#define TAM 5

typedef struct sBarraca {
    char nome_barraca[50];
    char nome[30];
    char cpf[30];
    char aluguel;
    int produto;
}barraca;

typedef struct sLista {
    barraca itens[TAM];
    int n;
}lista;

void inicializar(lista *L) {
    L->n = -1;
}

int vazia(lista *L) {
    if(L->n == -1) {
        return 1;
    }
    return 0;
}

int cheia(lista *L) {
    if(L->n == TAM-1) {
        return 1;
    }
    return 0;
}

barraca ler_barraca(barraca elem) {
    __fpurge(stdin); //fflush(stdin);
    printf("\nInforme o nome da barraca: ");
    scanf("%[^\n]", elem.nome_barraca);
    __fpurge(stdin); //fflush(stdin);
    printf("Informe o nome do responsavel: ");
    scanf("%[^\n]", elem.nome);
    __fpurge(stdin); //fflush(stdin);
    printf("Informe o CPF: ");
    scanf("%[^\n]", elem.cpf);
    __fpurge(stdin); //fflush(stdin);
    printf("O aluguel foi pago: ");
    scanf("%[^\n]", &elem.aluguel);
    __fpurge(stdin); //fflush(stdin);
    printf("Informe o tipo de produto: ");
    scanf("%d", &elem.produto);

    return elem;
}

void inserir_fim(lista *L, barraca elem) {
    if(cheia(L)) {
        printf("\nErro! - Lista cheia");
    } else {
        strcpy(L->itens[L->n+1].nome_barraca, elem.nome_barraca);
        strcpy(L->itens[L->n+1].nome, elem.nome);
        strcpy(L->itens[L->n+1].cpf, elem.cpf);
        L->itens[L->n+1].aluguel = elem.aluguel;
        L->itens[L->n+1].produto = elem.produto;
        L->n++;
    }
}

void relatorio_nao_pagou(lista *L) {
    int i;

    if(vazia(L)) {
        printf("\nErro! - Lista vazia");
    } else {
        printf("\nBarracas que nao pagaram o aluguel:");
        for(i = 0; i <= L->n; i++) {
            if(L->itens[i].aluguel == 'n' || L->itens[i].aluguel == 'N') {
                printf("\n\nInformacoes da barraca[%d]: %s", i, L->itens[i].nome_barraca);
                printf("\nInformacoes da barraca[%d]: %s", i, L->itens[i].nome);
                printf("\nInformacoes da barraca[%d]: %s", i, L->itens[i].cpf);
                printf("\nInformacoes da barraca[%d]: %c", i, L->itens[i].aluguel);
                printf("\nInformacoes da barraca[%d]: %d", i, L->itens[i].produto);
            }
        }
        printf("\n");
    }
}

void barracas_ocupadas_livres(lista *L) {
    int i, livre = 0, ocupada = 0;
    printf("\n");
    for(i = 0; i <= L->n; i++) {
        printf("\nPosicoes ocupadas: [%d]", i);
        ocupada++;
    }

    printf("\n");
    for(i = L->n+1; i < TAM; i++) {
        printf("\nPosicoes livres: [%d]", i);
        livre++;
    }

    printf("\nTotal de barracas ocupadas [%d], e total de barracas livres [%d]", ocupada, livre);
    printf("\n");
}

void exibir(lista *L) {
    int i;

    if(vazia(L)) {
        printf("\nErro! - Lista vazia");
    } else {
        for(i = 0; i <= L->n; i++) {
            printf("\nInformacoes da barraca[%d]: %s", i, L->itens[i].nome_barraca);
            printf("\nInformacoes da barraca[%d]: %s", i, L->itens[i].nome);
            printf("\nInformacoes da barraca[%d]: %s", i, L->itens[i].cpf);
            printf("\nInformacoes da barraca[%d]: %c", i, L->itens[i].aluguel);
            printf("\nInformacoes da barraca[%d]: %d", i, L->itens[i].produto);
        }
    }
}

int menu() {
    int opcao;

    printf("\nMENU\n");
    printf("1 - Adicionar barraca\n");
    printf("2 - Relatorio de quem nao pagou\n");
    printf("3 - Relatorio de barracas livres e ocupadas\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    return opcao;
}

void main() {
    lista L;
    barraca elem;
    int opcao;

    inicializar(&L);

    do {
        opcao = menu();
        switch(opcao) {
            case 0:
                printf("Encerrando o programa...\n");
                break;
            case 1:
                elem = ler_barraca(elem);
                inserir_fim(&L, elem);
                break;
            case 2:
                relatorio_nao_pagou(&L);
                break;
            case 3:
                barracas_ocupadas_livres(&L);
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while(opcao != 0);

//    ler_barraca(&elem);
//    inserir_fim(&L, elem);
//
//    ler_barraca(&elem);
//    inserir_fim(&L, elem);
//
//    ler_barraca(&elem);
//    inserir_fim(&L, elem);
//
//    relatorio_nao_pagou(&L);
//    barracas_ocupadas_livres(&L);
}
