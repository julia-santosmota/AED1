#include <stdio.h>
#include <string.h>

void posfix(char prefixo[], char infixo[], int preStart, int preEnd, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) return;

    char raiz = prefixo[preStart];

    int raizIdx;
    for (raizIdx = inStart; raizIdx <= inEnd; raizIdx++) {
        if (infixo[raizIdx] == raiz) break;
    }

    int tamEsq = raizIdx - inStart; 

    posfix(prefixo, infixo, preStart+1, preStart+tamEsq, inStart, raizIdx-1);
    posfix(prefixo, infixo, preStart+tamEsq+1, preEnd, raizIdx+1, inEnd);
    printf("%c", raiz);
}

int main() {
    int C;
    scanf("%d", &C);
    while(C--) {
        int N;
        char prefixo[55], infixo[55]; 
        scanf("%d %s %s", &N, prefixo, infixo);
        posfix(prefixo, infixo, 0, N-1, 0, N-1);
        printf("\n");
    }
    return 0;
}
