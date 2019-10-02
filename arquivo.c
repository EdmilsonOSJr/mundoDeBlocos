#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

int lerComandos(){
    int n;
    char comando[100];
    FILE *arq;

    arq = fopen("comandos.txt", "r+");
    if(arq==NULL)
        arq = fopen("comandos.txt", "w+");

    printf("\nForneça o numero de elementos: ");
    scanf("%d",&n);
    fprintf(arq,"%d\n",n);

    do{
        printf("\nForneça o comando: ");
        setbuf(stdin,NULL);
        fgets(comando,100,stdin);
        setbuf(stdin,NULL);
        if(comando[strlen(comando) - 1] == '\n')
            comando[strlen(comando) - 1] = '\0';
        fprintf(arq,"%s\n",comando);
    }while(strcmp(comando,"quit")!=0);

    fclose(arq);
    /*strcpy(a.elemento1,strtok(comando," "));
    strcpy(a.comando1,strtok(NULL," "));
    strcpy(a.comando2,strtok(NULL," "));
    strcpy(a.elemento2,strtok(NULL," "));

    printf("\nMensagem: %s",comando);

    printf("\nElemento 1: %s",a.elemento1);
    printf("\nComando 1: %s",a.comando1);
    printf("\nComando 2: %s",a.comando2);
    printf("\nElemento 2: %s",a.elemento2);*/
    return n;
}
