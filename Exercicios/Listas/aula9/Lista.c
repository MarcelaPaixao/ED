#include "Lista.h"

struct Cel {
    tProduto *prod;
    Cel *next;
};

Lista *CriaLista(){
    return NULL;
}

Lista *InsereListaRec(Lista *l, tProduto *p){
    if(l == NULL){
        Lista *c = malloc(sizeof(Lista));
        c->prod = p;
        c->next = NULL;
        return c;
    }
    else {
        l->next = InsereListaRec(l->next, p); //Insere no final
    }
    return l;
}

Lista *RetiraListaRec(Lista *l, int cod){
    if(l != NULL){
        if(RetornaCodigo(l->prod) == cod){
            Lista *aux = l;
            l = l->next;
            LiberaProduto(aux->prod);
            free(aux);
        }
        else {
            l->next = RetiraListaRec(l->next, cod);
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
        LiberaListaRec(l->next);
        LiberaProduto(l->prod); 
        free(l); 
    }
}

