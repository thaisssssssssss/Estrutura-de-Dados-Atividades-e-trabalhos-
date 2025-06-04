#ifndef gato_h
#define gato_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BRAVO 0
#define MANSO 1

typedef struct gato Gato;

Gato* inicGato(char* nome, int agressividade);
void liberaGato(Gato* gato);
int retornaAgressividadeGato(Gato* g);
void imprimeGato(Gato* g);
void atribuiNivelAgressividadeGato(Gato* g, int agressividade);


#endif