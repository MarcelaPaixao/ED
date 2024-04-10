#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tProduto tProduto;

tProduto *CriaProduto();

void ImprimeProduto(tProduto *p);

int RetornaCodigo(tProduto *p);

void LiberaProduto(tProduto *p);
