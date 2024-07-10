#ifndef HASH_H_
#define HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include "Palavra.h"

typedef struct hash Hash;

Hash *InicializaHash(int tam);

void InserePalavraHash(Hash *h, Palavra *p);

void LiberaHash(Hash *tab);

#endif