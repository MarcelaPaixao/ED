#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

#define TAM 10
#define NUM 4587 //num qualquer só pra teste

int main(){
    int vet[TAM];
    for(int i = 0; i < TAM; i++){
        vet[i] = rand() % 10000 + 1;
    }

    //bubble_sort(vet, TAM);

    for(int i = 0; i < TAM; i++){
        printf("%d ", vet[i]);
    }

    int idx_elem = linear_search(vet, TAM, NUM);
    printf("idx elemento: %d\n", idx_elem);

    return 0;
}