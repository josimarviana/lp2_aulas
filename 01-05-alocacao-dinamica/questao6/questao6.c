// Considere a seguinte definição de registro:
//typedef struct{
//char nome[80];
//float nota;
//} t_aluno;
//a) Declare um vetor do tipo t_aluno.
//b) Escreva uma função para ler o nome e a nota de cada aluno.
//c) Escreva uma função para encontrar a maior nota de aluno no vetor. Imprima o nome e a nota em seguida.

#include <stdio.h>
#define TAM 2
typedef struct{
    char nome[80];
    float nota;
} t_aluno;

int ledados(t_aluno * vetoralunos){ //lê as notas
    printf("Informe os dados dos alunos: ");
    for (int i=0;i<TAM;i++){
        printf("\nInforme o nome do %d aluno: ", i+1);
        scanf("%[^\n]", vetoralunos[i].nome);
       // fgets(vetoralunos[i].nome, 80, stdin);
        printf("Informe a nota do %d aluno: ", i+1);
        scanf("%f", &vetoralunos[i].nota);
        getchar();
    }
    return 0;
}

int maiorNota(t_aluno * vetoralunos){ // encontra maior nota
    int indiceMaior;
    float maiorNota;
    for (int i=0;i<TAM;i++){
        if(vetoralunos[i].nota > maiorNota){
            maiorNota=vetoralunos[i].nota;
            indiceMaior=i;
        }
    }
    printf("\nParabéns %s pela nota %.2f, a maior da turma",
           vetoralunos[indiceMaior].nome,
           vetoralunos[indiceMaior].nota);

    return 0;
}

int main (int argc, char ** argv){
    t_aluno valuno[TAM]; // vetor do tipo t_aluno
    if(!ledados(valuno))
        maiorNota(valuno);
    else
        return 1;
    return 0;
}
