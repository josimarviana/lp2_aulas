#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 10

int fila[10];
int p=0;
int u=0;

void enqueue(int i){
    if(u>=MAX){
        printf("Lista cheia\n");
        return;
    }
    fila[u] = i;
    u++;
}

int dequeue(void){
    if(p>=u){
        printf("A fila terminou\n");
        return NULL;
    }
    p++;
    return fila[p-1];

}

void mostra(void){
    printf("\n");
    for (int i=0;i<MAX;i++){
        printf("%d ", fila[i]);
    }

}

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");

    mostra();
    enqueue(4);
    enqueue(5);
    mostra();
    dequeue();
    enqueue(7);
    mostra();

    return 0;
}