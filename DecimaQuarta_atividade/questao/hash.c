#include "hash.h"
#include "palavra.h"

struct hash{
    int n;
    int dim;
    void** vetor;
};

Hash* criaHash(){
    Hash* tabela = malloc(sizeof(struct hash));
    tabela->n = 0;
    tabela->dim = 7;
    tabela->vetor = malloc(tabela->dim * sizeof(void*));

    int i;
    for(i = 0; i < tabela->dim; i++) tabela->vetor[i] = NULL;

    return tabela;
}

int hash(void* info, int(*funcao)(void*, int), int tamanho){
    return funcao(info, tamanho);
}

void insereHash(Hash* tabela, void* info, int(*funcao)(void*, int), void*(*colisao)(void*, void*)){
    if(tabela->n >= 0.75 * tabela->dim) redimensionaHash(tabela, funcao, colisao);

    int h = hash(info, funcao, tabela->dim);
    
    if(tabela->vetor[h] == NULL){
        tabela->vetor[h] = info;
        tabela->n++;
    }
    else tabela->vetor[h] = colisao(tabela->vetor[h], info);
}


void redimensionaHash(Hash* tabela, int(*funcao)(void*, int), void*(*colisao)(void*, void*)){
    int dimAntiga = tabela->dim;
    void** vetor = tabela->vetor;

    tabela->n = 0;
    tabela->dim = (int)(1.947 * dimAntiga);

    tabela->vetor = malloc(sizeof(void*) * tabela->dim);

    int i;
    for(i = 0; i < tabela->dim; i++){
        tabela->vetor[i] = NULL;
    }
    for(i = 0; i < dimAntiga; i++){
        if(vetor[i] != NULL) insereHash(tabela, vetor[i], funcao, colisao);
    }

    free(vetor);
}

void imprimeHash(Hash* tabela, void(*imprime)(void*)){
    int i;
    for(i = 0; i < tabela->dim; i++){
        if(tabela->vetor[i]) imprime(tabela->vetor[i]);
    }
}

void liberaHash(Hash* tabela, void(*libera)(void*)){
    int i;
    for(i = 0; i < tabela->dim; i++){
        if(tabela->vetor[i]) libera(tabela->vetor[i]);
    }
    free(tabela->vetor);
    free(tabela);
}

void* retornaItem(Hash* tabela, void*(*retorna)(void*, int)){
    return retorna(tabela->vetor, tabela->dim);
}

int quantidadeItensTabela(Hash* tabela, int(*contador)(void*)){
    int i, soma = 0;
    for(i = 0; i < tabela->dim; i++){
        if(tabela->vetor[i]) soma += contador(tabela->vetor[i]);
    }
    return soma;
}