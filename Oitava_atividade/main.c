#include <stdio.h>
#include "pilhaDupla.h"

int main(){
    TipoPilhaDupla* pilha = inicializaPilhaDupla();

    while(1){
        TipoItem valor;

        scanf("%d", &valor);
        if(!insereValorPilha1(pilha, valor)) break;

        scanf("%d", &valor);
        if(!insereValorPilha2(pilha, valor)) break;

        int parada;
        printf("Quer parar?\n");
        scanf("%d", &parada);
        if(parada) break;
    }

    imprimePilhaDupla(pilha);
    liberaPilhaDupla(pilha);
    return 0;
}