#include "Palavra.h"

struct palavra {
    char *string;
    int n;
    struct palavra *prox;
};

Palavra *InicializaPalavra(char *str){
    Palavra *p = malloc(sizeof(Palavra));
    p->n = 0;
    p->string = strdup(str);
    p->prox = NULL;
    return p;
}

Palavra *buscaPalavra(Palavra *pal, char *str){
    Palavra *p;
    for(p = pal; p != NULL; p = p->prox){
        if (strcmp(p->string, str) == 0){
            return p;
        }
    }
    return NULL;
}

Palavra *inserePalavraLista(Palavra *lista, Palavra *p){
    p->prox = lista;
    return p;
}

char *RetornaString(Palavra *p){
    return p->string;
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
        free(aux->string);
        free(aux);
        aux = t;
    }
} 

void imprimeListaPalavra(Palavra *pal){
    for(Palavra* p = pal; p; p = p->prox){
        printf("%s (%d ocorrencias)\n", p->string, p->n);
    }
}