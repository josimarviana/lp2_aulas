#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct {
    char inscricao[10];
    char nome[30];

}tCandidato;

typedef struct no{
    tCandidato candidado;
    struct no *proximo;
}tNo, *pLista;

void imprime(pLista p){
    while (p){
        printf("%s - %s\n", p->candidado.inscricao, p->candidado.nome);
        p=p->proximo;
    }
}

insere(pLista p, char *ni, char *nn, char *depoisnome){
    pLista noProcurado=NULL, noNovo;

    while(p && !noProcurado ){
        if(!strcmp(p->candidado.nome, depoisnome)){
            noProcurado=p;            
        }
        else    
            p=p->proximo;
    }

    if(noProcurado)
        noNovo = malloc(sizeof(tNo));
    
    if(noNovo){
        strcpy(noNovo->candidado.inscricao, ni);
        strcpy(noNovo->candidado.nome,nn);
        noNovo->proximo = noProcurado->proximo;
        noProcurado->proximo = noNovo;
    }


    return ;
}
int main (int argc, char *argv[]){
    pLista lista, ponteiroAuxiliar1, ponteiroAuxiliar2, ultimo;

    lista = malloc(sizeof(tNo));
    strcpy(lista->candidado.inscricao, "111");
    strcpy(lista->candidado.nome, "Josimar");
    ultimo = lista;

    ponteiroAuxiliar1 = malloc(sizeof(tNo));

    lista->proximo = ponteiroAuxiliar1;

    strcpy(ponteiroAuxiliar1->candidado.inscricao, "222");
    strcpy(ponteiroAuxiliar1->candidado.nome, "Maria");
    ultimo = ponteiroAuxiliar1;

    ponteiroAuxiliar2 = malloc(sizeof(tNo));
    ponteiroAuxiliar1->proximo = ponteiroAuxiliar2;
    strcpy(ponteiroAuxiliar2->candidado.inscricao,"333");
    strcpy(ponteiroAuxiliar2->candidado.nome, "Pedro");
    ponteiroAuxiliar2->proximo = NULL;
    ultimo = ponteiroAuxiliar2;

    imprime(lista);
    char nomenovo[30] = "Joao";
    char inscricaoNova[10] = "240";
    char depoisNome[30] = "Maria";

    printf("\n\n");
    insere(lista, inscricaoNova,nomenovo, depoisNome);

    imprime(lista);

    return 0;
}