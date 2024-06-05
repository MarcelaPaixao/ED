
#include "tLista.h"

typedef struct cel Cel;

struct lista {
    Cel *prim, *ult;
};

struct cel {
    tProduto *prod;
    Cel *prox;
};

Lista *CriaLista(){
    Lista *l = malloc(sizeof(Lista));
    if(!l){
        printf("Erro na alocacao da lista!\n");
        return NULL;
    }
    l->prim = l->ult = NULL;   
    return l;
}

void InsereItemNaLista(Lista *l, tProduto *p){
    Cel *c = malloc(sizeof(Cel));
    c->prod = p;
    c->prox = NULL;

    if(l->prim == NULL){
        l->prim = l->ult = c;
        return;
    }
    l->ult->prox = c;
    l->ult = c;
}

void ImprimeLista(Lista *l){
    Cel *c = l->prim;
    while(c){
        ImprimeProduto(c->prod);
        printf("\n");
        c = c->prox;
    }
}

void RetiraItemCodigo(Lista *l, int cod){
    Cel *c = l->prim;
    Cel *ant = NULL;

    while(c && RetornaCodigo(c->prod) != cod){
        ant = c;
        c = c->prox;
    }

    if(c == NULL){
        return;
    }
    if(c == l->prim && c == l->ult){
        l->prim = l->ult = NULL;
    }
    else if(c == l->prim){
        l->prim = c->prox;
    }
    else if(c == l->ult){
        l->ult = ant;
        ant->prox = NULL;
    }
    else {
        ant->prox = c->prox;
    }
    LiberaProduto(c->prod);
    free(c);
}

void LiberaLista(Lista *l){
    if(!l) return;
    Cel *prox = NULL;
    Cel *atual = l->prim;
    while(atual){
        prox = atual->prox;
        LiberaProduto(atual->prod);
        free(atual);
        atual = prox;
    }
    free(l);
}