#ifndef _tabelaRot_h
#define _tabelaRot_h

#include <stdio.h>
#include <stdlib.h>

typedef struct hash Hash;

typedef struct pacote Pacote;

Hash *InicHash(int size);

void insereHash(Hash *t, int key);

void liberaPacotes(Pacote **p);

void liberaHash(Hash *t);

void imprimeHash(Hash *t);

#endif