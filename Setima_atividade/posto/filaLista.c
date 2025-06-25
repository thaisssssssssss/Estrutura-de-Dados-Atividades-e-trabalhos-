//
//
//Criado por Thais Gomes no dia 24/06/2025
//
//


#include "filaLista.h"

typedef struct celula Celula;

struct celula{
    Amostra* amostra;
    Celula* prox;
};

struct filaLista{
    Celula* prim;
    Celula* ult;
};

FilaLista* criaFila(){
    FilaLista* f = malloc(sizeof(struct filaLista));
    f->prim = NULL;
    f->ult = NULL;
    return f;
}

void insereInicioFila(FilaLista* f, Amostra* a){
    Celula* nova = malloc(sizeof(struct celula));
    nova->amostra = a;
    nova->prox = NULL;

    if(f->prim == NULL && f->ult == NULL){
        f->prim = nova;
        f->ult = nova;
        return;
    }

    nova->prox = f->prim;
    f->prim = nova;
}

void insereFimFila(FilaLista* f, Amostra* a){
    Celula* nova = malloc(sizeof(struct celula));
    nova->amostra = a;
    nova->prox = NULL;

    if(f->prim == NULL && f->ult == NULL){
        f->prim = nova;
        f->ult = nova;
        return;
    }

    f->ult->prox = nova;
    f->ult = nova;
}

void imprimeLista(FilaLista* f){
    Celula* aux;
    for(aux = f->prim; aux != NULL; aux = aux->prox){
        imprimeAmostra(aux->amostra);
    }
}

void liberaLista(FilaLista* f){
    Celula* atual = f->prim;
    Celula* seguinte;

    while(atual != NULL){
        seguinte = atual->prox;
        liberaAmostra(atual->amostra);
        free(atual);
        atual = seguinte;
    }
    free(f);
}

Amostra* retiraItemLista(FilaLista* f){
    if(f->prim != NULL){
        Celula* p = f->prim;
        Amostra* a = p->amostra;
        f->prim = p->prox;
        free(p);
        return a;
    }
    return NULL;
}