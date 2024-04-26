#include "Lista.h"

#define CACHORRO 0
#define GATO 1

typedef struct cel cel;

struct cel{
    void *animal;
    int tipo;
    cel *prox;
};

struct Lista {
    cel *prim;
    cel *ult;
};

Lista *inicLista(){
    Lista *l = malloc(sizeof(Lista));
    if(l == NULL){
        return NULL;
    }
    l->prim = l->ult = NULL;
    return l;
}

void insereAnimal(Lista *lista, void *animal, int tipo){
    if(!animal) return lista;
    
    cel *nova = malloc(sizeof(cel));
    nova->animal = animal;
    nova->tipo = tipo;
    nova->prox = NULL;

    if(lista->prim == NULL){
        lista->prim = lista->ult = nova;
    }
    lista->ult->prox = nova;
    lista->ult = nova;
    
    return lista;
}

void retiraAnimal(Lista *lista, void *animal){
    if(!lista) return;
    cel *ant = NULL;
    cel *p = lista->prim;

    while(p && p->animal != animal){
        ant = p;
        p = p->prox;
    }
    if(p == NULL){
        return;
    }
    else if(p == lista->prim && p == lista->ult){
        lista->prim = lista->ult = NULL;
    }
    else if(p == lista->prim){
        lista->prim = p->prox;
    }
    else if(p == lista->ult){
        lista->ult = ant;
        ant->prox = NULL;
    }
    else {
        ant->prox = p->prox;
    }
    free(p);
    return;
}

void imprimeLista(Lista *lista){
    if(!lista){
        printf("Lista vazia!\n");
        return;
    }
    cel *p = lista->prim;
    while(p){
        if(p->tipo == CACHORRO){
            imprimeCachorro(p->animal);
        }
        else if(p->tipo == GATO){
            imprimeGato(p->animal);
        }
        p = p->prox;
    }
}

int buscaAnimalNaLista(Lista *lista, void *animal){
    if(!lista) return;
    cel *p = lista->prim;

    while(p){
        if(p->animal == animal){
            return 1;
        }
        p = p->prox;
    }
    return 0;
}

void liberaLista(Lista *lista){
    if(!lista) return;
    cel *atual, *prox;
    atual = lista->prim;
    while(atual){
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    free(lista);
}