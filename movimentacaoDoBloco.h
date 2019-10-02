#ifndef MOVIMENTACAODOBLOCO_H_INCLUDED
#define MOVIMENTACAODOBLOCO_H_INCLUDED

/*Retorna todos os elementos que não fazem parte da posição atual do vetor para suas respectivas origens*/
void posicaoOriginal(int,lista);

/*Passa o nodo de uma posição do vetor para outra posição do vetor*/
void posicaoNova(int,int,lista);

/*Move o bloco a para cima do bloco b retornando eventuais blocos que já estiverem
sobre a ou b para as suas posições originais*/
void moveOnto(int,int,lista);

/*Coloca o bloco a no topo do monte onde está o bloco b retornando eventuais blocos
que já estiverem sobre a às suas posições originais*/
void moveOver(int,int,lista);

/*Coloca o bloco a juntamente com todos os blocos que estiverem sobre ele em cima
do bloco b, retornando eventuais blocos que já estiverem sobre b as suas posições originais*/
void pileOnto(int,int,lista);

/*Coloca o bloco a juntamente com todos os blocos que estiverem sobre ele sobre o
monte que contem o bloco b*/
void pileOver(int,int,lista);


#endif // MOVIMENTACAODOBLOCO_H_INCLUDED
