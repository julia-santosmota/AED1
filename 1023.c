#include <stdio.h>

int main() {
    int N;
    int cidade = 1;
    int first = 1;

    while (scanf("%d", &N) == 1 && N != 0) {

        if (!first)
            printf("\n");
        first = 0;

        int pessoas_por_consumo[201] = {0};
        long long total_pessoas = 0;
        long long total_consumo = 0;

        for (int i = 0; i < N; i++) {
            int X, Y;
            scanf("%d %d", &X, &Y);

            int c = Y / X;  
            pessoas_por_consumo[c] += X;

            total_pessoas += X;
            total_consumo += Y;
        }

        printf("Cidade# %d:\n", cidade++);
        
        int primeiro = 1;
        for (int c = 0; c <= 200; c++) {
            if (pessoas_por_consumo[c] > 0) {
                if (!primeiro) printf(" ");
                printf("%d-%d", pessoas_por_consumo[c], c);
                primeiro = 0;
            }
        }
        printf("\n");

        double media = (double)total_consumo / total_pessoas;
        media *= 100;
        long long t = (long long) media;
        media = t / 100.0;

        printf("Consumo medio: %.2lf m3.\n", media);
    }

    return 0;
}
