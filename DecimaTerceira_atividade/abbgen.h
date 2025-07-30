#ifndef ARVORE_GENERICA_H
#define ARVORE_GENERICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

typedef struct arvore Arvore;


Arvore* criaArvoreVazia();
int estaVaziaArvore(Arvore* arv);
Arvore* criaArvore(void* info, Arvore* esq, Arvore* dir);
Arvore* insereOrdenado(Arvore* arv, void* info, int(*compara)(void*, void*));
void imprimeArvore(Arvore* arv, void(*imprime)(void*, FILE*), FILE* saida);
Arvore* liberaArvore(Arvore* arv, void(*libera)(void*));
Arvore* ordenaArvore(Arvore* arv, Arvore* nova, int(*compara)(void*, void*));

#endif