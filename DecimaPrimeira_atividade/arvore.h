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

Arvore* insereAlunoArvore(Arvore* arv, Aluno* aluno);

Aluno* buscaAlunoArvore(Arvore* arv, int matricula);

#endif