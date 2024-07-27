#ifndef _tabelaRot_h
#define _tabelaRot_h

#include <stdio.h>
#include <stdlib.h>

typedef struct hash Hash;

typedef struct pacote Pacote;

Hash *InicHash(int size);

Hash *insereHash(Hash *t, int orig, int nextHop);

int buscaDestino(Hash *t, int orig);

void liberaPacotes(Pacote *p);

void liberaHash(Hash *t);

#endif