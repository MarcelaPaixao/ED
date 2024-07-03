#ifndef ARVBIN_H
#define ARVBIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*funcImprime)(void *dado);
typedef int (*funcCompara)(void *dado1, void *dado2);

typedef struct abb ABB;

ABB *criaArvore(void *dado, ABB *e, ABB *d, funcCompara comparaDados, funcImprime imprimeDado);

ABB *insere(ABB* arv, void *dado, funcCompara comparaDados, funcImprime imprimeDado);

ABB *busca(ABB* arv, void *info);

ABB *retira(ABB* arv, void *info);

void imprimeArvore(ABB *arv);

int estaVazia(ABB* arv);

ABB *liberaArvore(ABB *arv);

#endif 