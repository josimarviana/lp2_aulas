#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define dict_size 280000
//#define dict_size 20
#define word_size 20

char palavras[dict_size][word_size];

int loadDictionary(){
    FILE * dict_file = fopen("brazilian.txt", "r");
    int i=0;
    if(!dict_file){
        printf("\nNão foi possível carregar o dicionário");
        exit(1);
    }

    fgets(palavras[i++], word_size, dict_file);
    while (!feof(dict_file) && i < dict_size){

        if(!feof(dict_file)){
            fgets(palavras[i++], word_size, dict_file);

        }
    }
/*
    for (i=0; i<dict_size;i++){
        printf("%s", palavras[i]);
    }
*/
    fclose(dict_file);
}

int BinarySearch (char *chave)
{
     int inf = 0;     // limite inferior (o primeiro índice de vetor em C é zero          )
     int sup = dict_size-1; // limite superior (termina em um número a menos. 0 a 9 são 10 números)
     int meio;
     while (inf <= sup)
     {
          meio = (inf + sup)/2;
          printf("\npalavra meio: %s %s", palavras[meio], chave);
          if (strcmp(palavras[meio], chave)==0)
               return meio;
          if (strcmp(palavras[meio], chave)>0)
               sup = meio-1;
          else
               inf = meio+1;
     }
     return -1;   // não encontrado
}

int main (int argc, char * argv[]){

    printf("\nComeçando...\n");
    loadDictionary();
    printf("resutado: %d", BinarySearch ("melancia"));
    return 0;
}
