/*Implemente um TAD árvore binária de busca (ABB) de alunos, com as funcionalidades básicas de: 
criação, busca, impressão, inserção, retirada e liberação. 
Você escolhe o critério de ordenação para sua ABB.*/

#ifndef _arvBusca_h
#define _arvBusca_h

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

typedef struct abb ABB;

ABB *criaABB();

ABB *insere(ABB *abb, Aluno *aluno);

ABB *retira(ABB *abb, int mat);

ABB *busca(ABB *abb, int mat);

void imprimeArvore(ABB *a);

void liberaArvore(ABB *a);

#endif