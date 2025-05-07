#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

char* leLinha(){
    char temp[100];
    scanf(" %99[^\n]", temp);
    char* str = strdup(temp);
    return str;
}

tProduto* criaEstoque(){
    tProduto *produto = malloc(sizeof(struct Produto*));

    printf("Insira o nome do produto:\n");
    produto->nome = leLinha();

    printf("Insira o valor do produto:\n");
    scanf("%d", &produto->valor);

    return produto;
}

void imprimeProduto(tProduto* prod){
    printf("%s, valor unitario: %d", prod->nome, prod->valor);
}

void liberaProduto(tProduto* prod){
    if(prod != NULL) free(prod);
}