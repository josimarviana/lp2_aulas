#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10

int t=0, pilha[TAM];

int tirardapilha(){
    if(t<=0){
        printf("A pilha está vazia");
        return -1;
    }
    return pilha[--t];
}

void colocarnapilha(int n){
    if(t==TAM){
        printf("A pilha está cheia");
        return;
    }
    pilha[t++]=n;
}

void mostrarpilha(){
    printf("\n");
    for(int i=0;i<TAM;i++)
        printf("%d ", pilha[i]);
    printf("\n");
    return;
}

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    mostrarpilha();
    colocarnapilha(5);
    mostrarpilha();
    colocarnapilha(6);
    mostrarpilha();
    colocarnapilha(7);
    mostrarpilha();
   
    printf("%d retirado da pilha", tirardapilha());
    mostrarpilha();
    printf("%d retirado da pilha", tirardapilha());
    mostrarpilha();
    printf("%d retirado da pilha", tirardapilha());
    mostrarpilha();
    printf("%d retirado da pilha", tirardapilha());
    mostrarpilha();
    return 0;
}