#ifndef Cachorro_h
#define Cachorro_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MANSO 1
#define BRAVO 2

typedef struct cachorro Cachorro;

Cachorro *inicCachorro(char *nome, int agr);

void atribuiNivelAgressividadeCachorro(Cachorro *c, int agr);

void imprimeCachorro(Cachorro *c);

void liberaCachorro(Cachorro *c);

int retornaNivelAgrCao(Cachorro *c);

#endif /* Cachorro_h */