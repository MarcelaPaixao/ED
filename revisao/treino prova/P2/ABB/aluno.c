#include "aluno.h"

struct  aluno{
    char *nome;
    int mat;
};

Aluno *CriaAluno(char *nome, int mat){
    Aluno *a = malloc(sizeof(Aluno));
    if(!a) return NULL;
    a->nome = strdup(nome);
    a->mat = mat;
    return a;
}

void ImprimeAluno(Aluno *a){
    if(!a) return;
    printf("%s, %d\n", a->nome, a->mat);
}

char *RetornaNome(Aluno *a){
    return a->nome;
}

int retornaMat(Aluno *a){
    return a->mat;
}

int comparaNomes(char *n1, char *n2){
    if(strcmp(n1, n2) == 0) return 1;
    else return 0;
}

int comparaMat(int m1, int m2){
    if(m1 > m2) return 1;
    if(m1 < m2) return -1;
    return 0;
}


void LiberaAluno(Aluno *a){
    if(!a) return;
    free(a->nome);
    free(a);
}