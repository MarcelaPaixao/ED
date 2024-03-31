#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

#define TAM1 3
#define TAM2 2

int main(){
    int n=0;
    
    Matriz *mat1 = inicializaMatriz(TAM1, TAM2);
    for(int i=0; i < TAM1; i++){
        for(int j=0; j < TAM2; j++){
            n += 2;
            modificaElemento(mat1, i, j, n);
        }
    }
    printf("Matriz 1:\n");
    imprimeMatriz(mat1);

    n=1;
    Matriz *mat2 = inicializaMatriz(TAM2, TAM1);
    for(int i=0; i < TAM2; i++){
        for(int j=0; j < TAM1; j++){
            modificaElemento(mat2, i, j, n);
            n += 2;
        }
    }
    printf("Matriz 2:\n");
    imprimeMatriz(mat2);

    Matriz *mult = multiplicacao(mat1, mat2);
    printf("Matriz 1 X Matriz 2:\n");
    imprimeMatriz(mult);

    Matriz *tranp = transposta(mult);
    printf("Transposta da Matriz 1 X Matriz 2:\n");
    imprimeMatriz(tranp);         
           
    destroiMatriz(mat1);
    destroiMatriz(mat2);
    destroiMatriz(mult);
    destroiMatriz(tranp);
        
    return 0;
}