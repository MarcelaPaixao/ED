#include "tSupermercado.h"

struct tSupermercado {
    int qtdEstoque, qtdFiliais;
    char *nome;
    tFilial **filiais;
};

tSupermercado *CriaSuperMercado(){
    tSupermercado *super = malloc(sizeof(tSupermercado));
    
    char aux[100];
    printf("Digite o nome e a qtd de filiais do supermercado: \n");
    scanf("%[^,], %d", aux, &super->qtdFiliais);
    super->nome = strdup(aux);
    super->qtdEstoque = 0;
    
    super->filiais = malloc(super->qtdFiliais * sizeof(tFilial *));
    for(int i=0; i < super->qtdFiliais; i++){
        printf("Digite o nome e a qtd de itens da filial %d: \n", i+1);
        super->filiais[i] = CriaFilial();
        super->qtdEstoque += RetornaEstoqueFilial(super->filiais[i]);
    }
    
    return super;
}

void ImprimeSupermercado(tSupermercado *super){
    printf("Nome: %s, Estoque Total: %d\n", super->nome, super->qtdEstoque);
    for(int i=0; i < super->qtdFiliais; i++){
        ImprimeFilial(super->filiais[i]);
    }
}

void LiberaSupermercado(tSupermercado *super){
    if(!super)return;
    for(int i=0; i < super->qtdFiliais; i++){
        LiberaFilial(super->filiais[i]);
    }
    free(super->filiais);
    free(super->nome);
    free(super);
}