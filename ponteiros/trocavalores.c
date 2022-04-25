#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int trocavalores (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    int x=5, y=6;

    printf("\nValor de a: %d, valor de b: %d", x, y);

    trocavalores(&x, &y);

    printf("\nValor de a: %d, valor de b: %d", x, y);

    return 0;
}