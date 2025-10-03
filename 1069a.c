/* # 1069 Beecrowd: Diamantes e Areia
-> Esta versão foi a que pensei primeiro, lembra
o uso de pilhas, mas é mais próximo de um contador */

#include <stdio.h>

int main() {
    int n;
    int leitura;

    leitura = scanf("%d", &n);
    if (leitura != 1) {
        return 0;
    }

    char string[1001];

    for (int i = 0; i < n; i++) {
        leitura = scanf("%s", string);
        if (leitura != 1) {
            break;
        }

        int aberto = 0;
        int diamantes = 0;

        for (int j = 0; string[j] != '\0'; j++) {
            if (string[j] == '<') {
                aberto++; 
            } else if (string[j] == '>' && aberto > 0) {
                aberto--;
                diamantes++;
            }
        }

        printf("%d\n", diamantes);
    }

    return 0;
}
