#include "aluno.h"

struct aluno{
    char* nome;
    int presencas;
    int faltas;
};

Aluno* criaAluno(char* nome){
    Aluno* a = malloc(sizeof(struct aluno));
    a->nome = strdup(nome);
    a->presencas = 0;
    a->faltas = 0;
    return a;
}

void incrementaPresencas(void* a){
    Aluno* aluno = (Aluno*)a;
    aluno->presencas++;
}

void incrementaFaltas(void* a){
    Aluno* aluno = (Aluno*)a;
    aluno->faltas++;
}

void imprimeAluno(void* a, FILE* saida){
    Aluno* aluno = (Aluno*)a;
    fprintf(saida, "%s %dP %dF\n", aluno->nome, aluno->presencas, aluno->faltas);
}

void liberaAluno(void* a){
    Aluno* aluno = (Aluno*)a;
    free(aluno->nome);
    free(aluno);
}

int comparaNomeAluno(void* a1, void* a2){
    Aluno* aluno1 = (Aluno*)a1;
    Aluno* aluno2 = (Aluno*)a2;

    return (strcmp(aluno1->nome, aluno2->nome));
}