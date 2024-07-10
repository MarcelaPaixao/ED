#include "Hash.h"

struct hash{
    Palavra **vet;
    int tam;
};

Hash *InicializaHash(int tam){
    Hash *tab = malloc(sizeof(Hash));
    tab->tam = 0;
    tab->vet = (Palavra**)malloc(tam*sizeof(Palavra*));
    for(int i=0; i < tam; i++){
        tab->vet[i] = NULL;
    }
    return tab;
}

int static hash_func(char *string, int tam){
    int total = 0;
    for(int i=0; i < strlen(string); i++){
        total += string[i];
    }
    return (total%tam);
}

void LiberaHash(Hash *tab){
    if(!tab)return;
    for(int i=0; i < tab->tam; i++){
        LiberaListaDePalavra(tab->vet[i]);
    }
    free(tab->vet);
    free(tab);
}
