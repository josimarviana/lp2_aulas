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