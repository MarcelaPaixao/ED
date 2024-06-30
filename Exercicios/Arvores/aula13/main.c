#include <stdio.h>
#include <stdlib.h>
#include "arvBin.h"
#include "aluno.h"

int main(){
    Aluno *a1 = CriaAluno("Marcela", 555);
    Aluno *a2 = CriaAluno("Malu", 333);
    Aluno *a3 = CriaAluno("Aline", 777);
    Aluno *a4 = CriaAluno("Gabriel", 999);
    Aluno *a5 = CriaAluno("Eduardo", 444);
    Aluno *a6 = CriaAluno("Raony", 222);

    ABB *arvRaiz = NULL;
    arvRaiz = insere(arvRaiz, a1);
    arvRaiz = insere(arvRaiz, a2);
    arvRaiz = insere(arvRaiz, a3);
    arvRaiz = insere(arvRaiz, a4);
    arvRaiz = insere(arvRaiz, a5);
    arvRaiz = insere(arvRaiz, a6);

    imprimeArvore(arvRaiz);

    ABB *arvFilho = busca(arvRaiz, 333);

    if(arvFilho){
        printf("\n");
        imprimeArvore(arvFilho);
        printf("\n");
    }
    else {
        printf("Matricula nao encontrada!\n");
    }

    //arvRaiz = retira(arvRaiz, 444); //Nó folha
    //arvRaiz = retira(arvRaiz, 777); //Nó com 1 filho
    arvRaiz = retira(arvRaiz, 333); //Nó com 2 filhos

    imprimeArvore(arvRaiz);

    liberaArvore(arvRaiz);
    
    LiberaAluno(a1);
    LiberaAluno(a2);
    LiberaAluno(a3);
    LiberaAluno(a4);
    LiberaAluno(a5);
    LiberaAluno(a6);

    return 0;
}