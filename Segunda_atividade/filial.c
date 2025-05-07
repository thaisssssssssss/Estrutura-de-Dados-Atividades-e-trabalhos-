#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filial.h"

typedef struct Filial tFilial;

char* leLinha(){
    char temp[100];
    scanf(" %99[^\n]", temp);
    char* str = strdup(temp);
    return str;
}

tFilial* criaFilial(){
    tFilial *f = malloc(sizeof(struct Filial*));

    printf("Insira o nome da filial:\n");
    f->nome = leLinha();

    f->estoque = criaEstoque();

    return f;
}

void imprimeFilial(tFilial* filial){
    printf("Filial: %s", filial->nome);
    imprimeEstoque(filial->estoque);
}

void liberaFilial(tFilial* filial){
    if(filial != NULL){
        if(filial->estoque != NULL) liberaEstoque(filial->estoque);
        free(filial->nome);
        free(filial);
    }
}