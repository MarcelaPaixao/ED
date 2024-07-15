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
    printf("%s", a->nome);
}

char *RetornaNome(Aluno *a){
    return a->nome;
}

int comparaNomes(char *n1, char *n2){
    if(strcmp(n1, n2) == 0) return 1;
    else return 0;
}

void LiberaAluno(Aluno *a){
    if(!a) return;
    free(a->nome);
    free(a);
}