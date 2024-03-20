#ifndef _TSUPERMERCADO_H_
#define _TSUPERMERCADO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tFilial.h"

typedef struct tSupermercado tSupermercado;

tSupermercado *CriaSuperMercado();

void LiberaSupermercado(tSupermercado *super);

void ImprimeSupermercado(tSupermercado *super);

#endif