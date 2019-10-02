#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

typedef struct{
    char tamanho[20],elemento1[20],elemento2[20],comando1[5],comando2[5];
}TComandos;

/*Essa função cria um ponteiro para um arquivo e abre o aquivo comandos.txt,
retornando o ponteiro*/
FILE* abrirArquivo();

/*Realiza a leirura do número de blocos e dos comandos que serão utilizados e então
os salva no arquivo comandos.txt*/
int lerComandos();

void executarComandosDoArquivo(lista);
#endif // ARQUIVO_H_INCLUDED
