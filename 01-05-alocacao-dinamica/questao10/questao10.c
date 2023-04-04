#include <stdio.h>
#include <stdlib.h>
void swap(int *i, int *j) {
    int *tmp; //erro, ponteiro tmp não foi alocado
    tmp = (int *) malloc(sizeof(int)); //correção
    *tmp = *i;
    *i = *j;
    *j = *tmp;
}

int main (int argc, char ** argv){
    int a=1, b=2;
    printf("Valor de a=%d e de b=%d\n", a, b);
    swap(&a, &b);
    printf("Valor de a=%d e de b=%d\n", a, b);
    return 0;
}
