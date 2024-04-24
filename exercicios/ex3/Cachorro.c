#include "Cachorro.h"

struct cachorro {
    char *nome;
    int nivelAgr;
};

Cachorro *inicCachorro(char *nome, int agr){
    Cachorro *c = malloc(sizeof(Cachorro));
    if(c == NULL){
        return NULL;
    }
    c->nome = strdup(nome);
    c->nivelAgr = 0;
}

void atribuiNivelAgressividadeCachorro(Cachorro *c, int agr){
    if(!c) return;
    c->nivelAgr = agr;
}

void imprimeCachorro(Cachorro *c){
    printf("Nome: %s, Nivel de agresividade: %d\n", c->nome, c->nivelAgr);
}

void liberaCachorro(Cachorro *c){
    if(c != NULL){
        free(c->nome);
        free(c);
    }
}
