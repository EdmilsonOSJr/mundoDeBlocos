#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"
#include "lista.h"
#include "locale.h"
#define tam 20

int iniciar(int nNomes, char **arquivos){
    char entrada[tam],saida[tam];
    int teste;

    setlocale(LC_ALL,"pt-BR");

    if(nNomes==3){
        teste=verificacaExtencao(arquivos,entrada,saida);
        if(teste==1)
            executarComandosDoArquivo(entrada,saida);
        else
            printf("\nExtenções incorrentas");
    }
    else
        printf("\nForneça os arquivos de entrada e de saída.");
    return 0;
}

int main(int argc,char *argv[]){
    return iniciar(argc,argv);
}
