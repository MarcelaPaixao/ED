#include "tabelaRot.h"

struct pacote {
    int nextHop;
    Pacote *next;
};

struct hash {
    Pacote **pacotes;
    int max;
    int size;
};

int funcaoHash(int key, int size){
    return key % size;
}

void liberaPacotes(Pacote **p){
    if(!p) return;

}

void liberaHash(Hash *t){
    if(!t) return;
    liberaPacotes(t->pacotes);
    free(t->pacotes);
    free(t);
}
