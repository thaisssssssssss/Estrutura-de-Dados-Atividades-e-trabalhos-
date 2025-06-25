#include "pilhaMultipla.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    TipoPilhaMultipla* p = inicializaPilhaMultipla();

    // Empilha em 3 pilhas diferentes
    for(int i = 0; i < 5; i++){
        TipoItem* item1 = malloc(sizeof(TipoItem));
        *item1 = i;
        empilha(p, 0, item1); // pilha 0

        TipoItem* item2 = malloc(sizeof(TipoItem));
        *item2 = i + 10;
        empilha(p, 1, item2); // pilha 1

        TipoItem* item3 = malloc(sizeof(TipoItem));
        *item3 = i + 20;
        empilha(p, 2, item3); // pilha 2
    }

    // Desempilha tudo da pilha 1
    printf("Desempilhando pilha 1:\n");
    while(!vazia(p, 1)){
        TipoItem* item = desempilha(p, 1);
        printf("Item: %d\n", *item);
        free(item);
    }

    liberaPilhaMultipla(p);
    return 0;
}
