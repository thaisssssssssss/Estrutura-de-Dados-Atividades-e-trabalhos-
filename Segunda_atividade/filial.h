#ifndef FILIAL_H
#define FILIAL_H
#include "estoque.h"

typedef struct Filial tFilial;

struct Filial{
    char *nome;
    tEstoque* estoque;
};

tFilial* criaFilial();
char* leLinha();
void imprimeFilial(tFilial* filial);
void liberaFilial(tFilial* filial);
#endif