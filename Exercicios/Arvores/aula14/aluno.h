#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno *CriaAluno(char *nome, int mat);

void ImprimeAluno(void *a);

/*
Se a1->mat == a2->mat, retorna 0
Se a1->mat < a2->mat, retorna 1
Se a1->mat > a2->mat, retorna -1
*/
int ComparaMatricula(void *a1, void *a2);

int RetornaMatricula(void *a);

void LiberaAluno(void *a);

#endif 