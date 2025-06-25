#ifndef ESTOQUE_H
#define ESTOQUE_H
#include "item.h"

typedef struct Estoque tEstoque;

struct Estoque{
    int valor;
    tItem** itens;
    int qtdItens;
};

tEstoque* criaEstoque();
int retornaValorEstoque(tEstoque* estoque);
void imprimeEstoque(tEstoque* estoque);
void liberaEstoque(tEstoque* estoque);
//int corfirmaTemProdutoEstoque(tEstoque* estoque, char* nomeProduto);
//tItem* retornaItem(tEstoque* estoque, char* nomeProduto);

#endif