#include <stdio.h>
#include <stdlib.h>
#include "pilhaMultipla.h"

#define MaxTam 100
#define MaxPilhas 10

struct IndicePilha{
    int Topo, Base;
};

struct TipoPilhaMultipla{
    TipoItem* Item[MaxTam];     // ponteiros para os elementos empilhados
    IndicePilha pilhas[MaxPilhas];
};

TipoPilhaMultipla* inicializaPilhaMultipla(){
    TipoPilhaMultipla* p = malloc(sizeof(TipoPilhaMultipla));

    int i;
    int tamPilha = MaxTam / MaxPilhas;

    for(i = 0; i < MaxPilhas; i++){
        p->pilhas[i].Base = i * tamPilha;
        p->pilhas[i].Topo = p->pilhas[i].Base - 1;
    }
    for(i = 0; i < MaxTam; i++){
        p->Item[i] = NULL;
    }

    return p;
}

int empilha(TipoPilhaMultipla* p, int indice, TipoItem* item){
    if(indice < 0 || indice >= MaxPilhas) return 0;

    int topo = p->pilhas[indice].Topo;
    int limite = ((indice + 1) * (MaxTam / MaxPilhas)) - 1;

    if(topo >= limite) return 0; // pilha cheia

    p->pilhas[indice].Topo++;
    p->Item[p->pilhas[indice].Topo] = item;
    return 1;
}

TipoItem* desempilha(TipoPilhaMultipla* p, int indice){
    if(indice < 0 || indice >= MaxPilhas) return NULL;

    if(p->pilhas[indice].Topo < p->pilhas[indice].Base)
        return NULL; // pilha vazia

    TipoItem* item = p->Item[p->pilhas[indice].Topo];
    p->Item[p->pilhas[indice].Topo] = NULL;
    p->pilhas[indice].Topo--;
    return item;
}

int vazia(TipoPilhaMultipla* p, int indice){
    return p->pilhas[indice].Topo < p->pilhas[indice].Base;
}

void liberaPilhaMultipla(TipoPilhaMultipla* p){
    for(int i = 0; i < MaxTam; i++){
        if(p->Item[i] != NULL)
            free(p->Item[i]);
    }
    free(p);
}
