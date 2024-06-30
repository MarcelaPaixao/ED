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
    printf("Aluno: %s, Matricula: %d\n", a->nome, a->mat);
}

int ComparaNomes(Aluno *a, char *nome2){
    if(!a) return 0;
    if(strcmp(a->nome, nome2) == 0){
        return 0;
    }
    else {
        return 1;
    }
}

int ComparaMatricula(Aluno *a1, int mat){
    if(a1->mat == mat){
        return 0;
    }
    else if(a1->mat > mat){
        return 1;
    }
    else {
        return -1;
    }
}

int RetornaMatricula(Aluno *a){
    return a->mat;
}

void LiberaAluno(Aluno *a){
    if(!a) return;
    free(a->nome);
    free(a);
}