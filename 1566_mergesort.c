#include <stdio.h>
#include <stdlib.h>

void Intercala (int p, int q, int r, int v[]) {
    int i, j, k;
    int *w; 

    w = malloc ((r - p) * sizeof (int));
    if (w == NULL) {
        printf("Erro de alocacao no Intercala\n");
        exit(1); 
    }

    i = p; 
    j = q; 
    k = 0;

    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];

        } 
        else {
            w[k++] = v[j++];
        }
    }
    
    while (i < q) {
        w[k++] = v[i++];
    }
    
    while (j < r) {
        w[k++] = v[j++];
    }

    for (i = p; i < r; i++) {
        v[i] = w[i - p];
    }

    free (w);
}

void Mergesort (int p, int r, int v[]) {
    if (p < r - 1) { 
        int q = (p + r) / 2;      
        Mergesort (p, q, v);      
        Mergesort (q, r, v);      
        Intercala (p, q, r, v); 
    }
}

int main() {
    int NC; 
    scanf("%d", &NC);

    while (NC--) { 
        int N; 
        scanf("%d", &N);

        int *v = malloc(N * sizeof(int));
        if (v == NULL) {
             printf("Erro ao alocar vetor principal\n");
             return 1;
        }

        for (int i = 0; i < N; i++) {
            scanf("%d", &v[i]); 
        }

        Mergesort(0, N, v);

        if (N > 0) {
            printf("%d", v[0]); 
            for (int i = 1; i < N; i++) {
                printf(" %d", v[i]); 
            }
        }
        printf("\n"); 

        free(v);
    }
    return 0;
}
