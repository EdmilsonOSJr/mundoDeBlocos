#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void GravaListaNoArqDeSaida(char *arqSaida,lista l){
    FILE *saida;
    TNodo *blocoPercorriddo;
    int i;

    saida = fopen(arqSaida, "w+");

    for(i=0;i<l->tamanho;i++){
        blocoPercorriddo=l->vetor[i]->first;
        fprintf(saida,"%d: ",i);
        while(blocoPercorriddo!=NULL){
            fprintf(saida,"%d ",blocoPercorriddo->info);
            blocoPercorriddo=blocoPercorriddo->next;
        }
        fprintf(saida,"\n");
    }

    fclose(saida);
}

lista criaLista(int n){
    lista l;
    TNodo *p;

    int i;

    l=(TLista*)malloc(sizeof(TLista));

    l->tamanho=n;

    l->vetor=(TIndice**)malloc(sizeof(TIndice*)*n);

    for(i=0;i<n;i++){

        l->vetor[i]=(TIndice*)malloc(sizeof(TIndice));
        p=(TNodo*)malloc(sizeof(TNodo));
        l->vetor[i]->first=p;
        l->vetor[i]->last=p;
        l->vetor[i]->info=i;
        p->info=i;
        p->next=NULL;
    }

    return l;
}

void liberaLista(lista l){
    int i;
    TNodo *aux,*p;

    for(i=0;i<l->tamanho;i++){
        p=l->vetor[i]->first;
        while(p!=NULL){
            aux=p;
            p=p->next;
            free(aux);
        }
        free(l->vetor[i]);
    }

    free(l->vetor);
    free(l);
}

void testeDaLista(lista l,int n){
    TNodo *in;
    int i;

    printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
    for(i=0;i<n;i++){
        in=l->vetor[i]->first;
        printf("%d: ",i);
        while(in!=NULL){
            printf("%d ",in->info);
            in=in->next;
        }
        printf("\n");
    }
    printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
}
