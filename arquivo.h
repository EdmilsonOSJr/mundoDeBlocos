#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

typedef struct{
    char tamanho[20],elemento1[20],elemento2[20],comando1[5],comando2[5];
}TComandos;

/*Essa função cria um ponteiro para um arquivo e abre o aquivo comandos.txt,
retornando o ponteiro*/
FILE* abrirArquivo();

/*Pega os comandos presentes no arquivo fornecido e os executa chamando as funções
de movimentação de blocos*/
void executarComandosDoArquivo();

#endif // ARQUIVO_H_INCLUDED
