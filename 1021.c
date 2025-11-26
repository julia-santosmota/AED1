#include <stdio.h>

int main() {
    double N;
    
    scanf("%lf", &N);

    int centavos = (N * 100) + 0.5;

    printf("NOTAS:\n");

    printf("%d nota(s) de R$ 100.00\n", centavos / 10000);
    centavos = centavos % 10000; 

    printf("%d nota(s) de R$ 50.00\n", centavos / 5000);
    centavos = centavos % 5000;

    printf("%d nota(s) de R$ 20.00\n", centavos / 2000);
    centavos = centavos % 2000;

    printf("%d nota(s) de R$ 10.00\n", centavos / 1000);
    centavos = centavos % 1000;

    printf("%d nota(s) de R$ 5.00\n", centavos / 500);
    centavos = centavos % 500;

    printf("%d nota(s) de R$ 2.00\n", centavos / 200);
    centavos = centavos % 200;

    printf("MOEDAS:\n");

    printf("%d moeda(s) de R$ 1.00\n", centavos / 100);
    centavos = centavos % 100;

    printf("%d moeda(s) de R$ 0.50\n", centavos / 50);
    centavos = centavos % 50;

    printf("%d moeda(s) de R$ 0.25\n", centavos / 25);
    centavos = centavos % 25;

    printf("%d moeda(s) de R$ 0.10\n", centavos / 10);
    centavos = centavos % 10;

    printf("%d moeda(s) de R$ 0.05\n", centavos / 5);
    centavos = centavos % 5;

    printf("%d moeda(s) de R$ 0.01\n", centavos / 1);
    
    return 0;
}
