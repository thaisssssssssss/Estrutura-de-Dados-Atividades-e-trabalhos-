#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"


tProduto* criaProduto(char* nome, int valor, int codigo){
    tProduto *produto = malloc(sizeof(struct Produto));

    produto->nome = nome;
    produto->valor = valor;
    produto->codigo = codigo;
    
    return produto;
}

void imprimeProduto(tProduto* prod){
    printf("%s, valor unitario: %d, codigo: %d\n", prod->nome, prod->valor, prod->codigo);
}

int comparaCodigo(tProduto* prod, int codigo){
    return (prod->codigo == codigo);
}

void liberaProduto(tProduto* prod){
    if(prod != NULL){
        if(prod->nome != NULL) free(prod->nome);
        free(prod);
    }
}