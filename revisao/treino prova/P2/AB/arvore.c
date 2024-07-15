#include "arvore.h"

struct arvore {
    Aluno *aluno;
    Arvore *dir, *esq;
};

Arvore *criaArvoreVazia(){
    return NULL;
}

Arvore *criaArvore(Arvore *esq, Arvore *dir, Aluno *a){
    Arvore *raiz = malloc(sizeof(Arvore));
    if(!raiz)return NULL;
    raiz->dir = dir;
    raiz->esq = esq;
    raiz->aluno = a;
    return raiz;
}

int arvoreVazia(Arvore *a){
    return a == NULL;
}

int pertence(Arvore *a, char *nome){
    if(arvoreVazia(a)){
        return 0;
    }
    else {
        return comparaNomes(RetornaNome(a->aluno), nome) ||
        pertence(a->esq, nome) ||
        pertence(a->dir, nome);
    }
}

int folhas (Arvore* a){
    if(arvoreVazia(a)) return 0;
    else {
        int ehFolha = arvoreVazia(a->esq) && arvoreVazia(a->dir); 
        return ehFolha + folhas(a->esq) + folhas(a->dir);
    }
}

int ocorrencias (Arvore* a , char* nome){
    if(arvoreVazia(a)) return 0;
    else {
        int compara = comparaNomes(RetornaNome(a->aluno), nome);
        return compara + ocorrencias(a->esq, nome) + ocorrencias(a->dir, nome);
    } 
}

int retornaMaior(int a, int b){
    if(a > b) return a;
    return b;
}

int altura (Arvore* a){
    if(arvoreVazia(a)) return -1;
    else {
        return 1 + retornaMaior(altura(a->esq), altura(a->dir));
    }
}

void imprimeArvore(Arvore *a){
    printf("<");
    if(!(arvoreVazia(a))){
        ImprimeAluno(a->aluno);
        imprimeArvore(a->esq);
        imprimeArvore(a->dir);
    }
    printf(">");
}

Arvore *liberaArvore(Arvore *a){
    if(!(arvoreVazia(a))){
        liberaArvore(a->esq);
        liberaArvore(a->dir);
        free(a);
    }
    return NULL;
}