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

void posicaoOriginal(int posicaoAtual,lista l){
    TIndice *posA,*posO;
    TNodo *p,*ant;
    int posOriginal;

    posA=l->vetor[posicaoAtual];

    while(p->info!=posicaoAtual){
        p=posA->first;
        while(p!=posA->last){
            ant=p;
            p=p->next;
        }
        printf("\nteste: %d",posA->last->info);
        ant->next=NULL;
        posA->last=ant;
        posA->nElementos--;

        posOriginal=p->info;

        posO=l->vetor[posOriginal];

        posO->first=p;
        posO->last=p;
        posO->nElementos++;
        posO->last->next=NULL;

    }
}

void posicaoNova(int posicaoNova,int posicaoAtual,lista l){
    TIndice *posA,*posN;
    TNodo *primeiroNodoAtual;


    while(l->vetor[posicaoAtual]->first!=NULL){
        posA=l->vetor[posicaoAtual];

        if(posA->first==l->vetor[posicaoAtual]->last){
            posA->last=NULL;
        }

        primeiroNodoAtual=posA->first;
        posA->first=primeiroNodoAtual->next;

        posN=l->vetor[posicaoNova];
        posN->last->next=primeiroNodoAtual;
        posN->last=primeiroNodoAtual;
        posN->last->next=NULL;


        printf("\nUltima pos: %d",posN->last->info);
    }
}
