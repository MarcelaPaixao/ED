#include "extra.h"

void print_char_by_char(const char *str) {
    while (*str) {
        putchar(*str++);
        fflush(stdout); // Garante que o caractere seja exibido imediatamente
        usleep(85000); // Pausa por 100.000 microssegundos (0,1 segundo)-------Linux
    }
}

void print_char_by_charLowSpeed(const char *str){
    while (*str) {
        putchar(*str++);
        fflush(stdout); // Garante que o caractere seja exibido imediatamente
        usleep(300000); 
    }
    putchar('\n');
}

void print_char_by_charHighSpeed(const char *str){
    while (*str) {
        putchar(*str++);
        fflush(stdout); // Garante que o caractere seja exibido imediatamente
        usleep(70000); 
    }
}