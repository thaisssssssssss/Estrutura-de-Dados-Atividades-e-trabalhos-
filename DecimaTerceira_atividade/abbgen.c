#include "abbgen.h"

struct arvore{
    void* info;
    Arvore* esq; 
    Arvore* dir;
};

Arvore* criaArvoreVazia(){
    return NULL;
}

int estaVaziaArvore(Arvore* arv){
    return(arv == NULL);
}

Arvore* criaArvore(void* info, Arvore* esq, Arvore* dir){
    Arvore* a = malloc(sizeof(struct arvore));
    a->info = info;
    a->esq = esq;
    a->dir = dir;
    return a;
}

Arvore* insereOrdenado(Arvore* arv, void* info, int(*compara)(void*, void*)){
    if(estaVaziaArvore(arv)){
        arv = criaArvore(info, NULL, NULL);
    }
    else if(compara(arv->info, info) > 0) arv->esq = insereOrdenado(arv->esq, info, compara);
    else arv->dir = insereOrdenado(arv->dir, info, compara);

    return arv;
}

Arvore* ordenaArvore(Arvore* arv, Arvore* nova, int(*compara)(void*, void*)){
    if(estaVaziaArvore(arv)) return NULL;
    else{
        nova = ordenaArvore(arv->esq, nova, compara);
        nova = ordenaArvore(arv->dir, nova, compara);
        nova = insereOrdenado(nova, arv->info, compara);
        return nova;
    }
}

void imprimeArvore(Arvore* arv, void(*imprime)(void*, FILE*), FILE* saida){
    if(estaVaziaArvore(arv));
    else{
        imprimeArvore(arv->esq, imprime, saida);
        imprime(arv->info, saida);
        imprimeArvore(arv->dir, imprime, saida);
    }
}

Arvore* liberaArvore(Arvore* arv, void(*libera)(void*)){
    if(estaVaziaArvore(arv)) return NULL;
    else{
        arv->esq = liberaArvore(arv->esq, libera);
        arv->dir = liberaArvore(arv->dir, libera);
        libera(arv->info);
        free(arv);
    }
}