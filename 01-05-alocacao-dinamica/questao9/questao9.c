#include <stdio.h>
#include <stdlib.h>
#define TAM 3

int leVetor (int * numeros){
    printf("Informe uma sequencia de números inteiros\n");
    for (int i=0;i<TAM;i++){
        printf("Informe o %d. número: ", i+1);
        scanf("%d", &numeros[i]);
    }

    return 0;
};

int maiorElemento(int * vetor){ // encontra maior nota
    int indiceMaior=0, maior=0;
    for (int i=0;i<TAM;i++){
        if(vetor[i] > maior){
            maior=vetor[i];
            indiceMaior=i;
        }
    }
    printf("\nMaior elemento %d, na posicao %d",
           vetor[indiceMaior],
           indiceMaior);

    return 0;
}

int main (int argc, char ** argv) {
    int * numeros = (int *) malloc(sizeof(int)*TAM);
    leVetor(numeros);
    maiorElemento(numeros);
    return 0;
}
