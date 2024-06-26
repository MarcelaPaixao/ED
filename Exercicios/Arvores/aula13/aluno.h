#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno *CriaAluno(char *nome, int mat);

void ImprimeAluno(Aluno *a);

int *ComparaNomes(Aluno *a, char *nome);
/*
Se a1->mat == mat, retorna 0
Se a1->mat > mat, retorna 1
Se a1->mat < mat, retorna -1
*/
int *ComparaMatricula(Aluno *a1, int mat);

int RetornaMatricula(Aluno *a);

void LiberaAluno(Aluno *a);

#endif 