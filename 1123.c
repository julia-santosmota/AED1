/*
Beecrowd 1123: Desvios de rota
assuntos: grafos, algoritmo de dijkstra
*/

#include <stdio.h>

#define MAX 255 
#define INF 100000000
int Grafo[MAX][MAX];
int dist[MAX];
int visitado[MAX];
int N, M, C, K;

int dijkstra() {
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visitado[i] = 0;
    }

    dist[K] = 0;

    for (int i = 0; i < N; i++) {
        
        int u = -1;
        int menor = INF;

        for (int j = 0; j < N; j++) {
            if (!visitado[j] && dist[j] < menor) {
                menor = dist[j];
                u = j;
            }
        }

        if (u == -1 || menor == INF) break;

        visitado[u] = 1;

        for (int v = 0; v < N; v++) {
            if (Grafo[u][v] != INF && dist[u] + Grafo[u][v] < dist[v]) {
                dist[v] = dist[u] + Grafo[u][v];
            }
        }
    }

    return dist[C-1];
}

int main() {
    int u, v, p;

    while (scanf("%d %d %d %d", &N, &M, &C, &K) && (N || M || C || K)) {
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                Grafo[i][j] = INF;
            }
        }

        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &u, &v, &p);
            Grafo[u][v] = p;
            Grafo[v][u] = p; 
        }

        for (int i = 0; i < C - 1; i++) {
            for (int j = 0; j < N; j++) {
                if (j != i + 1) {
                    Grafo[i][j] = INF; 
                }
            }
        }

        printf("%d\n", dijkstra());
    }

    return 0;
}
