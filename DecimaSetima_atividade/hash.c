#include "hash.h"

struct hash{
    int n;
    int dim;
    Aluno** vetor;
};

Hash* criaHash(){
    Hash* tabela = malloc(sizeof(struct hash));
    tabela->n = 0;
    tabela->dim = 29;
    tabela->vetor = malloc(sizeof(struct aluno*) * tabela->dim);

    int i;
    for(i = 0; i < tabela->dim; i++){
        tabela->vetor[i] = NULL;
    }

    return tabela;
}

int hash(Hash* tabela, Aluno* a){
    int h = funcao(a);
    return h % tabela->dim;
}

void insereHash(Hash* tabela, Aluno* a){
    if(tabela->n >= 0.75 * tabela->dim) redimensionaHash(tabela);

    int h = hash(tabela, a);

    if(tabela->vetor[h] == NULL){
        tabela->vetor[h] = a;
        tabela->n++;
    }
    else tabela->vetor[h] = trataColisao(tabela->vetor[h], a);
}

void redimensionaHash(Hash* tabela){
    int dimAntiga = tabela->dim;
    Aluno** vetor = tabela->vetor;

    tabela->n = 0;
    tabela->dim = dimAntiga * 1.947;
    tabela->vetor = malloc(sizeof(struct aluno*) * tabela->dim);

    int i;
    for(i = 0; i < tabela->dim; i++) tabela->vetor[i] = NULL;
        
    for(i = 0; i < dimAntiga; i++){
        if(vetor[i] != NULL) insereHash(tabela, vetor[i]);
    }

    free(vetor);
    
}

void imprimeHash(Hash* tabela, FILE* saida){
    int i;
    for(i = 0; i < tabela->dim; i++){
        if(tabela->vetor[i]) imprimeAluno(tabela->vetor[i], saida);
    }
}

void liberaHash(Hash* tabela){
    int i;
    for(i = 0; i < tabela->dim; i++){
        if(tabela->vetor[i]) liberaAluno(tabela->vetor[i]);
    }
    free(tabela->vetor);
    free(tabela);
}