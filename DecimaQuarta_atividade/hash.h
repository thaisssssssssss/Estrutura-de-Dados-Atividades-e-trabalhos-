#ifndef HASH_H
#define HASH_H

#include "palavra.h"

typedef struct hash Hash;

Hash* criaHash();
static int hash(Hash* tabela, char* palavra);
void insereHash(Hash* tabela, Palavra* palavra);
static void redimensionaHash(Hash* tabela);
void imprimeHash(Hash* tabela);
void liberaHash(Hash* tabela);

#endif