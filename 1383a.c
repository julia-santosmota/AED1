/* #1383 Beecrowd: Sudoku */

#include <stdio.h>
#include <stdlib.h>

// Função auxiliar que verifica um grupo de 9 números (linha, coluna)
int verifica_grupo_nove(int grupo[9]) {
    int visto[10] = {0}; 
    for (int i = 0; i < 9; i++) {
        int num = grupo[i];
        if (num < 1 || num > 9 || visto[num]) { 
            return 0; // intervalo errado ou duplicata
        }
        visto[num] = 1;
    }
    return 1; // Válido
}

// Função para verificar TODAS as 9 linhas
int verifica_linhas(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        int linha_atual[9];
        for (int j = 0; j < 9; j++) {
            linha_atual[j] = sudoku[i][j];
        }
        if (!verifica_grupo_nove(linha_atual)) {
            return 0; 
        }
    }
    return 1; // Se todas as linhas passaram, retorna 1 (válido)
}

// Função para verificar TODAS as 9 colunas
int verifica_colunas(int sudoku[9][9]) {
    for (int j = 0; j < 9; j++) {
        int coluna_atual[9];
        for (int i = 0; i < 9; i++) {
            coluna_atual[i] = sudoku[i][j];
        }
        if (!verifica_grupo_nove(coluna_atual)) {
            return 0;
        }
    }
    return 1;
}

// Função para verificar TODOS os 9 blocos 3x3
int verifica_blocos(int sudoku[9][9]) {
    for (int bloco_linha = 0; bloco_linha < 9; bloco_linha += 3) {
        for (int bloco_coluna = 0; bloco_coluna < 9; bloco_coluna += 3) {
            
            int visto[10] = {0}; 

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = sudoku[bloco_linha + i][bloco_coluna + j];

                    if (num < 1 || num > 9 || visto[num]) { 
                        return 0; 
                    }
                    visto[num] = 1;
                }
            }
        }
    }
    return 1; // Se todos os blocos passaram, retorna 1 (válido)
}


int main() {
    int n_instancias;
    scanf("%d", &n_instancias);

    for (int k = 1; k <= n_instancias; k++) {
        int sudoku[9][9];

        // Leitura do Tabuleiro
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        // O Sudoku SÓ é válido se passar nas TRÊS verificações
        int valido_linhas = verifica_linhas(sudoku);
        int valido_colunas = verifica_colunas(sudoku);
        int valido_blocos = verifica_blocos(sudoku);
        
        printf("Instancia %d\n", k); // sem usar o /n pra imprimir na mesma linha
        
        // Usando operador lógico AND (&&): só é SIM se TODOS forem 1 (verdadeiro)
        if (valido_linhas && valido_colunas && valido_blocos) {
            printf("SIM\n");
        }
        else {
            printf("NAO\n"); // não passou em algum teste
        }
        printf("\n"); 
    }

    return 0;
}
