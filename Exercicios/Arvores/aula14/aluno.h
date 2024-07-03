#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno *CriaAluno(char *nome, int mat);

void ImprimeAluno(void *a);

/*
Se a->mat == mat, retorna 0
Se a->mat < mat, retorna 1
Se a->mat > mat, retorna -1
*/
int ComparaMatricula(void *a, void *mat);

int RetornaMatricula(void *a);

void LiberaAluno(void *a);

#endif 