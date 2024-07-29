#include "tabelaRot.h"

struct pacote {
    int nextHop, origem;
    Pacote *next;
};

struct hash {
    Pacote **pacotes;
    int tam;
};

static int hashFunct(Hash *h, int origem){
    return (origem % h->tam);
}

Hash *InicHash(int tam){
    Hash *h = malloc(sizeof(Hash));
    h->pacotes = malloc(tam*sizeof(Pacote*));
    h->tam = tam;
    for(int i=0; i < tam; i++){
        h->pacotes[i] = NULL; 
    }
    return h;
}

void insereHash(Hash *h, int orig, int nextHop){
    int idx = hashFunct(h, orig);

    Pacote *novo = malloc(sizeof(Pacote));
        novo->nextHop = nextHop;
        novo->origem = orig;
        novo->next = NULL;

    if(h->pacotes[idx] == NULL){
        h->pacotes[idx] = novo;
    }
    else {
        novo->next = h->pacotes[idx];
        h->pacotes[idx] = novo;
    }
}

int buscaDestino(Hash *h, int origem){
    int idx = hashFunct(h, origem);
    Pacote *p = h->pacotes[idx];
    while(p){
        if(p->origem == origem){
            return p->nextHop;
        }
        p = p->next;
    }
    return -1;
}

void liberaPacotes(Pacote *p){
    Pacote *aux;
    while(p){
        aux = p->next;
        free(p);
        p = aux;
    }
}

void liberaHash(Hash *h){
    if(!h) return;
    for(int i=0; i < h->tam; i++){
        liberaPacotes(h->pacotes[i]);
    }
    free(h->pacotes);
    free(h);
}
