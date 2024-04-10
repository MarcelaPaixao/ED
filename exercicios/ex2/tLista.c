#include "tLista.h"

typedef tCelula tLista;

struct tCelula {
    tProduto *prod;
    tCelula *prox, *ant;
};

tLista *CriaLista(){
    tLista *lista = (tLista *)malloc(sizeof(tLista));
    if(!lista){
        printf("Erro na alocacao da lista!");
        exit(1);
    }
    lista = NULL;
    return lista;
}

tLista *InsereItemNaLista(tLista *lista, tProduto *p){
    if(!p) return;
    tCelula *cel = (tCelula *)malloc(sizeof(tCelula));
    
    cel->prod = p;
    cel->prox = lista;
    cel->ant = NULL;
    
    if(lista){
        lista->ant = cel;
    }
    lista = cel;

    return lista;
}

tLista *RetiraItemCodigo(tLista *lista, int cod){
    tCelula *aux = lista;
    while(aux){
        if(RetornaCodigo(aux->prod) == cod){
            if(aux == lista && lista->prox == NULL){ //se for primeiro e ultimo
                LiberaProduto(aux->prod);
                free(aux);
                lista = NULL;
                return NULL;
            }
            else if(aux == lista){//se for o primeiro
                lista = lista->prox;
                lista->ant = NULL;
            }
            else if(lista->ant != NULL && lista->prox != NULL){
                lista->ant->prox = aux->prox;
                lista->prox->ant = aux->ant;                
            }
            else {
                lista->ant->prox = NULL;
               
            }
            LiberaProduto(aux->prod);
            free(aux);
            return lista; 
        }
        aux = aux->prox;
    }
    return lista;
}

void ImprimeLista(tLista *lista){
    tCelula *aux = lista->prim;
    while(aux){
        ImprimeProduto(aux->prod);
        aux = aux->prox;
    }
}

void LiberaLista(tLista *lista){
    if(!lista) return;
   
    tCelula *p, *pos;
}


void InsereItemNaLista(tLista *lista, tProduto *p){
    if(!p) return;
    tCelula *cel = (tCelula *)malloc(sizeof(tCelula));
    cel->prod = p;
    cel->prox = NULL;
    if(lista == NULL){
        lista = lista->prim = cel;
    }
    else{
        lista->prox = cel;
        lista = cel;
    }
    lista->prod = p;
}

void RetiraItemCodigo(tLista *lista, int cod){
    tCelula *ant = NULL;
    tCelula *aux = lista->prim;
    while(aux){
        if(RetornaCodigo(aux->prod) == cod){
            if(aux == lista->prim){
                lista->prim = aux->prox;
            }
            else if(aux == lista){
                lista = ant;
            }
            free(aux);
            return;
        }
        ant = aux;
        aux = aux->prox;
    }
}

void ImprimeLista(tLista *lista){
    tCelula *aux = lista->prim;
    while(aux){
        ImprimeProduto(aux->prod);
        aux = aux->prox;
    }
}

void LiberaLista(tLista *lista){
    if(!lista) return;
   
    tCelula *p, *pos;
}
