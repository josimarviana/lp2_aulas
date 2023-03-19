#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10


int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    int vetor[10], *p=vetor, i=0;

    for (; i<TAM;i++,p++){
        printf("\nInforme o %dº valor: ", i+1);
        scanf("%d", p);
    }
    p--;
    i--;
    printf("\nValores invertidos: ");
    for (;i>=0;i--,p--){
        printf("%d ", *p);
    }


    return 0;
}