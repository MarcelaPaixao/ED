#ifndef fila_h
#define fila_h

#include "amostra.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct fila Fila;

Fila *CriaFila();

void InsereAmostraFinal(Fila *f,  Amostra *amostra);

void InsereAmostraInicio(Fila *f,  Amostra *amostra);

Amostra *RetiraAmostra(Fila *f);

void LiberaFila(Fila *f);

void ImprimeFila(Fila *f);

#endif