#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char elemento;
    struct Node *esq, *dir;
} Node;

Node* novoNode(char elemento) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->elemento = elemento;
    node->esq = node->dir = NULL;
    return node;
}

Node* inserir(Node* raiz, char elemento) {
    if (raiz == NULL) {
        return novoNode(elemento);
    }
    if (elemento < raiz->elemento) {
        raiz->esq = inserir(raiz->esq, elemento);
    }
    else if (elemento > raiz->elemento) {
        raiz->dir = inserir(raiz->dir, elemento);
    }
    return raiz;
}

int buscar(Node* raiz, char elemento) {
    if (raiz == NULL){
        return 0;
    }
    if (raiz->elemento == elemento) {
        return 1;
    }
    if (elemento < raiz->elemento) {
        return buscar(raiz->esq, elemento);
    }
    else {
        return buscar(raiz->dir, elemento);
    }
}

void infixa(Node* raiz, int *primeiro) {
    if (raiz != NULL) {
        infixa(raiz->esq, primeiro);
        if (*primeiro == 0) {
            printf(" ");
        }
        printf("%c", raiz->elemento);
        *primeiro = 0;
        infixa(raiz->dir, primeiro);
    }
}

void prefixa(Node* raiz, int *primeiro) {
    if (raiz != NULL) {
        if (!*primeiro) {
            printf(" ");
        }
        printf("%c", raiz->elemento);
        *primeiro = 0;
        prefixa(raiz->esq, primeiro);
        prefixa(raiz->dir, primeiro);
    }
}

void posfixa(Node* raiz, int *primeiro) {
    if (raiz != NULL) {
        posfixa(raiz->esq, primeiro);
        posfixa(raiz->dir, primeiro);
        if (!*primeiro) {
            printf(" ");
        }
        printf("%c", raiz->elemento);
        *primeiro = 0;
    }
}

int main() {
    Node* raiz = NULL;
    char command[20], c;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "I") == 0) {
            scanf(" %c", &c);
            raiz = inserir(raiz, c);
        }
        
        else if (strcmp(command, "P") == 0) {
            scanf(" %c", &c);
            if (buscar(raiz, c)){
                printf("%c existe\n", c);
            }
            else {
                printf("%c nao existe\n", c);
            }
        }
        
        else if (strcmp(command, "INFIXA") == 0) {
            int primeiro = 1;
            infixa(raiz, &primeiro);
            printf("\n");
        } 
        
        else if (strcmp(command, "PREFIXA") == 0) {
            int primeiro = 1;
            prefixa(raiz, &primeiro);
            printf("\n");
        }
        
        else if (strcmp(command, "POSFIXA") == 0) {
            int primeiro = 1;
            posfixa(raiz, &primeiro);
            printf("\n");
        }
    }
    return 0;
}
