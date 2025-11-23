#include <stdio.h>

#define MAX 1000

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particiona(int v[], int ini, int fim) {
    int pivo = v[fim];
    int i = ini - 1;
    int j;
    for (j = ini; j < fim; j++) {
        if (v[j] <= pivo) {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i+1], &v[fim]);
    return i + 1;
}

void quicksort(int v[], int ini, int fim) {
    if (ini < fim) {
        int q = particiona(v, ini, fim);
        quicksort(v, ini, q - 1);
        quicksort(v, q + 1, fim);
    }
}

void inverte(int v[], int n) {
    int i;
    for (i = 0; i < n / 2; i++)
        troca(&v[i], &v[n - 1 - i]);
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    while (N--) {
        int M;
        scanf("%d", &M);

        int orig[MAX];
        int ord[MAX];
        int i;

        for (i = 0; i < M; i++) {
            scanf("%d", &orig[i]);
            ord[i] = orig[i];
        }

        if (M > 0) {
            quicksort(ord, 0, M - 1);
            inverte(ord, M);
        }

        int cont = 0;
        for (i = 0; i < M; i++) {
            if (orig[i] == ord[i]) cont++;
        }

        printf("%d\n", cont);
    }

    return 0;
}
