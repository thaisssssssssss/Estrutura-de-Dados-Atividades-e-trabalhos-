#ifndef ITEM_H
#define ITEM_H
#include "produto.h"

typedef struct Item tItem;

struct Item{
    int qtd;
    tProduto* produto;
};

tItem* criaItem();
void imprimeItem(tItem* item);
void liberaItem(tItem* item);

#endif