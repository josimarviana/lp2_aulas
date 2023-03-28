// Escreva um programa em C leia uma matriz Am×n com números inteiros
// do teclado e então imprime os elementos
// com menor e maior frequência de ocorrência na matriz,
// com: 0 <= m, n <= 100. Use alocação dinâmica de memória.
#include "stdio.h"
#include "stdlib.h"
#define TAM 10
int main (int argc, char ** argv) {
    int n = 0, m = 0;
    printf("Informe os dados da matriz:\n");
    printf("Digite m para a quantidade de linhas: ");
    scanf("%d", &n);
    printf("Digite n para a quantidade de colunas: ");
    scanf("%d", &m);

    int *pvetorint = (int *) malloc(sizeof(int) * n*m);
    int auxn=0, auxm=0;
    for (int i = 0; i < n*m; i++) {
        printf("Digite a posição [%d][%d] da matriz: ", auxn, auxm);
        scanf("%d", &pvetorint[i]);
        auxm++;
        if(auxm>=m){
            auxm=0;
            auxn++;
        }
    }
    int *pfrequencia = (int *) malloc(sizeof(int) * n*m);
    int *pnumeros = (int *) malloc(sizeof(int) * n*m);
    int controle=0, frequencia=0, repetido=0;

    for (int i = 0; i < n*m; i++) {
        repetido=0;
        for (int l = 0; l < controle; l++) {
            if(pvetorint[i] == pnumeros[l]){
                repetido=1;
            }
        }
        if (repetido==1)
            continue;
        for (int j = 0; j  < n*m; j++) {
            if(pvetorint[i] == pvetorint[j]){
                frequencia++;
            }
        }
        pnumeros[controle]=pvetorint[i];
        pfrequencia[controle]=frequencia;
        controle++;
        frequencia=0;

    }

    for (int i=0; i<controle; i++){
        printf("\n%d - %d", pnumeros[i], pfrequencia[i]);
    }
    int maiorFreq, numeroMaior, menorFreq, numeroMenor;

    maiorFreq=pfrequencia[0];
    menorFreq=pfrequencia[0];

    for (int i=0; i<controle; i++){

        if(pfrequencia[i]>maiorFreq)
            numeroMaior = i;
        if(pfrequencia[i]<menorFreq)
            numeroMenor = i;
    }

    printf("\nO inteiro menos frequente eh: %d, que apareceu %d vezes.", pnumeros[numeroMenor], pfrequencia[numeroMenor]);
    printf("\nO inteiro mais frequente eh: %d, que apareceu %d vezes.", pnumeros[numeroMaior], pfrequencia[numeroMaior]);
}

