#include <stdio.h>
#include <stdlib.h>
#include "tLista.h"

void ImprimeMenu(){
    printf("============ Escolha uma opcao ============\n");
    printf("1 - Inserir produto na lista\n");
    printf("2 - Retirar produto da lista\n");
    printf("3 - Liberar lista e finalizar\n");
    printf("============================================\n");
}

int main(){
    Lista *lista = CriaLista();
    int option=0;

    while(option != 3){
        ImprimeMenu();
        scanf("%d", &option);

        if(option == 1){
            tProduto *prod = CriaProduto();
            InsereItemNaLista(lista, prod);
            printf("========== Estado atual da lista ==========\n");
            ImprimeLista(lista);
            printf("===========================================\n");
        }
        else if(option == 2){
            int cod;
            printf("Digite o codigo do produto que deseja retirar:");
            scanf("%d", &cod);
            RetiraItemCodigo(lista, cod);
            printf("========== Estado atual da lista ==========\n");
            ImprimeLista(lista);
            printf("===========================================\n");
        }
        else if(option == 3){
            LiberaLista(lista);
        }
        else {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}