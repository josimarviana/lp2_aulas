// Faça um programa que leia uma série de alunos de um arquivo texto passado via
// linha de comando. Cada aluno é composto de:
//
//- Nome (até 30 caracteres).
//- Semestre (inteiro).
//- Rendimento acadêmico (real).
//
// Considere que cada um dos atributos do aluno está em uma linha separada do arquivo.
// Por fim, leia um inteiro x do usuário e informe quais os alunos que estão cursando o semestre x.

#include "stdio.h"
#include "stdlib.h"
#define TAM 100
typedef struct registro_aluno{
    char nome[30];
    int semestre;
    float rendimento;
}taluno;
int main (int argc, char ** argv){
    if (argc<2){
        printf("Informe o nome do arquivo via linha de comando");
        return 1;
    }
    FILE * arquivo = fopen(argv[1], "r");
    if(!arquivo){
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    taluno alunos[TAM];
    int qtde=0;
    while(!feof(arquivo)){
        char ch;
        int pos=0;
        do{
            ch = fgetc(arquivo);
            //printf("%c", ch);
            if (ch != '\n') //evita a leitura da quebra de linha
                alunos[qtde].nome[pos] = ch;
            else //troca a quebra de linha pelo terminador de string
                alunos[qtde].nome[pos]= '\0';
            pos++;
        }while(ch != '\n'); //até que seja alcançado o fim da linha
        //fscanf(arquivo, "%s", alunos[qtde].nome);
        fscanf(arquivo, "%d", &alunos[qtde].semestre);
        fscanf(arquivo, "%f", &alunos[qtde].rendimento);
        fgetc(arquivo);
        qtde++;
    }

    printf("Digite o dígito do semetre para fazer uma busca: ");
    int semestre=0;
    scanf("%d", &semestre);

    printf("Lista de alunos do %d semestre:\n ");
    for (int i=0; i< qtde; i++){
        if(alunos[i].semestre == semestre)
            printf("\nAluno %d: %s, %d, %.2f", i+1, alunos[i].nome, alunos[i].semestre, alunos[i].rendimento);
    }

    return 0;
}
