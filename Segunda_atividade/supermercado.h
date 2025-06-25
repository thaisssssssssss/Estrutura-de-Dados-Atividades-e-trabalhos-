#ifndef MERCADOS_H
#define MERCADOS_H
#include "filial.h"
#include "item.h"

typedef struct Supermercado tSupermercado;

struct Supermercado{
    char *nome;
    tFilial** filiais;
    int valorTotalEstoque;
    int qtdfiliais;
};

tSupermercado* criaMercado();
tSupermercado* criaFiliaisMercado(tSupermercado* mercado);
void imprimeMercado(tSupermercado* mercado);
void liberaMercado(tSupermercado* mercado);
//tItem* procuraProduto(tSupermercado* mercado, int operacao);

#endif