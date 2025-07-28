// arvore.h
//
// Criado por Thais Gomes Brandao no dia 27/07/2025
//

#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavra.h"

typedef struct arvore Arvore;

Arvore* criaArvoreVazia();
Arvore* criaArvore(char* palavra, Arvore* esq, Arvore* dir);
int comparaPalavras(char* palavra, Arvore* arv);
int estaVaziaArvore(Arvore* arv);
Arvore* inserePalavraArvore(Arvore* arv, char* palavra);
void imprimeArvore(Arvore* arv);
int qtdTotaldePalavras(Arvore* arv);
int ocorrenciasPalavraArvore(Arvore* arv, char* palavra);
void ocorrenciaPalavrasDistintasArvore(Arvore* arv, Arvore** visitada, int* totalPalavras);
int existePalavraArvore(Arvore* arv, char* palavra);
void palavraMaisFrequenteArvore(Arvore* arv, Arvore** visitada, int* frequencia, char** palavra);
Arvore* liberaArvore(Arvore* arv);
void preencheVetorPalavras(Arvore* arv, Arvore** visitada, Palavra** vetor, int tamanho, int* posicao);

#endif