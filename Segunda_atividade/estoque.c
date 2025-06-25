#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"


tEstoque* criaEstoque(){
    tEstoque *estoque = malloc(sizeof(struct Estoque));

    printf("Insira o valor do estoque:\n");
    scanf("%d", &estoque->valor);

    int i; 
    printf("Insira a qtd de itens no estoque:\n");
    scanf("%d", &estoque->qtdItens);
    estoque->itens = malloc(sizeof(struct Item*) * estoque->qtdItens);

    for(i = 0; i < estoque->qtdItens; i++){
        estoque->itens[i] = criaItem();
    }
    
    return estoque;
}

int retornaValorEstoque(tEstoque* estoque){
    return estoque->valor;
}

void imprimeEstoque(tEstoque* estoque){
    int i;
    printf("\nEstoque: %d\n", estoque->valor);
    for(i = 0; i < estoque->qtdItens; i++){
        imprimeItem(estoque->itens[i]);
    }
}

void liberaEstoque(tEstoque* estoque){
    if(estoque!= NULL){
        if(estoque->itens != NULL){
            int i;
            for(i = 0; i < estoque->qtdItens; i++){
                liberaItem(estoque->itens[i]);
            }
            free(estoque->itens);
        }
        free(estoque);
    }
}

// int corfirmaTemProdutoEstoque(tEstoque* estoque, char* nomeProduto){
//     int i;
//     for(i = 0; i < estoque->qtdItens; i++){
//         if(comparaProdutos(estoque->itens[i], nomeProduto)){
//             printf("Produto encontrado no estoque:\n");
//             //imprimeItem(estoque->itens[i]);
//             return 1;
//         }
//     }
//     return 0;
// }

// tItem* retornaItem(tEstoque* estoque, char* nomeProduto){
//     int i;
//     for(i = 0; i < estoque->qtdItens; i++){
//         if(comparaProdutos(estoque->itens[i], nomeProduto)){
//             return estoque->itens[i];
//         }
//     }
// }