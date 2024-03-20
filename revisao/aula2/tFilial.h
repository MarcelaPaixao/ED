#ifndef _TFILIAL_H_
#define _TFILIAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tProduto.h"

typedef struct tFilial tFilial;

tFilial *CriaFilial();

void ImprimeFilial(tFilial *filial);

int RetornaEstoqueFilial(tFilial *filial);

void LiberaFilial(tFilial *filial);

#endif