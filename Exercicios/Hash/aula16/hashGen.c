#include "hashGen.h"

typedef struct cel Cel;

struct cel {
    void *dado;
    Cel *prox;
} ;

struct hash {
    Cel **dado;
    int tam;
};

Hash *criaHash(int tam){
    Hash *t = malloc(sizeof(Hash));
    if(!t) return NULL;
    t->tam = tam;
    t->dado = malloc(tam * sizeof(Cel *));
    for(int i=0; i < tam; i++){
        t->dado[i] = NULL;
    }
    return t;
}

void insere(Hash *t, void *chave, void *elem, hashFunction hashFunct){
    int idx = hashFunct(t->tam, chave);
    
    Cel *aux = malloc(sizeof(Cel));
    aux->dado = elem;
    aux->prox = NULL;
    
    if(t->dado[idx] == NULL){
        t->dado[idx] = aux;
    }
    else {
        aux->prox = t->dado[idx];
        t->dado[idx] = aux;
    }
}

void *busca(Hash *t, void *chave, hashFunction hashFunct, compFunction compara){
    int idx = hashFunct(t->tam, chave);
    Cel *aux = t->dado[idx];

    while(aux){
        if(compara(aux->dado, chave)){
            return aux->dado;
        }
        aux = aux->prox;
    }
    return NULL;
}

void liberaCel(Cel *c){
    if(!c) return;
    Cel *prox;
    while(c){
        prox = c->prox;
        free(c);
        c = prox;
    }
}

void liberaHash(Hash *t){
    if(!t) return;
    for(int i=0; i < t->tam; i++){
        liberaCel(t->dado[i]);
    }
    free(t->dado);
    free(t);
}

void imprimeCel(Cel *c, funcImprime imprime){
    if(!c) return;
    //se eu fizer tudo com o c (igual na liberaCel) eu perco a referencia?
    Cel *aux = c;
    while(aux){
        imprime(aux->dado);
        printf("\n");
        aux = aux->prox;
    }
}

void imprimeHash(Hash *t, funcImprime imprime){
    for(int i=0; i < t->tam; i++){
        printf("Idx [%d]:\n", i);
        imprimeCel(t->dado[i], imprime);
        printf("\n");
    }
}
