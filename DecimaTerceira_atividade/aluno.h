#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno* criaAluno(char* nome, int matricula, int cr);
int comparaPorNome(void* a1, void* a2);
int comparaPorMatricula(void* a1, void* a2);
void imprimeAluno(void* a, FILE* saida);
void liberaAluno(void* a);

#endif