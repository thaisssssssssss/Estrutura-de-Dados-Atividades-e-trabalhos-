#include "arvore.h"

struct arvore{
    void* info;
    Arvore* esq;
    Arvore* dir;
};

Arvore* criaArvoreVazia(){
    return NULL;
}

int estaArvoreVazia(Arvore* arv){
    return (arv == NULL);
}

Arvore* criaNo(void* info, Arvore* esq, Arvore* dir){
    Arvore* arv = malloc(sizeof(struct arvore));
    arv->info = info;
    arv->esq = esq;
    arv->dir = dir;
    return arv;
}

Arvore* insereOrdenadoArvore(Arvore* arv, void* info, int(*compara)(void*, void*)){
    if(estaArvoreVazia(arv)){
        arv = criaNo(info, NULL, NULL);
    }
    else if(compara(arv->info, info) > 0) arv->esq = insereOrdenadoArvore(arv->esq, info, compara);
    else arv->dir = insereOrdenadoArvore(arv->dir, info, compara);
    return arv;
}

void imprimeArvore(Arvore* arv, void(*imprime)(void*, FILE*), FILE* saida){
    if(estaArvoreVazia(arv));
    else{
        imprimeArvore(arv->esq, imprime, saida);
        imprime(arv->info, saida);
        imprimeArvore(arv->dir, imprime, saida);
    }
}

void liberaArvore(Arvore* arv, void(*libera)(void*)){
    if(estaArvoreVazia(arv));
    else{
        liberaArvore(arv->esq, libera);
        liberaArvore(arv->dir, libera);
        libera(arv->info);
        free(arv);
    }
}

int atualizaItemArvore(Arvore* arv, void* info, int(*compara)(void*, void*), void(*atualiza)(void*)){
    if(estaArvoreVazia(arv)) return 0;
    else if(!compara(arv->info, info)){
        atualiza(arv->info);
        return 1;
    }
    else{
        if(atualizaItemArvore(arv->esq, info, compara, atualiza)) return 1;
        else return(atualizaItemArvore(arv->dir, info, compara, atualiza));
    }
}