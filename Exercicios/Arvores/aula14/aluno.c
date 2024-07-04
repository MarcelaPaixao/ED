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

int ComparaMatricula(void *a1, void *a2){
    Aluno *aluno1 = (Aluno*) a1;
    Aluno *aluno2 = (Aluno*) a2;
    if(aluno1->mat == aluno2->mat){
        return 0;
    }
    else if(aluno1->mat < aluno2->mat){
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