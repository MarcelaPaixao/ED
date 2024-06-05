#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void ImprimeMenu(){
    printf("============ Escolha uma opcao ============\n");
    printf("1 - Inserir produto na lista\n");
    printf("2 - Retirar produto da lista\n");
    printf("3 - Imprimir lista\n");
    printf("4 - Liberar lista e finalizar\n");
    printf("============================================\n");
}

int main(){
    Lista *lista = CriaLista();
    int option=0;

    while(option != 4){
        ImprimeMenu();
        scanf("%d", &option);

        if(option == 1){
            tProduto *prod = CriaProduto();
            lista = InsereItemNaLista(lista, prod);/////
        }
        else if(option == 2){
            int cod;
            printf("Digite o codigo do produto que deseja retirar:");
            scanf("%d", &cod);
            lista = RetiraListaRec(lista, cod);
        }
        else if(option == 3){
            ImprimeListaRec(lista);
        }
        else if(option == 4){
            LiberaListaRec(lista);
        }
        else {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}