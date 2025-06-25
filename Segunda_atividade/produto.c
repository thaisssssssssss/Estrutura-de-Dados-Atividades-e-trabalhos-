#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

char* lerLinha(){
    char temp[100];
    scanf(" %99[^\n]", temp);
    char* str = strdup(temp);
    return str;
}

tProduto* criaProduto(){
    tProduto *produto = malloc(sizeof(struct Produto));

    printf("Insira o nome do produto:\n");
    produto->nome = lerLinha();

    printf("Insira o valor do produto:\n");
    scanf("%d", &produto->valor);

    return produto;
}

void imprimeProduto(tProduto* prod){
    printf("%s, valor unitario: %d ", prod->nome, prod->valor);
}

void liberaProduto(tProduto* prod){
    if(prod != NULL){
        free(prod->nome);
        free(prod);
    }
}