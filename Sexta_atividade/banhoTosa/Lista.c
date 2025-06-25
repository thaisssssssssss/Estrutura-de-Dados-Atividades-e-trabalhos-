#include "Lista.h"


typedef struct celula Celula;

struct celula{
    void* animal;
    int tipo;
    Celula* prox;
    Celula* ant;
};

struct lista{
    Celula* prim;
    Celula* ult;
};


Lista* incializaLista(){
    Lista* l = malloc(sizeof(struct lista));
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

void insereItemLista(Lista* l, void* animal, int tipo){
    Celula* nova = malloc(sizeof(struct celula));
    nova->animal = animal;
    nova->tipo = tipo;
    nova->prox = NULL;
    nova->ant = NULL;

    if(l->prim == NULL && l->ult == NULL){
        l->prim = nova;
        l->ult = nova;
        return;
    }

    l->ult->prox = nova;
    nova->ant = l->ult;
    l->ult = nova;
}

void imprimeLista(Lista* l){
    Celula* aux;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        if(aux->tipo == CACHORRO) imprimeCachorro(aux->animal);
        else imprimeGato(aux->animal);
    }
}

void liberaLista(Lista* l){
    Celula* atual = l->prim;
    Celula* seguinte;

    while (atual != NULL){
        seguinte = atual->prox;
        free(atual);
        atual = seguinte;
    }
    free(l);
}

int retornaQtdPorTipo(Lista* l, int tipo){
    int qtd = 0;
    Celula* aux;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        if(aux->tipo == tipo) qtd++;
    }
    return qtd;
}

int comparacao(void* animal1, void* animal2, int tipo1, int tipo2){
    if(tipo1 == tipo2){
        if(tipo1 == CACHORRO) if(comparaNomeCachorro(animal1, animal2)) return 1;
        else return 0;
    
        if(tipo1 == GATO) if(comparaNomeGato(animal1, animal2)) return 1;
        else return 0;
    }
    else return 0;
}

int confereItemNaLista(Lista* l, void* animal, int tipo){
    Celula* aux;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        if(comparacao(aux->animal, animal, aux->tipo, tipo)) return 1;
    }
    return 0;
}

void retiraItemLista(Lista* l, void* animal, int tipo){
    Celula* p = l->prim;

    while(p != NULL && !comparacao(p->animal, animal, tipo, p->tipo)){
        p = p->prox;
    }

    if(p == NULL) return;

    if(p == l->prim && p == l->ult){
        l->prim = NULL;
        l->ult = NULL;
        free(p);
        return;
    }

    if(p == l->prim){
        p->prox->ant = NULL;
        l->prim = p->prox;
        free(p);
        return;
    }

    if(p == l->ult){
        p->ant->prox = NULL;
        l->ult = p->ant;
        free(p);
        return;
    }

    p->prox->ant = p->ant;
    p->ant->prox = p->prox;
    free(p);
    return;
}