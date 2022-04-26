#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10

int p=0, u=0, fila[TAM];

int tirardafila(){
    if(p==u){
        printf("A fila está vazia");
        return -1;
    }
    return fila[p++];
}

void colocarnafila(int n){
    if(u==TAM){
        printf("A fila está cheia");
        return;
    }
    fila[u++]=n;
}

void mostrarfila(){
    printf("\n");
    for(int i=0;i<TAM;i++)
        printf("%d ", fila[i]);
    printf("\n");
    return;
}

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    mostrarfila();
    colocarnafila(5);
    mostrarfila();
    colocarnafila(6);
    mostrarfila();
    colocarnafila(7);
    mostrarfila();
   
    printf("%d retirado da fila", tirardafila());
    mostrarfila();
    printf("%d retirado da fila", tirardafila());
    mostrarfila();
    printf("%d retirado da fila", tirardafila());
    mostrarfila();
    printf("%d retirado da fila", tirardafila());
    mostrarfila();
    return 0;
}