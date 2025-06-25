#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filial.h"
#include "item.h"
typedef struct Filial tFilial;

char* leLinha(){
    char temp[100];
    scanf(" %99[^\n]", temp);
    char* str = strdup(temp);
    return str;
}

tFilial* criaFilial(){
    tFilial *f = malloc(sizeof(struct Filial));

    printf("Insira o nome da filial:\n");
    f->nome = leLinha();

    f->estoque = criaEstoque();

    return f;
}

int retornaValorEstoqueFilial(tFilial* filial){
    return retornaValorEstoque(filial->estoque);
}

void imprimeFilial(tFilial* filial){
    printf("Filial: %s\n", filial->nome);
    imprimeEstoque(filial->estoque);
}

void liberaFilial(tFilial* filial){
    if(filial != NULL){
        if(filial->estoque != NULL) liberaEstoque(filial->estoque);
        free(filial->nome);
        free(filial);
    }
}

// tItem* procuraProdutoFiliais(tFilial* filial, char* nomeProduto){
//     int temPrduto = corfirmaTemProdutoEstoque(filial->estoque, nomeProduto);
//     if(temPrduto){
//         printf("Produto encontrado na filial %s\n", filial->nome);
//         tItem *item = retornaItem(filial->estoque, nomeProduto);
//         return item;
//     }
//     return NULL;
// }

