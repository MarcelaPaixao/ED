#include <stdio.h>
#include <stdlib.h>
#include "tabelaRot.h"

#define TAMH 10

int main(int argc, char *argv[]){

    FILE *arqEnderecos = fopen("endereços.txt","r");
    if(!arqEnderecos){
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    Hash *hash = InicHash(TAMH);
    int origem, nextHop;
    while(fscanf(arqEnderecos, "%d %d", &origem, &nextHop) == 2){
        hash = insereHash(hash, origem, nextHop);
    }

    FILE *arqEntrada = fopen("input.txt","r");
    
    int chaveBusca;
    while(fscanf(arqEntrada, "%d", &chaveBusca) == 1){
        nextHop = buscaDestino(hash, chaveBusca);
        if(nextHop < 0){
            printf("Endereco inexistente!\n");
        } else {
            printf("Destino: %d, NextHop: %d\n", chaveBusca, nextHop);
        }
    }

    liberaHash(hash);
    fclose(arqEntrada);
    fclose(arqEnderecos);

    return 0;
}