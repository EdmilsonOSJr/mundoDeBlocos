#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "movimentacaoDoBloco.h"
#include "arquivo.h"

int iniciar(){
    lista l;

    //n=lerComandos();

    l=criaLista(7);
    //testeDaLista(l,n);

    /*moveOnto(3,2,l);
    testeDaLista(l,n);

    moveOnto(4,3,l);
    testeDaLista(l,n);

    moveOver(5,2,l);
    testeDaLista(l,n);

    pileOnto(4,5,l);
    testeDaLista(l,n);

    pileOver(3,4,l);
    testeDaLista(l,n);

    moveOnto(4,2,l);
    testeDaLista(l,n);*/
    executarComandosDoArquivo(l);
    //testeDaLista(l,7);
    return 0;
}

int main(){
    return iniciar();
}
