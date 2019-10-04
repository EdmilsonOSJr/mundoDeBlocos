#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

TIndice* pesquisaLista(int nBloco,lista l){
    int i;

    TNodo *bloco;
    TIndice *listaProcurada;

    for(i=0;i<l->tamanho;i++){

        listaProcurada=l->vetor[i];
        bloco=listaProcurada->first;

        while(bloco!=NULL){
            if(bloco->info==nBloco){
                //printf("%d",(*bloco)->info);
                return listaProcurada;
            }
            //printf("\n%d",(*bloco)->info);
            bloco=bloco->next;
        }
    }
    return NULL;
}

TNodo* pesquisaBloco(int nBloco,lista l){
    int i;

    TNodo*bloco;

    for(i=0;i<l->tamanho;i++){
        bloco=l->vetor[i]->first;

        while(bloco!=NULL){
            if(bloco->info==nBloco){
                //printf("%d",(*bloco)->info);
                return bloco;
            }
            //printf("\n%d",(*bloco)->info);
            bloco=bloco->next;
        }
    }
    return NULL;
}
