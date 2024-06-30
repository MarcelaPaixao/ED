#ifndef ARVBIN_H
#define ARVBIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

typedef struct abb ABB;

ABB *criaArvore(Aluno *aluno, ABB *e, ABB *d);

ABB *insere(ABB* arv, Aluno *aluno);

ABB *busca(ABB* arv, int mat);

ABB *retira(ABB* arv, int mat);

void imprimeArvore(ABB *arv);

int estaVazia(ABB* arv);

ABB *liberaArvore(ABB *arv);

#endif 