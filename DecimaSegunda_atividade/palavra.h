// palavra.h
//
// Criado por Thais Gomes Brandao no dia 27/07/2025
//

#ifndef PALAVRA_H
#define PALAVRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palavra Palavra;

Palavra* criaPalavra(char* string, int frequencia);
Palavra** criaVetorPalavras(int tamanho);
void liberaVetorPalavras(Palavra** palavra, int tamanho);
void imprimeVetorPalavras(Palavra** palavra, int tamanho, FILE* arquivo);
Palavra** ordenaVetorPalavras(Palavra** palavra, int tamanho);

#endif

