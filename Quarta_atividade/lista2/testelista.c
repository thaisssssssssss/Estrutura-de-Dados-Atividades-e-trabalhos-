#ifndef testelista_h
#define testelista_h


#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

typedef struct lista Lista;

typedef struct celula Celula;

struct celula{
    tProduto* prod;
    Celula* prox;
};

struct lista{
    Celula* prim;
    Celula* ult;
};


Lista* criaLista(){
    Lista* l = malloc(sizeof(struct celula));

    l->prim = NULL;
    l->ult = NULL;
    return l;
}

void adicionaElementoListaInicio(Lista* l, tProduto* prod){
    Celula* nova = malloc(sizeof(struct celula));
    nova->prod = prod;
    nova->prox = l->prim;
    l->prim = nova;

    if(l->ult == NULL) l->ult = nova;
}

void adicionaElementoListaFim(Lista* l, tProduto* prod){
    Celula* nova = malloc(sizeof(struct celula));
    nova->prod = prod;
    nova->prox = NULL;

    if(l->ult == NULL && l->prim == NULL){
        l->prim = nova;
        l->ult = nova;
    }
    else{
        l->ult->prox = nova;
        l->ult = nova;
    }
}

tProduto* retiraElementoLista(Lista* l, int mat){
    Celula* p = l->prim;
    Celula* ant = NULL;

    while(p != NULL && !comparaCodigo(p->prod, mat)){
        ant = p;
        p = p->prox;
    }

    //caso nao haja elemento na lista
    if(p == NULL) return NULL;

    //caso seja o unico elemento da lista
    if(l->prim->prox == NULL){
        tProduto* prod = p->prod;
        l->prim = NULL;
        l->ult = NULL;
        free(p);
        return prod;
    }

    //caso seja o primeiro elemento da lista
    if(l->prim == p){
        tProduto* prod = p->prod;
        l->prim = p->prox;

        free(p);
        return prod;
    }

    //caso seja o ultimo elemento da lista
    if(l->ult == p){
        l->ult = ant;
        ant->prox = NULL;
        tProduto* prod = p->prod;
        free(p);
        return prod;
    }

    //caso normal em que o elemento esta no meio da lista;
    ant->prox = p->prox;
    tProduto* prod = p->prod;
    free(p);
    return prod;


}
void imprimeLista(Lista* l){
    Celula* aux;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        imprimeProduto(aux->prod);
    }
}

void liberaLista(Lista* l){
    Celula* temp;
    Celula* next;
    temp = l->prim;
    while(temp != NULL){
        next = temp->prox;
        free(temp->prod);
        free(temp);
        temp = next;
    }
    free(l);
}


#endif