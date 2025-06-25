//
//
//Criado por Thais Gomes no dia 24/06/2025
//
//

#ifndef filaVetor_h
#define filaVetor_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "amostra.h"

typedef struct filaVetor FilaVetor;

#define TAM 10

FilaVetor* criaFila();

void insereFimFila(FilaVetor* f, Amostra* a);

void imprimeLista(FilaVetor* f);

void liberaLista(FilaVetor* f);

#endif