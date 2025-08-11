#ifndef PALAVRA_H
#define PALAVRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vetor.h"

typedef struct palavra Palavra;

Palavra* criaPalavra(char* palavra);
char* retornaCharPalavra(Palavra* palavra);
int retornaFrequencia(Palavra* palavra);
void imprimePalavraLista(Palavra* palavra);
void imprimePalavra(Palavra* palavra);
Palavra* adicionaPalavraLista(Palavra* prim, Palavra* adicionada);
void liberaPalavra(Palavra* palavra);
Palavra* PalavraMaisFrequente(Palavra* palavra);
int retornaTamanhoLista(Palavra* palavra);

void preencheVetorPalavras(Vetor* vetor, Palavra* palavra);



#endif