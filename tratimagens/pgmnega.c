#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main (int argc, char *argv[]){
    FILE *entrada;
    entrada = fopen("lena.pgm", "r");
    if(!entrada){
        printf("Não foi possível abrir arquivo");
        return 1;
    }

    char tipo[2];
    fscanf(entrada, "%s", tipo);
    printf("tipo detectado: %s", tipo);

    int linhas=0, colunas=0;
    fscanf(entrada, "%d %d", &linhas, &colunas);
    printf("\ncolunas %d - linhas: %d", colunas, linhas);

    int figura[colunas][linhas];
    int maximo;
    fscanf(entrada, "%d", &maximo);
    printf("\nMaximo: %d \n", maximo);

    for (int i=0; i<colunas;i++){
         for (int j=0; j<linhas;j++){
             fscanf(entrada, "%d", &figura[i][j]); 
        }   
    }

    
   fclose(entrada);

    FILE *saida;
    saida = fopen("lena_invertido.pgm", "w");
    if(!saida){
        printf("Não foi possível abrir arquivo");
        return 1;
    }

    fprintf(saida, "%s\n", tipo);
    fprintf(saida, "%d %d\n", linhas, colunas);
    fprintf(saida, "%d\n", maximo);


    for (int i=0; i<colunas;i++){
         for (int j=0; j<linhas;j++){
             
             fprintf(saida, "%d ", maximo-figura[i][j]); 
             

        }  fprintf(saida,"\n");
    }


    fclose(saida);  //inserindo comentários para testar o git

}
