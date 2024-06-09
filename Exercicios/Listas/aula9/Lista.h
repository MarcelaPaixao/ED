#ifndef Lista_h
#define Lista_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tProduto.h"

typedef struct Cel Cel;

typedef Cel Lista;

Lista *CriaLista();

Lista *InsereListaRec(Lista *l, tProduto *p);

Lista *RetiraListaRec(Lista *l, int cod);

void ImprimeListaRec(Lista *l);

void LiberaListaRec(Lista *l);

#endif