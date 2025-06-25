//
//
// Criado por Thais Gomes no dia 25/06/2025
//
//

#ifndef lista_h
#define lista_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

typedef struct lista Lista;

Lista* inicializaLista();
void insereOrdenadoNaLista(Lista* l, Aluno* a);
void imprimeLista(Lista* l);
void liberaLista(Lista* l);

#endif