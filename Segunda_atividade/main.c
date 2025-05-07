#include <stdio.h>
#include "supermercado.h"

int main(){
    tSupermercado *mercado = criaMercado();
    mercado = criaFiliaisMercado(mercado);
    imprimeMercado(mercado);
    liberaMercado(mercado);
    return 0;
}

