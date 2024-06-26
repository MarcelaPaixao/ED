#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno *CriaAluno(char *nome);

void ImprimeAluno(Aluno *a);

int *ComparaNomes(Aluno *a, char *nome);

void LiberaAluno(Aluno *a);

#endif 