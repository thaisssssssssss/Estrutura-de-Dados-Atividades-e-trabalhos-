//
//
//Criado por Thais Gomes no dia 24/06/2025
//
//

#ifndef filaLista_h
#define filaLista_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "amostra.h"

typedef struct filaLista FilaLista;


FilaLista* criaFila();

void insereInicioFila(FilaLista* f, Amostra* a);

void insereFimFila(FilaLista* f, Amostra* a);

void imprimeLista(FilaLista* f);

void liberaLista(FilaLista* f);

Amostra* retiraItemLista(FilaLista* f);

#endif