#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"
#include "lista.h"
#include "movimentacaoDoBloco.h"

FILE* abrirArquivo(){
    FILE *arq;
    arq = fopen("comandos.txt", "r+");
    if(arq==NULL)
        arq = fopen("comandos.txt", "w+");
    return arq;
}

int lerComandos(){
    int n;
    char comando[100];

    FILE *arq;

    arq=abrirArquivo();

    printf("\nForneça o numero de elementos: ");
    scanf("%d",&n);
    fprintf(arq,"%d\n",n);

    do{
        printf("\nForneça o comando: ");
        setbuf(stdin,NULL);
        fgets(comando,100,stdin);
        setbuf(stdin,NULL);
        if(comando[strlen(comando) - 1] == '\n')
            comando[strlen(comando) - 1] = '\0';
        fprintf(arq,"%s\n",comando);
    }while(strcmp(comando,"quit")!=0);

    fclose(arq);

    /*strcpy(a.elemento1,strtok(comando," "));
    strcpy(a.comando1,strtok(NULL," "));
    strcpy(a.comando2,strtok(NULL," "));
    strcpy(a.elemento2,strtok(NULL," "));

    printf("\nMensagem: %s",comando);

    printf("\nElemento 1: %s",a.elemento1);
    printf("\nComando 1: %s",a.comando1);
    printf("\nComando 2: %s",a.comando2);
    printf("\nElemento 2: %s",a.elemento2);*/
    return n;
}

void executarComandosDoArquivo(lista l){
    FILE *arq;
    TComandos a;
    char comando[20];

    arq=abrirArquivo();

    while(fgets(comando, 20, arq) != NULL){
        //printf("%s", comando);
        if(strlen(comando)<13){
            strcpy(a.tamanho,comando);
        }
        else{
            strcpy(a.elemento1,strtok(comando," "));
            strcpy(a.comando1,strtok(NULL," "));
            strcpy(a.comando2,strtok(NULL," "));
            strcpy(a.elemento2,strtok(NULL," "));


            if(strcmp(a.comando1,"move")==0){
                if(strcmp(a.comando2,"onto")==0){
                    moveOnto(atoi(a.elemento2),atoi(a.elemento1),l);
                }
                else
                    moveOver(atoi(a.elemento2),atoi(a.elemento1),l);

            }
            else{
                if(strcmp(a.comando1,"pile")==0){
                    if(strcmp(a.comando2,"onto")==0){
                        pileOnto(atoi(a.elemento2),atoi(a.elemento1),l);
                    }
                    else
                        pileOver(atoi(a.elemento2),atoi(a.elemento1),l);
                }
            }
            printf("\nTamanho: %s",a.tamanho);
            printf("\nElemento 1: %s",a.elemento1);
            printf("\nComando 1: %s",a.comando1);
            printf("\nComando 2: %s",a.comando2);
            printf("\nElemento 2: %s",a.elemento2);
            testeDaLista(l,7);
        }


    }
    fclose(arq);


}
