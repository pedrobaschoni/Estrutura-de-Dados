#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct sCarro{
    char nome[10];
    char placa[10];
}carro;

typedef struct sCelula {
    carro info;
    struct sCelula *next;
}celula;

void inicializar(celula **c) {
    *c = NULL;
}

void inicializarFila(celula **inicio, celula **fim) {
    *inicio = NULL;
    *fim = NULL;
}

celula* getnode()  {
    return (celula*) malloc (sizeof(celula));
}

void freenode(celula *c) {
    free(c);
}

int vaziacelula(celula *c) {
    if(c == NULL)
        return 1;
    return 0;
}

void push(celula **topo, carro elem) {
    celula *p;

    p = getnode();
    if(p != NULL) {
        strcpy(p->info.nome, elem.nome);
        strcpy(p->info.placa, elem.placa);
        p->next = *topo;
        (*topo) = p;
    } else
        printf("Erro ao alocar o no\n");
}

void enfileirar(celula **inicio, celula **fim, carro elem) {
    celula *f;

    f = getnode();
    if(f != NULL) {
        strcpy(f->info.nome, elem.nome);
        strcpy(f->info.placa, elem.placa);
        f->next = NULL;
        if(vaziacelula(*inicio)) {
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

void inserir_inicio(celula **L, carro elem) {
    celula *q;

    q = getnode();
    if(q != NULL) {
        strcpy(q->info.nome, elem.nome);
        strcpy(q->info.placa, elem.placa);

        q->next = *L;
        *L = q;
    } else {
        printf("\nErro! - Nao foi possivel alocar o no");
    }
}

void inserir_fim(celula **L, carro elem) {
    celula *q;
    celula *aux = *L;

    q = getnode();
    if(q != NULL) {
        strcpy(q->info.nome, elem.nome);
        strcpy(q->info.placa, elem.placa);
        q->next = NULL;

        if(vaziacelula(*L))
            *L = q;
        else {
            while(aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = q;
        }
    } else {
        printf("\nErro! - Nao foi possivel alocar o no");
    }
}

celula* pesquisar_placa(celula **L, carro elem) {
    celula *aux = *L;

    if(!vaziacelula(*L)) {
        while(aux != NULL) {
            if(strcmp(elem.placa, aux->info.placa) < 0) {
                return aux;
            }
            aux = aux->next;
        }
    }
    return NULL;
}

void inserir_ordenado(celula **L, carro elem) {
     celula *q;
     celula *aux;
     celula *aux2 = *L;

     aux = pesquisar_placa(L, elem);

     if(aux == NULL)
        inserir_fim(L, elem);
     else if(aux == *L)
        inserir_inicio(L, elem);
     else {
        q = getnode();
        if(q != NULL) {
            strcpy(q->info.nome, elem.nome);
            strcpy(q->info.placa, elem.placa);
            while(strcmp(aux2->next->info.placa, aux->info.placa) != 0) {
                aux2 = aux2->next;
            }
            q->next = aux;
            aux2->next = q;
        } else {
            printf("\nErro! - Nao foi possivel alocar o no");
        }
     }
}

carro pop(celula **topo) {
    carro elem;

    celula *aux = *topo;

    if(vaziacelula(*topo))
        printf("Erro! - celula vazia\n");
    else {
        (*topo) = (*topo)->next;
        strcpy(elem.nome, aux->info.nome);
        strcpy(elem.placa, aux->info.placa);
        freenode(aux);
        return elem;
    }
}

carro desenfileirar(celula **inicio, celula **fim) {
    carro elem;
    celula *q = *inicio;

    if(vaziacelula(*inicio)) {
        printf("Erro! - Fila vazia\n");
    } else {
        strcpy(elem.nome, (*inicio)->info.nome);
        strcpy(elem.placa, (*inicio)->info.placa);

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

carro removerCarroPilha(celula **topo, carro removerPlaca) {
    celula *aux;
    carro elem;

    inicializar(&aux);

    if(!vaziacelula(*topo)) {
        while(!vaziacelula(*topo) && (strcmp((*topo)->info.placa, removerPlaca.placa) != 0)) {
            push(&aux, pop(topo));
        }
        elem = pop(topo);

        if(strcmp(elem.placa, removerPlaca.placa) != 0)
            strcpy(elem.placa, "nao");

        while(aux != NULL) {
            push(topo, pop(&aux));
        }
    } else {
        printf("Vazia\n");
        strcpy(elem.placa, "erro");
    }

    return elem;
}

carro removerCarroFila(celula **inicio, celula **fim, carro removerPlaca) {
    carro elem, aux;

    if((!vaziacelula(*inicio))) {
        aux = desenfileirar(inicio, fim);
        elem = aux;
        if(strcmp(aux.placa, removerPlaca.placa) != 0) {
            enfileirar(inicio, fim, aux);
            while((strcmp((*inicio)->info.placa, removerPlaca.placa) != 0) && (strcmp((*inicio)->info.placa, aux.placa) != 0)) {
                elem = desenfileirar(inicio, fim);
                enfileirar(inicio, fim, elem);
            }

            if(strcmp((*inicio)->info.placa, removerPlaca.placa) == 0)
                elem = desenfileirar(inicio, fim);
            else
                strcpy(elem.placa, "nao");
        }

    } else {
        printf("Vazia\n");
        strcpy(elem.placa, "erro");
    }

    return elem;

}

celula* pesquisa_remover(celula **L, carro removerPlaca) {
    celula *aux = *L;

    if(!vaziacelula(*L)) {
        while(aux != NULL) {
            if(strcmp(aux->info.placa, removerPlaca.placa) == 0)
                return aux;
            aux = aux->next;
        }
    } else {
        printf("\nErro! - Lista vazia");
        return NULL;
    }
}

carro removerCarroLista(celula **L, carro removerPlaca) {
    celula *q;
    celula *aux = *L;
    carro elem;

    q = pesquisa_remover(L, removerPlaca);
    if(q != NULL) {
        if(strcmp(q->info.placa, (*L)->info.placa) == 0) {
            strcpy(elem.nome, (*L)->info.nome);
            strcpy(elem.placa, (*L)->info.placa);
            *L = (*L)->next;
            freenode(aux);
        }
        else {
            while(aux->next->info.placa != q->info.placa) {
                aux = aux->next;
            }
            elem = aux->next->info;
            aux->next = aux->next->next;
            freenode(q);
        }
        return elem;
    } else {
        printf("\nErro! - Elemento não encontrado");
        strcpy(elem.placa, "nao");
        return elem;
    }
}


void exibir_celula_pilha(celula **topo) {
    carro elem;
    celula *aux = *topo;
    if(vaziacelula(*topo)) {
        printf("Erro - Estacionamento vazio\n");
        return;
    }
    while(!vaziacelula(aux)) {
        elem = pop(&aux);
        printf("\nNome do carro: %s", elem.nome);
        printf("\nNumero da placa: %s", elem.placa);
    }
}

void exibir_celula_fila(celula **inicio, celula **fim) {
    carro elem;
    celula *auxInicio = *inicio;
    celula *auxFim = *fim;
    if(vaziacelula(*inicio)) {
        printf("Erro! - Estacionamento vazio\n");
        return;
    }
    while(!vaziacelula(auxInicio)) {
        elem = desenfileirar(&auxInicio, &auxFim);
        printf("\nNome do carro: %s", elem.nome);
        printf("\nNumero da placa: %s", elem.placa);
    }
}

void exibir_celula_lista(celula **L) {
    celula *aux = *L;
    if(vaziacelula(*L)) {
        printf("\nErro! - Estacionamento vazio");
        return;
    }
    while(aux != NULL) {
        printf("\nNome do carro: %s", aux->info.nome);
        printf("\nNumero da placa: %s", aux->info.placa);
        aux = aux->next;
    }
    printf("\n");
}

carro ler_carro(carro elem) {
    fflush(stdin);
    printf("\nInforme o nome do carro: ");
    scanf("%[^\n]", elem.nome);
    fflush(stdin);
    printf("Informe a placa do carro com 2 numeros e 2 letras [Exemplo de placa permitida '1a2r']: ");
    scanf("%[^\n]", elem.placa);
    fflush(stdin);

    return elem;
}

void menu() {
    printf("\n\nMENU PRINCIPAL\n");
    printf("1 - Pilha\n");
    printf("2 - Fila\n");
    printf("3 - Lista\n");
    printf("0 - Sair");
}

void menu2() {
    printf("1 - Estacionar carro\n");
    printf("2 - Retirar carro do estacionamento\n");
    printf("3 - Exibir carros estacionados\n");
    printf("0 - Voltar ao menu principal\n");
}

void main() {
    celula *topo;
    celula *inicio;
    celula *fim;
    celula *L;
    carro elem, removerPlaca;
    int opcao, op;

    inicializar(&topo);
    inicializar(&L);
    inicializarFila(&inicio, &fim);

    do {
        menu();
        printf("\nQual estrutura deseja utilizar em seu estacionamento: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                do {
                    printf("\n\nMENU - PILHA\n");
                    menu2();
                    printf("Qual opcao deseja: ");
                    scanf("%d", &op);

                    switch(op) {
                        case 1:
                            elem = ler_carro(elem);
                            push(&topo, elem);
                            break;

                        case 2:
                            fflush(stdin);
                            printf("\nInforme a placa do carro que quer remover: ");
                            scanf("%[^\n]", removerPlaca.placa);
                            elem = removerCarroPilha(&topo, removerPlaca);
                            if(strcmp(elem.placa, "erro") != 0 && strcmp(elem.placa, "nao") != 0) {
                                printf("\nCarro removido:");
                                printf("\nNome do carro: %s", elem.nome);
                                printf("\nNumero da placa: %s", elem.placa);
                            } else if(strcmp(elem.placa, "erro") == 0){
                                printf("\nEstacionamento vazio\n");
                            } else {
                                printf("\nCarro nao encontrado\n");
                            }
                            break;

                        case 3:
                            printf("\n");
                            exibir_celula_pilha(&topo);
                            break;

                        case 0:
                            printf("\nVoltando ao menu principal...");
                            break;

                        default:
                            printf("\nErro\n");

                    }
                }while(op != 0);
                break;
            case 2:
                do {
                    printf("\n\nMENU - FILA\n");
                    menu2();
                    printf("Qual opcao deseja: ");
                    scanf("%d", &op);

                    switch(op) {
                        case 1:
                            elem = ler_carro(elem);
                            enfileirar(&inicio, &fim, elem);
                            break;

                        case 2:
                            fflush(stdin);
                            printf("\nInforme a placa do carro que quer remover: ");
                            scanf("%[^\n]", removerPlaca.placa);
                            elem = removerCarroFila(&inicio, &fim, removerPlaca);
                            if(strcmp(elem.placa, "erro") != 0 && strcmp(elem.placa, "nao") != 0) {
                                printf("\nCarro removido:");
                                printf("\nNome do carro: %s", elem.nome);
                                printf("\nNumero da placa: %s", elem.placa);
                            } else if(strcmp(elem.placa, "erro") == 0){
                                printf("\nEstacionamento vazio\n");
                            } else {
                                printf("\nCarro nao encontrado\n");
                            }

                            break;

                        case 3:
                            printf("\n");
                            exibir_celula_fila(&inicio, &fim);
                            break;

                        case 0:
                            printf("\nVoltando ao menu principal...");
                            break;

                        default:
                            printf("\nErro\n");

                    }
                }while(op != 0);
                break;

            case 3:
                do {
                    printf("\n\nMENU - LISTA\n");
                    menu2();
                    printf("Qual opcao deseja: ");
                    scanf("%d", &op);

                    switch(op) {
                        case 1:
                            elem = ler_carro(elem);
                            inserir_ordenado(&L, elem);
                            break;

                        case 2:
                            fflush(stdin);
                            printf("\nInforme a placa do carro que quer remover: ");
                            scanf("%[^\n]", removerPlaca.placa);
                            elem = removerCarroLista(&L, removerPlaca);
                            if(strcmp(elem.placa, "erro") != 0 && strcmp(elem.placa, "nao") != 0) {
                                printf("\nCarro removido:");
                                printf("\nNome do carro: %s", elem.nome);
                                printf("\nNumero da placa: %s", elem.placa);
                            } else if(strcmp(elem.placa, "erro") == 0){
                                printf("\nEstacionamento vazio\n");
                            } else {
                                printf("\nCarro nao encontrado\n");
                            }
                            break;

                        case 3:
                            printf("\n");
                            exibir_celula_lista(&L);
                            break;

                        case 0:
                            printf("\nVoltando ao menu principal...");
                            break;

                        default:
                            printf("\nErro\n");

                    }
                }while(op != 0);
                break;

            case 0:
                printf("\nSaindo...\n\n");
                break;

            default:
                printf("\nErro");

        }
    }while(opcao != 0);
}
