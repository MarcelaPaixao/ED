#include "Palavra.h"

struct palavra {
    char *pal;
    int n;
    struct palavra *prox;
};

Palavra *InicializaPalavra(char *string){
    Palavra *p = malloc(sizeof(Palavra));
    p->n = 0;
    p->pal = strdup(string);
    p->prox = NULL;
    return p;
}

char *RetornaString(Palavra *p){
    return p->pal;
}

int RetornaOcorrencias(Palavra *p){
    return p->n;
}

void AtualizaOcorrencias(Palavra *p){
    p->n++;
}

void LiberaListaDePalavra(Palavra *p){
    if(!p)return;
    Palavra *aux = p;
    Palavra *t;
    while(aux){
        t = aux->prox;
        free(aux->pal);
        free(aux);
        aux = t;
    }
} 