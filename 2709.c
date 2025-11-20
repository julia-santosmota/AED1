#include <stdio.h>
#include <math.h>

int eh_primo(int x) {
    if (x < 2) return 0;
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0){
          return 0;
        }
    }
    return 1;
}

int main() {
    int M;
    while (scanf("%d", &M) != EOF) {
        int moedas[M];
        for (int i = 0; i < M; i++)
            scanf("%d", &moedas[i]);
        int N;
        scanf("%d", &N);

        int soma = 0;
        for (int i = M-1; i >= 0; i -= N)
            soma += moedas[i];

        if (eh_primo(soma)){
            printf("You’re a coastal aircraft, Robbie, a large silver aircraft.\n");
        }
        else {
            printf("Bad boy! I’ll hit you.\n");
        }
    }
    return 0;
}
