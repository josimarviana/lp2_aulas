#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10


int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");

    typedef struct {
        int dia;
        int mes;
        int ano;
    } data;

    typedef struct {
        int numeroOS;
        data dataOS;
        float valor;
        char servicoRealizado[50];
        char cliente[20];

    } Ordem_Servico;

    Ordem_Servico OS[TAM],*pOS=&OS;
    Ordem_Servico *pOSMatriz[TAM];//matriz de ponteiros
    pOSMatriz[0]=pOS;
    OS[0].numeroOS = 1;
    OS[0].dataOS.dia = 1;
    OS[0].dataOS.mes = 1;
    OS[0].dataOS.ano = 2021;
    pOS->valor = 100.0;
    strcpy(OS[0].servicoRealizado, "Reparo x");
    strcpy(OS[0].cliente, "Josimar");

    OS[1].numeroOS = 2;
    OS[1].dataOS.dia = 2;
    OS[1].dataOS.mes = 2;
    OS[1].dataOS.ano = 2022;
    pOS++;
    pOS->valor = 200.0;
    strcpy(OS[1].servicoRealizado, "Reparo y");
    strcpy(OS[1].cliente, "Maria");

    pOSMatriz[1]=pOS;

    printf("\nOS %d", pOSMatriz[0]->numeroOS);
    printf("\nOS %d", pOSMatriz[1]->numeroOS);
    return 0;
}