#include "tProduto.h"

struct tProduto {
    int qtd, valor;
    char *nome;
};

tProduto *Criaproduto(){
    tProduto *prod = malloc(sizeof(tProduto));
    char aux[100];
    scanf("%*c");
    scanf("%[^,], %d, %d", aux, &prod->valor, &prod->qtd);
    prod->nome = strdup(aux);
    return prod;
}

void ImprimeProduto(tProduto *prod){
    printf("\t   Item: %s, valor unitario: %d, quantidade: %d\n", prod->nome, prod->valor, prod->qtd);
}

int RetornaEstoqueProduto(tProduto *prod){
    return prod->qtd * prod->valor;
}

void LiberaProduto(tProduto *prod){
    if(prod){
        free(prod->nome);
        free(prod);
    }
}