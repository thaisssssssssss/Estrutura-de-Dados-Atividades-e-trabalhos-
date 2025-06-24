#ifndef fila_h
#define fila_h

#include <stdio.h>

typedef struct fila Fila;

Fila* criaFila();

void insereFila(Fila* f, int num);

int retiraFila(Fila* f);

void imprimeFila(Fila* f);



#endif