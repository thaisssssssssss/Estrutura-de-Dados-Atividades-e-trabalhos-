#ifndef testelista_h
#define testelista_h


#include <stdio.h>
#include "produto.h"

typedef struct lista Lista;

Lista* criaLista();
void adicionaElementoListaFim(Lista* l, tProduto* prod);
void adicionaElementoListaInicio(Lista* l, tProduto* prod);
tProduto* retiraElementoLista(Lista* l, int mat);
void imprimeLista(Lista* l);
void liberaLista(Lista* l);


#endif