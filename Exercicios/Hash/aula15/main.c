/*Implemente um programa para contar o número de vezes que uma palavra aparece em um arquivo de entrada. 
Seu programa deve ler um arquivo texto e retornar, no terminal, as palavras seguidas do número de ocorrências dessas palavras no arquivo. 
Use uma TABELA HASH para manter as palavras e contar o número de ocorrências. Implemente: TadPalavra, TadHash e um cliente.*/

#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

#define TAM 128
#define NPAL 64

int main(int argc, char *argv[]){
    if(argc <= 1){
        printf("Diretorio nao encontrado!\n");
        return 0;
    }
    
    FILE *arqEntrada = fopen(argv[1], "r");
    if(!arqEntrada){
        printf("Erro ao abrir arquivo!\n");
        return 0;
    }
    
    Hash *h = InicializaHash(TAM);
    char palavra[NPAL];
    while(fscanf(arqEntrada, "%s", palavra) == 1){
        Palavra *p = acessa(h, palavra);
    }

    ImprimeHash(h);
    LiberaHash(h);
    fclose(arqEntrada);

    return 0;
}