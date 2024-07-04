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
    arvRaiz = insere(arvRaiz, a1, ComparaMatricula, ImprimeAluno);
    arvRaiz = insere(arvRaiz, a2, ComparaMatricula, ImprimeAluno);
    arvRaiz = insere(arvRaiz, a3, ComparaMatricula, ImprimeAluno);
    arvRaiz = insere(arvRaiz, a4, ComparaMatricula, ImprimeAluno);
    arvRaiz = insere(arvRaiz, a5, ComparaMatricula, ImprimeAluno);
    arvRaiz = insere(arvRaiz, a6, ComparaMatricula, ImprimeAluno);

    imprimeArvore(arvRaiz);

    //Aluno *a7 = CriaAluno("Mona", 111); 
    //ABB *arvFilho = busca(arvRaiz, a7); //Aluno que não deve ser encontrado
    ABB *arvFilho = busca(arvRaiz, a5);   //Aluno que deve ser encontrado

    if(arvFilho){
        printf("\n");
        imprimeArvore(arvFilho);
        printf("\n");
    }
    else {
        printf("\nAluno nao encontrado!\n\n");
    }

    //arvRaiz = retira(arvRaiz, a4); //Nó folha
    //arvRaiz = retira(arvRaiz, a3); //Nó com 1 filho
    arvRaiz = retira(arvRaiz, a2); //Nó com 2 filhos

    imprimeArvore(arvRaiz);

    liberaArvore(arvRaiz);
    
    LiberaAluno(a1);
    LiberaAluno(a2);
    LiberaAluno(a3);
    LiberaAluno(a4);
    LiberaAluno(a5);
    LiberaAluno(a6);
    //LiberaAluno(a7);

    return 0;
}