#ifndef MOVIMENTACAODOBLOCO_H_INCLUDED
#define MOVIMENTACAODOBLOCO_H_INCLUDED

/*Recebe um int que seria o número do bloco e a lista. A função acha a posição desse bloco e retorna qualquer bloco que estiver
numa posição após a dele para sua posição original*/
void posicaoOriginal(int,lista);

/*Recebe um int que seria o número do bloco 'a' e outro int para o bloco 'b' e a lista. A função acha a posição do bloco 'a' e
move tal bloco e qualquer bloco que está numa posição após a dele para a posição final da lista onde o bloco 'b' se encontra*/
void posicaoNova(int,int,lista);

/*Move o bloco 'a' para cima do bloco 'b' retornando eventuais blocos que já estiverem sobre 'a' ou 'b' para as suas posições
originais. Antes  de movimentar o bloco 'b' para o 'a' é chamada a função posicaoOriginal() para ambos os blocos e logo depois
é chamada a função posicaoNova()*/
void moveOnto(int,int,lista);

/*Coloca o bloco 'a' no topo do monte onde está o bloco 'b' retornando eventuais blocos que já estiverem sobre 'a' às suas
posições originais. Antes  de movimentar o bloco 'b' para o 'a' é chamada a função posicaoOriginal() apenas para o bloco 'a'
e logo depois é chamada a função posicaoNova()*/
void moveOver(int,int,lista);

/*Coloca o bloco a juntamente com todos os blocos que estiverem sobre ele em cima do bloco b, retornando eventuais blocos que
já estiverem sobre b as suas posições originais. Antes  de movimentar o bloco 'b' para o 'a' é chamada a função posicaoOriginal()
apenas para o bloco 'b' e logo depois é chamada a função posicaoNova()*/
void pileOnto(int,int,lista);

/*Coloca o bloco a juntamente com todos os blocos que estiverem sobre ele sobre o monte que contem o bloco b. Apenas chama a
função posicaoNova()*/
void pileOver(int,int,lista);

#endif // MOVIMENTACAODOBLOCO_H_INCLUDED
