//FILA
#include "fila.h"

typedef struct cel Cel;

struct cel{
    Amostra *amostra;
    Cel *prox;
}; 

struct fila {
    Cel *inic;
    Cel *fim;
};

Fila *CriaFila(){
    Fila *f = malloc(sizeof(Fila));
    f->inic = f->fim = NULL;
    return f;
}

void InsereAmostraInicio(Fila *f, Amostra *a){
    Cel *c = malloc(sizeof(Cel));
    c->amostra = a;
    c->prox = NULL;

    if(f->inic == NULL){
        f->inic = f->fim = c;
        return;
    }
    c->prox = f->inic;
    f->inic = c;
}

void InsereAmostraFinal(Fila *f, Amostra *a){
    Cel *c = malloc(sizeof(Cel));
    c->amostra = a;
    c->prox = NULL;
    
    if(f->inic == NULL){
        f->inic = f->fim = c;
        return;
    }
    f->fim->prox = c;
    f->fim = c;
}

Amostra *RetiraAmostra(Fila *f){
    if(!f->fim || !f->inic) return NULL;
    Cel *c = f->inic;
    Amostra *a = c->amostra;
    f->inic = c->prox;

    if(f->inic == NULL){
        f->fim = NULL;
    }
    free(c);
    return a;
}

void LiberaFila(Fila *f){
    Cel *atual = f->inic;
    Cel *prox;
    while(atual){
        prox = atual->prox;
        liberaAmostra(atual->amostra);
        free(atual);
        atual = prox;
    }
    free(f);
}

void ImprimeFila(Fila *f){
    Cel *c = f->inic;
    while(c){
        imprimeAmostra(c->amostra);
        c = c->prox;
    }
}

int EstaVaziaFila(Fila *f){
    if(f->inic == NULL && f->fim == NULL){
        return 1;
    }
    return 0;
}

