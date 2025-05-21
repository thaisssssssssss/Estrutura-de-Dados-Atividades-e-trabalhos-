#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct Produto tProduto;

struct Produto{
    char* nome;
    int valor;
    int codigo;
};

char* lerLinha();
tProduto* criaProduto(char* nome, int valor, int codigo);
void imprimeProduto(tProduto* prod);
int comparaCodigo(tProduto* prod, int codigo);
void liberaProduto(tProduto* prod);

#endif