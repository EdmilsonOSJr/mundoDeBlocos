#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "movimentacaoDoBloco.h"
#include "arquivo.h"

int iniciar(){
    executarComandosDoArquivo();
    return 0;
}

int main(){
    return iniciar();
}
