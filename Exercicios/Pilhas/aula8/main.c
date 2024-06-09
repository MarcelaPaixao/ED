#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main(){
    Pessoa *p1 = inicializaPessoa("A", 10, "vix");
    Pessoa *p2 = inicializaPessoa("B", 45, "xiv");
    Pessoa *p3 = inicializaPessoa("C", 22, "ix");
    Pessoa *p4 = inicializaPessoa("D", 8, "vx");

    Pilha *pilha = cria_pilha();

    push(p1, pilha);
    push(p2, pilha);
    push(p3, pilha);
    push(p4, pilha);

    imprime_pilha(pilha);

    pop(pilha);
    pop(pilha);

    imprime_pilha(pilha);

    destroi_pilha(pilha);

    LiberaPessoa(p1);
    LiberaPessoa(p2);
    LiberaPessoa(p3);
    LiberaPessoa(p4);

    return 0;
}