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

void ImprimeAluno(void *a){
    if(!a) return;
    Aluno *aluno = (Aluno*) a;
    printf("Aluno: %s, Matricula: %d\n", aluno->nome, aluno->mat);
}

int ComparaMatricula(void *a, void *mat){
    Aluno *aluno = (Aluno*) a;
    int matricula = (int)mat;
    if(aluno->mat == matricula){
        return 0;
    }
    else if(aluno->mat < matricula){
        return 1;
    }
    else {
        return -1;
    }
}

int RetornaMatricula(void *a){
    Aluno *aluno = (Aluno*) a;
    return aluno->mat;
}

void LiberaAluno(void *a){
    if(!a) return;
    Aluno *aluno = (Aluno*) a;
    free(aluno->nome);
    free(aluno);
}