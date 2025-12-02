#include <stdio.h>

#define MAX 1000000

int pilha[MAX];
int topoPilha;

int fila[MAX];
int iniFila, fimFila;

int heap[MAX];
int tamHeap;

void sobeHeap(int i) {
    while (i > 1) {
        int pai = i / 2;
        if (heap[pai] >= heap[i]) {
          break;
        }
        int tmp = heap[pai];
        heap[pai] = heap[i];
        heap[i] = tmp;
        i = pai;
    }
}

void desceHeap(int i) {
    while (2 * i <= tamHeap) {
        int filho = 2 * i;
        if (filho + 1 <= tamHeap && heap[filho + 1] > heap[filho]) {
          filho++;
        }
        if (heap[i] >= heap[filho]){
          break;
        }
        int tmp = heap[i];
        heap[i] = heap[filho];
        heap[filho] = tmp;
        i = filho;
    }
}

void inserirHeap(int x) {
    heap[++tamHeap] = x;
    sobeHeap(tamHeap);
}

int removerHeap() {
    if (tamHeap == 0) {
      return -1;
    }
    int maior = heap[1];
    heap[1] = heap[tamHeap--];
    desceHeap(1);
    return maior;
}

int main() {
    int n; 

    while (scanf("%d", &n) == 1) {

        topoPilha = 0;
        iniFila = fimFila = 0;
        tamHeap = 0;

        int ehPilha = 1, ehFila = 1, ehFilaPrioridade = 1;

        for (int i = 0; i < n; ++i) {
            int oper, valor;
            if (scanf("%d %d", &oper, &valor) != 2) {
                return 0;
            }

            if (oper == 1) {
                pilha[topoPilha++] = valor;
                fila[fimFila++] = valor;
                inserirHeap(valor);
            } 
            else if {
              (oper == 2) 
            }

                if (topoPilha == 0 || pilha[topoPilha - 1] != valor) {
                  ehPilha = 0;
                }
                else topoPilha--;

                if (iniFila == fimFila || fila[iniFila] != valor) {
                  ehFila = 0;
                }
                else iniFila++;

                if (tamHeap == 0 || removerHeap() != valor) {
                  ehFilaPrioridade = 0;
                }
            } 
            else {
            }
        }

        int total = ehPilha + ehFila + ehFilaPrioridade;
        if (total == 0) {
          printf("impossible\n");
        }
        else if (total > 1) {
          printf("not sure\n");
        }
        else if (ehPilha) {
          printf("stack\n");
        }
        else if (ehFila) {
          printf("queue\n");
        }
        else printf("priority queue\n");
    }

    return 0;
}
