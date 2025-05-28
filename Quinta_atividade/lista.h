//
// criado por Thais Brandao
//
// dia 28 de marco de 2025
//
#ifndef lista_h
#define lista_h
#include "produto.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct listaDpl ListaDpl;

ListaDpl* criaLista();
ListaDpl* insereElementoListaInicio(ListaDpl* l, tProduto* prod);
ListaDpl* retiraElementoLista(ListaDpl* l, int codigo);
void imprimeElementoPorCodigo(ListaDpl* l, int codigo);
void imprimeLista(ListaDpl* l);
void liberaLista(ListaDpl* l);

#endif