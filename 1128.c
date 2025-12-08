/*
Beecrowd 1128: Ir e vir
assuntos: grafos -> dfs
*/

#include <stdio.h>

#define MAX 2005 // Tamanho máximo N + margem de segurança

int grafo[MAX][MAX];     
int grafoInv[MAX][MAX];  
int visitados[MAX];      
int N, M;                

void dfs(int u, int matriz[MAX][MAX]) {
    visitados[u] = 1; 

    for (int v = 1; v <= N; v++) {
        if (matriz[u][v] == 1 && visitados[v] == 0) {
            dfs(v, matriz);
        }
    }
}

int main() {
    int v, w, p; 

    while (scanf("%d %d", &N, &M) && N != 0) {
        
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                grafo[i][j] = 0;
                grafoInv[i][j] = 0;
            }
        }

        // 2. LEITURA DAS RUAS
        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &v, &w, &p);

            // Rua de mão única (V -> W)
            grafo[v][w] = 1;
            grafoInv[w][v] = 1; // Na invertida é W -> V

            // Se for mão dupla (P=2), vale para os dois lados
            if (p == 2) {
                grafo[w][v] = 1;
                grafoInv[v][w] = 1;
            }
        }

        for (int i = 0; i <= N; i++) {
            visitados[i] = 0;
        }

        dfs(1, grafo); 

        int conexo = 1; 
        for (int i = 1; i <= N; i++) {
            if (visitados[i] == 0) {
                conexo = 0; 
                break;
            }
        }

        if (conexo == 1) {
            for (int i = 0; i <= N; i++) {
                visitados[i] = 0;
            }

            dfs(1, grafoInv); 

            for (int i = 1; i <= N; i++) {
                if (visitados[i] == 0) {
                    conexo = 0; 
                    break;
                }
            }
        }

        printf("%d\n", conexo);
    }

    return 0;
}
