#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 40000
#define MAX_ARESTAS 50000

typedef struct {
    int origem, destino, custo;
} Aresta;

int representante[MAX_VERTICES];

int encontrar(int x) {
    if (representante[x] != x)
        representante[x] = encontrar(representante[x]);
    return representante[x];
}

void unir(int x, int y) {
    x = encontrar(x);
    y = encontrar(y);
    if (x != y)
        representante[y] = x;
}

int comparar(const void *a, const void *b) {
    return ((Aresta*)a)->custo - ((Aresta*)b)->custo;
}

int main() {
    int numVertices, numArestas;
    
    while (scanf("%d %d", &numVertices, &numArestas) && (numVertices || numArestas)) {
        Aresta arestas[MAX_ARESTAS];
        
        for (int i = 0; i < numArestas; i++) {
            scanf("%d %d %d", &arestas[i].origem, &arestas[i].destino, &arestas[i].custo);
        }

        for (int i = 0; i < numVertices; i++)
            representante[i] = i;

        qsort(arestas, numArestas, sizeof(Aresta), comparar);

        int custoMST = 0;
        for (int i = 0; i < numArestas; i++) {
            int u = arestas[i].origem;
            int v = arestas[i].destino;
            int c = arestas[i].custo;

            if (encontrar(u) != encontrar(v)) {
                unir(u, v);
                custoMST += c;
            }
        }

        printf("%d\n", custoMST);
    }

    return 0;
}
