#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 8

typedef struct {
    int linha;
    int coluna;
    int distancia;
} Posicao;

int buscaEmLargura(int linhaInicio, int colunaInicio, int linhaFim, int colunaFim) {
    int movimentos[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    
    int visitado[TAMANHO][TAMANHO];
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            visitado[i][j] = 0;
        }
    }
    
    Posicao fila[TAMANHO * TAMANHO];
    int inicio = 0, fim = 0;
    
    fila[fim].linha = linhaInicio;
    fila[fim].coluna = colunaInicio;
    fila[fim].distancia = 0;
    fim++;
    visitado[linhaInicio][colunaInicio] = 1; 
    
    while (inicio < fim) {
        Posicao atual = fila[inicio];
        inicio++;
        
        if (atual.linha == linhaFim && atual.coluna == colunaFim) {
            return atual.distancia;
        }
        
        for (int i = 0; i < 8; i++) {
            int novaLinha = atual.linha + movimentos[i][0];
            int novaColuna = atual.coluna + movimentos[i][1];
            
            if (novaLinha >= 0 && novaLinha < TAMANHO && 
                novaColuna >= 0 && novaColuna < TAMANHO && 
                visitado[novaLinha][novaColuna] == 0) {
                
                visitado[novaLinha][novaColuna] = 1;
                fila[fim].linha = novaLinha;
                fila[fim].coluna = novaColuna;
                fila[fim].distancia = atual.distancia + 1;
                fim++;
            }
        }
    }
    
    return -1; 
}

int main() {
    char inicio[3], fim[3];
    
    while (scanf("%s %s", inicio, fim) != EOF) {
        int linhaInicio = inicio[1] - '1';  
        int colunaInicio = inicio[0] - 'a'; 
        int linhaFim = fim[1] - '1';
        int colunaFim = fim[0] - 'a';
        
        int movimentos = buscaEmLargura(linhaInicio, colunaInicio, linhaFim, colunaFim);
        
        printf("To get from %s to %s takes %d knight moves.\n", inicio, fim, movimentos);
    }
    
    return 0;
}
