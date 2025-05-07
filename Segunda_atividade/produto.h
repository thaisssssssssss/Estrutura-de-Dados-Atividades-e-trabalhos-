#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct Produto tProduto;

struct Produto{
    char* nome;
    int valor;
};

char* leLinha();
tProduto* criaEstoque();
void imprimeProduto(tProduto* prod);
void liberaProduto(tProduto* prod);

#endif