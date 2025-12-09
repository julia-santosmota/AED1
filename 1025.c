#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int buscar_primeira_ocorrencia(int marmores[], int n, int consulta) {
    int esquerda = 0, direita = n - 1;
    int resultado = -1;
    
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        if (marmores[meio] == consulta) {
            resultado = meio;
            direita = meio - 1; 
        } 
        else if (marmores[meio] < consulta) {
            esquerda = meio + 1;
        } 
        else {
            direita = meio - 1;
        }
    }
    
    return resultado;
}

int main() {
    int N, Q;
    int caso = 1;
    
    while (1) {
        scanf("%d %d", &N, &Q);
        
        if (N == 0 && Q == 0) {
            break;
        }
        
        int marmores[N];
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &marmores[i]);
        }
        
        qsort(marmores, N, sizeof(int), comparar);
        
        printf("CASE# %d:\n", caso);
        
        for (int i = 0; i < Q; i++) {
            int consulta;
            scanf("%d", &consulta);
            
            int posicao = buscar_primeira_ocorrencia(marmores, N, consulta);
            
            if (posicao == -1) {
                printf("%d not found\n", consulta);
            } else {
                printf("%d found at %d\n", consulta, posicao + 1);
            }
        }
        
        caso++;
    }
    
    return 0;
}
