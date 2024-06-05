#include "Lista.h"

struct Cel {
    tProduto *prod;
    Cel *next;
};

Lista *CriaLista(){
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if(!l) return NULL;
    l->next = l->prod = NULL;
    return l;
}

void InsereListaRec(Lista *l, tProduto *p){
    if(l == NULL){
        l->prod = p;
        l->next = NULL;
        return;
    }
    else {
        InsereListaRec(l->next, p); //Insere no final
    }
}

Lista *RetiraListaRec(Lista *l, int cod){
    if(l != NULL){
        if(RetornaCodigo(l->prod) == cod){
            Lista *aux = l;
            l = l->next;
            free(aux);
        }
        else {
            l->next = RetiraDaLista(l->next, cod);
        }
    } 
    return l;
}

void ImprimeListaRec(Lista *l){
    if(l != NULL){
        ImprimeProduto(l->prod);
        ImprimeListaRec(l->next);
    }
}

void LiberaListaRec(Lista *l){
    if(l != NULL){
        

    }
}

