/*
1076 Beecrowd: Desenhando Labirintos
assuntos: grafos
*/

#include <stdio.h>

int main() {
    int T;
    if (scanf("%d", &T) != 1) {
      return 0;
    }

    while (T--) {
        int inicio;
        int V, A;
        scanf("%d", &inicio);
        scanf("%d %d", &V, &A);

        int visto[50][50] = {0};
        int unique_edges = 0;

        for (int i = 0; i < A; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (u == v) {

            if (!visto[u][u]) { 
              visto[u][u] = 1; unique_edges++; 
            }
            
            else {
                int a = u < v ? u : v;
                int b = u < v ? v : u;
                if (!visto[a][b]) {
                    visto[a][b] = 1;
                    visto[b][a] = 1;
                    unique_edges++;
                }
            }
        }

        printf("%d\n", 2 * unique_edges);
    }

    return 0;
}
