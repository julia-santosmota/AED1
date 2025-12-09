#include <stdio.h>
#include <stdlib.h>

struct cel {
    int numero;
    struct cel *dir;
    struct cel *esq;
};

typedef struct cel node;

node* inserir(node *raiz, int numero) {
    if (raiz == NULL) {
        node *novo = malloc(sizeof(node));
        novo->numero = numero;
        novo->esq = novo->dir = NULL;
        return novo;
    }

    if (numero < raiz->numero)
        raiz->esq = inserir(raiz->esq, numero);
    else
        raiz->dir = inserir(raiz->dir, numero);

    return raiz;
}

void prefixo(node *raiz) {
    if (raiz == NULL) {
        return;
    }
    printf(" %d", raiz->numero);
    prefixo(raiz->esq);
    prefixo(raiz->dir);
}

void infixo(node *raiz) {
    if (raiz == NULL) {
        return;
    }
    infixo(raiz->esq);
    printf(" %d", raiz->numero);
    infixo(raiz->dir);
}

void posfixo(node *raiz) {
    if (raiz == NULL) {
        return;
    }
    posfixo(raiz->esq);
    posfixo(raiz->dir);
    printf(" %d", raiz->numero);
}

void liberar(node *raiz) {
    if (raiz == 0) {
        return;
    }
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main() {
    int C, N, numero;

    if (scanf("%d", &C) != 1) {
        return 0;
    }

    for (int caso = 1; caso <= C; caso++) {
        node *raiz = NULL;

        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &numero);
            raiz = inserir(raiz, numero);
        }

        printf("Case %d:\n", caso);

        printf("Pre.:");
        prefixo(raiz);
        printf("\n");

        printf("In..:");
        infixo(raiz);
        printf("\n");

        printf("Post:");
        posfixo(raiz);
        printf("\n\n");

        liberar(raiz); 
    }
    return 0;
}
