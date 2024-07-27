#ifndef PALAVRA_H_
#define PALAVRA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palavra Palavra;

/*Inicializa a palavra com a string passada, e seta o  número de ocorrências para 
começar com zero;*/
Palavra *InicializaPalavra(char *str);

/*Procura na lista palavras a string passada, e caso a encontre, retorna a palavra em que ela está. 
Caso contrário, retorna NULL;*/
Palavra *buscaPalavra(Palavra *p, char *str);

/*Insere a palavra passada na na primeira posição da lista;*/
Palavra *inserePalavraLista(Palavra *lista, Palavra *p);

/*Retorna a string da palavra passada*/
char *RetornaString(Palavra *p);

/*Retorna o número de ocorrências da palavra passada*/
int RetornaOcorrencias(Palavra *p);

/*Incrementa o número de ocorrências da palavra passada*/
void AtualizaOcorrencias(Palavra *p);

/*Libera a lista*/
void LiberaListaDePalavra(Palavra *p);

/*Imprime a lista*/
void imprimeListaPalavra(Palavra *p);

#endif