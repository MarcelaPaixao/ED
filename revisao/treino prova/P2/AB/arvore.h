/*Implemente o TAD árvore da aula passada com a seguinte modificação: 
faça um TAD árvore de alunos (e não de char, como na aula). 
Use o nome do aluno como chave de busca na função pertence. Além disto, faça as funções:
    - int folhas (Arv* a); //retorna o número de folhas da árvore
    - int ocorrencias (Arv* a , char* nome); //retorna o número de vezes que o aluno aparece na árvore
    - int altura (Arv* a); retorna a altura da árvore*/

#ifndef _arvore_h
#define _arvore_h

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

typedef struct arvore Arvore;

Arvore *criaArvoreVazia();

Arvore *criaArvore(Arvore *esq, Arvore *dir, Aluno *a);

int arvoreVazia(Arvore *a);

int pertence(Arvore *a, char *nome);

int folhas (Arvore* a); //retorna o número de folhas da árvore

int ocorrencias (Arvore* a , char* nome); //retorna o número de vezes que o aluno aparece na árvore

int altura (Arvore* a); //retorna a altura da árvore*/

void imprimeArvore(Arvore *a);

Arvore *liberaArvore(Arvore *a);

#endif