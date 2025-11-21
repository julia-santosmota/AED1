#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int valor;
    struct node *esq, *dir;
} Node;

Node* inserir(Node* raiz, int v) { // arvore binaria de busca
    if (raiz == NULL) {
        Node *novo = malloc(sizeof(Node));
        novo->valor = v;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (v < raiz->valor)
        raiz->esq = inserir(raiz->esq, v);
    else
        raiz->dir = inserir(raiz->dir, v);

    return raiz;
}

typedef struct {
    Node* dados[600];
    int ini, fim;
} Fila;

void initFila(Fila* f) { f->ini = f->fim = 0; }
void push(Fila* f, Node* x) { f->dados[f->fim++] = x; }
Node* pop(Fila* f) { return f->dados[f->ini++]; }
int vazia(Fila* f) { return f->ini == f->fim; }

void bfs(Node* raiz) { // busca em largura
    Fila f;
    initFila(&f);
    push(&f, raiz);

    int primeiro = 1;

    while (!vazia(&f)) {
        Node* u = pop(&f);

        if (!primeiro) printf(" ");
        printf("%d", u->valor);
        primeiro = 0;

        if (u->esq) push(&f, u->esq);
        if (u->dir) push(&f, u->dir);
    }
}

void liberar(Node* r) {
    if (r == NULL) return;
    liberar(r->esq);
    liberar(r->dir);
    free(r);
}

int main() {
    int C;
    scanf("%d", &C);

    for (int caso = 1; caso <= C; caso++) {
        int N, x;
        scanf("%d", &N);

        Node* raiz = NULL;

        for (int i = 0; i < N; i++) {
            scanf("%d", &x);
            raiz = inserir(raiz, x);
        }

        printf("Case %d:\n", caso);
        bfs(raiz);
        printf("\n\n");

        liberar(raiz);
    }

    return 0;
}
