#include "arvore.h"

struct arvore{
    Aluno* info;
    Arvore* dir;
    Arvore* esq;
};


Arvore* criaArvoreVazia(){
    return NULL;
}

Arvore* criaArvore(Aluno* aluno, Arvore* dir, Arvore* esq){
    Arvore* arv = malloc(sizeof(struct arvore));
    arv->info = aluno;
    arv->dir = dir;
    arv->esq = esq;
    return arv;
}

void imprimeArvore(Arvore* arv){
    if(arv != NULL){
        imprimeArvore(arv->esq);
        imprimeAluno(arv->info);
        imprimeArvore(arv->dir);
    }
}

Arvore* insereAlunoArvore(Arvore* arv, Aluno* aluno){
    if(arv == NULL){
        arv = criaArvore(aluno, NULL, NULL);
    }
    else if(retornaMatriculaAluno(aluno) < retornaMatriculaAluno(arv->info)) arv->esq = insereAlunoArvore(arv->esq, aluno);
    else arv->dir = insereAlunoArvore(arv->dir, aluno);
    return arv;
}

Aluno* buscaAlunoArvore(Arvore* arv, int matricula){
    if(arv == NULL) return NULL;
    else{
        if(matricula < retornaMatriculaAluno(arv->info)) buscaAlunoArvore(arv->esq, matricula);
        else if(matricula > retornaMatriculaAluno(arv->info)) buscaAlunoArvore(arv->dir, matricula);
        else return arv->info;
    }
}
