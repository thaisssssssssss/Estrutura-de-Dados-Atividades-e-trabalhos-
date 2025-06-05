#ifndef lista_h
#define lista_h

#define CACHORRO 2
#define GATO 3

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
int confereAnimalEstaNaListaErrada(Lista* l, void* animal, int especie, int agressividade);
Lista* retiraAnimalLista(Lista* l, void* animal, int especie);

#endif