//Escreva um programa em C que leia 10 números de ponto flutuante
//em um vetor. Em seguida, o seu programa deve calcular a média
//dos valores armazenados no vetor e imprimir este valor.
//Use alocação dinâmica de memória.

#include "stdio.h"
#include "stdlib.h"
#define TAM 10
int main (int argc, char ** argv){
    float * pfloat = (float *) malloc(sizeof (float)*TAM), media=0.0;
    for (int i=0;i<TAM;i++, pfloat++){
        printf("Digite o %do número: ", i+1);
        scanf("%f", pfloat);
        media+=*pfloat;
    }
    printf ("Média: %.2f", media/=TAM);
 }