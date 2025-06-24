#include "fila.h"
#include "stdlib.h"

#define TAM 10

struct fila{
    int vet[TAM];
    int inicio;
    int n;
};


Fila* criaFila(){
    Fila* f = malloc(sizeof(struct fila));
    f->n = 0;
    f->inicio = 0;
    return f;
}

void insereFila(Fila* f, int num){
    if(f->n >= TAM){
        printf("Lista Cheia!\n");
        return;
    }

    int fim = ((f->inicio + f->n) % TAM);
    f->vet[fim] = num;
    f->n++;
}

int retiraFila(Fila* f){
    if(f->n == 0){
        printf("Fila vazia!\n");
        return 0;
    }

    int num = f->vet[f->inicio];
    f->inicio = (f->inicio + 1) % TAM;
    f->n--;
    return num;
}

void imprimeFila(Fila* f){
    int i;
    for(i = 0; i < f->n; i++){
        int pos = (f->inicio + i) % TAM;
        printf("Posicao %d, numero: %d\n", pos, f->vet[pos]);
    }
}