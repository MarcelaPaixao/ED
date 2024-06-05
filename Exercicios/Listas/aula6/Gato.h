#ifndef Gato_h
#define Gato_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MANSO 1
#define BRAVO 2

typedef struct gato Gato;

Gato *inicGato(char *nome, int agr);

void atribuiNivelAgressividadeGato(Gato *g, int agr);

void imprimeGato(Gato *g);

void liberaGato(Gato *g);

int retornaNivelAgrGato(Gato *g);

#endif /* Gato_h */