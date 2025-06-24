#include "fila.h"
#include "stdlib.h"
#include <stdio.h>

int main(){
    Fila* f = criaFila();

    int i = 9;

    while(i){
        insereFila(f, i);
        i--;
    }

    retiraFila(f);
    retiraFila(f);

    i = 2;
    while(i){
        insereFila(f, i);
        i--;
    }

    imprimeFila(f);
}