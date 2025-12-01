#include <stdio.h>

int fib(int n, int *contador) {
    (*contador)++;
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1, contador) + fib(n - 2, contador);
}

int main() {
    int t, n;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        int contador = -1; 
        int resultado = fib(n, &contador);
        printf("fib(%d) = %d calls = %d\n", n, contador, resultado);
    }

    return 0;
}
