#ifndef HASH_H_
#define HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include "Palavra.h"

typedef struct hash Hash;

Hash *InicializaHash(int tam);

Palavra *acessa(Hash *h, char *str);

void LiberaHash(Hash *h);

#endif