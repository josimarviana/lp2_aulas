#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 10

int pilha[10];
int t=0;

void push(int i){
    if(t>=MAX){
        printf("Pilha cheia\n");
        return;
    }
    pilha[t] = i;
    t++;
}

int pop(void){
    t--;
    if(t<0){
        printf("A pilha está vazia\n");
        return 0;
    }

    return pilha[t];

}

void mostra(void){
    printf("\n");
    for (int i=0;i<MAX;i++){
        printf("%d ", pilha[i]);
    }

}

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    
    mostra();
    push(5);
    mostra();
    push(6);
    push(7);
    mostra();
    pop();
    push(8);
    mostra();
    return 0;
}