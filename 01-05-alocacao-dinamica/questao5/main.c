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
    int n=0, maximo=2;
    printf("Informe a quantidade de elementos em cada linha ou coluna: ");
    scanf("%d", &n);

    int *pInt = (int *) malloc(sizeof(int)*n*n);

/*    for (int i = 0; i < n*n; i++) {
        //printf("Digite o %do número do vetor 1: ", i+1);
        //scanf("%d", &pInt[i]);
        pInt[i] = rand() % maximo; //gera aleatório de 0 até maximo-1
    }*/

    int auxn=0, auxm=0, m=n;
    for (int i = 0; i < n*n; i++) {
        printf("Digite a posição [%d][%d] da matriz: ", auxn, auxm);
        scanf("%d", &pInt[i]);
        auxm++;
        if(auxm>=m){
            auxm=0;
            auxn++;
        }
    }
    int *pvetorColunas = (int *) malloc(sizeof(int)*n);
    int *pvetorLinhas = (int *) malloc(sizeof(int)*n);
    int *pdiagPrincipal = (int *) malloc(sizeof(int)*n);
    int *pdiagSecundaria = (int *) malloc(sizeof(int)*n);
    int acumula=0, soma=0, controle=0;
    for (int i = 0; i < n*n; i++) {
            printf("%d ", pInt[i]);
            soma+=pInt[i];
            if((i+1)%n==0){
                pvetorLinhas[controle]=soma;
                controle++;
                soma=0;
                printf("\n");
            }
    }
    printf("\nExibindo soma das linhas:");
    for (int i = 0; i < controle; i++) {
        printf("%d ", pvetorLinhas[i]);
    }
}
