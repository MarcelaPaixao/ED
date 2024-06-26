#include "aluno.h"

struct  aluno{
    char *nome;
};

Aluno *CriaAluno(char *nome){
    Aluno *a = malloc(sizeof(Aluno));
    if(!a) return NULL;
    a->nome = strdup(nome);
    return a;
}

void ImprimeAluno(Aluno *a){
    if(!a) return;
    printf("Aluno: %s\n", a->nome);
}

int *ComparaNomes(Aluno *a, char *nome2){
    if(!a) return 0;
    if(strcmp(a->nome, nome2) == 0){
        return 0;
    }
    else {
        return 1;
    }
}

void LiberaAluno(Aluno *a){
    if(!a) return;
    free(a->nome);
    free(a);
}