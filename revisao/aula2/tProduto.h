#ifndef _TPRODUTO_H_
#define _TPRODUTO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tProduto tProduto;

tProduto *Criaproduto();

void ImprimeProduto(tProduto *prod);

int RetornaEstoqueProduto(tProduto *prod);

void LiberaProduto(tProduto *prod);

#endif