/*Nesta aula de laboratório, vamos implementar um TAD Lista Simplesmente Encadeada com Sentinela de produtos de um supermercado!
Tarefas:
1) Implementar produto.c e produto.h (o produto vai ter um código, um nome e um preço).
2) Implementar a lista.c e a lista.h, com as funcionalidades básicas de uma lista: criação, inserção, retirada (por código ou nome do produto), impressão e liberação da memória.
3) Implementar um testador (com a main) para testar a sua implementação.*/

#ifndef TLISTA_H
#define TLISTA_H

#include <stdio.h>
#include <stdlib.h>
#include "tProduto.h"

typedef struct tCelula tCelula;

typedef tCelula tLista;

tLista *CriaLista();

tLista *InsereItemNaLista(tLista *lista, tProduto *p);

tLista *RetiraItemCodigo(tLista *lista, int cod);

void ImprimeLista(tLista *lista);

void LiberaLista(tLista *lista);

#endif 