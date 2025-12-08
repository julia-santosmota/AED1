/*
Beecrowd 1082: Componentes conexos
assuntos: grafos com matriz de adjacência, bfs, e grafos conexos
*/


#include <stdio.h>
#include <string.h>

int grafo[26][26];
int visitado[26];
char componente[26];
int tamanho_componente;

void bfs(int inicio, int total_vertices) {
    int fila[26];
    int inicio_fila = 0, fim_fila = 0;

    fila[fim_fila++] = inicio;
    visitado[inicio] = 1;

    while (inicio_fila < fim_fila) {
        int v = fila[inicio_fila++];
        componente[tamanho_componente++] = 'a' + v;

        for (int u = 0; u < total_vertices; u++) {
            if (grafo[v][u] && !visitado[u]) {
                visitado[u] = 1;
                fila[fim_fila++] = u;
            }
        }
    }
}

void ordenar(char *vetor, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[i] > vetor[j]) {
                char temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int caso = 1; caso <= N; caso++) {
        int V, E;
        scanf("%d %d", &V, &E);

        memset(grafo, 0, sizeof(grafo));
        memset(visitado, 0, sizeof(visitado));

        for (int i = 0; i < E; i++) {
            char a, b;
            scanf(" %c %c", &a, &b);
            int u = a - 'a';
            int v = b - 'a';
            grafo[u][v] = 1;
            grafo[v][u] = 1; 
        }

        printf("Case #%d:\n", caso);

        int componentes_conectados = 0;
        for (int i = 0; i < V; i++) {
            if (!visitado[i]) {
                tamanho_componente = 0;
                bfs(i, V);
                ordenar(componente, tamanho_componente);
                for (int j = 0; j < tamanho_componente; j++)
                    printf("%c,", componente[j]);
                printf("\n");
                componentes_conectados++;
            }
        }
        printf("%d connected components\n\n", componentes_conectados);
    }

    return 0;
}
