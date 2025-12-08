#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int main() {
    int n, m;
    
    while (scanf("%d %d", &n, &m), n || m) {
        int grafo[MAX][MAX];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grafo[i][j] = INF;
            }
            grafo[i][i] = 0;
        }
        
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            u--; v--;
            grafo[u][v] = w;
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                if (grafo[i][k] == INF) continue;
                for (int j = 0; j < n; j++) {
                    if (grafo[k][j] == INF) continue;
                    if (grafo[i][j] > grafo[i][k] + grafo[k][j]) {
                        grafo[i][j] = grafo[i][k] + grafo[k][j];
                    }
                }
            }
        }
        
        int consultas;
        scanf("%d", &consultas);
        
        for (int i = 0; i < consultas; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            u--; v--;
            
            if (grafo[u][v] == INF) {
                printf("-1\n");
            } 
            else {
                printf("%d\n", grafo[u][v]);
            }
        }
    }
    
    return 0;
}
