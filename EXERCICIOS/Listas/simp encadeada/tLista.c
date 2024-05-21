//LISTA SIMPLESMENTE ENCADEADA COM SENTINELA
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
            if(aux == lista->prim && aux == lista->ult){
                lista->prim = lista->ult = NULL;
                free(aux);
                return;
            }
            if(aux == lista->prim){
                lista->prim = aux->prox;//isso é o msm que lista->prim = lista->prim->prox  ????
            }
            if(aux == lista->ult){
                lista->ult = ant;
                ant->prox = NULL;
            }
            else {
                ant->prox = aux->prox;
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
    int i=1;
    while(aux){
        printf("PRODUTO %d\n", i);
        ImprimeProduto(aux->prod);
        aux = aux->prox;
        printf("\n");
        i++;
    }
}

void LiberaLista(tLista *lista){
    if(!lista) return;
    tCelula *atual, *prox;
    atual = lista->prim;
    while(atual){
        prox = atual->prox;
        LiberaProduto(atual->prod);
        free(atual);
        atual = prox;
    }
    free(lista);
}
