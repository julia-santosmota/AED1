#include <stdio.h>

#define MAXID 100000

int saiu[MAXID + 1];

int main() {
    int N, M;

    scanf("%d", &N);

    int fila[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }

    scanf("%d", &M);

    for (int i = 0; i <= MAXID; i++)
        saiu[i] = 0;

    for (int i = 0; i < M; i++) {
        int id;
        scanf("%d", &id);
        saiu[id] = 1;
    }

    int primeiro = 1;
    for (int i = 0; i < N; i++) {
        if (!saiu[fila[i]]) {
            if (!primeiro) printf(" ");
            printf("%d", fila[i]);
            primeiro = 0;
        }
    }

    printf("\n");

    return 0;
}
