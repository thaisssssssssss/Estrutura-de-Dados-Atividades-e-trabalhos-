#include "pilhaDupla.h"
#include <stdio.h>
#include <stdlib.h>

TipoPilhaDupla* inicializaPilhaDupla(){
    TipoPilhaDupla* p = (TipoPilhaDupla*) malloc (sizeof (TipoPilhaDupla));
    p->Pilha1.Base = 0;
    p->Pilha1.Topo = -1; /* cresce para a direita */
    p->Pilha2.Base = MaxTam -1;
    p->Pilha2.Topo = MaxTam; /* cresce para a esquerda */

    return p;
}

TipoItem insereValorPilha1(TipoPilhaDupla* p, TipoItem valor){
    if(!confereOverflow(p)){
        p->Pilha1.Topo++;
        p->Item[p->Pilha1.Topo] = malloc(sizeof(TipoItem));
        *(p->Item[p->Pilha1.Topo]) = valor;
        return 1;
    }
    return 0 ;
}

TipoItem insereValorPilha2(TipoPilhaDupla* p, TipoItem valor){
    if(!confereOverflow(p)){
        p->Pilha2.Topo--;
        p->Item[p->Pilha2.Topo] = malloc(sizeof(TipoItem));
        *(p->Item[p->Pilha2.Topo]) = valor;
        return 1;
    }
    return 0;
}

TipoItem confereOverflow(TipoPilhaDupla* p){
    if(p->Pilha1.Topo == p->Pilha2.Topo - 1){
        printf("\nPilha cheia!\n");
        return 1;
    }
    return 0;
}

void liberaPilhaDupla(TipoPilhaDupla* p){
    if(p != NULL){
        int i;
        for(i = p->Pilha1.Topo; i >= p->Pilha1.Base; i--){
            free(p->Item[i]);
        }
    
        for(i = p->Pilha2.Topo; i <= p->Pilha2.Base; i++){
            free(p->Item[i]);
        }
        free(p);
    }
}

void imprimePilhaDupla(TipoPilhaDupla* p){
    int i;
    printf("\nPilha 1:\n");
    for(i = p->Pilha1.Topo; i >= p->Pilha1.Base; i--){
        printf(" %d ", *(p->Item[i]));
    }
    
    printf("\n\nPilha 2:\n");
    for(i = p->Pilha2.Topo; i <= p->Pilha2.Base; i++){
        printf(" %d ", *(p->Item[i]));
    }
    printf("\n");
}