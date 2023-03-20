// Escreva um programa em C que leia duas sequências de números inteiros ordenados em dois vetores v1 e v2 .
//Suponha que o número máximo de elementos de cada sequência é 50. O seu programa deve intercalar os valores dos
//dois vetores em um terceiro vetor, mantendo os valores em ordem crescente. Use alocação dinâmica de memória.
//int v1[] = {1, 3, 5, 5, 7, 9, 10};
//int v2[] = {2, 2, 4, 6, 8, 8, 10};
//int v3[] = {1, 2, 2, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 10};

#include "stdio.h"
#include "stdlib.h"
#define TAM 10
int main (int argc, char ** argv) {
    int qtdv1=0, qtdv2=0;
    printf("Informe a quantidade de inteiros para cada vetor: ");
    scanf("%d", &qtdv1);
    qtdv2 = qtdv1; //para simplificar inferimos que os vetores tem o mesmo tamanho

    int *pvetorint1 = (int *) malloc(sizeof(int )* qtdv1);
    int *pvetorint2 = (int *) malloc(sizeof(int )* qtdv2);
    int *pvetorint3 = (int *) malloc(sizeof(int )* (qtdv1+qtdv2));

    for (int i = 0; i < qtdv1; i++) {
        printf("Digite o %do número do vetor 1: ", i+1);
        scanf("%d", &pvetorint1[i]);
    }

    for (int i = 0; i < qtdv2; i++) {
        printf("Digite o %do número do vetor 2: ", i+1);
        scanf("%d", &pvetorint2[i]);
    }

    for (int i = 0, j = 0; i < qtdv1+qtdv2; i++) {
        if(pvetorint1[i]<pvetorint2[i]){
            pvetorint3[i*2]=pvetorint1[i];
            pvetorint3[i*2+1]=pvetorint2[i];
        }else{
            pvetorint3[i*2]=pvetorint2[i];
            pvetorint3[i*2+1]=pvetorint1[i];
        }
    }
    printf("Resultado do v3: ");
    for (int i = 0; i < qtdv1+qtdv2; i++) {

        printf("%d ", pvetorint3[i]);
    }

}
