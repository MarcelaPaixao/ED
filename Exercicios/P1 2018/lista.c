#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct aluno {
    char *nome;
    int mat;
};

typedef struct cel Cel;

struct lista {
    Cel *prim;
    Cel *ult;
};

struct cel {
    TAluno *aluno;
    Cel *prox;
};

TLista* CriaLista(){
    TLista *l = malloc(sizeof(TLista));
    if(!l){
        printf("Erro na alocaoa da lista!\n");
        return NULL;
    }
    l->prim = l->ult = NULL;
    
    return l;
}

TAluno* InicializaAluno(char* nome, int matricula){
    TAluno *a = malloc(sizeof(TAluno));
    if(!a){
        printf("Erro na alocaoa do aluno!\n");
        return NULL;
    }
    a->nome = strdup(nome);
    a->mat = matricula;
    
    return a;
}

void InsereAluno (TLista* lista, TAluno* aluno){
    if(!lista || !aluno) return;
    Cel *c = malloc(sizeof(Cel));
    c->aluno = aluno;
    
    if(lista->prim == NULL){
        c->prox = NULL;
        lista->prim = lista->ult = c;
        return;
    }
    c->prox = lista->prim;
    lista->prim = c;
}

TAluno* Retira (TLista* lista, int mat){
    if(!lista) return NULL;
    Cel *ant;
    Cel *c = lista->prim;
    TAluno *a = NULL;
    
    while(c && c->aluno->mat != mat){
        ant = c;
        c = c->prox;
    }

    if(c == NULL){
        return NULL;
    }
    else if(c == lista->prim && c == lista->ult){
        lista->prim = lista->ult = NULL;
    }
    else if(c == lista->prim){
        lista->prim = c->prox;
    }
    else if(c == lista->ult){
        lista->ult = ant;
        ant->prox = NULL;
    }
    else {
        ant->prox = c->prox;
    }
    a = c->aluno;
    free(c);
    return a;
}

void RetiraRepetidos (TLista* lista){
    if(!lista) return;
    Cel *c = lista->prim;
    Cel *p;
    Cel *aux;

    while(c){
        aux = NULL;
        p = c->prox;
        while(p){
            if(c->aluno->mat == p->aluno->mat){ 
                aux = c->prox;
                Retira(lista, c->aluno->mat);
                break;
            }
            p = p->prox;
        }
        if(aux){
            c = aux;
        }
        else {
            c = c->prox;
        }
    }
}

TLista* Merge (TLista* turma1, TLista* turma2){
    if(!turma1 || !turma2) return NULL;
    TLista *nova = CriaLista();
    Cel *t1 = turma1->prim;
    Cel *t2 = turma2->prim;
    TAluno *a = NULL;

    while(t1 && t2){
        a = Retira(turma1, t1->aluno->mat);
        InsereAluno(nova, a);
        t1 = turma1->prim;
        a = Retira(turma2, t2->aluno->mat);
        InsereAluno(nova, a);
        t2 = turma2->prim;
    }

    if(t1 == NULL){
        while(t2){
            a = Retira(turma2, t2->aluno->mat);
            InsereAluno(nova, a);
            t2 = turma2->prim;
        }
    }
    else if(t2 == NULL){
        while(t1){
            a = Retira(turma1, t1->aluno->mat);
            InsereAluno(nova, a);
            t1 = turma1->prim;
        }
    }
    return nova;
}

void LiberaAluno (TAluno* aluno){
    if(!aluno) return;
    free(aluno->nome);
    free(aluno);
}

void Imprime (TLista* lista){
    if(!lista) return;
    Cel *c = lista->prim;
    printf("ALUNOS:\n\n");
    while(c){
        printf("Nome: %s, Matricula: %d\n", c->aluno->nome, c->aluno->mat);
        c = c->prox;
    }
}

void LiberaLista (TLista* lista){
    if(!lista) return;
    Cel *atual = lista->prim;
    Cel *prox;
    
    while(atual){
        prox = atual->prox;
        LiberaAluno(atual->aluno);
        free(atual);
        atual = prox;
    }
    free(lista);
}
