#ifndef fila_h
#define fila_h

#include "amostra.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct fila Fila;

Fila *CriaFila();

void InsereAmostraInicio(Fila *f, Amostra *a);

void InsereAmostraFinal(Fila *f, Amostra *a);

Amostra *RetiraAmostra(Fila *f);

void LiberaFila(Fila *f);

void ImprimeFila(Fila *f);

int EstaVaziaFila(Fila *f);

#endif