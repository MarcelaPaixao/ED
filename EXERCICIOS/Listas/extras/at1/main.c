#include <stdio.h>
#include "listadpl.h"
#include "extra.h"

int main() {
    TipoItem* aluno1 = InicializaTipoItem("Marcela", 1, "Vila Velha");
    TipoItem* aluno2 = InicializaTipoItem("Aline", 2, "Vitoria");
    TipoItem* aluno3 = InicializaTipoItem("Malu", 3, "Eunapolis");
    TipoItem* aluno4 = InicializaTipoItem("Gabriel", 4, "Vitoria");
    TipoItem* aluno5 = InicializaTipoItem("Raony", 5, "Fim do Mundo1");
    TipoItem* aluno6 = InicializaTipoItem("Eduardo", 6, "Fim do Mundo2");

    TipoListaDpl *lista = NULL;
    lista = Insere(aluno6, lista);
    lista = Insere(aluno5, lista);
    lista = Insere(aluno4, lista);
    lista = Insere(aluno3, lista);
    lista = Insere(aluno2, lista);
    lista = Insere(aluno1, lista);

    const char *message = "\nAula do TODSANTOS esta acontecendo!\n\nVamos ver quem esta em sala . . .\n\n";
    print_char_by_char(message);
    Imprime(lista);

    lista = Retira(lista, "Marcela");
    lista = Retira(lista, "Malu");
    lista = Retira(lista, "Aline");
    lista = Retira(lista, "Gabriel");
    lista = Retira(lista, "Eduardo");

    message = "\nAlguns alunos se cansaram do Natal e resolveram abandonar o Papai Noel.\n";
    print_char_by_char(message);
    message = "\nEspera! Ainda tem alguem la!!\nParece que sobrou apenas o seu fa supremo: ";
    print_char_by_char(message);
    
    Imprime(lista);
    
    message = "\nTambem conhecido como... ";
    print_char_by_char(message);
    message = "\nTODJUNIOR!!!\n";
    print_char_by_charLowSpeed(message);
    
    message = "----------------- Feliz Natal Trivial! -----------------\n\n";
    print_char_by_char(message);

    libera(lista);
    return 0;
}
