#include <stdio.h>
#include <stdlib.h>

#define MAX_CIDADES 40000
#define MAX_ROTAS 50000

typedef struct {
    int u, v, peso;
} Rota;

Rota rotas[MAX_ROTAS];
int pai[MAX_CIDADES];
int tamanho[MAX_CIDADES];

// função de comparação para qsort (ordena por peso crescente)
int comparar(const void *a, const void *b) {
    Rota *r1 = (Rota *)a;
    Rota *r2 = (Rota *)b;
    return r1->peso - r2->peso;
}

// encontra o representante (raiz) do conjunto
int encontrar(int x) {
    if (pai[x] != x) {
        pai[x] = encontrar(pai[x]);  
    }
    return pai[x];
}

// une dois conjuntos
void unir(int x, int y) {
    int raiz_x = encontrar(x);
    int raiz_y = encontrar(y);
    
    if (raiz_x != raiz_y) {
        if (tamanho[raiz_x] < tamanho[raiz_y]) {
            pai[raiz_x] = raiz_y;
            tamanho[raiz_y] += tamanho[raiz_x];
        } else {
            pai[raiz_y] = raiz_x;
            tamanho[raiz_x] += tamanho[raiz_y];
        }
    }
}

int main() {
    int M, N;
    
    while (1) {
        scanf("%d %d", &M, &N);
        
        if (M == 0 && N == 0) {
            break;
        }
        
        // leitura das rotas
        int soma_total = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &rotas[i].u, &rotas[i].v, &rotas[i].peso);
            soma_total += rotas[i].peso; 
        }
        
        // ordena rotas por peso crescente
        qsort(rotas, N, sizeof(Rota), comparar);
        
        for (int i = 0; i < M; i++) {
            pai[i] = i;
            tamanho[i] = 1;
        }
        
        // algoritmo de Kkruskal
        int mst_soma = 0;
        int arestas_adicionadas = 0;
        
        for (int i = 0; i < N && arestas_adicionadas < M - 1; i++) {
            int u = rotas[i].u;
            int v = rotas[i].v;
            int peso = rotas[i].peso;
            
            if (encontrar(u) != encontrar(v)) {
                unir(u, v);
                mst_soma += peso;
                arestas_adicionadas++;
            }
        }
        
        printf("%d\n", mst_soma);
    }
    
    return 0;
}
