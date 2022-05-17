#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct No{
    int dados;
    struct No *esq;
    struct No *dir;
}tNo, *Arvore;

int imprimir (Arvore arv){
    if(arv){
        imprimir(arv->esq);
        printf("%d ", arv->dados);
        imprimir(arv->dir);
    }
    return 0;
}

Arvore inserirNo(Arvore arv, int numero){
    if(!arv){
        arv = (Arvore) malloc(sizeof(tNo));
        arv->dados = numero;
        arv->esq=NULL;
        arv->dir=NULL;
        return arv;
    }else{
        if(numero < arv->dados){
            arv->esq = inserirNo(arv->esq, numero);
        }
        if(numero > arv->dados){
            arv->dir = inserirNo(arv->dir, numero);
        }
    }

    return arv;
}

int buscaDFS(Arvore arv, int numero){
    if(!arv)
        return 0;
    if (arv->dados == numero)
        return 1;
    
    return buscaDFS(arv->esq, numero) || buscaDFS(arv->dir, numero);
}

int main (int argc, char *argv[]){

    Arvore arvore;

    arvore = inserirNo(arvore, 16);
    arvore = inserirNo(arvore, 1);
    arvore = inserirNo(arvore, 6);
    arvore = inserirNo(arvore, 5);
    arvore = inserirNo(arvore, 22);
    arvore = inserirNo(arvore, 3);
    arvore = inserirNo(arvore, 7);
    arvore = inserirNo(arvore, 8);
    arvore = inserirNo(arvore, 16);
    arvore = inserirNo(arvore, 9);
    arvore = inserirNo(arvore, 99);
    arvore = inserirNo(arvore, 23);

    imprimir(arvore);

    printf("Resposta: %s", buscaDFS(arvore, 3)==1? "encontrado" : "não encontrado" );

    return 0;
}