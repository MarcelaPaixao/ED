#include "arvBin.h"

struct abb {
    Aluno *aluno;
    ABB *esq;
    ABB *dir;
};

ABB *criaArvore(Aluno *aluno, ABB *e, ABB *d){
    ABB *nova = malloc(sizeof(ABB));
    if(!nova) return NULL;
    nova->aluno = aluno;
    nova->esq = e;
    nova->dir = d;
    return nova;
}

ABB *insere(ABB* arv, Aluno *aluno){
    if(arv == NULL){
        arv = criaArvore(aluno, NULL, NULL);
        return arv;
    }
    else if(ComparaMatricula(arv->aluno, RetornaMatricula(aluno)) > 0){
        arv->dir = insere(arv->dir, aluno);
    }
    else if(ComparaMatricula(arv->aluno, RetornaMatricula(aluno)) < 0){
        arv->esq = insere(arv->esq, aluno);
    }
    return arv;
}

ABB *busca(ABB* arv, int mat){
    if(!arv) return NULL;
    if(ComparaMatricula(arv->aluno, mat) == 0){
        return arv;
    }
    else if(ComparaMatricula(arv->aluno, mat) > 0){
        return busca(arv->esq, mat);
    }
    else if(ComparaMatricula(arv->aluno, mat) < 0){
        return busca(arv->dir, mat);
    }
}

ABB *retira(ABB* arv, int mat){
    if(!arv) return NULL;
    else if(ComparaMatricula(arv->aluno, mat) > 0){
        arv->esq = retira(arv->esq, mat);
    }
    else if(ComparaMatricula(arv->aluno, mat) < 0){
        arv->dir = retira(arv->dir, mat);
    }
    else { //Achou
        if(!arv->esq && !arv->dir){
            free(arv);
            arv = NULL; //testar sem isso
        }
        else if(!arv->esq){
            ABB *t = arv;
            arv = arv->dir;
            free(t);
        }
        else if(!arv->dir){
            ABB *t = arv;
            arv = arv->esq;
            free(t);
        }
        else {
            
        }
    }
    return arv;
}

void imprimeArvore(ABB *arv){
    if(arv){
        imprimeArvore(arv->esq);
        ImprimeAluno(arv->aluno);
        imprimeArvore(arv->dir);
    }
}

ABB *liberaArvore(ABB *arv){
    if(!estaVazia(arv)){
        liberaArvore(arv->esq);
        liberaArvore(arv->dir);
        free(arv);
    }
    return NULL;
}