#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*void posicaoOriginal(int posicaoAtual,lista l){
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
}*/

int pesquisaBloco(TNodo ** bloco,int nBloco,lista l){
    int i;
    TIndice *lis;

    for(i=0;i<l->tamanho;i++){
        lis=l->vetor[i];
        (*bloco)=l->vetor[i]->first;

        while((*bloco)!=NULL){
            if((*bloco)->info==nBloco){
                //printf("%d",(*bloco)->info);
                return i;
            }
            //printf("\n%d",(*bloco)->info);
            (*bloco)=(*bloco)->next;
        }
    }
}

void posicaoOriginal(int numeroDoBloco,lista l){
    TNodo *bloco,*blocoSeguinte;
    TIndice *listaA,*listaO;
    int indiceOriginal,indiceAtual;

    indiceAtual=pesquisaBloco(&bloco,numeroDoBloco,l);
    listaA=l->vetor[indiceAtual];

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
            printf("\nA lista de destino: %d",listaO->info);
            if(listaO->first==NULL){
                printf("\nNula");
                listaO->first=blocoSeguinte;
                listaO->last=blocoSeguinte;
                listaO->last->next=NULL;
            }
            else{
                blocoSeguinte->next=listaO->first;
                listaO->first=blocoSeguinte;
                printf("\nNão nula");
            }

        }while(bloco->next!=NULL);
    }
}

void posicaoNova(int numeroDoBlocoA,int numeroDoBlocoB,lista l){
    TIndice *listaA,*listaN;
    TNodo *blocoA,*blocoAnteriorDeA,*blocoB;
    int indiceAtual,indiceNovo;

    indiceAtual=pesquisaBloco(&blocoA,numeroDoBlocoA,l);
    listaA=l->vetor[indiceAtual];
    //printf("\nlista: %d",blocoA->info);
    do{
        blocoAnteriorDeA=listaA->first;
        if(blocoAnteriorDeA!=blocoA){
            while(blocoAnteriorDeA->next!=blocoA){
                blocoAnteriorDeA=blocoAnteriorDeA->next;
            }
        }
        printf("\n%d",blocoAnteriorDeA->info);

        if(blocoAnteriorDeA==blocoA){
            if(listaA->first->next==NULL){
                listaA->first=NULL;
                listaA->last=NULL;
                listaA->nElementos--;
            }
            else{
                do{
                    listaA->first=listaA->first->next;
                    indiceNovo=pesquisaBloco(&blocoB,numeroDoBlocoB,l);

                    listaN=l->vetor[indiceNovo];

                    blocoA->next=NULL;
                    listaN->last->next=blocoA;
                    listaN->last=blocoA;

                    blocoA=listaA->first;
                    blocoAnteriorDeA=listaA->first;
                }while(blocoAnteriorDeA!=NULL);
                break;
            }
            indiceNovo=pesquisaBloco(&blocoB,numeroDoBlocoB,l);

            listaN=l->vetor[indiceNovo];

            blocoA->next=NULL;
            listaN->last->next=blocoA;
            listaN->last=blocoA;

            blocoA=listaA->first;
            printf("\nEntrou aqui");
        }
        else{
            if(blocoA==listaA->last){
                blocoAnteriorDeA->next=NULL;
                listaA->last=blocoAnteriorDeA;

            }
            else{
                blocoAnteriorDeA->next=blocoA->next;
            }



            indiceNovo=pesquisaBloco(&blocoB,numeroDoBlocoB,l);

            listaN=l->vetor[indiceNovo];

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
