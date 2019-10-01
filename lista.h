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

typedef TLista *lista;

/*O parãmetro representao número de elementos do vetor de listas*/
lista criaLista(int);

/*libera todos as alocações feitas nas posições do vetor, depois o vetor de Tindice e por fim a lista*/
void liberaLista(lista);

void posicaoOriginal(int,lista);

void posicaoNova(int,int,lista);

#endif // LISTA_H_INCLUDED