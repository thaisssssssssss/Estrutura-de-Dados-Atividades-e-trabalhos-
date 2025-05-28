//
// criado por Thais Brandao
//
// dia 28 de marco de 2025
//

#include "lista.h"

struct listaDpl {
    tProduto* prod;
    ListaDpl* prox;
    ListaDpl* ant;
};


ListaDpl* criaLista(){
    return NULL;
}


ListaDpl* insereElementoListaInicio(ListaDpl* l, tProduto* prod){
    ListaDpl* nova = malloc(sizeof(struct listaDpl));
    nova->prod = prod;
    nova->prox = l;
    nova->ant = NULL;
    if(l != NULL) l->ant = nova;    //se o l passado nao for o primeira da lista, ento ele eh null e o ponteiro que aponta pra anterior nao existe, caso contrario, o l->ant aponta pra nova 

    return nova;
}


static ListaDpl* buscaElementoLista(ListaDpl* l, int codigo){
    ListaDpl* p;
    for(p = l; p != NULL; p = p->prox){
        if(comparaCodigo(p->prod, codigo)) return p;
    }

    return NULL;
}


ListaDpl* retiraElementoLista(ListaDpl* l, int codigo){
    ListaDpl* p = buscaElementoLista(l, codigo);

    //casos

    if(p == NULL) return l; //nao esta na lista

    if(p == l){  //primeiro elemento
        l = l->prox;  
    }
    else{
        p->ant->prox = p->prox;
    }

    if(p->prox != NULL){  //ultimo da lista
        p->prox->ant = p->ant;
    }

    liberaProduto(p->prod);
    free(p);
    return l;
}


void imprimeElementoPorCodigo(ListaDpl* l, int codigo){
    ListaDpl* p = buscaElementoLista(l, codigo);
    if(p != NULL) imprimeProduto(p->prod);
}


void imprimeLista(ListaDpl* l){
    ListaDpl* aux;
    for(aux = l; aux != NULL; aux = aux->prox){
        imprimeProduto(aux->prod);
    }
}


void liberaLista(ListaDpl* l){
    ListaDpl* temp = l;
    ListaDpl* next;
     
    while(temp != NULL){
        next = temp;
        temp = temp->prox;
        liberaProduto(next->prod);
        free(next);
    }
}

