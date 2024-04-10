#include "tLista.h"

struct tLista {
    tCelula *prim;
    tCelula *ult;
};

struct tCelula {
    tProduto *prod;
    tCelula *prox;
};

tLista *CriaLista(){
    tLista *lista = (tLista *)malloc(sizeof(tLista));
    if(!lista){
        printf("Erro na alocacao da lista!");
        exit(1);
    }
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

void InsereItemNaLista(tLista *lista, tProduto *p){
    if(!p) return;
    tCelula *cel = (tCelula *)malloc(sizeof(tCelula));
    cel->prod = p;
    cel->prox = NULL;
    if(lista->ult == NULL){
        lista->ult = lista->prim = cel;
    }
    else{
        lista->ult->prox = cel;
        lista->ult = cel;
    }
    lista->ult->prod = p;
}

void RetiraItemCodigo(tLista *lista, int cod){
    tCelula *ant = NULL;
    tCelula *aux = lista->prim;
    while(aux){
        if(RetornaCodigo(aux->prod) == cod){
            if(aux == lista->prim){
                lista->prim = aux->prox;
            }
            else if(aux == lista->ult){
                lista->ult = ant;
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
