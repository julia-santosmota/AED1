#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 501
#define INF INT_MAX

int grafo[MAX][MAX];
int n, m;

int menor_distancia(int dist[], int visitado[]) {
    int min = INF, min_indice = -1;
    
    for (int v = 1; v <= n; v++) {
        if (!visitado[v] && dist[v] <= min) {
            min = dist[v];
            min_indice = v;
        }
    }
    
    return min_indice;
}

int dijkstra(int origem, int destino) {
    int dist[MAX];
    int visitado[MAX] = {0};
    
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[origem] = 0;
    
    for (int count = 0; count < n; count++) {
        int u = menor_distancia(dist, visitado);
        if (u == -1 || u == destino) break;
        
        visitado[u] = 1;
        
        for (int v = 1; v <= n; v++) {
            if (!visitado[v] && grafo[u][v] != INF &&
                dist[u] != INF && dist[u] + grafo[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo[u][v];
            }
        }
    }
    
    return dist[destino];
}

int main() {
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                grafo[i][j] = INF;
            }
        }
        
        for (int i = 0; i < m; i++) {
            int x, y, h;
            scanf("%d %d %d", &x, &y, &h);
            
            // Verifica se já existe conexão inversa
            if (grafo[y][x] != INF) {
                grafo[x][y] = 0;
                grafo[y][x] = 0;
            } else {
                grafo[x][y] = h;
            }
        }
        
        int k;
        scanf("%d", &k);
        
        for (int i = 0; i < k; i++) {
            int origem, destino;
            scanf("%d %d", &origem, &destino);
            
            int resultado = dijkstra(origem, destino);
            
            if (resultado == INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", resultado);
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
