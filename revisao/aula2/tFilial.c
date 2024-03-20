#include "tFilial.h"

struct tFilial {
    int qtdEstoque, qtdProd;
    char *nome;
    tProduto **produtos;
};

tFilial *CriaFilial(){
    tFilial *filial = malloc (sizeof(tFilial));
    
    char aux[100];
    scanf("%[^,], %d", aux, &filial->qtdProd);
    filial->nome = strdup(aux);
    filial->qtdEstoque = 0;
    
    filial->produtos = malloc(filial->qtdProd * sizeof(tProduto *));
    for(int i=0; i < filial->qtdProd; i++){
        printf("Digite o nome, valor e qtd do produto %d:\n", i+1);
        filial->produtos[i] = Criaproduto();
        filial->qtdEstoque += RetornaEstoqueProduto(filial->produtos[i]);
    }
    
    return filial;
}

void ImprimeFilial(tFilial *filial){
    printf("\tFilial: %s\n", filial->nome);
    printf("\tEstoque: %d\n", filial->qtdEstoque);
    for(int i=0; i < filial->qtdProd; i++){
        ImprimeProduto(filial->produtos[i]);
    }
}

int RetornaEstoqueFilial(tFilial *filial){
    return filial->qtdEstoque;
}

void LiberaFilial(tFilial *filial){
    if(!filial) return;
    for(int i=0; i < filial->qtdProd; i++){
        LiberaProduto(filial->produtos[i]);
    }
    free(filial->produtos);
    free(filial->nome);
    free(filial);
}