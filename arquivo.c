#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"
#include "lista.h"
#include "movimentacaoDoBloco.h"
#define tam 20

FILE* abrirArquivo(){
    FILE *arq;
    arq = fopen("comandos.txt", "r+");
    if(arq==NULL)
        arq = fopen("comandos.txt", "w+");
    return arq;
}

void executarComandosDoArquivo(){
    FILE *arq;
    lista l;
    TNodo *b;
    TComandos a;
    char comando[tam];
    int lista1,lista2;

    arq=abrirArquivo();

    while(strcmp(fgets(comando, tam, arq),"quit\n")!=0){
        printf("%s", comando);
        if(atoi(comando)!=0){
            strcpy(a.tamanho,comando);
            l=criaLista(atoi(a.tamanho));
        }
        else{
            strcpy(a.comando1,strtok(comando," "));
            strcpy(a.elemento1,strtok(NULL," "));
            strcpy(a.comando2,strtok(NULL," "));
            strcpy(a.elemento2,strtok(NULL," "));
            lista1=pesquisaBloco(&b,atoi(a.elemento1),l);
            lista2=pesquisaBloco(&b,atoi(a.elemento2),l);

            if(atoi(a.elemento1)!=atoi(a.elemento2)){
                if(  lista1 != lista2 ){
                        if(strcmp(a.comando1,"move")==0){
                            if(strcmp(a.comando2,"onto")==0){
                                moveOnto(atoi(a.elemento1),atoi(a.elemento2),l);
                            }
                            else
                                moveOver(atoi(a.elemento1),atoi(a.elemento2),l);

                        }
                        else{
                            if(strcmp(a.comando1,"pile")==0){
                                if(strcmp(a.comando2,"onto")==0){
                                    pileOnto(atoi(a.elemento1),atoi(a.elemento2),l);
                                }
                                else
                                    pileOver(atoi(a.elemento1),atoi(a.elemento2),l);
                            }
                        }

                        printf("\nTamanho: %s",a.tamanho);
                        printf("\nElemento 1: %s",a.elemento1);
                        printf("\nComando 1: %s",a.comando1);
                        printf("\nComando 2: %s",a.comando2);
                        printf("\nElemento 2: %s",a.elemento2);
                        testeDaLista(l,atoi(a.tamanho));
                }
            }
        }


    }
    fclose(arq);
    liberaLista(l);


}
