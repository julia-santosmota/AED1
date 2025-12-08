#include <stdio.h>
#include <stdlib.h>

#define INFINITO 1000000000
#define MAX_CIDADES 10005
#define MAX_ESTRADAS 100005 
#define TAM_FILA 1000000 // Tamanho generoso para a fila circular

typedef struct {
    int destino;
    int custo;
    int proximo;
} Estrada;

Estrada arestas[MAX_ESTRADAS * 2]; 
int cabeca[MAX_CIDADES];
int total_arestas = 0;

void adicionar_estrada(int u, int v, int custo) {
    arestas[total_arestas].destino = v;
    arestas[total_arestas].custo = custo;
    arestas[total_arestas].proximo = cabeca[u];
    cabeca[u] = total_arestas;
    total_arestas++;
}

typedef struct {
    int cidade;
    int paridade;
} Estado;

Estado fila[TAM_FILA];
int inicio_fila = 0;
int fim_fila = 0;

void enfileirar(int c, int p) {
    fila[fim_fila].cidade = c;
    fila[fim_fila].paridade = p;
    fim_fila = (fim_fila + 1) % TAM_FILA; 
}

Estado desenfileirar() {
    Estado temp = fila[inicio_fila];
    inicio_fila = (inicio_fila + 1) % TAM_FILA;
    return temp;
}

int fila_vazia() {
    return inicio_fila == fim_fila;
}

int main() {
    int C, V; 
    
    if (scanf("%d %d", &C, &V) == EOF) return 0;

    for (int i = 0; i <= C; i++) cabeca[i] = -1;
    total_arestas = 0;

    int u, v, custo;
    for (int i = 0; i < V; i++) {
        scanf("%d %d %d", &u, &v, &custo);
        adicionar_estrada(u, v, custo);
        adicionar_estrada(v, u, custo);
    }

    
    int dist[MAX_CIDADES][2];
    
    int na_fila[MAX_CIDADES][2];

    for (int i = 0; i <= C; i++) {
        dist[i][0] = INFINITO;
        dist[i][1] = INFINITO;
        na_fila[i][0] = 0;
        na_fila[i][1] = 0;
    }

    dist[1][0] = 0;
    enfileirar(1, 0); 
    na_fila[1][0] = 1;

    while (!fila_vazia()) {
        Estado atual = desenfileirar();
        int u = atual.cidade;
        int par_u = atual.paridade;
        
        na_fila[u][par_u] = 0;

        for (int i = cabeca[u]; i != -1; i = arestas[i].proximo) {
            int vizinho = arestas[i].destino;
            int peso = arestas[i].custo;
            int prox_paridade = 1 - par_u; 

            if (dist[u][par_u] + peso < dist[vizinho][prox_paridade]) {
                dist[vizinho][prox_paridade] = dist[u][par_u] + peso;

                if (!na_fila[vizinho][prox_paridade]) {
                    enfileirar(vizinho, prox_paridade);
                    na_fila[vizinho][prox_paridade] = 1;
                }
            }
        }
    }

    int resultado = dist[C][0];

    if (resultado == INFINITO) printf("-1\n");
    else printf("%d\n", resultado);

    return 0;
}
