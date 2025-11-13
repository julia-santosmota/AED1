#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char dado;
    struct No* prox;
} No;

void empilhar(No** topo, char valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = *topo;
    *topo = novo;
}

void desempilhar(No** topo) {
    if (*topo != NULL) {
        No* temp = *topo;
        *topo = (*topo)->prox;
        free(temp);
    }
}

int balanceada(char s[]) {
    No* pilha = NULL;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            empilhar(&pilha, '(');
        }
        else if (s[i] == ')') {
            if (pilha == NULL) {
                return 0;
            }
            desempilhar(&pilha);
        }
    }
    
    int resultado = (pilha == NULL);
    
    while (pilha != NULL) {
        desempilhar(&pilha);
    }
    
    return resultado;
}

int main() {
    char expr[1001];
    
    while (scanf("%s", expr) != EOF) {
        if (balanceada(expr)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    
    return 0;
}
