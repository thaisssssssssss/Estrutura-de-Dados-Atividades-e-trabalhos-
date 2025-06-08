#include "listaNova.h"

typedef struct celula Celula;

struct celula{
    Cachorro* dog;
    Celula* prox;
    Celula* ant;
};

struct lista{
    Celula* prim;
    Celula* ult;
};

Lista* criaLista(){
    Lista* l = malloc(sizeof(struct lista));
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

Lista* adicionaItemLista(Lista* l, Cachorro* c){
    Celula* nova = malloc(sizeof(struct celula));
    nova->dog = c;
    nova->prox = NULL;
    nova->ant = NULL;

    if(l->prim == NULL && l->ult == NULL){
        l->prim = nova;
        l->ult = nova;
    }
    else{
        nova->ant = l->ult;
        l->ult->prox = nova;
        l->ult = nova;
    }
    return l;
}

Lista* removeItemLista(Lista* l, Cachorro* dog){
    Celula* aux = l->prim;

    while(aux != NULL){
        if(comparaNomeCachorro(aux->dog, dog)) break;
        aux = aux->prox;
    }

    if(aux == NULL) return l;
    
    if(aux == l->prim){
        aux->prox->ant = NULL;
        l->prim = aux->prox;
        free(aux);
        return l;
    }

    if(aux == l->ult){
        aux->ant->prox = NULL;
        l->ult = aux->ant;
        free(aux);
        return l;
    }

    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    free(aux);
    return l;
}

void liberaLista(Lista* l){
    Celula* atual = l->prim;
    Celula* seguinte;

    while(atual != NULL){
        seguinte = atual->prox;
        free(atual);
        atual = seguinte;
    }
    free(l);
}

void imprimeLista(Lista* l){
    Celula* aux;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        imprimeCachorro(aux->dog);
    }
}
