//
//
//Criado por Thais Gomes no dia 24/06/2025
//
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaVetor.h"
#include "amostra.h"


struct filaVetor{
    Amostra** amostras;
    int inicio;
    int n;
};

FilaVetor* criaFila(){
    FilaVetor* f = malloc(sizeof(struct filaVetor));
    f->amostras = malloc(TAM * sizeof(struct amostra*));
    f->inicio = 0;
    f->n = 0;
    return f;
}

void insereFimFila(FilaVetor* f, Amostra* a){
    if(f->n >= TAM){
        printf("Fila Cheia!");
        return;
    }

    int pos = (f->inicio + f->n) % TAM;
    f->amostras[pos] = a;
    //f->inicio = (f->inicio + 1) % TAM;
    f->n++;
}

void imprimeLista(FilaVetor* f){
    int i;
    for(i = 0; i < f->n; i++){
        int pos = (f->inicio + i) % TAM;
        imprimeAmostra(f->amostras[pos]);
    }
}

void liberaLista(FilaVetor* f){
    int i;
    for(i = 0; i < f->n; i++){
        int pos = (f->inicio + i) % TAM;
        liberaAmostra(f->amostras[pos]);
    }
    free(f->amostras);
    free(f);
}
