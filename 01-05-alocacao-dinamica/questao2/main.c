//Escreva um programa em C que leia 10 números inteiros em um vetor. 
//Em seguida, o seu programa deve ler um outro número inteiro x. 
//O programa deve então encontrar dois números de posições distintas do 
//vetor cuja multiplicação seja x e imprimi-los.
//Caso não existam tais números, o programa deve informar isto.
//Use alocação dinâmica de memória.

//int v[] = {2, 4, 5, -10, 7, 3, 2, 1, 0, 1};
//x = 35;
//Resultado = 5, 7

#include "stdio.h"
#include "stdlib.h"
#define TAM 10
int main (int argc, char ** argv) {
    int *pvetorint = (int *) malloc(sizeof(int) * TAM);
    int *pint = (int *) malloc(sizeof(int) * TAM);

    for (int i = 0; i < TAM; i++) {
        printf("Digite o %d o número: ", i+1);
        scanf("%d", &pvetorint[i]);
    }
    printf("Digite o número produto: ");
    scanf("%d", pint);


    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j + i < TAM; j++) {
            if(*pint / pvetorint[i] == pvetorint[j]){
                printf("Números encontrados: %d x %d = %d", pvetorint[i], pvetorint[j], *pint);
                exit(0);
            }
        }
    }
    printf("Os números não foram encontrados");
    return 0;
}