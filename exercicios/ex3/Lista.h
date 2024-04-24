#ifndef Lista_h
#define Lista_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gato.h"
#include "Cachorro.h"

typedef struct Lista Lista;

Lista *inicLista();

void insereAnimal(Lista *lista, void *animal);

void retiraAnimal(Lista *lista, void *animal);

void imprimeLista(Lista *lista);

void liberaLista(Lista *lista);

#endif /* Lista_h */