#include <iostream>
using namespace std;

struct cel {
    int valor;
    int frequencia;
    struct cel *esq;
    struct cel *dir;
};

typedef struct cel celula;
typedef celula *arvore;

arvore criar_no(int valor) {
    arvore novo = (arvore)malloc(sizeof(celula)); 
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novo->valor = valor;
    novo->frequencia = 1;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

arvore inserir(arvore raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }
    
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    }
    else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    else {
        raiz->frequencia++;
    }
    
    return raiz;
}

void em_ordem(arvore raiz, int *primeiro) {
    if (raiz != NULL) {
        em_ordem(raiz->esq, primeiro);
        
        for (int i = 0; i < raiz->frequencia; i++) {
            if (*primeiro) {
                printf("%d", raiz->valor);
                *primeiro = 0;
            } else {
                printf(" %d", raiz->valor);
            }
        }
        
        em_ordem(raiz->dir, primeiro);
    }
}

void liberar_arvore(arvore raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esq);
        liberar_arvore(raiz->dir);
        free(raiz);
    }
}

int main() {
    int num_casos; 
    scanf("%d", &num_casos);
    
    while (num_casos--) {
        int n; 
        scanf("%d", &n);
        
        arvore raiz = NULL;
        
        for (int i = 0; i < n; i++) {
            int numero;
            scanf("%d", &numero);
            raiz = inserir(raiz, numero);
        }
        
        int primeiro = 1;
        em_ordem(raiz, &primeiro);
        printf("\n");
        
        liberar_arvore(raiz);
    }
    
    return 0;
}
