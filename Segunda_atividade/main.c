#include <stdio.h>
#include "supermercado.h"
#include "item.h"

int main(){
    tSupermercado *mercado = criaMercado();
    mercado = criaFiliaisMercado(mercado);
    imprimeMercado(mercado);
    liberaMercado(mercado);

    int operacao;

    // printf("1-Procurar produto, qualquer filial\n2-Procurar produto, filial especifica\n");
    // scanf("%d", &operacao);
    // tItem* item = procuraProduto(mercado, operacao);
    // if(item != NULL) imprimeItem(item);
    return 0;
}

