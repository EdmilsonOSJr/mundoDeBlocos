#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void posicaoOriginal(int posicaoAtual,lista l){
    TIndice *posA,*posO;
    TNodo *p,*ant;
    int posOriginal;

    if(l->vetor[posicaoAtual]->first!=NULL){
        posA=l->vetor[posicaoAtual];

        do{
            p=posA->first;
            ant=p;
            while(p!=posA->last){
                ant=p;
                p=p->next;
            }

            if(p!=ant){
            //printf("\nteste: %d",posA->last->info);
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

        }while(p->info!=posicaoAtual);
    }
    else
        printf("\nnulo");
}

void posicaoNova(int posicaoNova,int posicaoAtual,lista l){
    TIndice *posA,*posN;
    TNodo *primeiroNodoAtual;

    while(l->vetor[posicaoAtual]->last!=NULL){
        posA=l->vetor[posicaoAtual];

        if(posA->first==l->vetor[posicaoAtual]->last){
            posA->last=NULL;
        }

        primeiroNodoAtual=posA->first;
        posA->first=primeiroNodoAtual->next;
        posA->nElementos--;

        if(l->vetor[posicaoNova]->first==NULL){ ///Essa parte tem de ser verificada
            posN=l->vetor[posicaoNova];
            posN->first=primeiroNodoAtual;
            posN->last=primeiroNodoAtual;
            posN->last->next=NULL;
        }
        else{
            posN=l->vetor[posicaoNova];
            posN->last->next=primeiroNodoAtual;
            posN->last=primeiroNodoAtual;
            posN->last->next=NULL;
            posN->nElementos++;
        }


        //printf("\nUltima pos: %d",posN->last->info);
    }
}

void moveOnto(int a,int b,lista l){

    posicaoOriginal(a,l);
    posicaoOriginal(b,l);
    //printf("\nTeste");

    posicaoNova(a,b,l);
}

void moveOver(int a,int b,lista l){
    posicaoOriginal(b,l);
    posicaoNova(a,b,l);

}

void pileOnto(int a,int b,lista l){

    posicaoOriginal(a,l);

    posicaoNova(a,b,l);
}

void pileOver(int a,int b,lista l){
    posicaoNova(a,b,l);
}
