#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "aluno.h"

int main(){
    Aluno *a1 = CriaAluno("Marcela");
    Aluno *a2 = CriaAluno("Malu");
    Aluno *a3 = CriaAluno("Aline");
    Aluno *a4 = CriaAluno("Gabriel");
    Aluno *a5 = CriaAluno("Raony");
    Aluno *a6 = CriaAluno("Eduardo");
    Aluno *a7 = CriaAluno("Eduardo");

    Arvore *no4 = criaArvore(criaArvoreVazia(), criaArvoreVazia(), a4);
    Arvore *no3 = criaArvore(criaArvoreVazia(), criaArvoreVazia(), a3);
    Arvore *raiz2 = criaArvore(no4, no3, a2);

    Arvore *no7 = criaArvore(criaArvoreVazia(), criaArvoreVazia(), a7);
    Arvore *raiz6 = criaArvore(no7, criaArvoreVazia(), a6);
    
    Arvore *raiz5 = criaArvore(criaArvoreVazia(), raiz6, a5);

    Arvore *arvRaiz = criaArvore(raiz2, raiz5, a1);
     
    imprimeArvore(arvRaiz);

    printf("Folhas: %d\n", folhas(arvRaiz));
    printf("Altura: %d\n", altura(arvRaiz));
    
    if(pertence(arvRaiz, RetornaNome(a3))){
        printf("%s encontrado(a)!\n", RetornaNome(a3));
    }

    printf("%s encontrado %d vezes!\n", RetornaNome(a7), ocorrencias(arvRaiz, RetornaNome(a7)));

    liberaArvore(arvRaiz);
    
    LiberaAluno(a1);
    LiberaAluno(a2);
    LiberaAluno(a3);
    LiberaAluno(a4);
    LiberaAluno(a5);
    LiberaAluno(a6);
    LiberaAluno(a7);

    return 0;
}