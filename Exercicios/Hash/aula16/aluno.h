#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno *CriaAluno(char *nome, int mat);

void ImprimeAluno(void *a);

int ComparaMatricula(void *a1, void *mat);

int RetornaMatricula(void *a);

void LiberaAluno(void *a);

#endif 