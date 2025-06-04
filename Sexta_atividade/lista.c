#include "lista.h"


#define CACHORRO 2
#define GATO 3

typedef struct celula Celula;

struct celula{
    void* animal;
    int especie;
    Celula* ant;
    Celula* prox;
};

struct lista{
    Celula* prim;
    Celula* ult;
};

Lista* inicializaLista(){
    Lista* lista = malloc(sizeof(struct lista));
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

Lista* adicionaCachorroLista(Lista* l, Cachorro* c){
    Celula* nova = malloc(sizeof(struct celula));
    nova->animal = c;
    nova->especie = CACHORRO;
    nova->ant = NULL;
    nova->prox = NULL;

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

Lista* adicionaGatoLista(Lista* l, Gato* g){
    Celula* nova = malloc(sizeof(struct celula));
    nova->animal = g;
    nova->especie = GATO;
    nova->ant = NULL;
    nova->prox = NULL;

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

void imprimeLista(Lista* l){
    Celula* aux;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        if(aux->especie == CACHORRO) imprimeCachorro(aux->animal);
        else imprimeGato(aux->animal);
    }
}

int returnQtdGatos(Lista* l){
    Celula* aux;
    int qtd = 0;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        if(aux->especie == GATO) qtd++;
    }
    return qtd;
}

int returnQtdCachorros(Lista* l){
    Celula* aux;
    int qtd = 0;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        if(aux->especie == CACHORRO) qtd++;
    }
    return qtd;
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