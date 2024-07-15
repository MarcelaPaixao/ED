#include "arvBusca.h"

struct abb {
    Aluno *aluno;
    ABB *esq, *dir;
};

ABB *criaABB(){
    return NULL;
}

ABB *insere(ABB *a, Aluno *aluno){
    if(a == NULL){
        ABB *node = malloc(sizeof(ABB));
        node->aluno = aluno;
        node->dir = node->esq = NULL;
        return node;
    }
    else if(comparaMat(retornaMat(aluno), retornaMat(a->aluno)) > 0){
        a->dir =  insere(a->dir, aluno);
    }
    else if(comparaMat(retornaMat(aluno), retornaMat(a->aluno)) < 0){
        a->esq =  insere(a->esq, aluno);
    }
    return a;
}

ABB *retira(ABB *a, int mat){
    if(!a) return NULL;
    else if(comparaMat(mat, retornaMat(a->aluno)) > 0){
        a->dir =  retira(a->dir, mat);
    }
    else if(comparaMat(mat, retornaMat(a->aluno)) < 0){
        a->esq =  retira(a->esq, mat);
    }
    else {
        if(!a->dir && !a->esq){
            free(a);
            a = NULL;
        }
        else if(!a->esq){
            ABB *t = a;
            a = a->dir;
            free(t);
        }
        else if(!a->dir){
            ABB *t = a;
            a = a->esq;
            free(t);
        }
        else {
            ABB *t = a->esq;
            while(t->dir){
                t = t->dir;
            }
            Aluno *al = a->aluno;
            a->aluno = t->aluno;
            t->aluno = al;
            a->esq = retira(a->esq, mat); 
        }
    }
    return a;
}

ABB *busca(ABB *a, int mat){
    if(!a) return NULL;
    if(comparaMat(mat, retornaMat(a->aluno)) == 0){
        return a;
    }
    else if(comparaMat(mat, retornaMat(a->aluno)) > 0){
        return busca(a->dir, mat);
    }
    else if(comparaMat(mat, retornaMat(a->aluno)) < 0){
        return busca(a->esq, mat);
    }
}

void imprimeArvore(ABB *a){
    if(a != NULL){
        imprimeArvore(a->esq);
        ImprimeAluno(a->aluno);
        imprimeArvore(a->dir);
    }
}

void liberaArvore(ABB *a){
    if(a != NULL){
        liberaArvore(a->esq);
        liberaArvore(a->dir);
        free(a);
    }
}