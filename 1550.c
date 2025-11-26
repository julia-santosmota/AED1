#include <stdio.h>
#include <string.h>

#define MAX 10000

// função que inverte os dígitos do visor
int reveso(int n) {
    int invertido = 0;
    while (n > 0) {
        invertido = invertido * 10 + n % 10;
        n /= 10;
    }
    return invertido;
}

// algoritmo do bfs (busca em largura) pra encontrar o n° mínimo de acertos
int minimo(int inicio, int alvo) {
    int visitado[MAX*2] = {0};   // marca números visitados
    int fila[MAX*20];             // bfs usa fila
    int passos[MAX*20];           // passos da fila
    int frente = 0, adiciona = 0; // indices da fila

    // inicializando a fila com o número inicial
    fila[adiciona] = inicio;
    passos[adiciona] = 0;  // passos até aqui (camada do grafo)
    adiciona++;
    visitado[inicio] = 1;

    while (frente < adiciona) {
        int passoAtual = fila[frente];
        int qtPassos = passos[frente];
        frente++;

        // se alcançou o alvo (maior igual a B) retorna passo (camada)
        if (passoAtual == alvo) return qtPassos;

        //vizinho 1: +1 (botão que adiciona 1)
        int prox = passoAtual + 1;
        if (prox < MAX*2 && !visitado[prox]) { 
            visitado[prox] = 1;
            fila[adiciona] = prox;
            passos[adiciona] = qtPassos + 1;
            adiciona++;
        }

        // vizinho 2: inverso (botão que inverte)
        prox = reveso(passoAtual);
        if (prox < MAX*2 && !visitado[prox]) {
            visitado[prox] = 1;
            fila[adiciona] = prox;
            passos[adiciona] = qtPassos + 1;
            adiciona++;
        }
    }

    return -1; // Não deveria acontecer
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        printf("%d\n", minimo(A, B));
    }

    return 0;
}
