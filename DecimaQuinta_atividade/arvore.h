#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore Arvore;

Arvore* criaArvoreVazia();

int estaArvoreVazia(Arvore* arv);

Arvore* criaNo(void* info, Arvore* esq, Arvore* dir);

Arvore* insereOrdenadoArvore(Arvore* arv, void* info, int(*compara)(void*, void*));

void imprimeArvore(Arvore* arv, void(*imprime)(void*, FILE*), FILE* saida);

void liberaArvore(Arvore* arv, void(*libera)(void*));

int atualizaItemArvore(Arvore* arv, void* info, int(*compara)(void*, void*), void(*atualiza)(void*));

#endif