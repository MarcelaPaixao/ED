#ifndef PALAVRA_H_
#define PALAVRA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palavra Palavra;

Palavra *InicializaPalavra(char *str);

Palavra *buscaPalavra(Palavra *p, char *str);

Palavra *inserePalavraLista(Palavra *lista, Palavra *p);

char *RetornaString(Palavra *p);

int RetornaOcorrencias(Palavra *p);

void AtualizaOcorrencias(Palavra *p);

void LiberaListaDePalavra(Palavra *p);

#endif