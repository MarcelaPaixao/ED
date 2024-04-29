#include "BanhoTosa.h"
#include "Lista.h"

/*Tipo que define a loja de banho e tosa (tipo opaco)
 *Cada loja deve ter os seguintes atributos:
 * * Nome da loja
 * * Uma lista de animais (gatos e cachorros) agressivos
 * * Uma lista de animais (gatos e cachorros) mansos
 * */
struct banhotosa {
    char *nome;
    Lista *lAgressivos;
    Lista *lMansos;
};


/* Cria uma loja de banho e tosa, ainda vazia, com duas listas de animais vazias
* inputs: nome da loja (char*). Esta função deve alocar dinamicamente o nome da loja.
* output: loja alocada e vazia, com listas de animais ainda vazias
* pre-condicao: nao tem
* pos-condicao: loja alocada e vazia, com listas de animais criadas e vazias  */
BanhoTosa* inicBanhoTosa(char* nome){
    BanhoTosa *loja = malloc(sizeof(BanhoTosa));
    if(!loja){
        return NULL;
    }
    loja->nome = strdup(nome);
    loja->lAgressivos = inicLista();
    loja->lMansos = inicLista();

    return loja;
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraCachorro(BanhoTosa* loja, Cachorro* dog){
    if(!dog || !loja)return;

    int agr = retornaNivelAgrCao(dog);

    if(agr == MANSO){
        insereAnimal(loja->lMansos, dog, agr);
    }
    else if(agr == BRAVO){
        insereAnimal(loja->lAgressivos, dog, agr);
    }
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraGato(BanhoTosa* loja, Gato* cat){
    if(!cat || !loja)return;
    
    int agr = retornaNivelAgrGato(cat);
    
    if(agr == MANSO){
        insereAnimal(loja->lMansos, cat, agr);
    }
    else if(agr == BRAVO){
        insereAnimal(loja->lAgressivos, cat, agr);
    }
}


/* Essa função atualiza a situação de um gato na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat){
    if(!cat || !loja)return;

    int agr = retornaNivelAgrGato(cat);
    
    if(agr == MANSO){
        if(buscaAnimalNaLista(loja->lAgressivos, cat)){
            insereAnimal(loja->lMansos, cat, agr);
            retiraAnimal(loja->lAgressivos, cat);
        }
    }
    else {
        if(buscaAnimalNaLista(loja->lMansos, cat)){
            insereAnimal(loja->lAgressivos, cat, agr);
            retiraAnimal(loja->lMansos, cat);
        }
    }
}//se inverter a ordem das funções insere e retira vai dar problema?

/* Essa função atualiza a situação de um cachorro na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog){
    if(!dog || !loja)return;

    int agr = retornaNivelAgrCao(dog);
    
    if(agr == MANSO){
        if(buscaAnimalNaLista(loja->lAgressivos, dog)){
            insereAnimal(loja->lMansos, dog, agr);
            retiraAnimal(loja->lAgressivos, dog);
        }
    }
    else {
        if(buscaAnimalNaLista(loja->lMansos, dog)){
            insereAnimal(loja->lAgressivos, dog, agr);
            retiraAnimal(loja->lMansos, dog);
        }
    }
}


/* Imprime os dados da Loja (nome, e conteúdo das listas)
* inputs: referencia para a loja
* output: nenhum
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
void imprimeBanhoTosa(BanhoTosa* loja){
    if(!loja)return;
    printf("Nome da loja:%s\n", loja->nome);
    
    printf("Lista de animais agressivos:\n");
    imprimeLista(loja->lAgressivos);
    
    printf("Lista de animais mansos:\n");
    imprimeLista(loja->lMansos);
}


/* Calcula o valor que a loja vai receber caso todos os animais tomem banho.
 Valor Gato: 30 reais, Valor Cachorro: 40 reais. Caso o animal seja agressivo, é cobrado uma taxa extra de 5 reais.
* inputs: referencia para a loja
* output: valor da receita
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
float calculaReceita(BanhoTosa* loja){
    if(!loja) return 0;
    float receita=0;
    int qtdDog, qtdCat;
    
    retornaQtdCadaAnimal(loja->lMansos, &qtdDog, &qtdCat);
    receita += (50 * qtdDog) + (40 * qtdCat);

    retornaQtdCadaAnimal(loja->lAgressivos, &qtdDog, &qtdCat);
    receita += (55 * qtdDog) + (45 * qtdCat);

    return receita;
}


/* Libera toda a memória alocada
* inputs: referencia para a loja
* output: não tem
* pre-condicao: loja alocada
* pos-condicao: Toda a memória liberada, a não ser gatos e cachorros, que são responsabilidade do cliente. */
void liberaBanhoTosa(BanhoTosa* loja){
    if(!loja) return;
    free(loja->nome);
    liberaLista(loja->lAgressivos);
    liberaLista(loja->lMansos);
    free(loja);
}