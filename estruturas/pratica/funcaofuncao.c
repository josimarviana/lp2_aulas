#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int mult(int a, int b){
    return a*b;
}

int main(int argc, char *argv[]){
    int (*d)(int, int);
    d = mult;

    printf("%d ", d(3, 4));
    return 0;
}