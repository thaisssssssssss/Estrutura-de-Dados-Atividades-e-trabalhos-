#ifndef lista_h
#define lista_h

#include "gato.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cachorro.h"

typedef struct lista Lista;

Lista* inicializaLista();
Lista* adicionaCachorroLista(Lista* l, Cachorro* c);
Lista* adicionaGatoLista(Lista* l, Gato* g);
void imprimeLista(Lista* l);
int returnQtdGatos(Lista* l);
int returnQtdCachorros(Lista* l);
void liberaLista(Lista* l);

#endif