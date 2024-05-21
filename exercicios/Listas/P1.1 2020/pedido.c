#include "pedido.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cel Cel;

/* Define o tipo TPedido (tipo opaco). Estrutura interna deste tipo eh definida na implementacao do TAD.
 * Trata-se da sentinela da lista e deve conter as seguintes informacoes:
 * Dono do pedido (char*) e os campos prim e ult da sentinela
 */
struct pedido {
    char *dono;
    Cel *prim;
    Cel *ult;
};

struct Cel {
    TProduto *prod;
    Cel *prox;
};

/*----------------------------------------------------------------------
 * Inicializa o pedido de um cliente (ou seja, a sentinela!)
 * inputs: nome do dono do pedido
 * output: Pedido inicializado
 * pre-condicao: nome devidamente alocado
 * pos-condicao: Pedido inicializado contendo o nome como informado
 *---------------------------------------------------------------------- */
TPedido* InicPedido (char* dono){
    TPedido *p = malloc(sizeof(TPedido));
    if(!p){
        printf("Erro na alocação do pedido!");
        return NULL;
    }
    p->dono = strdup(dono);
    p->prim = p->ult = NULL;
    return p;
}

/*----------------------------------------------------------------------
 * Inclui um produto no pedido de um cliente (ou seja, a sentinela!). Inserir ao FINAL!
 * Lembrando que um produto nao pode ser inserido mais de uma vez no pedido! Neste caso, exiba a mensagem "Produto já existe no pedido\n"
 * inputs: o pedido e o produto a ser inserido
 * output: nada
 * pre-condicao: pedido e produto foram devidamente inicializados
 * pos-condicao: produto inserido no pedido OU lista inalterada (caso o produto ja esteja na lista)
 *----------------------------------------------------------------------*/
void IncluiProdutoPedido (TPedido* pedido, TProduto* prod){
    if(!pedido || !prod) return;
    
    Cel *aux = pedido->prim;

    while(aux){
        if(strcmp(RetornaNome(aux->prod), RetornaNome(prod)) == 0){
            printf("Produto já existe no pedido\n");
            return;
        }
        aux = aux->prox;
    }
    printf("oi\n");
    Cel *c = malloc(sizeof(Cel));
    c->prod = prod;
    c->prox = NULL;
        
    if(pedido->prim == NULL){
        pedido->prim = pedido->ult = c;
        return;
    }
    pedido->ult->prox = c;
    pedido->ult = c;
}

/*----------------------------------------------------------------------
 * Imprime todos os dados de um pedido (o dono seguido de todos os produtos e ingredientes)
 * Caso o pedido seja novo e nao tenha ainda produtos, exibir a mensagem "Nao ha produtos neste pedido!\n"
 * inputs: o pedido
 * output: nada
 * pre-condicao: pedido devidamente inicializado
 * pos-condicao: funcao nao alterad os dados do pedido
 *----------------------------------------------------------------------*/
void ImprimePedido (TPedido* pedido){
    if(!pedido){
        printf("Nao ha produtos neste pedido!\n");
        return;
    }
    
    printf("Dono do pedido: %s\n", pedido->dono);
    Cel *c = pedido->prim;
    while(c){
        ImprimeIngredientes(c->prod);
        c = c->prox;
    }
}

/*----------------------------------------------------------------------
 * Retira a unica ocorrência do produto (caso eltypedef struct Cel Cel;e exista na lista).
 * Importante!!! Esta funcao nao libera o produto! Apenas o retira do pedido!
 * inputs: o pedido e, o produto a ser retirado
 * output: nada
 * pre-condicao: pedido e produto devidamente inicializados
 * pos-condicao: pedido nao contem o produto
 *----------------------------------------------------------------------*/
void RetiraProdutoPedido (TPedido* pedido, char* prod){
    if(!pedido || !prod) return;

    Cel *c = pedido->prim;
    Cel *ant = NULL;
    
    while(c && strcmp(RetornaNome(c->prod), prod) != 0){
        ant = c;
        c = c->prox;
    }

    if(c == NULL){
        return;
    }
    else if(c == pedido->prim && c == pedido->ult){
        pedido->prim = pedido->ult = NULL;
    }
    else if(c == pedido->prim){
        pedido->prim = c->prox;
    }
    else if(c == pedido->ult){
        pedido->ult = ant;
        ant->prox = NULL;
    }
    else {
        ant->prox = c->prox;
    }
    free(c);
}

//A função envia pedido verifica se há restrição calórica ou restrição alimentar
//Se estiver tudo ok, retira o pedido da lista (libera o pedido, porém não libera o produto) e retorna 1
//Se não estiver ok, a lista permanece a mesma e a função retorna zero

/*----------------------------------------------------------------------
 * Primeiramente, verifica se há restrição calórica ou restrição alimentar, de acordo com os parametros
 **** Para a restricao calorica, deve-se somar as calorias de todos o produtos do pedido! Caso o numero de calorias do pedido ultrapasse a restricao, exiba a mensagem : "Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!"
 ****** Para a restricao alimentar, deve-se verificar se algum produto contem como ingrediente a restricao especificada. Caso algum produto contenha o ingrediente indicado, exiba a mensagem: Pedido não Enviado! Restricao alimentar no produto: %s\n
* Se estiver tudo certo (ou seja respeitando-se as restricoes), destroi o pedido da pessoa, porém não libera os produtos) e retorna 1
 * inputs: o pedido e as restricoes calorica e alimentar
 * output: 0 (problema em algumas das restricoes). 1 (pedido enviado)
 * pre-condicao: pedido devidamente inicializado e strings validas
 * pos-condicao: se houver problema com as restricoes, o pedido deve ficar inalterado. se estiver tudo ok com as restricoes, deve destruir o pedido, porem os produtos nao devem ser liberados (pois podem estar em outros pedidos, de outras pessoas).
 *----------------------------------------------------------------------*/
int EnviaPedido (TPedido* pedido, int restricao_calorica, char* restricao_alimentar){
    if(!pedido || !restricao_alimentar) return 0;
    
    int calorias = 0;
    int restricao = 0;
    Cel *atual = pedido->prim;
    while(atual){
        calorias += Calorias(atual->prod);
        if(VerificaIngrediente(atual->prod, restricao_alimentar)){
            restricao = 1;
            break;
        }
        atual = atual->prox;
    }
    
    if(calorias > restricao_calorica){
        printf("Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!\n");
        return 0;
    }
    if(restricao){
        printf("Pedido não Enviado! Restricao alimentar no produto: %s\n", RetornaNome(atual->prod));
        return 0;
    }

    atual = pedido->prim;
    Cel *prox = NULL;
    while(atual){
        prox = atual->prox;
        free(atual);
        atual = prox;
    } 
    free(pedido);
}
