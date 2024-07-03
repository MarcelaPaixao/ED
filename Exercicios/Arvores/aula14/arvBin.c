#include "arvBin.h"

struct abb {
    void *dado;
    ABB *esq;
    ABB *dir;
    funcImprime imprimeDado;
    funcCompara comparaDados;
};

ABB *criaArvore(void *dado, ABB *e, ABB *d, funcCompara comparaDados, funcImprime imprimeDado){
    ABB *nova = malloc(sizeof(ABB));
    if(!nova) return NULL;
    nova->dado = dado;
    nova->esq = e;
    nova->dir = d;
    nova->comparaDados = comparaDados;
    nova->imprimeDado = imprimeDado;
    return nova;
}

ABB *insere(ABB* arv, void *dado, funcCompara comparaDados, funcImprime imprimeDado){
    if(arv == NULL){
        arv = criaArvore(dado, NULL, NULL, comparaDados, imprimeDado);
        return arv;
    }
    else if(arv->comparaDados(arv->dado, dado) > 0){
        arv->dir = insere(arv->dir, dado, comparaDados, imprimeDado);
    }
    else if(arv->comparaDados(arv->dado, dado) < 0){
        arv->esq = insere(arv->esq, dado, comparaDados, imprimeDado);
    }
    return arv;
}

ABB *busca(ABB* arv, void *info){
    if(!arv) return NULL;
    if(arv->comparaDados(arv->dado, info) == 0){
        return arv;
    }
    else if(arv->comparaDados(arv->dado, info) < 0){
        return busca(arv->esq, info);
    }
    else if(arv->comparaDados(arv->dado, info) > 0){
        return busca(arv->dir, info);
    }
}

ABB *retira(ABB* arv, void *info){
    if(!arv) return NULL;
    else if(arv->comparaDados(arv->dado, info) < 0){
        arv->esq = retira(arv->esq, info);
    }
    else if(arv->comparaDados(arv->dado, info) > 0){
        arv->dir = retira(arv->dir, info);
    }
    else { //Achou
        if(!arv->esq && !arv->dir){
            free(arv);
            arv = NULL; 
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
            ABB *t = arv->esq;
            while(t->dir){
                t = t->dir;
            }
            void *a = arv->dado;
            arv->dado = t->dado;
            t->dado = a;
            arv->esq = retira(arv->esq, info);
        }
    }
    return arv;
}

void imprimeArvore(ABB *arv){
    if(arv){
        imprimeArvore(arv->esq);
        arv->imprimeDado(arv->dado);
        imprimeArvore(arv->dir);
    }
}

int estaVazia(ABB* arv){
    return arv == NULL;
}

ABB *liberaArvore(ABB *arv){
    if(!estaVazia(arv)){
        liberaArvore(arv->esq);
        liberaArvore(arv->dir);
        free(arv);
    }
    return NULL;
}