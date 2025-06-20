#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

struct produto{
    char* nome;
    int calorias;
    char* ingrediente;
};


TProduto* InicProd(char* nome, int calorias){
    TProduto* prod = malloc(sizeof(struct produto));
    prod->nome = strdup(nome);
    prod->calorias = calorias;
    return prod;
}

void InsereIngrediente(TProduto* prod, char* ingrediente);

int ComparaProdutos(TProduto* p1, char* nome){
    return (strcmp(p1->nome, nome) == 0);
}

int retornaCaloriasProduto(TProduto* prod){
    return prod->calorias;
}

void ImprimeProduto(TProduto* prod){
    printf("\n nome produto: %s\n", prod->nome);
}

void DestroiProd(TProduto* prod){
    if(prod != NULL){
        if(prod->nome != NULL) free(prod->nome);
        free(prod);
    }
}

