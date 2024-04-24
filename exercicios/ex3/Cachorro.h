#ifndef Cachorro_h
#define Cachorro_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cachorro Cachorro;

Cachorro *inicCachorro(char *nome, int agr);

void atribuiNivelAgressividadeCachorro(Cachorro *c, int agr);

void imprimeCachorro(Cachorro *c);

void liberaCachorro(Cachorro *c);

#endif /* Cachorro_h */