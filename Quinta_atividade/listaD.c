#include "listaD.h"

struct listaD{
    tProduto* prod;
    ListaD* prox;
};

ListaD* criaListaSEsemSentinela(){
    ListaD* l = NULL;
    return l;
}

ListaD* insereElementoListaInicio(ListaD* l, tProduto* prod){
    ListaD* nova = malloc(sizeof(struct listaD));
    nova->prod = prod;
    nova->prox = l;

    return nova;
}

void imprimeElementoPorCodigo(ListaD* l, int codigo){
    ListaD* aux;
    for(aux = l; aux != NULL; aux = aux->prox){
        if(comparaCodigo(aux->prod, codigo)) imprimeProduto(aux->prod);
    }
}


ListaD* retiraElementoLista(ListaD* l, int codigo){
    ListaD* p = l;
    ListaD* ant;
    
    while(p != NULL && !comparaCodigo(p->prod, codigo)){
        ant = p;
        p = p->prox;
    }

    //unico
    if(p == l && l->prox == NULL){
        liberaProduto(p->prod);
        free(p);
        l = NULL;
        return l;
    }

    //primeiro
    if(p == l){
        l = l->prox;
        liberaProduto(p->prod);
        free(p);
        return l;
    }

    //ultimo
    if(p->prox == NULL){
        ant->prox = NULL;
        liberaProduto(p->prod);
        free(p);
        return l;
    }

    ant->prox = p->prox;
    return l;
}


void imprimeLista(ListaD* l){
    ListaD* aux;
    for(aux = l; aux != NULL; aux = aux->prox){
        imprimeProduto(aux->prod);
    }
}

void liberaLista(ListaD* l){
    ListaD* atual = l;
    ListaD* seguinte;

    while(atual != NULL){
        seguinte = atual->prox;
        liberaProduto(atual->prod);
        free(atual);
        atual = seguinte;
    }
}