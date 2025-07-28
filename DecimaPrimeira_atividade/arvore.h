// arvore.h
//
// Criado por Thais Gomes Brandao no dia 27/07/2025
//

#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

typedef struct arvore Arvore;

Arvore* criaArvoreVazia();
Arvore* criaArvore(Aluno* aluno, Arvore* dir, Arvore* esq);
void imprimeArvore(Arvore* arv);
int estaVaziaArvore(Arvore* arv);
Arvore* insereAlunoArvore(Arvore* arv, Aluno* aluno);
Aluno* buscaAlunoArvore(Arvore* arv, int matricula);
Arvore* retiraAlunoArvore(Arvore* arv, int matricula);
Arvore* liberaArvore(Arvore* arv);

#endif