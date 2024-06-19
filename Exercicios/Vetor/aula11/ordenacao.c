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

int binary_search(int *vet, int elem, int inicio, int fim){
    if(inicio <= fim){
        int meio = (inicio + fim)/2;
        if(vet[meio] > elem){ 
            return binary_search(vet, elem, inicio, meio -1);
        }
        else if(vet[meio] < elem){
            return binary_search(vet, elem, meio + 1, fim);
        }
        else {
            return meio;
        }
    }
    else {
        return -1;
    }
}
