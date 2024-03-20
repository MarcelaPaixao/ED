#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tSupermercado.h"


int main(){
    tSupermercado *mercado = CriaSuperMercado();
    ImprimeSupermercado(mercado);
    LiberaSupermercado(mercado);
    return 0;
}