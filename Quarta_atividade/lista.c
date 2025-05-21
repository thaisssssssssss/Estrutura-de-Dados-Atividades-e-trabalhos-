// 
// lista.c
// 
// Created by Thais Gomes on 19/05/2025.
// 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

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
    Lista* lista = malloc(sizeof(struct lista));
    if(lista == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }

    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}


void insereProdutoLista(Lista* l, tProduto* prod){
    Celula* nova = malloc(sizeof(struct celula));
    nova->prox = NULL;
    nova->prod = prod;
    
    if(l->prim == NULL) l->prim = nova;

    if(l->ult == NULL) l->ult = nova;
    else{
        //adicionar no fim
        l->ult->prox = nova;
        l->ult = nova;
    }
}

tProduto* retiraProdutoLista(Lista* l, int codigo){
    Celula* p = l->prim;
    Celula* ant = NULL;

    while(p->prox != NULL && !comparaCodigo(p->prod, codigo)){
        ant = p;
        p = p->prox;
    }


    if(p == NULL) return NULL; //lista vazia ou aluno nao esta na lista

    //caso o aluno seja o unico da lista
    if(l->prim == p && l->ult == p){
        l->prim = NULL;
        l->ult = NULL;

        tProduto* prod = p->prod;  
        free(p); //libera a celula
        return prod;
    }

    //caso o produto desejado seja o primeiro da lista
    if(l->prim == p){
        l->prim = p->prox;
        tProduto* prod = p->prod;  
        free(p); //libera a celula
        return prod;
    }
    
    //caso o aluno seja o ultimo d lista
    if(l->ult == p){
        l->ult = ant;
        ant->prox = NULL;
        tProduto* prod = p->prod;  
        free(p); //libera a celula
        return prod;
    }


    //caso nao haja caso especial
    ant->prox = p->prox;    //desconecta o p da lista
    tProduto* prod = p->prod;  

    free(p); //libera a celula
    return prod;
}

void imprimeLista(Lista* l){
    Celula* aux;
    for(aux = l->prim; aux != NULL; aux = aux->prox){
        imprimeProduto(aux->prod);
    }
}

void liberaLista(Lista* l){
    Celula* c = l->prim;
    Celula* prox;

    while(c != NULL){
        prox = c->prox;
        liberaProduto(c->prod);
        free(c);
        c = prox;
    }
    free(l);
}

