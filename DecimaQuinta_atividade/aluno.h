#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno* criaAluno(char* nome);

void incrementaPresencas(void* a);

void incrementaFaltas(void* a);

void imprimeAluno(void* a, FILE* saida);

void liberaAluno(void* a);

int comparaNomeAluno(void* a1, void* a2);

#endif