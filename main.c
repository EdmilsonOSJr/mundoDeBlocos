#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main(){
    int n;
    lista l;

    printf("\nForneça o numero de elementos: ");
    scanf("%d",&n);

    l=criaLista(n);

    //posicaoNova(2,3,l);
    //posicaoNova(2,4,l);


    //posicaoOriginal(2,l);
    testeDaLista(l,n);

    printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");

    moveOnto(3,2,l);

    testeDaLista(l,n);

    printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");

    moveOnto(4,3,l);

    testeDaLista(l,n);

    printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");

    moveOver(5,2,l);

    testeDaLista(l,n);

    printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");

    moveOver(5,4,l);

    testeDaLista(l,n);

    printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");

    moveOver(5,4,l);

    testeDaLista(l,n);

    return 0;
}
