#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 10

char *pnomes[10];
int p=0;
int u=0;

void insere(char *nome){
    if(u>=MAX){
        printf("Lista cheia\n");
        return;
    }
    pnomes[u] = *nome;
    u++;
}

char *retira(void){
    if(p>=u){
        printf("A fila terminou\n");
        return NULL;
    }
    p++;
    return pnomes[p-1];

}

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");


    

    return 0;
}