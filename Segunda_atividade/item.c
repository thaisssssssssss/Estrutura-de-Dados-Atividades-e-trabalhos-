#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"


tItem* criaItem(){
    tItem *item = malloc(sizeof(struct Item*));

    item->produto = criaProduto();
    printf("Insira a qtd de itens:\n");
    scanf("%d", &item->qtd);
    
    return item;
}

void imprimeItem(tItem* item){
    printf("Item:");
    imprimeProduto(item->produto);
    printf("quantidade: %d", item->qtd);

}

void liberaItem(tItem* item){
    if(item != NULL){
        if(item->produto != NULL) liberaProduto(item->produto);
        free(item);
    }
}