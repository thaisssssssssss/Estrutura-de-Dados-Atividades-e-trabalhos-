#include "arvore.h"

struct arvore{
    Aluno* info;
    Arvore* dir;
    Arvore* esq;
};


// Arvore* criaArvoreVazia(){
//     return NULL;
// }

// Arvore* criaArvore(Aluno* aluno, Arvore* dir, Arvore* esq){
//     Arvore* arv = malloc(sizeof(struct arvore));
//     arv->info = aluno;
//     arv->dir = dir;
//     arv->esq = esq;
//     return arv;
// }

// void imprimeArvore(Arvore* arv){
//     if(arv != NULL){
//         imprimeArvore(arv->esq);
//         imprimeAluno(arv->info);
//         imprimeArvore(arv->dir);
//     }
// }

// Arvore* insereAlunoArvore(Arvore* arv, Aluno* aluno){
//     if(arv == NULL){
//         arv = criaArvore(aluno, NULL, NULL);
//     }
//     else if(retornaMatriculaAluno(aluno) < retornaMatriculaAluno(arv->info)) arv->esq = insereAlunoArvore(arv->esq, aluno);
//     else arv->dir = insereAlunoArvore(arv->dir, aluno);
//     return arv;
// }

// Aluno* buscaAlunoArvore(Arvore* arv, int matricula){
//     if(arv == NULL) return NULL;
//     else{
//         if(matricula < retornaMatriculaAluno(arv->info)) buscaAlunoArvore(arv->esq, matricula);
//         else if(matricula > retornaMatriculaAluno(arv->info)) buscaAlunoArvore(arv->dir, matricula);
//         else return arv->info;
//     }
// }


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
    if(!estaVaziaArvore(arv)){
        imprimeArvore(arv->esq);
        imprimeAluno(arv->info);
        imprimeArvore(arv->dir);
    }
}

int estaVaziaArvore(Arvore* arv){
    return (arv == NULL);
}

Arvore* insereAlunoArvore(Arvore* arv, Aluno* aluno){
    if(estaVaziaArvore(arv)){
        arv = criaArvore(aluno, NULL, NULL);
    }
    else if(retornaMatriculaAluno(aluno) < retornaMatriculaAluno(arv->info)){
        arv->esq = insereAlunoArvore(arv->esq, aluno);
    }
    else if(retornaMatriculaAluno(aluno) >= retornaMatriculaAluno(arv->info)){
        arv->dir = insereAlunoArvore(arv->dir, aluno);
    }
    return arv;
}

Aluno* buscaAlunoArvore(Arvore* arv, int matricula){
    if(estaVaziaArvore(arv)) return NULL;
    else if(matricula < retornaMatriculaAluno(arv->info)){
        buscaAlunoArvore(arv->esq, matricula);
    }
    else if(matricula > retornaMatriculaAluno(arv->info)){
        buscaAlunoArvore(arv->dir, matricula);
    }
    else{
        //Aluno* a = arv->info;
        return arv->info;
    }
}

Arvore* retiraAlunoArvore(Arvore* arv, int matricula){
    if(estaVaziaArvore(arv));
    else if(matricula < retornaMatriculaAluno(arv->info)) arv->esq = retiraAlunoArvore(arv->esq, matricula);
    else if(matricula > retornaMatriculaAluno(arv->info)) arv->dir = retiraAlunoArvore(arv->dir, matricula);
    else{
        //caso em que e um no folha (direita e esquerda apontam pra null)
        if(estaVaziaArvore(arv->dir) && estaVaziaArvore(arv->esq)){
            free(arv);
            arv = NULL;
        }
        else if(estaVaziaArvore(arv->esq)){
            Arvore* aux = arv->dir;
            free(arv);
            arv = aux;
        }
        else if(estaVaziaArvore(arv->dir)){
            Arvore* aux = arv->esq;
            free(arv);
            arv = aux;
        }
        else{ //caso em que tem dois filhos
            Arvore* aux = arv->esq;
            while(!estaVaziaArvore(aux->dir)){
                aux = aux->dir;
            }
            Aluno* aluno = aux->info;
            aux->info = arv->info;
            arv->info = aluno;
            arv->esq = retiraAlunoArvore(arv->esq, matricula);
        }
    }
    return arv;
}

Arvore* liberaArvore(Arvore* arv){
    if(estaVaziaArvore(arv));
    else{
        arv->esq = liberaArvore(arv->esq);
        arv->dir = liberaArvore(arv->dir);
        free(arv);
    }
    return arv;
}
