#include "aluno.h"

struct aluno{
    char* nome;
    int matricula;
    int cr;
};

Aluno* criaAluno(char* nome, int matricula, int cr){
    Aluno* a = malloc(sizeof(struct aluno));
    a->nome = strdup(nome);
    a->matricula = matricula;
    a->cr = cr;
    return a;
}

int comparaPorNome(void* a1, void* a2){
    Aluno* aluno1 = (Aluno*)a1;
    Aluno* aluno2 = (Aluno*)a2;

    return strcmp(aluno1->nome, aluno2->nome);
}

int comparaPorMatricula(void* a1, void* a2){
    Aluno* aluno1 = (Aluno*)a1;
    Aluno* aluno2 = (Aluno*)a2;

    if(aluno1->matricula < aluno2->matricula) return 1;
    else return 0;
}

void imprimeAluno(void* a, FILE* saida){
    Aluno* aluno = (Aluno*)a;
    fprintf(saida, "%d %s %d\n", aluno->matricula, aluno->nome, aluno->cr);
}

void liberaAluno(void* a){
    Aluno* aluno = (Aluno*)a;
    if(aluno != NULL){
        free(aluno->nome);
        free(aluno);
    }
}