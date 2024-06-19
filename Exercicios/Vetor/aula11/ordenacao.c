#include "ordenacao.h"

void bubble_sort(int *vet, int tam){
    for(int i=0; i < tam; i++){
        for(int j=i+1; j < tam; j++){
            if(vet[i] > vet[j]){
                int aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

void quick_sort(int *vet, int tam);

int linear_search(int *vet, int tam, int elem){
    for(int i = 0; i < tam; i++){
        if(vet[i] == elem){
            return i;
        }
    }
    return -1;
}

void binary_search(int *vet, int tam, int elem){
    
}
