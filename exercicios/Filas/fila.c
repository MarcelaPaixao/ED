#include "fila.h"

typedef struct Cel Cel;

struct Cel {
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

void InsereAmostraFinal(Fila *f,  Amostra *amostra){
    Cel *nova = malloc(sizeof(Cel));

    nova->amostra = amostra;
    nova->prox = NULL;

    if(f->fim){
        f->fim->prox = nova;
    }
    else {
        f->inic = nova;
    }
    f->fim = nova;
}

void InsereAmostraInicio(Fila *f,  Amostra *amostra){
    Cel *nova = malloc(sizeof(Cel));
    nova->amostra = amostra;
    nova->prox = f->inic;

    if(!f->fim){
        f->fim = nova;
    }
    f->inic = nova;
}

Amostra *RetiraAmostra(Fila *f){
    if(!f || !f->inic) return NULL;
    
    Cel *c = f->inic;
    Amostra *a = c->amostra;
    f->inic = c->prox;
    
    if(!f->inic){
        f->fim = NULL;
    }
    
    free(c);
    return a;
}

void LiberaFila(Fila *f){
    if(!f)return;
    Cel *c = f->inic;
    
    while(c){
        Cel *aux = c->prox;
        free(c);
        c = aux;
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

