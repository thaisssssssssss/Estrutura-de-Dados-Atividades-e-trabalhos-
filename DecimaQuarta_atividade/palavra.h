#ifndef PALAVRA_H
#define PALAVRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palavra Palavra;

Palavra* criaPalavra(char* palavra);
char* retornaCharPalavra(Palavra* palavra);
void imprimePalavra(Palavra* palavra);
Palavra* adicionaPalavraLista(Palavra* prim, Palavra* adicionada);
void liberaPalavra(Palavra* palavra);
#endif