#include <stdio.h>
#include <stdlib.h>
#include "estoque.h"

char* leLinha(){
    char temp[100];
    scanf(" %99[^\n]", temp);
    char* str = strdup(temp);
    return str;
}

tEstoque* criaEstoque(){
    tEstoque *estoque = malloc(sizeof(struct Estoque*));

    printf("Insira o valor do estoque:\n");
    scanf("%d", &estoque->valor);

    int i; 
    printf("Insira a qtd de itens no estoque\n");
    scanf("%d", &estoque->qtdItens);
    estoque->itens = malloc(sizeof(struct Item**) * estoque->qtdItens);

    for(i = 0; i < estoque->qtdItens; i++){
        estoque->itens[i] = criaItem();
    }
    
    return estoque;
}

void imprimeEstoque(tEstoque* estoque){
    int i;
    printf("Estoque: %d", estoque->valor);
    for(i = 0; i < estoque->qtdItens; i++){
        imprimeItem(estoque->itens[i]);
    }
}

void liberaEstoque(tEstoque* estoque){
    if(estoque!= NULL){
        if(estoque->itens != NULL){
            int i;
            for(i = 0; i < estoque->qtdItens; i++){
                liberaFiliais(estoque->itens[i]);
            }
        }
        free(estoque);
    }
}