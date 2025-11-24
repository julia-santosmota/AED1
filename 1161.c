#include <stdio.h>

unsigned long long fatorial(int n) {
    unsigned long long fat = 1;
    for (int i = 2; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

int main() {
    int num1, num2;
    while (scanf("%d %d", &num1, &num2) != EOF) {
        unsigned long long f1 = fatorial(num1);
        unsigned long long f2 = fatorial(num2);
        printf("%llu\n", f1 + f2);
    }
    return 0;
}
