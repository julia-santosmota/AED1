#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int M, C;
        scanf("%d %d", &M, &C);

        int tabela[M][200];
        int tam[M];

        for (int i = 0; i < M; i++)
            tam[i] = 0;

        for (int i = 0; i < C; i++) {
            int x;
            scanf("%d", &x);
            int pos = x % M;
            tabela[pos][ tam[pos] ] = x;
            tam[pos]++;
        }

        for (int i = 0; i < M; i++) {
            printf("%d", i);
            for (int j = 0; j < tam[i]; j++)
                printf(" -> %d", tabela[i][j]);
            printf(" -> \\\n");
        }

        if (N > 0) printf("\n");
    }

    return 0;
}
