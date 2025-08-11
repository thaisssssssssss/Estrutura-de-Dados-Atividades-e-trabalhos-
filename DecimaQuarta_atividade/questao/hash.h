#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hash Hash;

Hash* criaHash();

int hash(void* info, int(*funcao)(void*, int), int tamanho);

void insereHash(Hash* tabela, void* info, int(*funcao)(void*, int), void*(*colisao)(void*, void*));

void redimensionaHash(Hash* tabela, int(*funcao)(void*, int), void*(*colisao)(void*, void*));

void imprimeHash(Hash* tabela, void(*imprime)(void*));

void liberaHash(Hash* tabela, void(*libera)(void*));

void* retornaItem(Hash* tabela, void*(*retorna)(void*, int));

int quantidadeItensTabela(Hash* tabela, int(*contador)(void*));

#endif