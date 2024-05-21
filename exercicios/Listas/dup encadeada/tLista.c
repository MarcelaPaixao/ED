//LISTA DUPLAMENTE ENCADEADA SEM SENTINELA
#include "tLista.h"

struct tCelula {
    tProduto *prod;
    tCelula *prox, *ant;
};

tLista *CriaLista(){
    tLista *lista = NULL;
    return lista;
}

tLista *InsereItemNaLista(tLista *lista, tProduto *p){
    if(!p) return lista;
    tCelula *cel = (tCelula *)malloc(sizeof(tCelula));
    
    cel->prod = p;
    cel->ant = NULL;
    cel->prox = NULL;
    
    if(!lista){;
        return cel; //a própria célula já será o 1 elemento da lista
    }
    
    cel->prox = lista;
    lista->ant = cel;
    
    return cel; //retorna o 1 elemento da lista
}

tLista *RetiraItemCodigo(tLista *lista, int cod){
    if(!lista) return NULL;
    tCelula *aux = lista;
    
    while(aux){
        if(RetornaCodigo(aux->prod) == cod){
            if(aux == lista && lista->prox == NULL){ //se for único
                LiberaProduto(aux->prod);
                free(aux);
                lista = NULL;
                return NULL;
            }
            else if(aux == lista){//se for o primeiro
                lista = lista->prox;
                if(lista != NULL){
                    lista->ant = NULL;
                }
            }
            else if(aux->ant != NULL && aux->prox != NULL){ //se não for único, nem primeiro e nem último
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;                
            }
            else { //se for o último
                aux->ant->prox = NULL;
            }
            LiberaProduto(aux->prod);
            free(aux);
            return lista; 
        }
        aux = aux->prox;
    }
    return lista;
}

void ImprimeLista(tLista *lista){
    int i=1;
    if(!lista){
        printf("Lista vazia!\n");
        return;
    }
    while(lista){
        printf("PRODUTO %d\n", i);
        ImprimeProduto(lista->prod);
        lista = lista->prox;
        printf("\n");
        i++;
    }
}

void LiberaLista(tLista *lista){
    if(!lista) return;
    tCelula *prox;

    while(lista){
        prox = lista->prox;
        LiberaProduto(lista->prod);
        free(lista);
        lista = prox;
    }
}
