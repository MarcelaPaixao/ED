#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno *CriaAluno(char *nome, int mat);

void ImprimeAluno(Aluno *a);

char *RetornaNome(Aluno *a);

int retornaMat(Aluno *a);

// se forem iguais retorna 1, se não retorna 0;
int comparaNomes(char *n1, char *n2);

/*
se a1->mat == a2->mat retorna 0;
se a1->mat > a2->mat retorna 1;
se a1->mat < a2->mat retorna -1;
*/
int comparaMat(int m1, int m2);

void LiberaAluno(Aluno *a);

#endif 