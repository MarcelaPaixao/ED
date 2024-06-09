#include "pilha.h"

#define MAX 10

/*TipoItem Pessoa (tipo opaco). Contem campos:
  - nome (string)
  - idade (int)
  - endereco (string)
  */
struct pessoa {
    char *nome, *endereco;
    int idade;
};


/*Tipo que define a Pilha (tipo opaco)
  Atencao: Esta pilha pode conter ate 10 Pessoas
*/
struct pilha {
    Pessoa *pessoas[MAX];
    int topo;
};


/*Inicializa a Pilha
* inputs: nenhum
* output: P (a pilha criada)
* pre-condicao: nenhuma
* pos-condicao: P está definida e vazia
*/
Pilha* cria_pilha(){
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

/*Insere uma pessoa no topo da pilha (se houver espaco)
* inputs: P (uma pilha) e E (uma pessoa)
* output: nenhum
* pre-condicao: P nao vazia e com espaco para o elemento.
* pos-condicao: Ao final da função, a pilha tem E como o elemento
do topo
*/
void push(Pessoa* pessoa, Pilha* p){
    if(!p || !pessoa || p->topo >= MAX){
        printf("Nao foi possiel realizaro push!");
        return;
    }
    p->pessoas[p->topo] = pessoa;
    (p->topo)++;
}


/*Retira uma Pessoa do topo da Pilha (se pilha não vazia)
* inputs: a Pilha
* output: a pessoa retirada do topo da pilha
* pre-condicao: Pilha não é nula e não é vazia
* pos-condicao: pilha não contém o elemento retirado do topo
*/
Pessoa* pop(Pilha* p){
    if(!p || p->topo == 0){
        return NULL;
    }
    Pessoa *pessoa = p->pessoas[p->topo-1];
    (p->topo)--;
    return pessoa;
}


/*Imprime as pessoas da pilha
 * inputs: a pilha
 * output: nenhum
 * pre-condicao: pilha P não vazia
 * pos-condicao: Pilha permanece inalterada
 */
void imprime_pilha (Pilha* p){
    if(!p) return;
    for(int i = (p->topo-1); i >= 0; i--){
        printf("Nome: %s, Endereco: %s, Idade: %d\n", p->pessoas[i]->nome, p->pessoas[i]->endereco, p->pessoas[i]->idade);
    }
}


/*Libera a memoria ocupada pela pilha
* inputs: a Pilha
* output: NULL
* pre-condicao: Pilha não é nula
* pos-condicao: Toda memoria eh liberada
*/
Pilha* destroi_pilha(Pilha* p){
    if(!p) return NULL;
    free(p);
    return NULL;
}


/*Inicializa um TipoItem Pessoa
* inputs: o nome, a idade e o endereco da pessoa
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, idade e endereco validos
* pos-condicao: tipo item criado, com os campos nome, idade e endereco copiados
*/
Pessoa* inicializaPessoa(char* nome, int idade, char* endereco){
    Pessoa *a = malloc(sizeof(Pessoa));
    a->endereco = strdup(endereco);
    a->nome = strdup(nome);
    a->idade = idade;
    return a;
}

void LiberaPessoa(Pessoa *pessoa){
    if(pessoa){
        free(pessoa->nome);
        free(pessoa->endereco);
        free(pessoa);
    }
}