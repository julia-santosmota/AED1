#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int particiona_crescente(int v[], int inicio, int fim) {
    int pivo = v[fim];   
    int i = inicio - 1; 

    for (int j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {  
            i++;
            troca(&v[i], &v[j]);
        }
    }

    troca(&v[i+1], &v[fim]);  
    return i + 1;
}


void quicksort_crescente(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = particiona_crescente(v, inicio, fim);
        quicksort_crescente(v, inicio, meio - 1);
        quicksort_crescente(v, meio + 1, fim);
    }
}


int particiona_decrescente(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (v[j] >= pivo) {  
            i++;
            troca(&v[i], &v[j]);
        }
    }

    troca(&v[i+1], &v[fim]);
    return i + 1;
}


void quicksort_decrescente(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = particiona_decrescente(v, inicio, fim);
        quicksort_decrescente(v, inicio, meio - 1);
        quicksort_decrescente(v, meio + 1, fim);
    }
}


int main() {
    int N, x;

    scanf("%d", &N);

    int pares[MAX];
    int impares[MAX];
    int p = 0, im = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        if (x % 2 == 0)
            pares[p++] = x;
        else
            impares[im++] = x;
    }

    if (p > 0)
        quicksort_crescente(pares, 0, p - 1);

    if (im > 0)
        quicksort_decrescente(impares, 0, im - 1);

    for (int i = 0; i < p; i++)
        printf("%d\n", pares[i]);

    for (int i = 0; i < im; i++)
        printf("%d\n", impares[i]);

    return 0;
}
