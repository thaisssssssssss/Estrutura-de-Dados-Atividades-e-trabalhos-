#ifndef listaD_h
#define listaD_h


#include <stdio.h>
#include <stdlib.h>
#include "produto.h"


typedef struct listaD ListaD;

ListaD* criaListaSEsemSentinela();

ListaD* insereElementoListaInicio(ListaD* l, tProduto* prod);

void imprimeElementoPorCodigo(ListaD* l, int codigo);

ListaD* retiraElementoLista(ListaD* l, int codigo);

void imprimeLista(ListaD* l);

void liberaLista(ListaD* l);


#endif