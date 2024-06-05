#ifndef lista_h
#define lista_h

#include <stdio.h>
#include <stdlib.h>
#include "tProduto.h"

typedef struct lista Lista;

Lista *CriaLista();

void InsereItemNaLista(Lista *l, tProduto *p);

void ImprimeLista(Lista *l);

void RetiraItemCodigo(Lista *l, int cod);

void LiberaLista(Lista *l);

#endif