#ifndef PALAVRA_H
#define PALAVRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palavra Palavra;

Palavra* criaPalavra(char* palavra);

Palavra* fazCasting(void* palavra);

int funcaoPalavra(void* palavra, int tamanho);

int comparaPalavras(Palavra* palavra1, Palavra* palavra2);

void incrementaFrequenciaPalavra(Palavra* palavra);

void* trataColisao(void* palavra1, void* palavra2);

void imprimePalavra(void* palavra);

void imprimePalavraUnica(Palavra* p);

void liberaPalavra(void* palavra);

int quantidadePalavras(void* palavra);

int quantidadePalavras(void* palavra);

int quantidadePalavrasTotais(void* palavra);

char* retornaPalavra(Palavra* palavra);

int retornaFrequencia(Palavra* palavra);

Palavra* maisFrequenteLista(void* palavra);

void* retornaPalavraMaisFrequente(void* vet, int tamanho);

int preencheVetor(void* palavra, Palavra** vetor, int posicao);

void* retornaVetorPalavras(void* vet, int tamanho);

void imprimeVetorPalavras(Palavra** vetor, int tamanho);

int compara(const void* a, const void* b);

void ordenaVetorPalavras(Palavra** vetor, int tamanho);

#endif