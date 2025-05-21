// 
// lista.h
// 
// Created by Thais Gomes on 19/05/2025.
// 

#ifndef lista_h
#define lista_h

#include "produto.h"

typedef struct lista Lista;

Lista* criaLista();
void insereProdutoLista(Lista* l, tProduto* prod);
tProduto* retiraProdutoLista(Lista* l, int codigo);
void imprimeLista(Lista* l);
void liberaLista(Lista* l);

#endif