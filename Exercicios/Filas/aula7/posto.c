//Define o limite entre positivo e negativo
//Amostras com carga viral >= LIMETE_CARGA_VIRAL são consideradas POSITIVAS
//Amostras com carga viral < LIMETE_CARGA_VIRAL são consideradas NEGATIVAS
#define LIMITE_CARGA_VIRAL 500
#define POS 1
#define NEG 0
#include "posto.h"

/*Tipo que define um Posto de Saúde (tipo opaco)
 *Um posto deve ter os seguintes atributos:
 * * Nome do Posto
 * * Uma FILA de amostras para exame não processadas
 * * Uma FILA de amostras processadas com resultado POSITIVO
 * * Uma FILA de amostras processadas com resultado NEGATIVO
 * */
struct posto {
    char *nome;
    Fila *naoProcessado, *positivo, *negativo;
};

/* Cria um posto de saúde, ainda vazio, com as 3 filas, vazias
* inputs: nome do posto de saúde.
* output: posto alocado e vazio, com filas de amostras ainda vazias
* pre-condicao: nao tem
* pos-condicao: posto alocado e vazio, com filas de amostras alocadas e vazias
 */
Posto* inicPosto(char* nome){
    Posto *p = malloc(sizeof(Posto));
    p->nome = strdup(nome);
    p->naoProcessado = CriaFila();
    p->negativo = CriaFila();
    p->positivo = CriaFila();
    return p;
}

/* Imprime os dados do Posto no seguinte formato:
 
 Dados do Posto: <nome do posto>
 Amostras não processadas
 <fila de amostras não processadas - do início ao fim>
 
 Amostras com resultados positivos
 <fila de amostras positivas - do início ao fim>
 
 Amostra com resultados negativos
 <fila de amostras negativas - do início ao fim>
 
* inputs: referencia para o posto
* output: nenhum
* pre-condicao: posto alocado
* pos-condicao: dados do posto não são alterados
 */
void imprimePosto(Posto* posto){
    if(!posto) return;
    printf("Dados do Posto: %s\n", posto->nome);
    printf("Amostras não processadas\n");
    
    ImprimeFila(posto->naoProcessado);

    printf("\nAmostras com resultados positivos\n");
    ImprimeFila(posto->positivo);

    printf("\nAmostras com resultados negativos\n");
    ImprimeFila(posto->negativo);
}

/* Simula a realização de uma coleta de material para teste
 * A função deve criar uma amostra e fazer as devidas atribuições à amostra
 * Deve-se inserir a amostra na fila de "não processados"
 * ATENÇÃO: se a pessoa for idosa (idade>=60), ela deve ir para o início da fila de não processados
* inputs: referência para o posto de saúde, o nome do dono da coleta e a idade da pessa
* output: nenhum
* pre-condicao: posto válido, nome da pessoa válido
* pos-condicao: Amostra alocada e inserida na fila de amostras não processadas
 */
void realizaColeta(Posto* posto, char* pessoa, int idade) {
    Amostra *a = inicAmostra(pessoa, idade);

    if(idade >= 60){
        InsereAmostraInicio(posto->naoProcessado, a);
    }
    else {
        InsereAmostraFinal(posto->naoProcessado, a);
    }
}


/* Essa função simula o processamento (testagem) das amostras e atualiza os resultados nas amostras. Deve-se usar a constante LIMITE_CARGA_VIRAL para definir positivo e negativo.
* inputs: referência do posto de saúde.
* output: nenhum
* pre-condicao: posto válido
* pos-condicao: amostras foram devidamente processadas; fila de amostras não processadas deve ficar vazia; fila de amostras positivas deve conter as amostras que testaram positivo (idosos na frente); fila de amostras negativas deve conter as amostras que testaram negativo (idosos na frente).
 */
void processaLoteAmostras(Posto* posto){
    while(!EstaVaziaFila(posto->naoProcessado)){
        Amostra *a = RetiraAmostra(posto->naoProcessado);
        if(retornaCargaViral(a) >= LIMITE_CARGA_VIRAL){
            registraResultado(a, POS);
            if(retornaIdade(a) >= 60){
                InsereAmostraInicio(posto->positivo, a);
            }
            else{
                InsereAmostraFinal(posto->positivo, a);
            }
        }
        else if(retornaCargaViral(a) < LIMITE_CARGA_VIRAL){
            registraResultado(a, NEG);
            if(retornaIdade(a) >= 60){
                InsereAmostraInicio(posto->negativo, a);
            }
            else{
                InsereAmostraFinal(posto->negativo, a);
            }
        }
    }
}

/* Libera toda a memória alocada para o posto de saúde
* inputs: referência do posto de saúde.
* output: nenhum
* pre-condicao: posto válido
* pos-condicao: Memória para a string nome liberada; memória para as 3 filas liberada, memoria do posto liberada
 */
void liberaPosto(Posto* posto){
    if(!posto) return;
    free(posto->nome);
    LiberaFila(posto->naoProcessado);
    LiberaFila(posto->positivo);
    LiberaFila(posto->negativo);
    free(posto);
}


