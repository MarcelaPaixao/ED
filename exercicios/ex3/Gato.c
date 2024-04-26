#include "Gato.h"

struct gato{
    char *nome;
    int nivelAgr;
};

Gato *inicGato(char *nome, int agr){
    Gato *g = malloc(sizeof(Gato));
    if(g == NULL){
        return NULL;
    }
    g->nome = strdup(nome);
    g->nivelAgr = 0;
}

void atribuiNivelAgressividadeGato(Gato *g, int agr){
    if(!g) return;
    g->nivelAgr = agr;
}

void imprimeGato(Gato *g){
    printf("Nome: %s, Nivel de agresividade:", g->nome);
    if(g->nivelAgr == MANSO){
        printf("Manso\n");
    }
    else {
        printf("Bravo\n");
    }
}

void liberaGato(Gato *g){
    if(g != NULL){
        free(g->nome);
        free(g);
    }
}

int retornaNivelAgrGato(Gato *g){
    return g->nivelAgr;
}
