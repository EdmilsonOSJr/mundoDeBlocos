#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

/*Estrutura que retira cada comando do arquivo de entrada para efetuar as movimentações*/
typedef struct{
    char tamanho[20],elemento1[20],elemento2[20],comando1[5],comando2[20];
}TComandos;

/*Essa função cria um ponteiro para um arquivo e abre o aquivo comandos.txt,retornando o ponteiro*/
FILE* abrirArquivo(char*);

/*Pega um comando por vez do arquivo de entrada e chama as função correspondente à movimentação que esse comando representa*/
void executarComandosDoArquivo(char*,char*);

/*Grava no arquivo de saída a situação final da distribuição dos blocos após as movimentações*/
void GravaNoArqDeSaida(char*,lista);

int verificacaExtencao(char **,char*,char*);


#endif // ARQUIVO_H_INCLUDED
