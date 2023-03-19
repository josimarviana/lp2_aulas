#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

aplica (int (ponteiroparafuncao)(int), char *string){
    for (int i=0;string[i];i++){
        string[i] = ponteiroparafuncao(string[i]);
    }
}

int tiravogal(int c){
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return '-';
    default:
        return c;
    }
}

int main(int argc, char *argv[]){
    
    char frase[50] = "A frase mais bonita que eu ja fiz";

    printf("\n%s", frase);
    aplica(toupper, frase);

    printf("\n%s", frase);
    aplica(tolower, frase);
    printf("\n%s", frase);

    aplica(tiravogal, frase);
    printf("\n%s", frase);
}