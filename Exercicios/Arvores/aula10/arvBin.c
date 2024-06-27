#include "arvBin.h"

struct arv {
    Aluno *aluno;
    Arv *esq;
    Arv *dir;
};

Arv *criaArvore(Aluno *aluno, Arv *e, Arv *d){
    Arv *nova = malloc(sizeof(Arv));
    if(!nova) return NULL;
    nova->aluno = aluno;
    nova->esq = e;
    nova->dir = d;
    return nova;
}

int pertence(Arv* arv , char* nome){
    if(estaVazia(arv)){
        return 0;
    }
    else {
        return (ComparaNomes(arv->aluno, nome) || 
        pertence(arv->esq, nome) || 
        pertence(arv->dir, nome));
    }
}

int estaVazia(Arv* arv){
    return arv == NULL;
}

int folhas(Arv* arv){
    if(estaVazia(arv->dir) && estaVazia(arv->esq)){
        return 1;
    }
    else if(estaVazia(arv->dir) && !estaVazia(arv->esq)){
        return (folhas(arv->esq));
    }
    else if(!estaVazia(arv->dir) && estaVazia(arv->esq)){
        return (folhas(arv->dir));
    }
    return folhas(arv->esq) + folhas(arv->dir);
}

int ocorrencias(Arv* arv, char* nome){
    if(estaVazia(arv)){
        return 0;
    }
    if(pertence(arv, nome)){
        return 1 + ocorrencias(arv->esq, nome) + ocorrencias(arv->dir, nome);
    }
    return ocorrencias(arv->esq, nome) + ocorrencias(arv->dir, nome);
}

int altura(Arv* arv){
 
}

void imprimeArvore(Arv *arv){
    printf("<");
    if(arv){
        ImprimeAluno(arv->aluno);
        imprimeArvore(arv->esq);
        imprimeArvore(arv->dir);
    }
    printf(">");
}

Arv *liberaArvore(Arv *arv){
    if(!estaVazia(arv)){
        liberaArvore(arv->esq);
        liberaArvore(arv->dir);
        free(arv);
    }
    return NULL;
}