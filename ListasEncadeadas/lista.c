//
//  lista.h
//
//  Created by Thais Gomes on 19/05/2025.
//


#include <stdio.h>
#include "lista.h"
#include <stdlib.h>
#include <string.h>

typedef struct lista Lista;
typedef struct celula Celula;

struct celula{
    Aluno* aluno;
    Celula* prox;
};

struct lista{
    Celula* prim;
    Celula* ult;
};

Lista* criaLista(){
    Lista* l = malloc(sizeof(struct lista));
    if(l == NULL){
        printf("Erro ao alocar memoria");
    }

    l->prim = NULL;
    l->ult = NULL;

    return l;
}


void liberaLista(Lista* lista){
    Celula* p = lista->prim;
    while(p != NULL){
        Celula* temp = p->prox;
        liberaAluno(p->aluno);
        free(p);
        p = temp;
    }
    free(lista);
}


void insereAluno(Lista* lista, Aluno* aluno){
    Celula* nova = malloc(sizeof(struct celula));
    if(nova == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }

    nova->prox = lista->prim;
    nova->aluno = aluno;
    lista->prim = nova;

    if(lista->ult == NULL) lista->ult = nova;
}


Aluno* retiraAluno(Lista* lista, int matricula){
    Celula* ant = NULL;
    Celula* p = lista->prim;

    while(p != NULL && retornaMatricula(p->aluno) != matricula){
        ant = p;
        p = p->prox;
    }

    if(p == NULL) return NULL; //lista vazia ou aluno nao esta na lista

    if(p == lista->prim && p == lista->ult){ //caso o aluno seja o unico na lista
        Aluno* aluno = p->aluno;
        lista->prim = NULL;
        lista->ult = NULL;
        free(p);
        return aluno;
    }

    if(lista->prim == p){ //se o aluno for o primeiro da lista
        lista->prim = p->prox;
        Aluno* aluno = p->aluno;
        free(p);
        return aluno;
    }

    if(p == lista->ult){ //se o aluno for o ultimo da lista
        lista->ult = ant;
        ant->prox = NULL;
        Aluno* aluno = p->aluno;
        free(p);
        return aluno;
    }

    ant->prox = p->prox; //caso nao haja caso especial
    Aluno* aluno = p->aluno;
    free(p);
    return aluno;
}


void imprimeLista(Lista* lista){
    Celula* aux;
    for(aux = lista->prim; aux != NULL; aux = aux->prox){
        imprimeAluno(aux->aluno);
    }
}


