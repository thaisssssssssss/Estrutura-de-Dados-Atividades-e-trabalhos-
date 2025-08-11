#ifndef VETOR_H
#define VETOR_H

#include "palavra.h"

typedef struct vetor Vetor;

Vetor* criaVetor(int tamanho);
void colocaPalavraVetor(Vetor* vetor, Palavra* palavra);

#endif