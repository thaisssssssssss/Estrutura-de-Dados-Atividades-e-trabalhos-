#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno* criaAluno(char* nome, int f, int p);

int funcao(Aluno* a);

void imprimeAluno(Aluno* a, FILE* saida);

void imprimeAlunoUnico(Aluno* a, FILE* saida);

void liberaAluno(Aluno* a);

int comparaAlunos(Aluno* a1, Aluno* a2);

void incrementaFrequencia(Aluno* a1, Aluno* a2);

Aluno* trataColisao(Aluno* lista, Aluno* novo);

int quantidadeAlunos(Aluno* a);

int preencheVetor(Aluno** vetor, Aluno* lista, int posicao);

void imprimeVetor(Aluno** vetor, int tamanho, FILE* saida);

int compara(const void* a, const void* b);

void ordenaVetor(Aluno** vetor, int tamanho);



#endif