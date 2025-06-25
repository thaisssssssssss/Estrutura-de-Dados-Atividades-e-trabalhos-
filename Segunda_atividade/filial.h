#ifndef FILIAL_H
#define FILIAL_H
#include "estoque.h"
#include "item.h"

typedef struct Filial tFilial;

struct Filial{
    char *nome;
    tEstoque* estoque;
};

tFilial* criaFilial();
char* leLinha();
int retornaValorEstoqueFilial(tFilial* filial);
void imprimeFilial(tFilial* filial);
void liberaFilial(tFilial* filial);
//tItem* procuraProdutoFiliais(tFilial* filial, char* nomeProduto);

#endif