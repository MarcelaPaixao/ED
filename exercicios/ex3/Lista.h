#ifndef Lista_h
#define Lista_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gato.h"
#include "Cachorro.h"

typedef struct Lista Lista;

Lista *inicLista();

void insereAnimal(Lista *lista, void *animal, int tipo);

void retiraAnimal(Lista *lista, void *animal);

void imprimeLista(Lista *lista);

int buscaAnimalNaLista(Lista *lista, void *animal);

void retornaQtdCadaAnimal(Lista *lista, int *dog, int *cat);

void liberaLista(Lista *lista);

#endif /* Lista_h */