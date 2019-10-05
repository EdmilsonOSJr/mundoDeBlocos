#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/*Essa estrutura representa os nodos*/
typedef struct TNodo{
    int info;
    struct TNodo *next;
}TNodo;


/*Essa estrutura representa uma lista, a qual cada elemento do vetor será alocado*/
typedef struct{
    int info;
    TNodo *first,*last;
    int nElementos;
}TIndice;


/*Essa estrutura representa um vetor de listas*/
typedef struct{
    TIndice **vetor;
    int tamanho;
}TLista;

typedef TLista * lista;

/*Recebe uma variável int que representa o tamanho do vetor de listas e aloca dinamicamente as regiões de memória para cada um*/
lista criaLista(int);

/*libera todos as alocações feitas nas posições do vetor, depois o vetor de Tindice e por fim a lista*/
void liberaLista(lista);

/*Imprime tudo que está na lista*/
void testeDaLista(lista,int);


/*Grava no arquivo de saída a situação final da distribuição dos blocos após as movimentações*/
void GravaListaNoArqDeSaida(char*,lista);

#endif // LISTA_H_INCLUDED
