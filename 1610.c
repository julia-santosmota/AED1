#include <stdio.h>
#include <stdlib.h>

#define MAX 10010

typedef struct No {
    int v;
    struct No *prox;
} No;

No* adj[MAX];
int cor[MAX];
int temLoop;

void adicionarAresta(int u, int v) {
    No* novo = (No*) malloc(sizeof(No));
    novo->v = v;
    novo->prox = adj[u];
    adj[u] = novo;
}

void dfs(int u) {
    if (temLoop) return;

    cor[u] = 1; 

    for (No* p = adj[u]; p != NULL; p = p->prox) {
        int v = p->v;

        if (cor[v] == 1) {  
            temLoop = 1;
            return;
        }

        if (cor[v] == 0) {
            dfs(v);
            if (temLoop) return;
        }
    }

    cor[u] = 2;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        for (int i = 1; i <= n; i++) {
            adj[i] = NULL;
            cor[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adicionarAresta(u, v);
        }

        temLoop = 0;

        for (int i = 1; i <= n && !temLoop; i++) {
            if (cor[i] == 0)
                dfs(i);
        }

        if (temLoop)
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}
