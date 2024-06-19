#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

#define TAM 10

int main(){
    int vet[TAM];
    for(int i = 0; i < TAM; i++){
        vet[i] = rand() % 100;
        printf("%d ", vet[i]);
    }
    printf("\n");

    int idx_elem = linear_search(vet, TAM, vet[3]);
    printf("idx elemento: %d\n", idx_elem);

    bubble_sort(vet, TAM);

    for(int i = 0; i < TAM; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

    idx_elem = binary_search(vet, vet[3], 0, TAM-1);
    printf("idx elemento: %d\n", idx_elem);

    return 0;
}