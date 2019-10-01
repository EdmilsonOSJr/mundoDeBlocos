#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main(){
    int i,n;
    lista l;
    TNodo *in;

    printf("\nForneça o numero de elementos: ");
    scanf("%d",&n);

    l=criaLista(n);

    posicaoNova(2,3,l);
    posicaoNova(2,4,l);

    for(i=0;i<n;i++){

        in=l->vetor[i]->first;
        printf("\n==================");
        while(in!=NULL){
            printf("\n%d",in->info);
            in=in->next;
        }
        printf("\n==================");
    }

    posicaoOriginal(2,l);

    printf("\nApos chamar original\n");
    for(i=0;i<n;i++){
        in=l->vetor[i]->first;
        printf("\n==================");
        while(in!=NULL){
            printf("\n%d",in->info);
            in=in->next;
        }
        printf("\n==================");
    }
    return 0;
}
