#ifndef Gato_h
#define Gato_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gato Gato;

Gato *inicGato(char *nome, int agr);

void atribuiNivelAgressividadeGato(Gato *g, int agr);

void imprimeGato(Gato *g);

void liberaGato(Gato *g);

#endif /* Gato_h */