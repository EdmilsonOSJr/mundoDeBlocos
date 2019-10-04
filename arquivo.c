#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"
#include "lista.h"
#include "movimentacaoDoBloco.h"
#include "pesquisaNaLista.h"
#define tam 20

FILE* abrirArquivo(){
    FILE *arq;

    arq = fopen("comandos.txt", "r+");
    if(arq==NULL)
        arq = NULL;
    return arq;
}

void GravaNoArqDeSaida(lista l){
    FILE *saida;
    TNodo *blocoPercorriddo;
    int i;

    saida = fopen("saida.txt", "w+");

    for(i=0;i<l->tamanho;i++){
        blocoPercorriddo=l->vetor[i]->first;
        fprintf(saida,"\n%d: ",i);
        while(blocoPercorriddo!=NULL){
            fprintf(saida,"%d ",blocoPercorriddo->info);
            blocoPercorriddo=blocoPercorriddo->next;
        }
    }

    fclose(saida);
}

void executarComandosDoArquivo(){
    FILE *entrada;
    lista l;
    TComandos c;
    char comando[tam];
    TIndice *lista1,*lista2;

    entrada=abrirArquivo();
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
        GravaNoArqDeSaida(l);
        liberaLista(l);
    }
}
