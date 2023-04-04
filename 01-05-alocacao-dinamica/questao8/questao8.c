// Escreva um algoritmo em linguagem C que atenda os seguintes requisitos:
// Crie um registro para armazenar o seu Nome Completo e sua matrícula.
// Solicite ao usuário que digite o sua matrícula e o seu Nome Completo.
// Crie um ponteiro para o registro.
// Através do ponteiro para o registro verifique se a matrícula digitado é um número par ou ímpar e informe a
//resposta na tela.
// Através do ponteiro para o registro imprima o Nome Completo informado de traz para frente, invertido. Por
//exemplo:
//Josimar Viana -> anaiV ramisoJ

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[80];
    char matricula[11];
} t_aluno;

int verificaMatricula(t_aluno *aluno){
    char *p = &aluno->matricula;
    int numero=0;
    while(*p){
        numero=*p;
        p++;
    }
    printf("A matricula %s par\n", (numero-48)%2== 0?"eh":"nao eh");
    return 0;
}

int inverteNome(t_aluno *aluno){
    char *p = &aluno->nome;
    int tam=0;
    while(*p){
        p++;
        tam++;
    }
    p--;
    while(tam>0){
        printf("%c", *p);
        tam--;
        p--;
    }
    return 0;
}

int main(int argc, char **argv){
    t_aluno aluno;

    printf("Informe os dados do aluno:");
    printf("\nInforme a matrícula do aluno: ");
    scanf("%[^\n]", aluno.matricula);
    getchar();
    printf("Informe o nome do aluno: ");
    scanf("%[^\n]", aluno.nome);

    t_aluno *paluno=&aluno;
    verificaMatricula(paluno);
    inverteNome(paluno);

}