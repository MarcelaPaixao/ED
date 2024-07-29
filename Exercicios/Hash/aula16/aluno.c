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
    printf("Aluno: %s - Matricula: %d", aluno->nome, aluno->mat);
}

int ComparaMatricula(void *a1, void *mat){
    Aluno *aluno1 = (Aluno*) a1;
    int *matricula = (int*) mat;
    if(aluno1->mat == *matricula){
        return 1;
    }
    return 0;
}

int RetornaMatricula(void *a){
    Aluno *aluno = (Aluno*) a;
    return aluno->mat;
}

void LiberaAluno(void *a){
    if(!a) return;
    Aluno *aluno = (Aluno*) a;
    if(aluno->nome) free(aluno->nome);
    free(aluno);
}