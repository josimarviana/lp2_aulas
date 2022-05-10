#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct data{
    int dia, mes, ano;
}tData;

typedef struct ordem_servico{
    
    int nOS;
    tData data;
    char servico[30];
    struct ordem_servico *proximo;
    struct ordem_servico *anterior;

}tOS, *pOS;

pOS lista, ultimo;
int cadastrar(int,  char *);
int entrar();
pOS verificar(pOS );
pOS consultar(pOS , int );
int excluir(pOS );
int imprimir(pOS );
int salvar(pOS );
pOS carregar();
int menu();       

int cadastrar(int nOS, char *servico){
    
    pOS novaOS = malloc(sizeof(tOS));
    if(!novaOS){
        printf("Falha ao alocar memória para a OS");
        return 1;
    }
    if(!lista)
        lista=novaOS;
    if(ultimo){
        ultimo->proximo=novaOS;
        novaOS->anterior=ultimo;
    }
    novaOS->nOS = nOS;
    strcpy(novaOS->servico, servico);
    printf("\nOS %d cadastrada com sucesso!", novaOS->nOS);
    ultimo = novaOS;
    return 0;
}

int entrar(){
    int nOS;
    char servico[30];
    printf("\nDigite o n. da OS: ");
    scanf("%d", &nOS);

    if(!consultar(lista, nOS)){
        getchar();
        printf("\nDigite o serviço da OS: ");
        scanf("%s", &servico);
        cadastrar(nOS, servico);
    }
    else    
        printf("\nEssa OS já está registrada");
}

pOS verificar(pOS p){
    int nOS;
    printf("\nDigite o n. da OS procurada: ");
    scanf("%d", &nOS);
    return consultar(p, nOS);
}

pOS consultar(pOS p, int OSprocurada){

    while (p){
        if(p->nOS==OSprocurada){
            printf("OS %d encontrada, serviço executado: %s", p->nOS, p->servico);
            return p;
        }
        p=p->proximo;
    }

    printf("OS não localizada");
    return NULL;
}

int excluir(pOS p){
        pOS OSemremocao = verificar(p);
        if(OSemremocao){
            getchar();
            printf("\nTem certeza que deseja excluir a OS %d (y/n)? ", OSemremocao->nOS);
            char resposta = getchar();
            if(resposta == 'y' || resposta == 'Y'){

                pOS OSanterior = OSemremocao->anterior;
                if(!OSanterior){
                    lista=OSemremocao->proximo;
                    lista->anterior=NULL;
                }
                else{
                    OSanterior->proximo = OSemremocao->proximo;
                    OSemremocao->proximo->anterior = OSanterior;
                }    
                printf("\nOS %d removida com sucesso!", OSemremocao->nOS);
            }
        }

    return 0;
}
int imprimir(pOS p){
    printf("OSs: "); 
    while (p){
        printf("%d - %s ; ", p->nOS, p->servico);
        p=p->proximo;
    }
}

int salvar(pOS p){
    int qtdeRegistros=0;
    FILE *arquivo = fopen("saida.dat", "w");
    if(!arquivo){
        printf("\nNão foi possível abrir o arquivo para gravação");
        return 1;
    }
     
    while (p){
        fprintf(arquivo,"%d ",p->nOS);
        fputs(p->servico, arquivo);
        putc('\n', arquivo);
        qtdeRegistros++;
        p=p->proximo;
    }
    printf("\nForam gravados %d registros no arquivo",qtdeRegistros);
    fclose(arquivo);
}

pOS carregar(){
    int qtdeRegistros=0;
    char servico[30];
    FILE *arquivo = fopen("saida.dat", "r");
    if(!arquivo){
        printf("\nNão foi possível abrir o arquivo para leitura");
        return 1;
    }

    while (1){
        int nOS;
        if(fscanf(arquivo, "%d ", &nOS)>0 && !feof(arquivo)){
            fgets(servico, 30, arquivo);
            qtdeRegistros++;
        }else
            break;
        cadastrar(nOS, servico);

        if(feof(arquivo))
            break;
    }
    printf("\nForam carregados %d registros no arquivo",qtdeRegistros);
    return lista;
    fclose(arquivo);

}

int menu(){

    int opcao=1;
    do{
  //      system("clear || cls");
        printf("\n\tSistema de OSs\t\n");
        printf("\n1. Cadastrar");
        printf("\n2. Consultar");
        printf("\n3. Excluir");
        printf("\n4. Salvar OSs no arquivo");
        printf("\n5. Carregar OSs do arquivo");
        printf("\n6. Imprimir");
        printf("\n0. Sair");
        printf("\n\n");
        printf("\nEscolha uma opção: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            entrar();
            break;
        case 2:
            verificar(lista);
            break;
        case 3:
            excluir(lista);
            break;
        case 4:
            salvar(lista);
            break;
        case 5:
            lista = carregar();
            break;
        case 6:
            imprimir(lista);
            break;               
        default:
            break;
        }


    }while(opcao);


}

int main(){

    setlocale(LC_ALL, "");
    menu();
}




