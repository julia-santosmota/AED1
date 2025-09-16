#include <stdio.h>

int validarSudoku(int matriz[9][9]) {
    int i, j, k, num;
    int verificacao[10];
    
    for (i = 0; i < 9; i++) {
        for (k = 1; k <= 9; k++) {
            verificacao[k] = 0;
        }
        
        for (j = 0; j < 9; j++) {
            num = matriz[i][j];
            if (num < 1 || num > 9 || verificacao[num] == 1) {
                return 0; 
            }
            verificacao[num] = 1;
        }
    }
    
    for (j = 0; j < 9; j++) {
        for (k = 1; k <= 9; k++) {
            verificacao[k] = 0;
        }
        
        for (i = 0; i < 9; i++) {
            num = matriz[i][j];
            if (verificacao[num] == 1) {
                return 0;
            }
            verificacao[num] = 1;
        }
    }
    
    for (int regiao_i = 0; regiao_i < 3; regiao_i++) {
        for (int regiao_j = 0; regiao_j < 3; regiao_j++) {
            for (k = 1; k <= 9; k++) {
                verificacao[k] = 0;
            }
            
            for (i = regiao_i * 3; i < (regiao_i + 1) * 3; i++) {
                for (j = regiao_j * 3; j < (regiao_j + 1) * 3; j++) {
                    num = matriz[i][j];
                    if (verificacao[num] == 1) {
                        return 0;
                    }
                    verificacao[num] = 1;
                }
            }
        }
    }
    
    return 1;
}

int main() {
    int n, instancia;
    int matriz[9][9];
    
    scanf("%d", &n);
    
    for (instancia = 1; instancia <= n; instancia++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        
        printf("Instancia %d\n", instancia);
        if (validarSudoku(matriz)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }
    
    return 0;
}
