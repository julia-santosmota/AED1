#include <stdio.h>
#include <string.h>


typedef struct {
    char nome[55];
    double preco;
} Item;


void troca(Item *a, Item *b);
int separa(Item v[], int p, int r);
void quicksort(Item v[], int p, int r);
double busca_binaria(char *chave, Item v[], int n);


int main() {
    int N; 
    int M; 
    int P; 
    int i, qtd;
    char nome_fruta[55];
    double total;
    
    Item mercado[1000]; 

    scanf("%d", &N);

    while (N--) {
        scanf("%d", &M);

        /* Leitura do catálogo da feira */
        for (i = 0; i < M; i++) {
            scanf("%s %lf", mercado[i].nome, &mercado[i].preco);
        }


        quicksort(mercado, 0, M - 1);

        scanf("%d", &P);
        total = 0.0;

        for (i = 0; i < P; i++) {
            scanf("%s %d", nome_fruta, &qtd);

            double preco_unitario = busca_binaria(nome_fruta, mercado, M);
            total += preco_unitario * qtd;
        }

        printf("R$ %.2lf\n", total);
    }

    return 0;
}


void troca(Item *a, Item *b) {
    Item t = *a; 
    *a = *b; 
    *b = t;
}


int separa(Item v[], int p, int r) {
    Item pivo = v[r]; 
    int j = p;
    int k;
    
    for (k = p; k < r; k++) {
        if (strcmp(v[k].nome, pivo.nome) <= 0) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}


void quicksort(Item v[], int p, int r) {
    if (p < r) {
        int j = separa(v, p, r); 
        quicksort(v, p, j - 1);
        quicksort(v, j + 1, r);
    }
}


double busca_binaria(char *chave, Item v[], int n) {
    int esquerda = 0;
    int direita = n - 1;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        int cmp = strcmp(chave, v[meio].nome);

        if (cmp == 0) {
            return v[meio].preco; 
        }
        
        if (cmp < 0) {
            direita = meio - 1; 
        } else {
            esquerda = meio + 1;
        }
    }
    return 0.0; 
}
