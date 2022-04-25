#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10


int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");

    struct data{
        int dia;
        int mes;
        int ano;
    };

    struct Ordem_Servico{
        int numeroOS;
        struct data dataOS;
        float valor;
        char servicoRealizado[50];
        char cliente[20];

    } OS[TAM],*pOS=&OS;;

  //  struct Ordem_Servico OS,*pOS=&OS;
  //  struct Ordem_Servico *pOS=&OS;

    OS[0].numeroOS = 1;
    OS[0].dataOS.dia = 1;
    OS[0].dataOS.mes = 1;
    OS[0].dataOS.ano = 2021;
    pOS->valor = 100.0;
    strcpy(OS[0].servicoRealizado, "Reparo x");
    strcpy(OS[0].cliente, "Josimar");


    return 0;
}