#include <stdio.h>

int main() {
    int C;
    scanf("%d", &C);

    for(int i = 0; i < C; i++) {
        int N; 
        scanf("%d", &N);
        
        int notas[1000];
        int soma = 0;
        
        for(int j = 0; j < N; j++) {
            scanf("%d", &notas[j]);
            soma += notas[j];
        }
        
        double media = (double)soma / N;
        
        int contaAcima = 0;
        
        for(int j = 0; j < N; j++) {
            if(notas[j] > media) {
                contaAcima++;
            }
        }
        
        double porcentagem = ((double)contaAcima / N) * 100.0;
        
        printf("%.3lf%%\n", porcentagem);
    }
 
    return 0;
}
