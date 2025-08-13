#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

typedef struct hash Hash;

Hash* criaHash();

void insereHash(Hash* tabela, Aluno* a);

void redimensionaHash(Hash* tabela);

void imprimeHash(Hash* tabela, FILE* saida);

void liberaHash(Hash* tabela);

int quantidadeItensHash(Hash* tabela);

Aluno** retornaVetor(Hash* tabela);



#endif