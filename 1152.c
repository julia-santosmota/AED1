#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, peso;
} Aresta;

Aresta arestas[200000];
int pai[200000], tam[200000];

int comparar(const void *a, const void *b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}

int encontrar(int x) {
    if (pai[x] != x) pai[x] = encontrar(pai[x]);
    return pai[x];
}

void unir(int x, int y) {
    x = encontrar(x);
    y = encontrar(y);
    if (x != y) {
        if (tam[x] < tam[y]) {
            pai[x] = y;
            tam[y] += tam[x];
        } else {
            pai[y] = x;
            tam[x] += tam[y];
        }
    }
}

int main() {
    int m, n;
    
    while (scanf("%d %d", &m, &n), m || n) {
        int total = 0;
        
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
            total += arestas[i].peso;
        }
        
        qsort(arestas, n, sizeof(Aresta), comparar);
        
        for (int i = 0; i < m; i++) {
            pai[i] = i;
            tam[i] = 1;
        }
        
        int mst = 0, arestas_usadas = 0;
        
        for (int i = 0; i < n && arestas_usadas < m - 1; i++) {
            if (encontrar(arestas[i].u) != encontrar(arestas[i].v)) {
                unir(arestas[i].u, arestas[i].v);
                mst += arestas[i].peso;
                arestas_usadas++;
            }
        }
        
        printf("%d\n", total - mst); 
    }
    
    return 0;
}
