//
// Criado por Thais Gomes 
//
// Dia 11/06/2025
//

#ifndef fila_h
#define fila_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "amostra.h"

typedef struct fila Fila;

Fila* criaFila();
void adicionaAmostraFilaSemPrioridade(Fila* fila, Amostra* amostra);
void adicionaAmostraFilaComPrioridade(Fila* fila, Amostra* amostra);
Amostra* retiraAmostraFila(Fila* fila);
void liberaCelulaFila(Fila* fila);
void liberaFila(Fila* fila);
void imprimeFila(Fila* fila);
void organizaFilas(Fila* naoProcessados, Fila* positivo, Fila* negativo, int limite);

#endif