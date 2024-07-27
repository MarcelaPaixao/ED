#ifndef HASH_H_
#define HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include "Palavra.h"

typedef struct hash Hash;

/*Inicializa a tabela hash com o tamanho passado, e o vetor de palavras tem todas as suas
posições iniciadas como NULL*/
Hash *InicializaHash(int tam);

/*Verifica-se se a string passada já é uma palavra da tabela. Se sim, ela só é retornada. 
Caso contrário, ela é inserida na tabela, e então retornada*/
Palavra *acessa(Hash *h, char *str);

/*Imprime a tabela*/
void ImprimeHash(Hash *h);

/*Libera a tabela e seus elementos*/
void LiberaHash(Hash *h);

#endif