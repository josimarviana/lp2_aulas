#include <stdio.h>
#include <stdlib.h>
#define TAM 5
int main(int argc, char **argv){
    float * numeros = (float *) malloc(sizeof(float)*TAM);
    int soma=0; float produto=1;
    printf("Informe uma sequencia de números inteiros ou não");
    for (int i=0;i<TAM;i++){
        printf("\nInforme o %d. número: ", i+1);
        scanf("%f", &numeros[i]);
    }
    for (int i=0;i<TAM;i++){
        int valor = (int) numeros[i];
        if (valor == numeros[i]){
            soma +=numeros[i];
        }else{
            produto*=numeros[i];
        }
    }
    printf("A soma dos inteiros eh: %d", soma);
    printf("\nA multiplicação dos não inteiros eh: %.2f", produto);
    return 0;
}
