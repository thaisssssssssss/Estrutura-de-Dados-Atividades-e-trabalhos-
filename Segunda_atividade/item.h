#ifndef ITEM_H
#define ITEM_H
#include "produto.h"

typedef struct Item tItem;

struct Item{
    int qtd;
    tProduto* produto;
};

char* leLinha();
tItem* criaFilial();
void imprimeItem(tItem* item);
void liberaItem(tItem* item);
#endif