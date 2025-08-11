#ifndef HASH_H
#define HASH_H

#include "palavra.h"
#include "vetor.h"

typedef struct hash Hash;

Hash* criaHash();
static int hash(Hash* tabela, char* palavra);
void insereHash(Hash* tabela, Palavra* palavra);
static void redimensionaHash(Hash* tabela);
void imprimeHash(Hash* tabela);
void liberaHash(Hash* tabela);
Palavra* retornaPalavraMaisFrequente(Hash* tabela);
Vetor* criaVetorPalavras(Hash* tabela);
void preencheVetor(Vetor* vetor, Hash* tabela);

#endif