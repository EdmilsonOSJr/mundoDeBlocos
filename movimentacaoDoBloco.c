#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pesquisaNaLista.h"

void posicaoOriginal(int numeroDoBloco,lista l){
    TNodo *bloco,*blocoSeguinte;
    TIndice *listaA,*listaO;
    int indiceOriginal;

    bloco=pesquisaBloco(numeroDoBloco,l);
    listaA=pesquisaLista(numeroDoBloco,l);

    //listaA=l->vetor[indiceAtual];

    if(bloco->next!=NULL){
        do{

            blocoSeguinte=bloco->next;
            if(blocoSeguinte==listaA->last){
                bloco->next=NULL;
                listaA->last=bloco;
            }
            else
                bloco->next=blocoSeguinte->next;

            listaA->nElementos--;

            indiceOriginal=blocoSeguinte->info;
            listaO=l->vetor[indiceOriginal];
            if(listaO->first==NULL){
                listaO->first=blocoSeguinte;
                listaO->last=blocoSeguinte;
                listaO->last->next=NULL;
            }
            else{
                blocoSeguinte->next=listaO->first;
                listaO->first=blocoSeguinte;
            }

        }while(bloco->next!=NULL);
    }
}

void posicaoNova(int numeroDoBlocoA,int numeroDoBlocoB,lista l){
    TIndice *listaA,*listaN;
    TNodo *blocoA,*blocoAnteriorDeA;

    blocoA=pesquisaBloco(numeroDoBlocoA,l);
    listaA=pesquisaLista(numeroDoBlocoA,l);

    //printf("\nlista: %d",blocoA->info);
    do{
        blocoAnteriorDeA=listaA->first;
        if(blocoAnteriorDeA!=blocoA){
            while(blocoAnteriorDeA->next!=blocoA){
                blocoAnteriorDeA=blocoAnteriorDeA->next;
            }
        }
        //printf("\n%d",blocoAnteriorDeA->info);

        if(blocoAnteriorDeA==blocoA){
            if(listaA->first->next==NULL){
                listaA->first=NULL;
                listaA->last=NULL;
                listaA->nElementos--;
            }
            else{
                do{
                    listaA->first=listaA->first->next;

                    listaN=pesquisaLista(numeroDoBlocoB,l);

                    blocoA->next=NULL;
                    listaN->last->next=blocoA;
                    listaN->last=blocoA;

                    blocoA=listaA->first;
                    blocoAnteriorDeA=listaA->first;
                }while(blocoAnteriorDeA!=NULL);
                break;
            }

            listaN=pesquisaLista(numeroDoBlocoB,l);

            blocoA->next=NULL;
            listaN->last->next=blocoA;
            listaN->last=blocoA;

            blocoA=listaA->first;
        }
        else{
            if(blocoA==listaA->last){
                blocoAnteriorDeA->next=NULL;
                listaA->last=blocoAnteriorDeA;

            }
            else{
                blocoAnteriorDeA->next=blocoA->next;
            }


            listaN=pesquisaLista(numeroDoBlocoB,l);

            blocoA->next=NULL;
            listaN->last->next=blocoA;
            listaN->last=blocoA;

            blocoA=blocoAnteriorDeA->next;
    }
    }while(blocoAnteriorDeA->next!=NULL);

}

void moveOnto(int a,int b,lista l){

    posicaoOriginal(a,l);
    posicaoOriginal(b,l);

    posicaoNova(a,b,l);
}

void moveOver(int a,int b,lista l){

    posicaoOriginal(a,l);

    posicaoNova(a,b,l);

}

void pileOnto(int a,int b,lista l){

    posicaoOriginal(b,l);

    posicaoNova(a,b,l);
}

void pileOver(int a,int b,lista l){

    posicaoNova(a,b,l);
}
