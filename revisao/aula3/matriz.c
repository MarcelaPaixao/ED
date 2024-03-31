#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

//Tipo matriz (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementaÁ„o do TAD
struct matriz {
    int col, lin, *vet;
};

/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    if(nlinhas <= 0 || ncolunas <= 0) return NULL;
    
    Matriz *mat = malloc(sizeof(Matriz));
    if(!mat){
        printf("Erro na alocacao do tipo Matriz!\n"); 
        exit(1);
    } 

    mat->vet = calloc(nlinhas * ncolunas, sizeof(int));
    if(!mat->vet){
        printf("Erro na alocacao da matriz!\n"); 
        exit(1);
    } 
    
    mat->lin = nlinhas;
    mat->col = ncolunas;

    return mat;
}

int verificaLimiteMatriz(Matriz *mat, int lin, int col){
    if(lin < 0 || lin >= mat->lin ||
       col < 0 || col >= mat->col){
        return 0;
    }
    return 1;
}

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna s„o v·lidos na matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    if(!mat || !verificaLimiteMatriz(mat, linha, coluna)) return;
    mat->vet[mat->col*linha + coluna] = elem;
}

/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a coluna
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna s„o v·lidos na matriz
 * pos-condicao: mat n„o È modificada
 */
int recuperaElemento(Matriz* mat, int linha, int coluna){
    if(!mat || !verificaLimiteMatriz(mat, linha, coluna)) return 0;
    return (mat->vet[(mat->col*linha) + coluna]);
}

/*Retorna o n˙mero de colunas da matriz mat
 * inputs: a matriz
 * output: o n˙mero de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada
 */
int recuperaNColunas (Matriz* mat){
    if(mat) return mat->col;
}

/*Retorna o n˙mero de linhas da matriz mat
 * inputs: a matriz
 * output: o n˙mero de linhas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada
 */
int recuperaNLinhas (Matriz* mat){
    if(mat) return mat->lin;
}

/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada e matriz transposta existe
 */
Matriz* transposta (Matriz* mat){
    if(!mat) return NULL;
    Matriz *transp =  inicializaMatriz(recuperaNColunas(mat), recuperaNLinhas(mat));

    for(int i=0; i < transp->lin; i++){
        for(int j=0; j < transp->col; j++){
            transp->vet[(transp->col*i)+j] = mat->vet[(mat->col*j)+i];
        }
    }

    return transp;
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicaÁ„o
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1
 * correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 n„o s„o modificadas e a matriz multiplicacao existe
 */
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    Matriz *mat3 = NULL;
    if(mat1 && mat2 && mat1->col == mat2->lin){
        mat3 = inicializaMatriz(mat1->lin, mat2->col);

        for(int i=0; i < mat3->lin; i++){
            for(int j=0; j < mat3->col; j++){
                for(int k=0; k < mat1->col; k++){
                    mat3->vet[mat3->col*i+j] += mat1->vet[mat1->col*i+k] * mat2->vet[mat2->col*k+j];
                }
            }
        }
    }
    
    return mat3;
}

void imprimeLinhas (Matriz* mat, int indice){
    if(!mat) return;
    for(int j=0; j < mat->col; j++){
        printf("%d ", recuperaElemento(mat, indice, j));
    }
    printf("\n");
}

/*Imprime a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz* mat){
    if(!mat) return;
    for(int i=0; i < mat->lin; i++){
        imprimeLinhas(mat, i);
    }
    printf("\n");
}

void destroiMatriz (Matriz* mat){
    if(!mat) return;
    free(mat->vet);
    free(mat);
}