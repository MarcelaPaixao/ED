#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

void calc_esfera(float r, float* area, float* volume){
    *area = 4*PI*r*r;
    *volume = (4*PI*r*r*r)/3;
}

/*int raizes(float a, float b, float c, float* x1, float* x2){
    double delta = (b*b) - 4*a*c;
    if(delta < 0){
        return 0;
    }
    *x1 = ((-1*b) + sqrt(delta))/(2*a);
    *x2 = ((-1*b) - sqrt(delta))/(2*a);
    return 1;
}*/

int pares (int n, int* vet){
    int qtdPares=0;
    for(int i=0; i < n; i++){
        if(vet[i]%2 == 0){
            qtdPares++;
        }
    }
    return qtdPares;
}

void inverte (int n, int*vet){
    
}

/*
//2.1)
int main(){
    float r=0, area=0, volume=0;
    printf("Digite o raio:");
    scanf("%f", &r);
    calc_esfera(r, &area, &volume);
    printf("Area: %.2f\nVolume:%.2f\n", area, volume);
    return 0;
}
*/

/*
//2.2)
int main(){
    float a, b, c, x1=0, x2=0;
    printf("Digite tres valores:");
    scanf("%f %f %f", &a, &b, &c);

    if(raizes(a, b, c, &x1, &x2)){
        printf("As raizes da equacao sao:\nx1: %.2f\nx2:%.2f\n", x1, x2);
    }
    else {
        printf("A equacao nao possui raizes!\n");
    }
    
    return 0;
}
*/

/*
//2.3)
int main(){
    int n=0;
    printf("Digite o numero de elementos:");
    scanf("%d", &n);

    int *vet = malloc(n * sizeof(int));
    printf("Digite os elementos:");
    for(int i=0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    printf("A qtd de pares e: %d\n", pares(n, vet));
    free(vet);
    return 0;
}
*/

