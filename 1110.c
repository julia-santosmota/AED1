#include <stdio.h>

int main() {
    int n;
    
    while (scanf("%d", &n) && n != 0) {
        int cartas[100];
        int inicio = 0, fim = 0;
        
        for (int i = 1; i <= n; i++) {
            cartas[fim++] = i;
        }
        
        printf("Discarded cards:");
        
        if (n > 1) {
            int primeiro = 1;
            while (fim - inicio > 1) {
                if (primeiro) {
                    printf(" %d", cartas[inicio]);
                    primeiro = 0;
                } else {
                    printf(", %d", cartas[inicio]);
                }
                inicio++;
                
                cartas[fim] = cartas[inicio];
                fim++;
                inicio++;
            }
        }
        
        printf("\n");
        printf("Remaining card: %d\n", cartas[inicio]);
    }
    
    return 0;
}
