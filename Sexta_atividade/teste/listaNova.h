#ifndef lista_nova_h
#define lista_nova_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cachorro.h"

typedef struct lista Lista;

Lista* criaLista();
Lista* adicionaItemLista(Lista* l, Cachorro* c);
Lista* removeItemLista(Lista* l, Cachorro* dog);
void liberaLista(Lista* l);
void imprimeLista(Lista* l);
#endif