#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadpl.h"

/*TipoItem Aluno (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD. Devem ser definidos campos:
  - nome (string)
  - matricula (int)
  - endereco (string)
  */
struct tipoitem {
    char *nome, *endereco;
    int mat;
};

/*Tipo que define a lista (tipo opaco)
  Estrutura interna do tipo deve ser definida na implementação do TAD.
  Usar lista duplamente encadeada sem Sentinela
  */
struct tipolistadpl {
    TipoItem *aluno;
    TipoListaDpl *prox, *ant;
};

typedef TipoListaDpl Cel;

/*Insere um aluno na primeira posição da lista duplamente encadeada de alunos
* inputs: aluno a ser inserido na lista (do tipo TipoItem) e a lista
* output: lista duplamente encadeada com o item inserido na primeira posição
* pre-condicao: aluno e lista não são nulos
* pos-condicao: lista contém o aluno inserido na primeira posição
*/
TipoListaDpl* Insere (TipoItem* aluno, TipoListaDpl* lista){
    Cel *c = malloc(sizeof(Cel));
    
    c->aluno = aluno;
    c->ant = NULL;
    c->prox = NULL;
    
    if(!lista){
        return c;
    }
    
    c->prox = lista;
    lista->ant = c;

    return c;
}

void LiberaTipoItem(TipoItem *a){
    if(a){
        free(a->nome);
        free(a->endereco);
        free(a);
    }
}

/*Retira um aluno de nome "nome" da lista de alunos
* inputs: a lista e o nome do aluno a ser retirado da lista
* output: o aluno (do tipo TipoItem) retirado da lista ou NULL, se o aluno não se encontrar na lista
* pre-condicao: lista não é nula
* pos-condicao: lista não contém o aluno de nome "nome"
*/
TipoListaDpl* Retira (TipoListaDpl* lista, char* nome){
    if(!lista) return NULL;
    Cel *c = lista;
    while(c && strcmp(c->aluno->nome, nome) != 0){
        c = c->prox;
    }

    if(c == lista && c->prox == NULL){ //se for o 1 e único elemento
        lista = NULL;
    }
    else if(c == lista){//se for o 1
        lista = c->prox;
        c->prox->ant = NULL;
    }
    else if(c->prox == NULL){ //se for o último
        c->ant->prox = NULL;
    }
    else { //nenhum dos casos acima
        c->ant->prox = c->prox;
        c->prox->ant = c->ant;
    }
    LiberaTipoItem(c->aluno);
    free(c);
    return lista;
}


/*Imprime os dados de todos os alunos da lista duplamente encadeada
* inputs: a lista de alunos
* output: nenhum
* pre-condicao: lista não é nula
* pos-condicao: dados dos alunos impressos na saida padrao
*/
void Imprime (TipoListaDpl* lista){
    Cel *c = lista;
    while(c){
        const char *m = "Aluno: ";
        print_char_by_charHighSpeed(m);
        printf("%s", c->aluno->nome);
        
        m = ", Matricula: ";
        print_char_by_charHighSpeed(m);
        printf("%d", c->aluno->mat);
        
        m = ", Endereco: ";
        print_char_by_charHighSpeed(m);
        printf("%s\n", c->aluno->endereco);
        c = c->prox;
    }
}


/*Inicializa um TipoItem aluno
* inputs: o nome, a matricula e o endereco do aluno
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, matricula e endereco validos
* pos-condicao: tipo item criado, com os campos nome, matricula e endereco copiados
*/
TipoItem* InicializaTipoItem(char* nome, int matricula, char* endereco){
    TipoItem *a = malloc(sizeof(TipoItem));
    a->endereco = strdup(endereco);
    a->nome = strdup(nome);
    a->mat = matricula;
    return a;
}


/*Libera toda a memória alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
* inputs: a lista duplamente encadeada de alunos
* output: Lista vazia (NULL)
* pre-condicao: lista não é nula
* pos-condicao: memória alocada é liberada
*/
TipoListaDpl* libera (TipoListaDpl* lista){
    Cel *prox;
    while(lista){
        prox = lista->prox;
        LiberaTipoItem(lista->aluno);
        free(lista);
        lista = prox;
    }
}

