#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    char *p = "Josimar Viana";
    int i=0;
    while (*p){
        i++;
        p++;
    }


    printf("\nO tamanho da string é: %d", i);

    return 0;
}