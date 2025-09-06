/* 1180 Beecrowd: Faça um programa que leia um valor N. Este N será o tamanho de um vetor X[N].
* A seguir, leia cada um dos valores de X, encontre o menor elemento deste vetor
* e a sua posição dentro do vetor, mostrando esta informação. -> Essa versão usa ponteiros. */

#include <stdio.h>

int main(){

    int N;
    scanf("%d", &N);

    int X[N];

    for(int i=0; i<N;i++){
        scanf("%d", &X[i]);
    }

    int menor = X[0];
    int posicao = 0;

    for(int i=1; i<N; i++){
        if(*(X + i) < menor){
            menor = *(X + i);
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);
}
