/* 1383: Sudoku (versão dinâmica) */

#include <stdio.h>
#include <stdlib.h> 

// Função auxiliar que verifica um grupo de 9 números (linha, coluna)
int verifica_grupo_nove(int grupo[9]) {
    int visto[10] = {0}; 
    for (int i = 0; i < 9; i++) {
        int num = grupo[i];
        if (num < 1 || num > 9 || visto[num]) {
            return 0; 
        }
        visto[num] = 1;
    }
    return 1; 
}

int verifica_linhas(int **sudoku) { ///Aqui é diferente
    for (int i = 0; i < 9; i++) {
        int linha_atual[9];
        for (int j = 0; j < 9; j++) {
            linha_atual[j] = sudoku[i][j]; 
        }
        if (!verifica_grupo_nove(linha_atual)) {
            return 0; 
        }
    }
    return 1; 
}

int verifica_colunas(int **sudoku) { //aqui é diferente
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

int verifica_blocos(int **sudoku) { //aqui é diferente
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
    return 1; 
}

// Função para liberar a memória da matriz dinâmica
void liberar_sudoku(int **sudoku) {
    for (int i = 0; i < 9; i++) {
        free(sudoku[i]); // Libera cada linha
    }
    free(sudoku); // Libera o array de ponteiros para as linhas
}

#include <stdio.h>
#include <stdlib.h>


int main() {
    int n_instancias;
    scanf("%d", &n_instancias);

    for (int k = 1; k <= n_instancias; k++) {
        
        int **sudoku; 

        // aloca memória para 9 ponteiros (um para cada linha)
        sudoku = (int **)malloc(9 * sizeof(int *));
        if (sudoku == NULL) {
             // MUDANÇA 1: Usando printf simples
             printf("Erro de alocacao de memoria (ponteiros de linha)!\n"); 
             return 1; 
        }

        // aloca memória para cada linha (9 inteiros por linha)
        for (int i = 0; i < 9; i++) {
            sudoku[i] = (int *)malloc(9 * sizeof(int));
            if (sudoku[i] == NULL) {
                 // MUDANÇA 2: Usando printf simples
                 printf("Erro de alocacao de memoria (linha %d)!\n", i); 
                 
                 // Liberar memória já alocada antes de sair (importante)
                 for(int j = 0; j < i; j++) {
                     free(sudoku[j]);
                 }
                 free(sudoku);
                 return 1; 
            }
        }
        
        // leitura do tabuleiro
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        // verificando usando as funções
        int valido_linhas = verifica_linhas(sudoku);
        int valido_colunas = verifica_colunas(sudoku);
        int valido_blocos = verifica_blocos(sudoku);
        
        // resultado
        printf("Instancia %d\n", k);
        if (valido_linhas && valido_colunas && valido_blocos) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        
        // liberando a memória
        liberar_sudoku(sudoku);

        printf("\n"); 
    }

    return 0;
}

/*
  Diferenças entre alocação a Estática vs. Dinâmica (Matriz Sudoku):
  Declaração:
   - Estática: int sudoku[9][9]; (matriz normal).
   - Dinâmica: int **sudoku; (ponteiro para ponteiro).

  Por que `**` na Dinâmica?
   - malloc só aloca blocos 1D (contíguos). Não cria matrizes 2D de forma direta.
   - Precisamos de um "índice" para encontrar cada linha. Esse índice é um **vetor de ponteiros**
  (int *), onde cada ponteiro guarda o endereço do início de uma linha.
   - O int **sudoku aponta para o início desse vetor de ponteiros.

  Alocação (malloc):
   - Estática: Feita automaticamente na Stack (memória automática).
   - Dinâmica: Feita manualmente no Heap (memória dinâmica) em **dois níveis**:
     a) malloc para o vetor de 9 ponteiros de linha (sizeof(int *)).
     b) malloc (9 vezes) para cada uma das 9 linhas de inteiros (sizeof(int)).

  Liberação (free):
   - Estática: Automática ao sair da função.
   - Dinâmica: Manual, na **ordem inversa** da alocação:
     a) free (9 vezes) para cada linha.
     b) free para o vetor de ponteiros das linhas.
*/
