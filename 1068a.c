/* #1068 Beecrowd: Balanço de Parênteses I (versão com pilha e vetor) */

#include <stdio.h>

int balanceada(char s[]) {
    char pilha[1001];
    int topo = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') { // push / empilha '('
            pilha[++topo] = '(';
        } 
        else if (s[i] == ')') { // pop / desempilha
            if (topo == -1) {
                return 0;
            }
            topo--;
        }
    }

    return (topo == -1);
}

int main() {
    char string[1001];
    while (scanf("%s", string) != EOF) {
        if (balanceada(string)) {
            printf("correct\n");
        }
        else {
            printf("incorrect\n");
        }
    }

    return 0;
}
