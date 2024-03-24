#include "tSupermercado.h"

struct tSupermercado {
    int qtdEstoque, qtdFiliais;
    char *nome;
    tFilial **filiais;
};

tSupermercado *CriaSuperMercado(){
    tSupermercado *super = malloc(sizeof(tSupermercado));
    
    char aux[100];
    printf("DIGITE O NOME E A QTD DE FILIAIS DO SUPERMERCADO: \n");
    scanf("%[^,],%d", aux, &super->qtdFiliais);
    super->nome = strdup(aux);
    super->qtdEstoque = 0;
    
    super->filiais = malloc(super->qtdFiliais * sizeof(tFilial *));
    for(int i=0; i < super->qtdFiliais; i++){
        printf("\nDIGITE O NOME E A QTD DE ITENS DA FILIAL %d: \n", i+1);
        super->filiais[i] = CriaFilial();
        super->qtdEstoque += RetornaEstoqueFilial(super->filiais[i]);
    }
    
    return super;
}

void ImprimeSupermercado(tSupermercado *super){
    printf("\nNome: %s, Estoque Total: %d\n", super->nome, super->qtdEstoque);
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