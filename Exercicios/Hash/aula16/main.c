#include <stdio.h>
#include <stdlib.h>
#include "hashGen.h"
#include "aluno.h"

int hashAluno(int tam, void *matricula){
    int *mat = (int*)matricula;
    return  (*mat) % tam;
}

int hashString(int tam, void *str){
    int total = 0;
    char *string = (char *)str;
    for(int i=0; i < strlen(string); i++){
        total += string[i];
    }
    return total % tam;
}

void imprimeStr(void *str){
    char *string = (char *)str;
    printf("%s\n", string);
}

int comparaStr(void *str1, void *str2){
    char *string1 = (char *)str1;
    char *string2 = (char *)str2;
    if(strcmp(string1, string2) == 0) return 1;
    return 0;
}

int main(){
    Hash *table1 = criaHash(12);
    
    Aluno *a1 = CriaAluno("Marcela", 105);//
    Aluno *a2 =CriaAluno("Aline", 321);//
    Aluno *a3 =CriaAluno("Malu", 445);//
    Aluno *a4 =CriaAluno("Gabriel", 555);//
    Aluno *a5 =CriaAluno("Eduardo", 9997);//
    Aluno *a6 =CriaAluno("Raony", 909);//

    insere(table1, RetornaMatricula(a1), a1, hashAluno);
    insere(table1, RetornaMatricula(a2), a2, hashAluno);
    insere(table1, RetornaMatricula(a3), a3, hashAluno);
    insere(table1, RetornaMatricula(a4), a4, hashAluno);
    insere(table1, RetornaMatricula(a5), a5, hashAluno);
    insere(table1, RetornaMatricula(a6), a6, hashAluno);

    imprimeHash(table1, ImprimeAluno);

    Hash *table2 = criaHash(8);

    char *str1 = "ola mundo!\0";
    char *str2 = "ok\0";
    char *str3 = "ko\0";

    insere(table2, str1, str1, hashString);
    insere(table2, str2, str2, hashString);
    insere(table2, str3, str3, hashString);

    imprimeHash(table2, imprimeStr);

    Aluno *a7 = busca(table1, 555, hashAluno, ComparaMatricula);
    printf("Encontrou:");
    ImprimeAluno(a7);

    //char str4[20];
    //str4 = strcpy(str4, busca(table2, str2, hashString, comparaStr));

    liberaHash(table1);
    liberaHash(table2);

    LiberaAluno(a1);
    LiberaAluno(a2);
    LiberaAluno(a3);
    LiberaAluno(a4);
    LiberaAluno(a5);
    LiberaAluno(a6);
    LiberaAluno(a7);

    return 0;
}
