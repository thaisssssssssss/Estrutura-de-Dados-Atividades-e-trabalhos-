#ifndef ESTOQUE_H
#define ESTOQUE_H
#include "item.h"

typedef struct Estoque tEstoque;

struct Estoque{
    int valor;
    tItem** itens;
    int qtdItens;
};

char* leLinha();
tEstoque* criaEstoque();
void imprimeEstoque(tEstoque* estoque);
void liberaEstoque(tEstoque* estoque);
#endif