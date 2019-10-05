#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"
#include "lista.h"
#include "movimentacaoDoBloco.h"
#include "pesquisaNaLista.h"
#define tam 20

int verificacaExtencao(char ** comando,char *entrada,char *saida){

    if(strstr(comando[1],".txt")!=NULL  && strstr(comando[1],".txt")!=NULL){
        strcpy(entrada,comando[1]);
        strcpy(saida,comando[2]);
        return 1;
    }
    else
        return 0;
}

FILE* abrirArquivo(char *arqEntrada){
    FILE *arq;

    arq = fopen(arqEntrada, "r+");
    if(arq==NULL)
        arq = NULL;
    return arq;
}

void executarComandosDoArquivo(char *arqEntrada,char *saida){
    FILE *entrada;
    lista l;
    TComandos c;
    char comando[tam];
    TIndice *lista1,*lista2;

    entrada=abrirArquivo(arqEntrada);
    if(entrada==NULL)
        printf("\nArquivo de entrada inexistente");
    else{

        while(strcmp(fgets(comando, tam, entrada),"quit\n")!=0){
            printf("%s", comando);
            if(atoi(comando)!=0){
                strcpy(c.tamanho,comando);
                l=criaLista(atoi(c.tamanho));
            }
            else{
                strcpy(c.comando1,strtok(comando," "));
                strcpy(c.elemento1,strtok(NULL," "));
                strcpy(c.comando2,strtok(NULL," "));
                strcpy(c.elemento2,strtok(NULL," "));
                lista1=pesquisaLista(atoi(c.elemento1),l);
                lista2=pesquisaLista(atoi(c.elemento2),l);

                if(atoi(c.elemento1)!=atoi(c.elemento2)){
                    if(  lista1 != lista2 ){
                            if(strcmp(c.comando1,"move")==0){
                                if(strcmp(c.comando2,"onto")==0){
                                    moveOnto(atoi(c.elemento1),atoi(c.elemento2),l);
                                }
                                else
                                    moveOver(atoi(c.elemento1),atoi(c.elemento2),l);

                            }
                            else{
                                if(strcmp(c.comando1,"pile")==0){
                                    if(strcmp(c.comando2,"onto")==0){
                                        pileOnto(atoi(c.elemento1),atoi(c.elemento2),l);
                                    }
                                    else
                                        pileOver(atoi(c.elemento1),atoi(c.elemento2),l);
                                }
                            }

                            testeDaLista(l,atoi(c.tamanho));
                    }
                }
            }

        }

        fclose(entrada);
        GravaListaNoArqDeSaida(saida,l);
        liberaLista(l);
    }
}
