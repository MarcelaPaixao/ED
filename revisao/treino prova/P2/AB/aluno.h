#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno *CriaAluno(char *nome);

void ImprimeAluno(Aluno *a);

char *RetornaNome(Aluno *a);

//se forem iguais retorna 1, se não retorna 0;
int comparaNomes(char *n1, char *n2);

void LiberaAluno(Aluno *a);

#endif 