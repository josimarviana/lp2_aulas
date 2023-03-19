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
    // fila[u++] = i; // ou assim na mesma instrução
    return;
}

int dequeue(void){
    if(p>=u){
        printf("A fila terminou\n");
        return NULL;
    }
    p++;
    return fila[p-1];
    // return fila[p++]; // ou assim na mesma instrução
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
    mostra();
    enqueue(5);
    mostra();
    printf("\nElemento retirado: %d", dequeue());
    mostra();
    enqueue(7);
    printf("\nElemento retirado: %d", dequeue());
    mostra();

    return 0;
}
