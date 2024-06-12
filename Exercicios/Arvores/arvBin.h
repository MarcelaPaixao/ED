#ifndef ARVBIN_H
#define ARVBIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

typedef struct arv Arv;

Arv *criaArvore(Aluno *aluno, Arv *e, Arv *d);

int pertence(Arv* arv , char* nome);

int folhas(Arv* arv);

int ocorrencias(Arv* arv, char* nome);

int altura(Arv* arv);

int estaVazia(Arv* arv);

void imprimeArvore(Arv *arv);

Arv *liberaArvore(Arv *arv);

#endif 