#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

#define TAM 1000000
#define ELEM 45

int main(){
    int vet[TAM];
    
    printf("Vetor desordenado:\n");
    for(int i = 0; i < TAM; i++){
        vet[i] = rand() % 100;
        printf("%d ", vet[i]);
    }

    bubble_sort(vet, TAM);
    //quick_sort(vet, TAM);

    printf("\nVetor ordenado:\n");
    for(int i = 0; i < TAM; i++){
        printf("%d ", vet[i]);
    }

    //printf("\nidx elemento: %d\n", linear_search(vet, TAM, ELEM));
    //printf("idx elemento: %d\n", binary_search(vet, ELEM, 0, TAM-1));

    return 0;
}