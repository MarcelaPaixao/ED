#include "tProduto.h"

struct tProduto {
    char *nome;
    int codigo;
    float preco;
};

tProduto *CriaProduto(){
    tProduto *p = (tProduto *)malloc(sizeof(tProduto));
    char nome[100];
    
    printf("Digite o nome do produto: ");
    scanf("%*c");
    scanf("%[^\n]", nome);
    scanf("%*c");
    p->nome = strdup(nome);

    printf("Digite o codigo do produto: ");
    scanf("%d", &p->codigo);

    printf("Digite o valor do produto: ");
    scanf("%f", &p->preco);
    
    return p;
}

void ImprimeProduto(tProduto *p){
    printf("Nome: %s\n", p->nome);
    printf("Codigo: %d\n", p->codigo);
    printf("Preco: %.2f\n", p->preco);
}

int RetornaCodigo(tProduto *p){
    return p->codigo;
}

void LiberaProduto(tProduto *p){
    if(!p) return;
    free(p->nome);
    free(p);
}