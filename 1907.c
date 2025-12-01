#include <stdio.h>

#define MAX 1024

char imagem[MAX][MAX];
int visitado[MAX][MAX];

int filaX[MAX * MAX];
int filaY[MAX * MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int inicioX, int inicioY, int linhas, int colunas) {
    int frente = 0, tras = 0;

    filaX[tras] = inicioX;
    filaY[tras] = inicioY;
    tras++;

    visitado[inicioX][inicioY] = 1;

    while (frente < tras) {
        int x = filaX[frente];
        int y = filaY[frente];
        frente++;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < linhas && ny >= 0 && ny < colunas) {
                if (!visitado[nx][ny] && imagem[nx][ny] == '.') {
                    visitado[nx][ny] = 1;
                    filaX[tras] = nx;
                    filaY[tras] = ny;
                    tras++;
                }
            }
        }
    }
}

int main() {
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);

    for (int i = 0; i < linhas; i++) {
        scanf("%s", imagem[i]);
    }

    int cliques = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (imagem[i][j] == '.' && !visitado[i][j]) {
                bfs(i, j, linhas, colunas);
                cliques++;
            }
        }
    }

    printf("%d\n", cliques);

    return 0;
}
