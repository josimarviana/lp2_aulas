//Dizemos que uma matriz quadrada de números inteiros distintos
// é um quadrado mágico se a soma dos elementos de
//cada linha, a soma dos elementos de cada coluna e a soma dos
// elementos da diagonal principal e secundária são todas iguais.
//Dada uma matriz quadrada de números inteiros An×n , com: 1 <= n <= 100
// escreva um programa em C que verifique se A é um quadrado mágico.
// Use alocação dinâmica de memória.

#include "stdio.h"
#include "stdlib.h"
#include<time.h>
int main (int argc, char ** argv) {
    srand(time(NULL));
    int n=0;
    printf("Informe a quantidade de elementos em cada linha ou coluna: ");
    scanf("%d", &n);

    int *pInt = (int *) malloc(sizeof(int)*n*n);

    for (int i = 0; i < n*n; i++) {
        //printf("Digite o %do número do vetor 1: ", i+1);
        //scanf("%d", &pInt[i]);
        pInt[i] = rand() % 100;
    }

    for (int i = 0; i < n*n; i++) {
            printf("%d ", pInt[i]);
            if((i+1)%n==0)
                printf("\n");
    }


    //rand() % 100;


}
