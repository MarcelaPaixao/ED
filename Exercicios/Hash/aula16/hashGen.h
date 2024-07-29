#ifndef HASHGEN_H_
#define HASHGEN_H_

#include <stdlib.h>
#include <stdio.h>

typedef int (*hashFunction)(int tam, void *dado); //função que dará o idx na hash
typedef int (*compFunction)(void *dado1, void *dado2);
//typedef void (*funcLibera)(void *dado); 
typedef void (*funcImprime)(void *dado);

typedef struct hash Hash;

Hash *criaHash(int tam);

void insere(Hash *t, void *chave, void *elem, hashFunction hashFunct);

void *busca(Hash *t, void *chave, hashFunction hashFunct, compFunction compara);

void liberaHash(Hash *t);

void imprimeHash(Hash *t, funcImprime imprime);



/*
Hash* cria (int tam, size_t tam_item);
void* busca (Hash* hash, void* key, int (*fhash)(void*), int (*comp)(void*,void*));
void* hash_insere (Hash* thash, void* key, void* objeto, int (*hash)(void*), int(*comp)(void*,void*));
void libera(Hash* table);
*/

#endif