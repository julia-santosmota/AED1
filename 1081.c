#include <stdio.h>
#include <string.h>

#define MAX 20

int grafo[MAX][MAX];
int visitado[MAX];
int n;

void dfs(int v, int nivel) {
    visitado[v] = 1;
    
    for (int u = 0; u < n; u++) {
        if (grafo[v][u]) {
            for (int i = 0; i < nivel; i++) {
                printf("  ");
            }
            
            printf("%d-%d", v, u);
            
            if (!visitado[u]) {
                printf(" pathR(G,%d)\n", u);
                dfs(u, nivel + 1);
            } else {
                printf("\n");
            }
        }
    }
}

int main() {
    int N, caso = 1;
    
    scanf("%d", &N);
    
    while (caso <= N) {
        int m;
        scanf("%d %d", &n, &m);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grafo[i][j] = 0;
            }
            visitado[i] = 0;
        }
        
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            grafo[u][v] = 1;
        }
        
        printf("Caso %d:\n", caso++);
        
        for (int i = 0; i < n; i++) {
            if (!visitado[i]) {
                int tem_aresta = 0;
                
                for (int j = 0; j < n; j++) {
                    if (grafo[i][j]) {
                        tem_aresta = 1;
                        break;
                    }
                }
                
                if (tem_aresta) {
                    dfs(i, 1);
                    printf("\n");
                }
            }
        }
    }
    
    return 0;
}
