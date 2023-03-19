#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#define MAX 1000-1
int x=0,y=0;
int retornamaior(int vetor[], unsigned int tamanho){
    int maior=0,i; 
    for(i=0; i<tamanho ;i++){
     //   printf("%d ", vetor[i]);
        if(vetor[i]>maior)
        maior=vetor[i]; 
    }
   // return maior;
    return i;
} // T = an + b

int retornamaiormatriz(int *matriz, unsigned int tamanho){
    int maior=0,x=0; 
    for(int i=0; i<tamanho ;i++){     
         for(int j=0; j<tamanho ;j++){
             x++;
            if(*matriz>maior)
                 maior=*matriz; 
        }

    }
   // return maior;
    return x;
} // T = an + b

int retornaprimeiro(int vetor[], unsigned int tamanho){
    int i=0;
    i++;
   // return vetor[0];
   return i;
} // T = 1

int buscabinaria (int vetor[],  unsigned int tamanho,int chave)
{   
     int i=0;
     int inf = 0;     // limite inferior (o primeiro índice de vetor em C é zero          )
     int sup = tamanho-1; // limite superior (termina em um número a menos. 0 a 9 são 10 números)
     int meio;
     while (inf <= sup)
     {
          meio = (inf + sup)/2;
          i++;
          if (chave == vetor[meio])
             //  return meio;
               return i;
          if (chave < vetor[meio])
               sup = meio-1;
          else
               inf = meio+1;
     }
    // return -1;   // não encontrado
    return i;
}

int inicializavetor(int vetor[], int tam){
       srand((unsigned) time(NULL));
       for(int i=0; i<tam; i++){
            vetor[i]=rand()%MAX;
    } 
}

int imprimevetor(int vetor[], int tam){

       for(int i=0; i<tam; i++){
            printf("%d ", vetor[i]);
        } 
    printf("\n");
}

int inicializamatriz(int *matriz, int tam){
       srand((unsigned) time(NULL));

       for(int i=0; i<tam; i++){
            for(int j=0; j<tam; j++){
                *matriz=rand()%MAX;
                matriz++;
            } 
        } 
}

int fibonacci(int n){

       if (n<=1){
           return n;
       }
       x++;
       return fibonacci(n-2)+fibonacci(n-1);
      
}

// Função que imlementa Insertioin Sort
int InsertionSort(int vetor[], int tamanho){
    int i, j, chave;
     //Compare a chave com cada elemento à esquerda dela até que um elemento menor do que seja encontrado.
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
    return vetor;
}

int main(int argc, char *argv[]){
    
    setlocale(LC_ALL, "");
    int v10[10];
    int v100[100];
    int v100000[100000];
    int matriz[100][100];

    inicializavetor(v100, 100);
    printf("\nQtde operações - constante - o(1): %d", retornaprimeiro(v100, 100));
    printf("\nQtde operações - linear - o(n): %d", retornamaior(v100, 100));

    InsertionSort(v100, 100);
  //  imprimevetor(v100, 100);
    printf("\nQtde operações - quasilinear - O(log n): %d", buscabinaria(v100, 100, 521));
    inicializamatriz(matriz, 100);

    printf("\nQtde operações - quadrático - O(n2): %d", retornamaiormatriz(matriz, 100));
    fibonacci(10);
    printf("\nQtde operações - exponencial - O(2n): %d", x);

    return 0;
}