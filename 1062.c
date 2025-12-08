/* 
Beecrowd 1062: Trilhos
assuntos: pilhas
*/

#include <stdio.h>

#define MAX 1005

int main() {
    int N;
    while (scanf("%d", &N), N != 0) {
        int alvo[MAX];

        while (1) {
            int topo = 0; 
            int stack[MAX];
            int i, ok = 1;

            scanf("%d", &alvo[0]);
            if (alvo[0] == 0) break;

            for (i = 1; i < N; i++) scanf("%d", &alvo[i]);

            int proximo = 1;
            for (i = 0; i < N; i++) {
                int vagaoDesejado = alvo[i];

                while (proximo <= N && (topo == 0 || stack[topo-1] != vagaoDesejado)) {
                    stack[topo++] = proximo++;
                }

                if (stack[topo-1] != vagaoDesejado) {
                    ok = 0;
                    break;
                } 
                else {
                    topo--;
                }
            }

            if (ok) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
