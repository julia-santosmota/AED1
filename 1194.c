#include <stdio.h>
#include <string.h>

void posfixo(char prefixo[], char infixo[], int preInicio, int preFim, int inInicio, int inFim) {
    if (preInicio > preFim || inInicio > inFim) {
        return;
    }

    char raiz = prefixo[preInicio];

    int posRaiz;
    for (posRaiz = inInicio; posRaiz <= inFim; posRaiz++) {
        if (infixo[posRaiz] == raiz) {
            break;
        }
    }

    int tamEsquerda = posRaiz - inInicio;

    posfixo(prefixo, infixo, 
            preInicio + 1,                 
            preInicio + tamEsquerda,      
            inInicio,                       
            posRaiz - 1);               

    posfixo(prefixo, infixo,
            preInicio + tamEsquerda + 1,    
            preFim,                         
            posRaiz + 1,                 
            inFim);                       

    printf("%c", raiz);
}

int main() {
    int C; 
    scanf("%d", &C);
    
    while (C--) {
        int N;  
        char prefixo[55], infixo[55];
        
        scanf("%d %s %s", &N, prefixo, infixo);
        
        posfixo(prefixo, infixo, 0, N - 1, 0, N - 1);
        printf("\n");
    }
    
    return 0;
}
