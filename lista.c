#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

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
        l->vetor[i]->nElementos=1;
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

    for(i=0;i<l->tamanho;i++){
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
        printf("\n==================\n");
        printf("%d: ",i);
         if(in==NULL)
            printf("nulo");
        while(in!=NULL){
            printf("%d ",in->info);
            in=in->next;
        }
    }
    printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
}
