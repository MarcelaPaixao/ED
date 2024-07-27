#include "Hash.h"

struct hash{
    Palavra **vet;
    int tam;
};

Hash *InicializaHash(int tam){
    Hash *h = malloc(sizeof(Hash));
    h->tam = tam;
    h->vet = (Palavra**)malloc(tam*sizeof(Palavra*));
    for(int i=0; i < tam; i++){
        h->vet[i] = NULL;
    }
    return h;
}

int static hash_func(char *str, int tam){
    int total = 0;
    for(int i=0; i < strlen(str); i++){
        total += str[i];
    }
    return (total%tam);
}

Palavra *acessa(Hash *h, char *str){
    int idx = hash_func(str, h->tam);
    Palavra *p = buscaPalavra(h->vet[idx], str);
    
    if(!p){
    //se a palara ainda não existe, ela é criada e inserida na lista de palavras daquele indice;
        p = InicializaPalavra(str);
        h->vet[idx] = inserePalavraLista( h->vet[idx], p);
    }
    AtualizaOcorrencias(p);
    //se a palara já existe ela simplesmente é retornada
    return p;
}

void ImprimeHash(Hash *h){
     if(!h)return;
    for(int i=0; i < h->tam; i++){
        printf("indice %d:\n", i);
        imprimeListaPalavra(h->vet[i]);
        printf("\n");
    }
}

void LiberaHash(Hash *h){
    if(!h)return;
    for(int i=0; i < h->tam; i++){
        LiberaListaDePalavra(h->vet[i]);
    }
    free(h->vet);
    free(h);
}
